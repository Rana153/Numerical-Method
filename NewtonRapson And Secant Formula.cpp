#include<bits/stdc++.h>
#define ERROR .00001
using namespace std;

struct Newton{
     double newtonRoot;
    public :
     void newtonRapsonFormula();
     void secant();
     void generateRange(double &x0, double &x1);
};
double equFunc(double x){
   return x*x*x - 2*x - 5;
   //return x*x*x - x*x + 2;
}
double derivFunc(double x){
    return 3*x*x - 2;
    //return 2*x - x;

}
int findApproxRoot(){
    int i = 1;
    double dif = 100000.0;
    while(true){
        double difTmp = fabs(0 - equFunc(i));
        if(difTmp >= dif)
            return (i-1);
        i++;
        dif = difTmp;
        if(i == 1000) break;
    }
    return 1;
}

void Newton::newtonRapsonFormula(){
    double x = double(findApproxRoot());
    double h = equFunc(x)/derivFunc(x);
    x = x - h;
    h = equFunc(x)/derivFunc(x);

    while(abs(x - (x-h)) >= ERROR){
        h = equFunc(x)/derivFunc(x);
        x = x - h;
    }
    cout << "Actual root by using newton raposn : " << x << endl;
    newtonRoot = x;
}

void Newton::generateRange(double &a,double &b){
    a = 1.0;
    b = -1.0;
    while(true){
        if((equFunc(a) * equFunc(b)) < 0)
            break;
        a += 1.0;
        b -= 1.0;
    }
}
void Newton::secant(){
    double x0,x1,x2;
    generateRange(x1,x0);
    do{
        x2 = x1 - (((x1-x0)/(equFunc(x1)-equFunc(x0)))*equFunc(x1));
        x0 = x1;
        x1 = x2;
    }while(fabs(x1-x0)>= ERROR);
    cout << "Actual Root by using secant method : " << x1 << endl;
}

int main(){
    Newton ob;
    ob.newtonRapsonFormula();

    ob.secant();
    return 0;
}
