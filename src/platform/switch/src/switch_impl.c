#include "switch_impl.h"

#include <switch.h>
#include <stdarg.h>
#include <stdio.h>

void SwitchImpl_Init() {
    appletInitializeGamePlayRecording();
    appletSetGamePlayRecordingState(true);
    appletSetFocusHandlingMode(AppletFocusHandlingMode_NoSuspend);
    socketInitializeDefault();
#ifdef DEBUG
    nxlinkStdio();
#endif
}

void SwitchImpl_Exit() {
    appletSetGamePlayRecordingState(false);
    socketExit();
}

void PrintErrorMessageToScreen(const char* str, ...) {
    consoleInit(NULL);

    va_list args;
    va_start(args, str);
    vprintf(str, args);
    va_end(args);

    while (appletMainLoop()) {
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
}

// Error messages

void ThrowMissingROM() {
    PrintErrorMessageToScreen(
        "\x1b[2;2HYou've launched Super Mario World without the rom file."
        "\x1b[4;2HPlease relaunch making sure smw.sfc exists."
        "\x1b[44;2HMade with <3 by snesrev and Lywx"
    );
}