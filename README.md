# smw
A reimplementation of Super Mario World.

Our discord server is: https://discord.gg/AJJbJAzNNJ

## About

This is a reverse engineered clone of Super Mario World.

It reimplements all parts of the original game and a bunch of mods added by Lunar Magic. The game is playable from start to end.

You need a copy of the ROM to extract game resources (levels, images). Then once that's done, the ROM is no longer needed.

It uses the PPU and DSP implementation from [LakeSnes](https://github.com/elzo-d/LakeSnes), but with lots of speed optimizations.

## Building

You must self-build for now. Easy method on 64-bit Windows (no terminal or big downloads):<br>
(1) Download [Python](https://www.python.org/ftp/python/3.11.4/python-3.11.4-amd64.exe) if you don't have it and install with "Add to PATH" checked<br>
(2) Click the green button "Code > Download ZIP" on the github page and extract the ZIP<br>
(3) Place your USA rom named smw.sfc in that folder<br>
(4) Download [TCC](https://github.com/FitzRoyX/tinycc/releases/download/tcc_20230519/tcc_20230519.zip) and [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.28.1/SDL2-devel-2.28.1-VC.zip) and extract each ZIP into the "third-party" subfolder<br>
(5) Double click "extract_assets.bat" in the main dir. This will create smw_assets.dat.<br>
(6) Double-click "run_with_tcc.bat" in the main dir. This will create smw.exe and run it.<br>
(7) Configure with smw.ini in a text editor like notepad++<br>

For other platforms and compilers, see: https://github.com/snesrev/smw/blob/main/BUILDING.md

When running, it runs an emulated version in the background and compares the ram state every frame. If it detects a mismatch, it saves a snapshot in saves/ and displays a counter on screen counting down from 300. Please submit these bug snapshots on discord so that they can be fixed.

## Usage and controls

The game supports snapshots. The joypad input history is also saved in the snapshot. It's thus possible to replay a playthrough in turbo mode to verify that the game behaves correctly.

| Button | Key         |
| ------ | ----------- |
| Up     | Up arrow    |
| Down   | Down arrow  |
| Left   | Left arrow  |
| Right  | Right arrow |
| Start  | Enter       |
| Select | Right shift |
| A      | X           |
| B      | Z           |
| X      | S           |
| Y      | A           |
| L      | C           |
| R      | V           |

The keys can be reconfigured in smw.ini

Additionally, the following commands are available:

| Key | Action                |
| --- | --------------------- |
| Tab | Turbo mode |
| P   | Pause (with dim)                |
| Shift+P   | Pause (without dim)                |
| Ctrl+Up   | Increase window size                |
| Ctrl+Down   | Decrease window size                |
| T   | Toggle replay turbo mode  |
| K   | Clear all input history from the joypad log  |
| L   | Stop replaying a shapshot  |
| R   | Toggle between fast and slow renderer |
| F   | Display renderer performance |
| F1-F10 | Load snapshot      |
| Alt+Enter | Toggle Fullscreen     |
| Shift+F1-F10 | Save snapshot |
| Ctrl+F1-F10 | Replay the snapshot |
