# Welcome to the building instructions for the project! Please make sure to prepeare the required files and install the necessary dependencies for your current OS.

# Requirements:
  * A Super Mario World rom (Make sure to rename it to `smw.sfc`)
  * `libsdl2-dev` (The installation for this will be different for each compiler.)
  * Super Mario World repo `git clone --recursive https://github.com/snesrev/smw`
  * [Python](https://www.python.org/) (During installation, make sure to check the "Add to PATH")
  
 For Linux/MacOS you must install these for your desired OS:
 * Ubuntu/Debian: `sudo apt install libsdl2-dev`
 * Fedora Linux: `sudo dnf in sdl2-devel`
 * Arch Linux: `sudo pacman -S sdl2`
 * macOS: `brew install sdl2`

# Windows

## Building with Tiny C Compiler

 Dependencies and requirements:
 * You'll need [TCC](https://github.com/FitzRoyX/tinycc/releases/download/tcc_20230519/tcc_20230519.zip) and [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-devel-2.26.5-VC.zip) in order to compile using TCC.

1. Unzip both TCC and SDL and place them in `third_party` folder.
2. Double click `run_with_tcc.bat`
3. Wait for it to compile and the game will automatically boot-up.

# More advanced methods

## Building with MSYS2

Dependencies and requirements:

  * The `libsdl2-dev` library
  * [MSYS2](https://www.msys2.org)
  
Note: *Make sure you're using MINGW64 and you're in `smw` folder in the terminal.*

1. Install MSYS2 on your machine.
2. Place the copy of your rom in the main directory.
3. Install the necessary dependencies and SDL2 by inputting this command in MSYS2 terminal:

```sh
pacman -S mingw-w64-x86_64-SDL2 && pacman -S make && pacman -S mingw-w64-x86_64-gcc
```
4. Type `sdl2-config --cflags`, it should output:
```sh
-IC:/msys64/mingw64/include/SDL2 -Dmain=SDL_main
```
5. After that type `sdl2-config --libs`, should output:
```sh
-LC:/msys64/mingw64/lib -lmingw32 -mwindows -lSDL2main -lSDL2
```

After you've done installing everything, in the terminal, type `make`
In order to speed up the compilation, type `make -j16`

## Building with Visual Studio

Dependencies and requirements:
 * The `libsdl2-dev` library, which is automatically installed with NuGet.
 * [Visual Studio Community 2022](https://visualstudio.microsoft.com)

Download VS installer. On installer prompt, make sure you're on "Workloads" and check `Desktop Development with C++` this will install the necessary deps for compilation.

1. Open `smw.sln` solution.
2. Change the build target from `Debug` to `Release`
3. Build the solution.


# Running SMB1 and SMBLL

Dependencies and requirements:

  * Super Mario All-Stars rom (US version and not + Mario World)
  * `zstandard`

1. In MSYS2 terminal, type `git checkout smb1` or `git checkout devel` to change the branches.
2. Rename your obtained rom to `smas.sfc` and place it inside the `other` folder.
3. To install `zstandard` make sure you've installed Python and added to PATH. Open up CMD and type `pip install zstandard` to install the required dep.
4. In the `other` folder drag and drop your renamed rom into `extract.py` or by typing `extract.py` in the command line to extract the necessary files.
5. Move `smb1.sfc` and `smbll.sfc` to root folder.
6. Before running the games, make sure to recompile or else they won't boot up.
7. Drag your desired game to `smw.exe` in order to run.

 
# Linux/MacOS

Open the terminal and CD to your SM root folder:
```sh
make
```

For more advanced usage:
```sh
make -j$(nproc) # run on all core
make clean all  # clear gen+obj and rebuild
CC=clang make   # specify compiler
```

# Nintendo Switch

Dependencies and requirements:

  * The `switch-sdl2` library
  * [DevKitPro](https://github.com/devkitPro/installer)
  * [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere)
  * `pk-config`
  
1. Make sure you've installed Atmosphere on your Switch.
2. Please download the DevKitPro version of MSYS2 through their installer, as the default MSYS2 causes issues with windows compiling.
3. Now that you've installed DevKitPro, open up the location you've installed DevKitPro to, then find `mingw64.exe` inside `msys2` located in `devkitPro` folder.
4. Type `pacman -S git switch-dev switch-sdl2 switch-tools pkg-config` in the terminal to install the `switch-sdl2` library.
5. CD to `switch` folder by typing `cd src/platform/switch` in the terminal on the `smw` root folder.
6. type `make` to compile the Switch Port.
7. Transfer the `.ini`, `nro`, `ncap` and your rom file to the Switch.

**OPTIONAL STEP**

```sh
make -j$(nproc) # To build using all cores
```
