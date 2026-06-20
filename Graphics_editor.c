#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawLine(int row, int startCol, int endCol)
{
    int i;

    if(startCol > endCol)
    {
        int temp = startCol;
        startCol = endCol;
        endCol = temp;
    }

    for(i = startCol; i <= endCol; i++)
    {
        canvas[row][i] = '*';
    }
}

void drawRectangle(int row, int col, int height, int width)
{
    int i;

    for(i = col; i < col + width; i++)
    {
        canvas[row][i] = '*';
        canvas[row + height - 1][i] = '*';
    }

    for(i = row; i < row + height; i++)
    {
        canvas[i][col] = '*';
        canvas[i][col + width - 1] = '*';
    }
}

void drawTriangle(int row, int col, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        canvas[row + i][col - i] = '*';
        canvas[row + i][col + i] = '*';
    }

    for(j = col - height + 1; j <= col + height - 1; j++)
    {
        canvas[row + height - 1][j] = '*';
    }
}

void drawCircle(int centerRow, int centerCol, int radius)
{
    int angle;

    for(angle = 0; angle < 360; angle++)
    {
        int x = centerRow + radius * sin(angle * 3.14159 / 180);
        int y = centerCol + radius * cos(angle * 3.14159 / 180);

        if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
        {
            canvas[x][y] = '*';
        }
    }
}

void deleteArea(int row, int col, int height, int width)
{
    int i, j;

    for(i = row; i < row + height; i++)
    {
        for(j = col; j < col + width; j++)
        {
            if(i < ROWS && j < COLS)
            {
                canvas[i][j] = '_';
            }
        }
    }
}

int main()
{
    int choice;

    initCanvas();

    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int row, startCol, endCol;

                printf("Enter row: ");
                scanf("%d", &row);

                printf("Enter start column: ");
                scanf("%d", &startCol);

                printf("Enter end column: ");
                scanf("%d", &endCol);

                drawLine(row, startCol, endCol);
                break;
            }

            case 2:
            {
                int row, col, height, width;

                printf("Enter row and column: ");
                scanf("%d%d", &row, &col);

                printf("Enter height and width: ");
                scanf("%d%d", &height, &width);

                drawRectangle(row, col, height, width);
                break;
            }

            case 3:
            {
                int row, col, height;

                printf("Enter top row: ");
                scanf("%d", &row);

                printf("Enter center column: ");
                scanf("%d", &col);

                printf("Enter height: ");
                scanf("%d", &height);

                drawTriangle(row, col, height);
                break;
            }

            case 4:
            {
                int row, col, radius;

                printf("Enter center row: ");
                scanf("%d", &row);

                printf("Enter center column: ");
                scanf("%d", &col);

                printf("Enter radius: ");
                scanf("%d", &radius);

                drawCircle(row, col, radius);
                break;
            }

            case 5:
            {
                int row, col, height, width;

                printf("Enter row and column: ");
                scanf("%d%d", &row, &col);

                printf("Enter height and width: ");
                scanf("%d%d", &height, &width);

                deleteArea(row, col, height, width);
                break;
            }

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}
