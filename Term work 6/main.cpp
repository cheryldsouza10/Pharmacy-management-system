#include <iostream>
#include <cstdlib>
using namespace std;

class Figures
{
 private:
    double Area;
 public:
    double area(float r)    //function to calculate the area of a circle
    {
        Area=3.1412*r*r;
        return(Area);
    }

    double area(float x,float y)     //function to calculate the area of a rectangle
    {
        Area=x*y;
        return(Area);
    }

    double area(double b,double h)      //function to calculate the area of a triangle
    {
        Area=0.5*b*h;
        return(Area);
    }
};           //end of class

int main()
{
    int ch;
    float r,l,w;
    double b,h;
    double Ac,Ar,At;
    Figures a;
    for(;;)
    {
        cout<<"Menu:"<<endl;
        cout<<"1.Area of circle"<<endl<<"2.Area of rectangle"<<endl<<"3.Area of triangle"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:cout<<"Enter the radius:";
                   cin>>r;
                   Ac=a.area(r);
                   cout<<"Area="<<Ac<<endl;
                   cout<<"======================================="<<endl;
                   break;
            case 2:cout<<"Enter the length and breadth:";
                   cin>>l>>w;
                   Ar=a.area(l,w);
                   cout<<"Area="<<Ar<<endl;
                   cout<<"======================================="<<endl;
                   break;
            case 3:cout<<"Enter the base and height:";
                   cin>>b>>h;
                   At=a.area(b,h);
                   cout<<"Area="<<At<<endl;
                   cout<<"======================================="<<endl;
                   break;
            case 4: exit(0);
            default:cout<<"Invalid choice"<<endl;
                    cout<<"======================================="<<endl;
        }
    }
    return 0;
}
