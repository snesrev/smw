# smw

Our discord server is: https://discord.gg/AJJbJAzNNJ

Early version. It has bugs and the code is messy.

You must self-build for now. Easy method on Windows (no installs, terminal, or big downloads):<br>
(1) Click the green button "Code > Download ZIP" on the github page and extract the ZIP<br>
(2) Place the USA rom named smw.sfc in that folder (crc32=b1ed489)<br>
(3) Download [TCC](https://github.com/FitzRoyX/tinycc/releases/download/tcc_20230519/tcc_20230519.zip) and [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-devel-2.26.5-VC.zip) and extract each ZIP into the "third-party" subfolder<br>
(4) Double-click run_with_tcc.bat in the main dir. This will create smw.exe and run it.<br>
(5) Configure with smw.ini<br>

For other platforms and compilers, see: https://github.com/snesrev/smw/blob/main/BUILDING.md

When running, it runs an emulated version in the background and compares the ram state every frame. If it detects a mismatch, it saves a snapshot in saves/ and displays a counter on screen counting down from 300. Please submit these bug snapshots on discord so that they can be fixed.

