# Requirements
  * A Super Mario World rom (Make sure to rename it to `smw.sfc`)
  * libsdl2-dev
  * Super Mario World repo `git clone --recursive https://github.com/snesrev/smw`
  
 For Linux/MacOS you must install these for your desired OS:
 * Ubuntu/Debian: `sudo apt install libsdl2-dev`
 * Fedora Linux: `sudo dnf in sdl2-devel`
 * Arch Linux: `sudo pacman -S sdl2`
 * macOS: `brew install sdl2`

# Windows

## Building with MSYS2

Dependencies and requirements:

  * The `libsdl2-dev` library
  * [MSYS2](https://www.msys2.org)
  
Note: *Make sure you're using MINGW64 and you're in `smw` folder in the terminal.*

1. Install MSYS2 on your machine.
2. Place the copy of your rom in the main directory.
3. Install the necessary dependencies by inputting this command in the terminal.

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
Also you need pkg-config
```sh
pacman -S pkg-config
```

After you've done installing everything, cd to `smw` folder. Type `make`
In order to speed up the compilation, type `make -j16`

## Building with Visual Studio

Dependencies and requirements:
 * The `libsdl2-dev` library, which is automatically installed with NuGet.
 * [Visual Studio Community 2022](https://visualstudio.microsoft.com)

Download VS installer. On installer prompt, make sure you're on "Workloads" and check `Desktop Development with C++` this will install the necessary deps for compilation.

1. Open `smw.sln` solution.
2. Change the build target from `Debug` to `Release`
3. Build the solution.

# Linux/MacOS

CD to your SM root folder and open the terminal and type:
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
