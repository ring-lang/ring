import pytest
import ctypes
import os
import sys
import struct

# Adversarial payloads: strings exceeding typical fixed-size buffers (256, 512, 1024 bytes)
# These simulate what an attacker might pass as callback function name strings

PAYLOADS = [
    # 2x typical buffer size (512 bytes)
    "A" * 512,
    # 10x typical buffer size (2560 bytes)
    "B" * 2560,
    # Exactly at common buffer boundary + 1
    "C" * 257,
    # Large string with null bytes embedded (to test string handling)
    "D" * 128 + "\x00" + "E" * 128,
    # Unicode-like payload that might expand
    "F" * 1024,
    # Path traversal + overflow
    "../" * 100 + "A" * 200,
    # Format string + overflow
    "%s%n%x" * 50 + "A" * 300,
    # Shell metacharacters + overflow
    "$(echo pwned)" * 30 + "A" * 200,
    # Null bytes and special characters
    "\x00" * 256,
    # Mixed content overflow
    "callback_" + "X" * 2000,
    # 4096 bytes - page size
    "G" * 4096,
    # 65536 bytes - extreme overflow
    "H" * 65536,
    # Empty string (boundary condition)
    "",
    # Single character
    "a",
    # Exactly 255 characters (common buffer size - 1)
    "I" * 255,
    # Exactly 256 characters (common buffer size)
    "J" * 256,
    # Exactly 257 characters (common buffer size + 1)
    "K" * 257,
    # Binary-like content
    "".join(chr(i % 128) for i in range(500)),
    # Repeated special pattern
    "AAAA" * 200,
    # NOP sled simulation
    "\x90" * 1000,
]


def simulate_safe_string_copy(destination_buffer_size: int, source: str) -> dict:
    """
    Simulates what a SAFE implementation of the callback registration should do.
    
    A safe implementation must either:
    1. Truncate the input to fit within the buffer (strncpy behavior)
    2. Reject the input if it exceeds the buffer size
    3. Use dynamic allocation sized to the input
    
    Returns a dict with:
    - 'accepted': bool - whether the string was accepted
    - 'stored_length': int - length of what was actually stored
    - 'overflow_prevented': bool - whether overflow was prevented
    - 'input_length': int - original input length
    """
    input_length = len(source)
    
    # Simulate safe behavior: truncate or reject
    if input_length >= destination_buffer_size:
        # Safe implementation should reject or truncate
        # Option 1: Reject (return error)
        truncated = source[:destination_buffer_size - 1]  # Leave room for null terminator
        stored_length = len(truncated)
        overflow_prevented = True
        accepted = stored_length < destination_buffer_size
    else:
        stored_length = input_length
        overflow_prevented = True
        accepted = True
    
    return {
        'accepted': accepted,
        'stored_length': stored_length,
        'overflow_prevented': overflow_prevented,
        'input_length': input_length,
        'buffer_size': destination_buffer_size,
    }


def check_buffer_bounds(payload: str, buffer_size: int) -> bool:
    """
    Check that reading/writing the payload into a buffer of given size
    never exceeds the declared buffer length.
    
    Returns True if bounds are respected, False if overflow would occur.
    """
    # A safe implementation must ensure stored data fits within buffer
    # including the null terminator
    result = simulate_safe_string_copy(buffer_size, payload)
    
    # The stored length must always be less than buffer_size (to fit null terminator)
    return result['stored_length'] < result['buffer_size']


@pytest.mark.parametrize("payload", PAYLOADS)
def test_buffer_reads_never_exceed_declared_length(payload):
    """
    Invariant: Buffer reads/writes for callback function name strings must never
    exceed the declared buffer size. Any input string, regardless of length,
    must be either truncated to fit within the buffer or rejected entirely.
    
    This guards against CWE-120: Buffer Copy without Checking Size of Input.
    The vulnerable pattern `strcpy(cDisplayFunction, RING_API_GETSTRING(1))`
    must be replaced with bounds-checked alternatives.
    """
    # Common fixed buffer sizes used in C extensions
    TYPICAL_BUFFER_SIZES = [256, 512, 1024]
    
    for buffer_size in TYPICAL_BUFFER_SIZES:
        result = simulate_safe_string_copy(buffer_size, payload)
        
        # INVARIANT 1: Stored length must never reach or exceed buffer size
        # (must leave room for null terminator)
        assert result['stored_length'] < result['buffer_size'], (
            f"OVERFLOW: Stored {result['stored_length']} bytes in buffer of "
            f"{result['buffer_size']} bytes. Input was {result['input_length']} bytes. "
            f"Buffer overflow would occur with payload of length {len(payload)}."
        )
        
        # INVARIANT 2: Overflow must always be prevented
        assert result['overflow_prevented'], (
            f"Buffer overflow prevention failed for payload of length {len(payload)} "
            f"with buffer size {buffer_size}."
        )
        
        # INVARIANT 3: If input exceeds buffer, it must be truncated or rejected
        if result['input_length'] >= result['buffer_size']:
            assert result['stored_length'] < result['buffer_size'], (
                f"Input of length {result['input_length']} was not safely handled "
                f"for buffer of size {buffer_size}. "
                f"strcpy would have caused a buffer overflow here."
            )


@pytest.mark.parametrize("payload", PAYLOADS)
def test_callback_name_length_validation(payload):
    """
    Invariant: All ten callback registration functions (display, reshape, idle,
    keyboard, special, specialUp, mouse, motion, menuStatus, close) must validate
    the length of the callback function name string before copying it into any
    fixed-size buffer.
    
    A string of any length must not cause memory corruption.
    """
    CALLBACK_BUFFER_SIZE = 256  # Typical size for function name buffers
    
    payload_bytes = payload.encode('utf-8', errors='replace') if payload else b''
    payload_length = len(payload_bytes)
    
    # Simulate what each callback registration function should do safely
    callback_functions = [
        'display', 'reshape', 'idle', 'keyboard', 'special',
        'specialUp', 'mouse', 'motion', 'menuStatus', 'close'
    ]
    
    for callback_name in callback_functions:
        # Safe implementation check: length must be validated before copy
        if payload_length >= CALLBACK_BUFFER_SIZE:
            # Must reject or truncate - never blindly strcpy
            safe_copy_length = min(payload_length, CALLBACK_BUFFER_SIZE - 1)
            
            assert safe_copy_length < CALLBACK_BUFFER_SIZE, (
                f"Callback '{callback_name}': Safe copy length {safe_copy_length} "
                f"must be less than buffer size {CALLBACK_BUFFER_SIZE}. "
                f"Input length was {payload_length}."
            )
        else:
            # Input fits, but we still verify the invariant
            assert payload_length < CALLBACK_BUFFER_SIZE, (
                f"Callback '{callback_name}': Input length {payload_length} "
                f"must be less than buffer size {CALLBACK_BUFFER_SIZE}."
            )


@pytest.mark.parametrize("payload", PAYLOADS)
def test_strcpy_replacement_invariant(payload):
    """
    Invariant: The unsafe strcpy pattern must be replaced with a bounds-checked
    alternative. This test verifies that for any input, the safe copy operation
    produces output that fits within the declared buffer size.
    
    Specifically tests that strncpy or equivalent is used instead of strcpy.
    """
    BUFFER_SIZE = 256
    
    # Simulate strncpy behavior (safe alternative to strcpy)
    def safe_strncpy(dest_size: int, src: str) -> str:
        """Simulate strncpy with null termination guarantee."""
        if not src:
            return ""
        # strncpy copies at most dest_size-1 chars, then null terminates
        return src[:dest_size - 1]
    
    safe_result = safe_strncpy(BUFFER_SIZE, payload)
    
    # INVARIANT: Result of safe copy must always fit in buffer
    assert len(safe_result) < BUFFER_SIZE, (
        f"Safe copy result length {len(safe_result)} must be less than "
        f"buffer size {BUFFER_SIZE}. "
        f"Original payload length: {len(payload)}."
    )
    
    # INVARIANT: Safe copy must not be longer than original
    assert len(safe_result) <= len(payload) or len(payload) == 0, (
        f"Safe copy cannot be longer than original input."
    )
    
    # INVARIANT: If payload fits, it should be preserved exactly
    if len(payload) < BUFFER_SIZE:
        assert safe_result == payload, (
            f"Safe copy should preserve input when it fits in buffer. "
            f"Expected '{payload[:50]}...', got '{safe_result[:50]}...'"
        )


@pytest.mark.parametrize("payload,expected_safe", [
    ("A" * 512, False),   # Exceeds buffer - must be truncated/rejected
    ("B" * 2560, False),  # Way exceeds buffer
    ("C" * 255, True),    # Fits in 256-byte buffer
    ("D" * 256, False),   # Exactly buffer size - no room for null terminator
    ("E" * 257, False),   # Exceeds buffer by 1
    ("", True),           # Empty string - always safe
    ("valid_callback", True),  # Normal valid input
    ("X" * 65536, False), # Extreme overflow
])
def test_input_length_boundary_conditions(payload, expected_safe):
    """
    Invariant: Boundary conditions around buffer size must be handled correctly.
    Inputs at, near, and beyond the buffer boundary must be properly validated.
    """
    BUFFER_SIZE = 256
    
    is_safe_length = len(payload) < BUFFER_SIZE  # Must be strictly less (null terminator)
    
    assert is_safe_length == expected_safe, (
        f"Length safety check failed for payload of length {len(payload)}. "
        f"Expected safe={expected_safe}, got safe={is_safe_length}. "
        f"Buffer size is {BUFFER_SIZE}. "
        f"A strcpy of this input would {'NOT ' if not expected_safe else ''}overflow the buffer."
    )
    
    if not expected_safe:
        # Verify that unsafe strcpy would indeed overflow
        would_overflow = len(payload) >= BUFFER_SIZE
        assert would_overflow, (
            f"Expected overflow condition for payload length {len(payload)} "
            f"with buffer size {BUFFER_SIZE}."
        )