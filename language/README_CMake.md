![Ring](https://raw.githubusercontent.com/ring-lang/ring/master/marketing/graphics/thering.jpg)

# Ring Programming Language

## Building Ring with CMake

Build the Ring Compiler/VM with CMake, supporting both dynamic (default) and static linking to suit your platform and preferences.

## Prerequisites

Before you begin, ensure you have the following installed on your system:

*   **CMake**: Version 3.16 or higher.
*   **A C Compiler**: Such as GCC, Clang, TCC, or MSVC.
*   **Build tools**: Such as `make` or `Ninja` on Linux/macOS, or Visual Studio Build Tools on Windows.

## Build Ring

If you want to build a statically-linked executable, add the `-DRING_STATIC=ON` flag during the CMake configuration step.

**Build Steps:**

1. **Create a build directory:**
    - ```bash
      mkdir rbuild
      cd rbuild
      ```
2. **Configure the project with CMake:**
    - On Linux/macOS (dynamic build):
      ```bash
      cmake ..
      ```
    - On Linux/macOS (static build):
      ```bash
      cmake -DRING_STATIC=ON ..
      ```
      > **Note:** For a fully static build on Linux (with no glibc warnings), use `musl-gcc` or `clang` with musl as your compiler. This ensures the resulting binary does not depend on glibc at runtime.
    - To build a release version:
      ```bash
      cmake -DCMAKE_BUILD_TYPE=Release ..
      # or for static release:
      cmake -DCMAKE_BUILD_TYPE=Release -DRING_STATIC=ON ..
      ```
    - To use Ninja:
      ```bash
      cmake .. -G Ninja
      # or for static:
      cmake .. -G Ninja -DRING_STATIC=ON
      ```
    - On Windows with Visual Studio 2022:
      ```bash
      cmake .. -G "Visual Studio 17 2022"
      # or for static:
      cmake .. -G "Visual Studio 17 2022" -DRING_STATIC=ON
      ```
3. **Build Ring:**
    - On Linux/macOS:
      ```bash
      make
      ```
    - Or, for a general command (cross-platform):
      ```bash
      cmake --build .
      ```
	- Or, if you want to build the release version:
	  ```bash
	  cmake --build . --config Release
	  ```

**Resulting files in `rbuild`:**

* `ring` (or `ring.exe`): The Ring language executable (dynamically or statically linked, depending on your configuration).
* `libring.so` (Linux), `libring.dylib` (macOS), or `ring.dll` (Windows): The shared library (not built if static build is selected).
* `libringstatic.a` (Linux/macOS) or `ringstatic.lib` (Windows): The static library.

## Installation

After building, you can install the files using the `install` target.

```bash
# If you generated Makefiles
make install

# Or, the recommended cross-platform command
cmake --install .
```