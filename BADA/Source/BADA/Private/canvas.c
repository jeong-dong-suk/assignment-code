#include "canvas.h"

static uint32_t* s_canvas;
static size_t s_rows;
static size_t s_cols;

void set_canvas(uint32_t* canvas, size_t rows, size_t cols)
{

}

void release_canvas(void)
{

}

void draw_pixel(size_t x, size_t y, uint32_t rgb_color)
{

}

void remove_pixel(size_t x, size_t y)
{

}

void fill_canvas(uint32_t rgb_color)
{

}

void draw_horizontal_line(size_t y, uint32_t rgb_color)
{

}

void draw_vertical_line(size_t x, uint32_t rgb_color)
{

}

void draw_rectangle(size_t start_x, size_t start_y, size_t end_x, size_t end_y, uint32_t rgb_color)
{

}

int undo(void)
{
    return FALSE;
}

int redo(void)
{
    return FALSE;
}