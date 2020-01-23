#include <iostream>
#include <cstdlib>
using namespace std;

class Manager
{
    protected:
        char name[10];
        float salary, hra, da, all,g_sal;
    public:
        virtual void read()=0;
        virtual void compute()=0;
        virtual void display()=0;
};

class P_manager:public Manager
{
    private:
        static int count;

    public:
        P_manager()
        {
            count++;
        }

        void read()
        {
            cout<<"Enter production manager name:";
            cin>>name;
            cout<<"Enter salary:";
            cin>>salary;
        }

        void compute()
        {
            hra=0.1*salary;
            da=0.75*salary;
            all=0.60*salary;
            g_sal=salary+hra+da+all;
        }

        void display()
        {
            cout<<"Name:"<<name;
            cout<<"\tGross salary:"<<g_sal<<endl;
        }

        int obj_no()
        {
            return(count);
        }
};

int P_manager::count;


class S_manager:public Manager
{
    private:
        static int count;

    public:
        S_manager()
        {
            count++;
        }
    float tra_all;
    void  read()
    {
        cout<<endl<<"Enter sales manager name:";
        cin>>name;
        cout<<"Enter salary:";
        cin>>salary;
    }

    void compute()
    {
        hra=0.1*salary;
        da=0.75*salary;
        all=0.60*salary;
        tra_all=0.8*salary;
        g_sal=salary+hra+da+all+tra_all;
    }

    void display()
    {
        cout<<endl<<"Name:"<<name;
        cout<<"\tGross salary:"<<g_sal<<endl;
    }

    int obj_no()
    {
        return(count);
    }
};

int S_manager::count;

int main()
{
    Manager *m;
    S_manager s,s1,s2,s3;
    P_manager p,p1,p2,p3;

    m=&p;

    m->read();
    m->compute();
    m->display();

    m=&s;

    m->read();
    m->compute();
    m->display();

    cout<<endl<<"Number of sales managers:"<<s.obj_no();
    cout<<endl<<"Number of production managers:"<<p.obj_no();
}
