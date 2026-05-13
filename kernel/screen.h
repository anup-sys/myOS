#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

/* VGA TEXT MODE SETTINGS */

#define VGA_WIDTH  80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000

/* VGA COLORS */

enum vga_color {
    COLOR_BLACK = 0,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_LIGHT_GREY,
    COLOR_DARK_GREY,
    COLOR_LIGHT_BLUE,
    COLOR_LIGHT_GREEN,
    COLOR_LIGHT_CYAN,
    COLOR_LIGHT_RED,
    COLOR_LIGHT_MAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE,
};

/* SCREEN FUNCTIONS */

void clear_screen();
void print_char(char c);
void print(const char* str);
void new_line();
void set_color(uint8_t foreground,
               uint8_t background);

#endif