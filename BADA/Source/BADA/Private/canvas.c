#include <stdio.h>

#include "canvas.h"

struct data
{
    int x;
    int y;
    int rgb_color;
};

struct data s_data[256];
size_t s_data_count = 0;

struct data d[256];
size_t d_count = 0;

static uint32_t* s_canvas;
static size_t s_rows;
static size_t s_cols;

void set_canvas(uint32_t* canvas, size_t rows, size_t cols)
{
    s_canvas = canvas;
    s_rows = rows;
    s_cols = cols;
}

void release_canvas(void)
{

}

void draw_pixel(size_t x, size_t y, uint32_t rgb_color)
{
    s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
    s_data[s_data_count].x = x;
    s_data[s_data_count].y = y;

    s_data_count += 1;

    s_canvas[y * s_cols + x] = rgb_color;

}

void remove_pixel(size_t x, size_t y)
{
    s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
    s_data[s_data_count].x = x;
    s_data[s_data_count].y = y;

    s_data_count += 1;

    s_canvas[y * s_cols + x] = 0xffffff;
}

void fill_canvas(uint32_t rgb_color)
{
    int x = s_data[s_data_count].x;
    int y = s_data[s_data_count].y;
    
   
    for (int y = 0; y < s_rows; y++)
    {

        for (int x = 0; x < s_cols; x++)
        {
            s_data[s_data_count].x = x;
            s_data[s_data_count].y = y;
            s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
            s_data_count += 1;

            s_canvas[y * s_cols + x] = rgb_color;
      
            
        }
    }
    if (s_data > 256)
        return -1;

}

void draw_horizontal_line(size_t y, uint32_t rgb_color)
{ 
 
     int x = s_data[s_data_count].x;
     

    for (int x = 0; x < s_cols; x++)
    {    
         
        s_data[s_data_count].x = x;
        s_data[s_data_count].y = y;
        s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
        s_canvas[y * s_cols + x] = rgb_color;
         s_data_count += 1;
    }
      
}


void draw_vertical_line(size_t x, uint32_t rgb_color)
{
    int y = s_data[s_data_count].y;
    
    

    for (int y = 0; y < s_rows; y++)
    {
        s_data[s_data_count].x = x;
        s_data[s_data_count].y = y;
        s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
        s_canvas[y * s_cols + x] = rgb_color;
        s_data_count += 1;
    }
   
    
}

void draw_rectangle(size_t start_x, size_t start_y, size_t end_x, size_t end_y, uint32_t rgb_color)
{
    int x = s_data[s_data_count].x;
    int y = s_data[s_data_count].y;
       
    
    for (int y = start_y; y <= end_y; y++)
    {
        for (int x = start_x; x <= end_x; x++)
        {
            s_data[s_data_count].x = x;
            s_data[s_data_count].y = y;
            s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
            s_canvas[y * s_cols + x] = rgb_color;
            s_data_count += 1;
        }

    }
   
   
}



int undo(void)
{
    if (s_data_count >= 1)
    {
        s_data_count -= 1;
        int x = s_data[s_data_count].x;
        int y = s_data[s_data_count].y;
        uint32_t rgb_color = s_data[s_data_count].rgb_color;

        d[d_count].x = x;
        d[d_count].y = y;
        d[d_count].rgb_color = s_canvas[y * s_cols + x];
        d_count += 1;

        s_canvas[y * s_cols + x] = rgb_color;
        return TRUE;
    }

    else
        return FALSE;


}





int redo()
{ 
   
    if (d_count > 0)
    {
        d_count -= 1;
        int x = d[d_count].x;
        int y = d[d_count].y;
        uint32_t rgb_color = d[d_count].rgb_color;

        s_data[s_data_count].x= d[d_count].x;
        s_data[s_data_count].y= d[d_count].y;
        s_data[s_data_count].rgb_color = s_canvas[y * s_cols + x];
        s_data_count += 1;

        s_canvas[y * s_cols + x] = rgb_color;
       
        
        return TRUE;
    }
   
    return FALSE;
 
  
}
