![Tilengine logo](Tilengine.png)
# Tilengine - The 2D retro graphics engine
[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)
[![Build Status](https://travis-ci.org/megamarc/Tilengine.svg?branch=master)](https://travis-ci.org/megamarc/Tilengine)

Tilengine is an open source, cross-platform 2D graphics engine for creating classic/retro games with tile maps, sprites and palettes. Its unique scanline-based rendering algorithm makes raster effects a core feature, a technique used by many games running on real 2D graphics chips.

http://www.tilengine.org

# Contents
- [Tilengine - The 2D retro graphics engine](#tilengine---the-2d-retro-graphics-engine)
- [Contents](#contents)
- [Features](#features)
- [Getting binaries](#getting-binaries)
	- [Download from itch.io](#download-from-itchio)
	- [Build from source](#build-from-source)
		- [Windows](#windows)
		- [Debian-based linux](#debian-based-linux)
		- [MacOS](#macos)
- [Running the samples](#running-the-samples)
	- [Windows](#windows-1)
	- [Unix-like](#unix-like)
- [The tilengine window](#the-tilengine-window)
- [Creating your first program](#creating-your-first-program)
	- [Windows](#windows-2)
	- [Linux](#linux)
	- [MacOS](#macos-1)
- [Documentation](#documentation)
- [Editing assets](#editing-assets)
- [Creating packages](#creating-packages)
- [Bindings](#bindings)
- [Contributors](#contributors)

# Features
* Written in portable C (C99)
* MPL 2.0 license: free for any project, including commercial ones, allows console development
* Cross platform: available builds for Windows (32/64), Linux PC(32/64), MacOS and Raspberry Pi
* High performance: all samples run at 60 fps with CRT emulation enabled on a Raspberry Pi 3
* Streamlined, easy to learn API that requires very little lines of code
* Built-in SDL-based windowing for quick tests
* Integrate inside any existing framework as a slave renderer
* Loads assets from open standard standard file formats
* Create or modify graphic assets procedurally at run time
* True raster effects: modify render parameters between scanlines
* Background layer scaling and rotation
* Sprite scaling
* Several blending modes for layers and sprites
* Pixel accurate sprite vs sprite and sprite vs layer collision detection
* Special effects: per-column offset, mosaic, per-pixel displacement, CRT emulation...
* Supports packaged assets with optional AES-128 encryption

# Getting binaries

## Download from itch.io
The recommended way to get prebuilt binaries ready to install, run and test samples is grabbing them from official [itch.io download](https://megamarc.itch.io/tilengine). Just download the package for your platform, they contain required dependencies to run.

## Build from source
You can also build the library from source. Tilengine requires `SDL2` and `libpng` to build, you must provide these libraries yourself depending on your target platform.

### Windows
You must provide development libraries:
* SDL: https://www.libsdl.org/download-2.0.php
* libpng: http://gnuwin32.sourceforge.net/packages/libpng.htm

Put the following files inside the `src` directory:
Path | Files
-----|---------------------------------------
`src\libpng`             | libpng headers
`src\libpng\$(Platform)` | libpng.lib import library
`src\sdl\SDL2`           | SDL2 headers
`src\sdl\lib\$(Platform)`| SDL2.lib import library

**NOTE**: If you're having problems setting up these dependencies, you can download them already pre-packaged from [itch.io downloads](https://megamarc.itch.io/tilengine), file is `windows_libs.zip`. It contains headers and libraries for both 32 and 64 bit platforms.

### Debian-based linux
Just install standard packages `libpng-dev` and `libsdl2-dev`

### MacOS

Tilengine depends on having SDL2 in Framework format installed on your system. Homebrew port won't work. Download the latest dmg here: https://github.com/libsdl-org/SDL/releases.

# Running the samples

C samples are located in `Tilengine/samples` folder. To build them you need the gcc compiler suite, and/or Visual C++ in windows.
* **Linux**: the GCC compiler suite is already installed by default
* **Windows**: you must install [MinGW](http://www.mingw.org/) or [Visual Studio Community](https://www.visualstudio.com/vs/community/)
* **MacOS**: You must install [Command-line tools for Xcode](https://developer.apple.com/xcode/). An Apple ID account is required.

Once installed, open a console window in the C samples folder and type the suitable command depending on your platform:

## Windows
```
> mingw32-make
```

## Unix-like
```
> make
```

# The tilengine window
The following actions can be done in the created window:
* Press <kbd>Esc</kbd> to close the window
* Press <kbd>Alt</kbd> + <kbd>Enter</kbd> to toggle full-screen/windowed
* Press <kbd>Backspace</kbd> to toggle built-in CRT effect (enabled by default)

# Creating your first program
The following section shows how to create from scratch and execute a simple tilengine application that does the following:
1. Reference the inclusion of Tilengine module
2. Initialize the engine with a resolution of 400x240, one layer, no sprites and no palette animations
3. Load a *tilemap*, the asset that contains background layer data
4. Attach the loaded tilemap to the allocated background layer
5. Create a display window with default parameters: windowed, auto scale and CRT effect enabled
6. Run the window loop, updating the display at each iteration until the window is closed
7. Release allocated resources

![Test](test.png)

Create a file called `test.c` in `Tilengine/samples` folder, and type the following code:
```c
#include "Tilengine.h"

void main(void) {
    TLN_Tilemap foreground;

    TLN_Init (400, 240, 1, 0, 0);
    foreground = TLN_LoadTilemap ("assets/sonic/Sonic_md_fg1.tmx", NULL);
    TLN_SetLayerTilemap (0, foreground);

    TLN_CreateWindow (NULL, 0);
    while (TLN_ProcessWindow()) {
        TLN_DrawFrame (0);
    }

    TLN_DeleteTilemap (foreground);
    TLN_Deinit ();
}
```
Now the program must be built to produce an executable. Open a console window in the C samples folder and type the suitable command for your platform:

## Windows
```
> gcc test.c -o test.exe -I"../include" ../lib/Win32/Tilengine.dll
> test.exe
```

## Linux
```
> gcc test.c -o test -lTilengine -lm
> ./test
```

## MacOS
```
> gcc test.c -o test "/usr/local/lib/Tilengine.dylib" -lm
> ./test
```

# Documentation
Doxygen-based documentation and API reference can be found in the following link:
http://www.tilengine.org/doc

# Editing assets
Tilengine is just a programming library that doesn't come with any editor, but the files it loads are made with standard open-source tools. Samples come bundled with several ready-to-use assets, but these are the tools you'll need to edit or create new ones:
* Source code: [VSCode](https://code.visualstudio.com/), [Notepad++](https://notepad-plus-plus.org/downloads/)...
* Graphics, tiles & sprites: [Aseprite](https://www.aseprite.org/), [Piskel](https://www.piskelapp.com/), [Grafx2](http://grafx2.chez.com/)...
* Maps: [Tiled Map Editor](https://www.mapeditor.org/)

# Creating packages
To create a package with all the assets, the add-on tool [ResourcePacker](https://megamarc.itch.io/resourcepacker) must be used. It's a Windows command-line tool that creates packages with files keeping the same directory structure. Tilengine has built-in support for loading assets from these packages just as if they still were stand-alone files.

# Bindings
There are bindings to use Tilengine from several programming languages:

Language  |Binding
----------|-----------------------------------------
C/C++     | Native support, no binding required
Python    | [PyTilengine](https://github.com/megamarc/PyTilengine)
C#        | [CsTilengine](https://github.com/megamarc/CsTilengine)
C#        | [CsTilenginePure](https://github.com/vonhoff/CsTilenginePure)
Pascal    | [PascalTileEngine](https://github.com/turric4n/PascalTileEngine)
FreeBasic | [FBTilengine](https://github.com/megamarc/FBTilengine)
Java	    | [JTilengine](https://github.com/megamarc/JTilengine)
Rust      | [tilengine-sys](https://crates.io/crates/tilengine-sys)
LuaJIT    | [tilengine_libretro](https://github.com/megamarc/Tilengine/tree/libretro) ([libretro](https://www.libretro.com) core)
Ring      | [RingTilengine](https://github.com/ring-lang/ring/tree/master/extensions/ringtilengine)
Nim       | [nim-tilengine](https://sr.ht/~exelotl/nim-tilengine)
V         | [V-Tilengine](https://github.com/system64MC/V-Tilengine)
Go        | [gotilengine](https://github.com/thechampagne/gotilengine)
Zig       | [zigtilengine](https://github.com/thechampagne/zigtilengine)
D         | [dtilengine](https://github.com/thechampagne/dtilengine)

# Contributors
These kind users contributed to tilengine:

@turric4an - the Pascal wrapper<br>
@davideGiovannini - help with the Linux-x86_64 port<br>
@shayneoneill - help with the OS X port<br>
@adtennant - provided cmake and pkg-config support<br>
@tvasenin - improved C# binding<br>
@tyoungjr - LUA/FFI binding<br>
@vonhoff - provided CsTilenginePure binding<br>
@system64MC - provided bindings for Nim an V
