#include<bits/stdc++.h>
#define ERROR .00001
using namespace std;

struct Newton{
     double newtonRoot;
    public :
     void newtonRapsonFormula();
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


int main(){
    Newton ob;
    ob.newtonRapsonFormula();
    return 0;
}

