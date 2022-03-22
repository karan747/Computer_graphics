#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x + 320, 240 - (yc + y), RED);
    putpixel(xc - x + 320, 240 - (yc + y), RED);
    putpixel(xc + x + 320, 240 - (yc - y), RED);
    putpixel(xc - x + 320, 240 - (yc - y), RED);
    putpixel(xc + y + 320, 240 - (yc + x), RED);
    putpixel(xc - y + 320, 240 - (yc + x), RED);
    putpixel(xc + y + 320, 240 - (yc - x), RED);
    putpixel(xc - y + 320, 240 - (yc - x), RED);
}

void midpoint(int xc, int yc, int r)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int x = r;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        drawCircle(xc,yc,x,y);

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
    getch();
    closegraph();
}

void Bresenham(int xc, int yc, int r)
{

    // Function for circle-generation
    // using Bresenham's algorithm
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels

        x++;

        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(50);
    }
    getch();
    closegraph();
}

int main(int argc, char const *argv[])
{
    int x, y, r, algo;
    cout << "x,y"
         << " "
         << "r" << endl;
    cin >> x >> y >> r;
    cout << "select algo :";
    cin >> algo;
    if (algo == 1)
    {
        midpoint(x, y, r);
    }
    if (algo == 2)
    {
        Bresenham(x, y, r);
    }
    return 0;
}
