#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-4

double f(double x)
{
    return x*x*x*x - 5*x*x +4 ;
}

void bisec(double x1,double x2)
{
    cout<< "Range: " << x1 << " "<<x2<<endl;
    double z;
    int it=0;
    while((x2-x1)>=EPS)
    {
        z= x1+ ((f(x1)*(x1-x2))/(f(x2)-f(x1)));
        if(f(z)==0)
        {
            break;
        }
        else if(f(z)*f(x1)<0)
        {
            x2=z;
        }
        else x1=z;
        it++;
    }
    cout<< "Iteration: " << it <<endl;
    cout<< "Root: " << z << endl;
}

int main()
{
    double a,b,c,lr,ll;
    c=0.5;
    lr=sqrt(10);
    ll=-lr;
    a=ll;
    b=ll+c;
    while(b<=lr)
    {
        if(f(b)==0)
        {
            cout<<b<<endl;
            a+=c;b+=c;
        }
        else if(f(a)*f(b)<0)
        {
            bisec(a,b);
        }
        a+=c;b+=c;
    }
}
