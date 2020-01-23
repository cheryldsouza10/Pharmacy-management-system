#include <iostream>
#include<cstdlib>              //for exit 0;
using namespace std;

class Complex                     //class definition;
{
  private:
      float real,img;
  public:
      void read()
      {
          cout<<"Enter the real part:";
          cin>>real;
          cout<<"Enter the imaginary part";
          cin>>img;
      }  //end of read function
      void display()
      {
          if(img<0)
            cout<<real<<img<<"i"<<endl;
          else
            cout<<real<<"+i"<<img<<endl;
      }      //end of display function
      Complex add(Complex c1,Complex c2)
      {
          Complex result;
          result.real=c1.real+c2.real;
          result.img=c1.img+c2.img;
          return(result);                     //returns a complex number which is the member of the cll\ass
      }
      Complex add(Complex c1, int a)
      {
          Complex rest;
          rest.real=c1.real+a;
          rest.img=c1.img;
          return(rest);
      }
};

int main()
{
    int x,ch;
    Complex c1,c2,res,res1;       //Object name usually in lower case
    for(;;)
    {
        cout<<"======================================="<<endl;
        cout<<"Menu:"<<endl;
        cout<<"1.Enter the complex number"<<endl;
        cout<<"2.Add the 2 complex numbers"<<endl;
        cout<<"3.Display the result"<<endl;
        cout<<"4.Add an integer"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<"======================================="<<endl;

        switch(ch)
        {
            case 1: c1.read();                        //Reading the first complex number
                    c2.read();
                    break;

            case 2: res=res.add(c1,c2);
                    cout<<"Result =";
                    res.display();
                    break;

            case 3: c1.display();
                    c2.display();
                    break;

            case 4: cout<<"Enter the integer";
                    cin>>x;
                    res1=res1.add(c1,x);
                    cout<<"Result =";
                    res1.display();

            case 5: exit (0);

            default: cout<<"Invalid choice"<<endl;

        }
    }
    return 0;
}
