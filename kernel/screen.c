#include "screen.h"
#include <stdint.h>

/* =========================================
   VGA TEXT MODE DRIVER
========================================= */

/* VGA buffer address */
static uint16_t* video_memory =
    (uint16_t*) VGA_MEMORY;

/* Default text color */
static uint8_t current_color =
    (COLOR_LIGHT_GREY | (COLOR_BLACK << 4));

/* Cursor position */
static int cursor_row = 0;
static int cursor_col = 0;

/* =========================================
   CREATE VGA ENTRY
========================================= */

static uint16_t vga_entry(
    unsigned char character,
    uint8_t color
) {
    return (uint16_t) character |
           (uint16_t) color << 8;
}

/* =========================================
   SET TEXT COLOR
========================================= */

void set_color(
    uint8_t foreground,
    uint8_t background
) {
    current_color =
        foreground | (background << 4);
}

/* =========================================
   CLEAR SCREEN
========================================= */

void clear_screen() {

    for (int y = 0; y < VGA_HEIGHT; y++) {

        for (int x = 0; x < VGA_WIDTH; x++) {

            int index =
                y * VGA_WIDTH + x;

            video_memory[index] =
                vga_entry(' ', current_color);
        }
    }

    cursor_row = 0;
    cursor_col = 0;
}

/* =========================================
   SCROLL SCREEN
========================================= */

static void scroll_screen() {

    /* Move all rows upward */

    for (int y = 1; y < VGA_HEIGHT; y++) {

        for (int x = 0; x < VGA_WIDTH; x++) {

            video_memory[(y - 1) * VGA_WIDTH + x] =
                video_memory[y * VGA_WIDTH + x];
        }
    }

    /* Clear last row */

    for (int x = 0; x < VGA_WIDTH; x++) {

        video_memory[(VGA_HEIGHT - 1) * VGA_WIDTH + x] =
            vga_entry(' ', current_color);
    }

    cursor_row = VGA_HEIGHT - 1;
}

/* =========================================
   NEW LINE
========================================= */

void new_line() {

    cursor_col = 0;
    cursor_row++;

    /* Scroll if screen full */

    if (cursor_row >= VGA_HEIGHT) {
        scroll_screen();
    }
}

/* =========================================
   PRINT SINGLE CHARACTER
========================================= */

void print_char(char c) {

    /* Handle newline */

    if (c == '\n') {
        new_line();
        return;
    }

    int index =
        cursor_row * VGA_WIDTH + cursor_col;

    video_memory[index] =
        vga_entry(c, current_color);

    cursor_col++;

    /* Move to next line if row full */

    if (cursor_col >= VGA_WIDTH) {
        new_line();
    }
}

/* =========================================
   PRINT STRING
========================================= */

void print(const char* str) {

    while (*str) {

        print_char(*str);

        str++;
    }
}