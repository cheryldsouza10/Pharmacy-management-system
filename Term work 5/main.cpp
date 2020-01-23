#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class Student
{
 private:
   char name[20];
   char usn[10];
   int m1,m2,m3,total;
   float percentage;
   char grade;

 public:
    Student(char n[10], char u[10], int M1, int M2, int M3)          //constructor
    {
        strcpy(this->name,n);
        strcpy(this->usn,u);
        this->m1=M1;
        this->m2=M2;
        this->m3=M3;
    }


    void result()
    {
        total=m1+m2+m3;
        percentage=(total/3.0);
        if(percentage>=80)
            grade='A';
        else
            if(percentage>=70 && percentage<80)
            grade='B';
        else
            if(percentage>=60 && percentage<70)
            grade='C';
        else
            grade='F';
    }

    void display()
    {
        /*cout<<"USN:"<<usn<<endl;
        cout<<"Marks:"<<m1<<"\t"<<m2<<"\t"<<m3<<endl;
        cout<<"Total:"<<total<<endl;
        cout<<"Percentage:"<<percentage<<endl;
        cout<<"Grade:"<<grade<<endl;*/

        cout<<"Name"<<"\t"<<"USN\t"<<"Marks\t \t \t"<<"Total\t"<<"Percentage\t"<<"Grade:"<<endl;
        cout<<this->name<<"\t"<<this->usn<<"\t"<<this->m1<<"\t"<<this->m2<<"\t"<<this->m3<<"\t";
        cout<<this->total<<"\t"<<this->percentage<<"\t\t"<<this->grade<<endl;
        cout<<"==============================================================================="<<endl;
    }
};

int main()
{
   /*Student s1("Asha", "2GI17CS080", 12, 45, 67);
   s1.result();
   s1.display();*/

   Student *s1[10];
   int m1,m2,m3,i,n;
   char name[10], usn[10];
   cout<<"Enter the number of students:";
   cin>>n;

   for(i=0;i<n;i++)
   {
       cout<<"Enter name:";
       cin>>name;
       cout<<"Enter the USN:";
       cin>>usn;
       cout<<"Enter three subject marks:";
       cin>>m1>>m2>>m3;
       s1[i]= new Student(name, usn, m1,m2,m3);
       s1[i]->result();
       s1[i]->display();
   }
    return 0;
}
