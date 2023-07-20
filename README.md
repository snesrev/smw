# smw

Our discord server is: https://discord.gg/AJJbJAzNNJ

Early version. It has bugs and the code is messy.

You must self-build for now. Easy method on 64-bit Windows (no terminal or big downloads):<br>
(1) Download [Python](https://www.python.org/ftp/python/3.11.4/python-3.11.4-amd64.exe) if you don't have it and install with "Add to PATH" checked<br>
(2) Click the green button "Code > Download ZIP" on the github page and extract the ZIP<br>
(3) Place your USA rom named smw.sfc in that folder<br>
(4) Download [TCC](https://github.com/FitzRoyX/tinycc/releases/download/tcc_20230519/tcc_20230519.zip) and [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.28.1/SDL2-devel-2.28.1-VC.zip) and extract each ZIP into the "third-party" subfolder<br>
(5) Double click "restool.py" in the "assets" subfolder. This will create smw_assets.dat.<br>
(6) Double-click "run_with_tcc.bat" in the main dir. This will create smw.exe and run it.<br>
(7) Configure with smw.ini in a text editor like notepad++<br>

For other platforms and compilers, see: https://github.com/snesrev/smw/blob/main/BUILDING.md

When running, it runs an emulated version in the background and compares the ram state every frame. If it detects a mismatch, it saves a snapshot in saves/ and displays a counter on screen counting down from 300. Please submit these bug snapshots on discord so that they can be fixed.

