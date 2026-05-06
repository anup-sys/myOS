#include "screen.h"
#include <stdint.h>


static uint16_t* video_memory = (uint16_t*) VGA_MEMORY;

static uint8_t current_color = (COLOR_LIGHT_GREY | COLOR_BLACK << 4);

static int cursor_row = 0;
static int cursor_col = 0;



static uint16_t vga_entry(unsigned char character, uint8_t color) {
    return (uint16_t) character | (uint16_t) color << 8;
}

void set_color(uint8_t foreground, uint8_t background) {
    current_color = foreground | background << 4;
}

void clear_screen() {

    for (int y = 0; y < VGA_HEIGHT; y++) {

        for (int x = 0; x < VGA_WIDTH; x++) {

            int index = y * VGA_WIDTH + x;

            video_memory[index] = vga_entry(' ', current_color);
        }
    }

    cursor_row = 0;
    cursor_col = 0;
}



void new_line() {

    cursor_col = 0;
    cursor_row++;

    if (cursor_row >= VGA_HEIGHT) {
        cursor_row = 0;
    }
}

void print_char(char c) {

    if (c == '\n') {
        new_line();
        return;
    }

    int index = cursor_row * VGA_WIDTH + cursor_col;

    video_memory[index] = vga_entry(c, current_color);

    cursor_col++;

    if (cursor_col >= VGA_WIDTH) {
        new_line();
    }
}

void print(const char* str) {

    while (*str) {
        print_char(*str);
        str++;
    }
}