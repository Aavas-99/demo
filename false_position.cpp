#include<bits/stdc++.h>
using namespace std;
#define eps 1e-4

double f(double x)
{
    return 3*x-cos(x)+1;
}

void bisection(double x1,double x2)
{
    double x3;
    int it=0;

    cout<<"Range: "<<x1<<" "<<x2<<endl;
    while((x2-x1)>=eps)
    {
        x3= x2-((f(x2)*(x2-x1))/(f(x2)-f(x1)));

        if(f(x3)==0)
        {
            break;
        }
        if(f(x3)*f(x1)<0)
        {
            x2=x3;
        }
        else
        {
            x1=x3;
        }
        it++;
    }
    cout<< "iteration: "<<it<<endl;
    cout<< "Root: " <<x3<<endl;
}

int main()
{
    double a,b,c;

    //a=-(sqrt(10));
    //b=-a;
    //c=(a+0.5);
    a=-10;
    b=10;
    c=-9;

    while(c<=b)
    {
        if(f(c)==0)
        {
            cout<<c<< " ";
            a+=1;
            c+=1;
        }
        else if(f(a)*f(c)<0)
        {
            bisection(a,c);
        }
        a+=1;
        c+=1;
    }
}

