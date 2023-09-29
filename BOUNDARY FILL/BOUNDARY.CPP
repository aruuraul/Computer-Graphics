#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void boundaryfill(int x,int y,int f_c,int b_c)
{
int current;
current=getpixel(x,y);
if(current!=b_c && current!=f_c)
{
putpixel(x,y,f_c);
boundaryfill(x,y+1,f_c,b_c);
boundaryfill(x,y-1,f_c,b_c);
boundaryfill(x+1,y,f_c,b_c);
boundaryfill(x-1,y,f_c,b_c);
}
}
void floodfill(int x1,int y1,int o_c,int n_c)
{
int current;
current=getpixel(x1,y1);
if(current==o_c)
{
putpixel(x1,y1,n_c);
floodfill(x1,y1+1,o_c,n_c);
floodfill(x1,y1-1,o_c,n_c);
floodfill(x1-1,y1,o_c,n_c);
floodfill(x1+1,y1,o_c,n_c);
}
}
void main()
{
int gd,gm,x,y,x1,y1,r;
gd=DETECT;
printf("Enter the origin points for circle 1 & 2:");
scanf("%d %d %d %d",&x,&y,&x1,&y1);
printf("\n Enter radius:");
scanf("%d",&r);
initgraph(&gd,&gm,"..//bgi");
circle(x,y,r);
circle(x1,y1,r);
boundaryfill(x,y,5,15);
floodfill(x1,y1,0,2);
getch();
closegraph();
}

