#include<bits/stdc++.h>
using namespace std;

class ALL{
    double a, b, c, fa, fb, fc;
    int i, j;
    public:
    double f(double x);
    void bisection();
};

double ALL::f(double x){
    return x*x*x - 2*x - 5;
}

void ALL::bisection(){
    double a, b, e, c, fa, fb, fc;
    int iter = 0;
    int i, j;
    for(i= 0, j = 0; ; i++,j--){
        a = j;
        b = i;
        if(f(a)* f(b) < 0){
            while(true){
                if(f(a+1)*f(b) >= 0.0 ) break;
                a++;
            }
            while(true){
                if(f(a)*f(b-1) >= 0.0 ) break;
                b--;
            }
            break;
        }
    }
    e = .001;
    while (fabs(a-b)>=e){
        c=(a+b)/2.0;
        fa=f(a);
        fb=f(b);
        fc=f(c);
        iter++;
        cout<<iter<<"\t"<<"a = "<<a<<"\t"<<"b = "<<b<<"\t"<<"c = "<<c<<"\tfc = "<<fc<<endl;
        if (fc==0)
            break;
        else if (fa*fc<0)
            b=c;
        else
            a  = c;
    }
    cout<<"\n\tThe root of the equation is = "<<c<<endl;
   // cout <<"\t--------------------------------" << endl;
}

int main()
{
    int i;
    ALL obj;
    obj.bisection();
    return 0;
}
