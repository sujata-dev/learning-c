/*Check whether a triangle can be formed by determining the length of each side from three given vertices and using the condition that in a triangle, the sum of any side is greater than the 3rd side. Calculate the area of the triangle if it can be formed with given vertices. Next verify whether a given point is within or outside the triangle.*/
#include<stdio.h>
#include<math.h>
int distance(int,int,int,int);
int area(int,int,int);
struct coordinate
{
    int x,y;
}a,b,c,p;
int main()
{
    float AB,BC,CA,total,PA,PB,PC,area1,area2,area3;
    printf("\nEnter coordinates of side A of triangle ABC: ");
    scanf("%d %d",&a.x,&a.y);
    printf("\nEnter coordinates of side B of triangle ABC: ");
    scanf("%d %d",&b.x,&b.y);
    printf("\nEnter coordinates of side C of triangle ABC: ");
    scanf("%d %d",&c.x,&c.y);
    AB=distance(a.x,a.y,b.x,b.y);
    BC=distance(b.x,b.y,c.x,c.y);
    CA=distance(c.x,c.y,a.x,a.y);
    printf("\nAB= %f,BC= %f,CA= %f,",AB,BC,CA);
    total=area(AB,BC,CA);
    printf("\nArea of triangle ABC: %f",total);
    if(AB<(BC+CA)&&BC<(AB+CA)&&CA<(AB+BC))
    {
        printf("\nTriangle is possible");
        printf("\nEnter coordinates of point P: ");
        scanf("%d %d",&p.x,&p.y);
        PA=distance(p.x,p.y,a.x,a.y);
        PB=distance(p.x,p.y,b.x,b.y);
        PC=distance(p.x,p.y,c.x,c.y);
        area1=area(PA,PB,AB);
        area2=area(PB,PC,BC);
        area3=area(PA,PC,CA);
        if(total==(area1+area2+area3))
             printf("\nPoint P lies inside triangle ABC");
        else
            printf("\nPoint P does not lie inside triangle ABC");
    }
    else
        printf("\nTriangle is not possible");
    return 0;
}
int distance(int p1,int q1,int p2,int q2)
{
    float ar;
    ar=sqrt(pow((p2-p1),2)+pow((q2-q1),2));
    return ar;
}
int area(int r,int s,int t)
{
    float s1,ar1;
    s1=(r+s+t)/2;
    ar1=sqrt(s1*(s1-r)*(s1-s)*(s1-t));
    return ar1;
}
