#include<iostream>
#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

void DDA(int x1,int y1,int x2,int y2){
    delay(100);
    int gd =DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    int dx = x2-x1;
    int dy = y2-y1;
    int steps;
    float x_inc,y_inc;
    if (abs(dx) <= abs(dy)){
        steps = dy;
    }
    else{
        steps = dx;
    }
    x_inc = (float)dx/(float)steps;
    y_inc = (float)dy/(float)steps;

    for(int i = 0 ; i<=steps ; ++i){
        putpixel(x1+320,240-y1,WHITE);
        x1 += x_inc;
        y1 += y_inc;
        delay(20);
    }
    getch();
    closegraph();
    
}

void Bresenham(int x1,int y1,int x2,int y2){
    delay(100);
    int gd =DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    int dy=y2-y1,dx=x2-x1,x=x1,y=y1;
    float m = (float)(dy)/(float)(dx);
    int P = (2*dy) - dx;
    while(x<=x2){
        if (m<1){
            putpixel(x+320,240-y,WHITE);
            if (P<0){
                x += 1;
                P += 2*dy;
            }
            if(P>=0){
                x += 1;
                y += 1;
                P += 2*dy-2*dx; 
            }
        }
        if (m>=1){
            putpixel(x+320,240-y,WHITE);
            if (P<0){
                x += 1;
                P += 2*dx;
            }
            if(P>=0){
                x += 1;
                y += 1;
                P += 2*dx-2*dy; 
            }
        }
    }
    getch();
    closegraph();
}
 
int main(int argc, char const *argv[])
{
    int x1,y1,x2,y2,algo;
    cout<<"x1,y1"<<endl<<"x2,y2"<<endl;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cout<<"select algo :";
    cin>>algo;
    if(algo==1){
        cout<<"DDA";
        DDA(x1,y1,x2,y2);}
    if(algo==2){
        cout<<"bres";
        Bresenham(x1,y1,x2,y2);}
    return 0;
}