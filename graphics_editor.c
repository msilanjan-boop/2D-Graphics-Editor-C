#include <stdio.h>

#define ROWS 40
#define COLS 80

char canvas[ROWS][COLS];

void initCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int row, int col, int width, int height)
{
    for(int i = col; i < col + width; i++)
    {
        canvas[row][i] = '*';
        canvas[row + height - 1][i] = '*';
    }

    for(int i = row; i < row + height; i++)
    {
        canvas[i][col] = '*';
        canvas[i][col + width - 1] = '*';
    }
}

int main()
{
    initCanvas();

    drawRectangle(5, 10, 15, 6);

    displayCanvas();

    return 0;
}
