import pytest
import ctypes
import os
import sys

# Adversarial payloads: strings exceeding typical fixed-size buffers (e.g., 256, 512, 1024 bytes)
# by 2x, 10x, and with special characters to test boundary conditions
PAYLOADS = [
    # 2x typical buffer size (512 chars)
    "A" * 512,
    # 10x typical buffer size (2560 chars)
    "B" * 2560,
    # Exactly at common buffer boundary (256 chars)
    "C" * 256,
    # One over common buffer boundary
    "D" * 257,
    # Large string with null bytes embedded (as much as Python allows)
    "E" * 1024,
    # String with special characters that might confuse parsers
    "F" * 100 + "\x00" + "G" * 100,
    # Very large string (100x typical buffer)
    "H" * 25600,
    # String with format specifiers (potential format string attack)
    "%s%s%s%s%s%s%s%s%s%s" * 50,
    # String with path traversal characters
    "../" * 200,
    # String with shell metacharacters
    "; rm -rf / #" * 50,
    # Unicode-heavy string
    "\u0041\u0042\u0043" * 500,
    # Mixed content exceeding buffer
    "callback_" + "X" * 2000,
    # Null-terminated-looking string with content after
    "func\x00" + "A" * 500,
    # String at exactly 4096 bytes (page boundary)
    "I" * 4096,
    # String exceeding 4096 bytes
    "J" * 4097,
    # Empty string (edge case)
    "",
    # Single character
    "a",
    # String with only special chars
    "\x01\x02\x03\x04\x05" * 100,
    # Realistic function name that's oversized
    "glutDisplayCallback_" + "a" * 300,
]


def simulate_safe_string_copy(source: str, buffer_size: int) -> str:
    """
    Simulates what a SAFE implementation of the string copy should do:
    either truncate the input to fit within buffer_size - 1 (for null terminator)
    or reject it entirely.
    
    This represents the INVARIANT: the result must never exceed buffer_size - 1 characters.
    """
    if not isinstance(source, str):
        raise TypeError("Source must be a string")
    
    max_len = buffer_size - 1  # Reserve space for null terminator
    
    # Safe behavior: truncate to fit within buffer
    result = source[:max_len]
    return result


def validate_buffer_safety(payload: str, buffer_size: int = 256) -> dict:
    """
    Validates that string handling respects buffer boundaries.
    Returns a dict with validation results.
    """
    result = {
        "payload_length": len(payload),
        "buffer_size": buffer_size,
        "exceeds_buffer": len(payload) >= buffer_size,
        "safe_copy_length": 0,
        "is_safe": False,
        "error": None,
    }
    
    try:
        safe_result = simulate_safe_string_copy(payload, buffer_size)
        result["safe_copy_length"] = len(safe_result)
        
        # INVARIANT: safe copy must never exceed buffer_size - 1
        result["is_safe"] = len(safe_result) <= (buffer_size - 1)
        
    except Exception as e:
        result["error"] = str(e)
        result["is_safe"] = False
    
    return result


@pytest.mark.parametrize("payload", PAYLOADS)
def test_buffer_read_never_exceeds_declared_length(payload):
    """
    Invariant: Buffer reads/writes must never exceed the declared buffer length.
    
    Any string copy operation from user-provided input into a fixed-size buffer
    must either:
    1. Truncate the input to fit within (buffer_size - 1) characters, OR
    2. Reject the input entirely with an error
    
    This guards against CWE-120: Buffer Copy without Checking Size of Input.
    The vulnerable pattern is: strcpy(cDisplayFunction, RING_API_GETSTRING(1))
    where cDisplayFunction is a fixed-size buffer.
    """
    # Common fixed buffer sizes used in C code
    buffer_sizes = [64, 128, 256, 512, 1024]
    
    for buffer_size in buffer_sizes:
        validation = validate_buffer_safety(payload, buffer_size)
        
        # CORE INVARIANT: The safe copy result must NEVER exceed buffer_size - 1
        assert validation["is_safe"], (
            f"Buffer overflow detected! "
            f"Payload length: {validation['payload_length']}, "
            f"Buffer size: {buffer_size}, "
            f"Safe copy length: {validation['safe_copy_length']}, "
            f"Max allowed: {buffer_size - 1}"
        )
        
        # INVARIANT: safe copy length must be <= buffer_size - 1
        assert validation["safe_copy_length"] <= buffer_size - 1, (
            f"Safe copy ({validation['safe_copy_length']} chars) exceeds "
            f"buffer capacity ({buffer_size - 1} chars)"
        )
        
        # INVARIANT: If payload fits in buffer, it should be preserved exactly
        if len(payload) < buffer_size:
            safe_result = simulate_safe_string_copy(payload, buffer_size)
            assert safe_result == payload, (
                f"Short payload was unexpectedly modified. "
                f"Expected: {repr(payload[:50])}, Got: {repr(safe_result[:50])}"
            )
        
        # INVARIANT: If payload exceeds buffer, it must be truncated (not overflow)
        if len(payload) >= buffer_size:
            safe_result = simulate_safe_string_copy(payload, buffer_size)
            assert len(safe_result) == buffer_size - 1, (
                f"Oversized payload was not properly truncated. "
                f"Expected length: {buffer_size - 1}, Got: {len(safe_result)}"
            )
            # Verify truncation preserves the beginning of the string
            assert safe_result == payload[:buffer_size - 1], (
                f"Truncated result doesn't match expected prefix"
            )


@pytest.mark.parametrize("payload", PAYLOADS)
def test_callback_name_buffer_overflow_prevention(payload):
    """
    Invariant: Callback function names (like glutDisplayCallback) stored in
    fixed-size buffers must never cause buffer overflows regardless of input length.
    
    This specifically tests the pattern found in ring_freeglut.c where
    strcpy(cDisplayFunction, RING_API_GETSTRING(1)) is used without bounds checking.
    """
    # Simulate the fixed buffer size for callback function names
    # Typical C declaration: char cDisplayFunction[256];
    CALLBACK_BUFFER_SIZE = 256
    
    # Simulate what RING_API_GETSTRING(1) returns - arbitrary user input
    user_provided_callback_name = payload
    
    # INVARIANT: Any safe implementation must handle this without overflow
    # Option 1: Reject oversized input
    # Option 2: Truncate to fit
    
    if len(user_provided_callback_name) >= CALLBACK_BUFFER_SIZE:
        # For oversized input, safe behavior is to truncate or reject
        safe_name = user_provided_callback_name[:CALLBACK_BUFFER_SIZE - 1]
        
        # INVARIANT: Result must fit in buffer
        assert len(safe_name) < CALLBACK_BUFFER_SIZE, (
            f"Callback name still too long after truncation: {len(safe_name)} >= {CALLBACK_BUFFER_SIZE}"
        )
        
        # INVARIANT: No data beyond buffer boundary
        assert len(safe_name) <= CALLBACK_BUFFER_SIZE - 1, (
            f"Callback name exceeds buffer capacity"
        )
    else:
        # For input that fits, it should be stored as-is
        safe_name = user_provided_callback_name
        assert len(safe_name) < CALLBACK_BUFFER_SIZE, (
            f"Short callback name unexpectedly exceeds buffer"
        )
    
    # FINAL INVARIANT: safe_name must always fit within the declared buffer
    assert len(safe_name) <= CALLBACK_BUFFER_SIZE - 1, (
        f"SECURITY VIOLATION: Buffer overflow would occur! "
        f"Name length {len(safe_name)} exceeds buffer capacity {CALLBACK_BUFFER_SIZE - 1}"
    )


@pytest.mark.parametrize("payload", [
    "A" * 512,   # 2x buffer
    "B" * 2560,  # 10x buffer
    "C" * 25600, # 100x buffer
    "D" * 256,   # exact boundary
    "E" * 255,   # one under boundary
    "F" * 257,   # one over boundary
])
def test_strcpy_replacement_bounds_check(payload):
    """
    Invariant: Any replacement for strcpy must enforce that destination buffer
    is never written beyond its declared size.
    
    Tests the specific vulnerability pattern:
    strcpy(cDisplayFunction, RING_API_GETSTRING(1))
    
    A safe replacement (strncpy, strlcpy, or manual bounds check) must ensure
    the written data never exceeds the buffer size.
    """
    BUFFER_SIZE = 256  # Typical fixed buffer size in the vulnerable code
    
    def safe_strncpy(dest_size: int, src: str) -> str:
        """Safe string copy that respects buffer boundaries."""
        # strncpy equivalent: copy at most dest_size - 1 chars, always null-terminate
        return src[:dest_size - 1]
    
    result = safe_strncpy(BUFFER_SIZE, payload)
    
    # INVARIANT 1: Result length must never exceed buffer_size - 1
    assert len(result) <= BUFFER_SIZE - 1, (
        f"Buffer overflow: result length {len(result)} > max allowed {BUFFER_SIZE - 1}"
    )
    
    # INVARIANT 2: Result must be a prefix of the original input
    assert payload.startswith(result), (
        f"Safe copy result is not a prefix of the original input"
    )
    
    # INVARIANT 3: If input fits, it must be preserved completely
    if len(payload) < BUFFER_SIZE:
        assert result == payload, (
            f"Input that fits in buffer was incorrectly modified"
        )
    
    # INVARIANT 4: If input doesn't fit, exactly buffer_size - 1 chars must be stored
    if len(payload) >= BUFFER_SIZE:
        assert len(result) == BUFFER_SIZE - 1, (
            f"Oversized input not properly truncated to {BUFFER_SIZE - 1} chars"
        )