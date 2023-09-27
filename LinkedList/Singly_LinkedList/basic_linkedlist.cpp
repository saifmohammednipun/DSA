#include <bits/stdc++.h>
using namespace std;

struct Point
{
    // int x;
    // int y;
    int x,y;
};

int main()
{
    struct Point p1,p2;
    p1.x = 10;
    p1.y = 20;

    struct Point* ptr = &p2;
    ptr->x = 30;
    ptr->y = 40;

    cout<< ptr->x <<endl;
    cout<< ptr->y <<endl;

    ptr = &p1;

    cout<< ptr->x <<endl;
    cout<< ptr->y <<endl;


    struct Point points[5];
    ptr = points;
        
    for(int i=0; i<5; i++)
    {
        (ptr+i)->x = i;
        (ptr+i)->y = i*i;
    }

    for(int i=0; i<5; i++)
    {
        cout<< (ptr+i)->x <<endl;
        cout<< (ptr+i)->y <<endl;
    }

    return 0;
}