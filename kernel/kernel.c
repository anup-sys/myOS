#include "screen.h"

void kernel_main() {

    /* Clear screen */

    clear_screen();

    /* Set text color */

    set_color(COLOR_LIGHT_GREEN,
              COLOR_BLACK);

    /* Print welcome message */

    print("Welcome to MyOS!\n");

    /* Change color */

    set_color(COLOR_WHITE,
              COLOR_BLACK);

    print("Kernel Loaded Successfully\n");

    print("Phase 3: Screen Driver Active\n");

    print("--------------------------------\n");

    print("Features Enabled:\n");

    print("[+] VGA Text Output\n");
    print("[+] Cursor Control\n");
    print("[+] Screen Clearing\n");
    print("[+] Color Support\n");
    print("[+] Scrolling Support\n");

    print("\nSystem Ready...\n");
}