#include<bits/stdc++.h>
using namespace std;

class ALL{
    double a, b, c, fa, fb, fc;
    int i, j;
    public:
    double f(double x);
    void falsePosition();
    double findApproxValue(double a, double b);
};

double ALL::f(double x){
    return x*x*x - 2*x - 5;
}
double ALL::findApproxValue(double a, double b){
    return ((a*f(b)) - (b*f(a))) / (f(b)-f(a));
}

void ALL::falsePosition(){
    double a, b, e, x1, x2, fx1, fx2, fb, fc;
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
    cout << a << "  " << b << endl;
    e = .000001;
    x1 = findApproxValue(a,b);
    if(f(x1)*f(a)<0) b = x1;
    else a = x1;
    x2 = findApproxValue(a,b);
    if(f(x2)*f(a)<0) b = x2;
    else a = x2;

    while (fabs(x1-x2)>=e){
     //   cout << a << "  " << b << endl;
        x1 = x2;
        x2 = findApproxValue(a,b);
        if(f(x1)*f(a)<0) b = x2;
        else a = x2;
    }
    cout<<"\n\tThe root of the equation is = "<<x2<<endl;
}

int main()
{
    int i;
    ALL obj;
    obj.falsePosition();
    return 0;
}

