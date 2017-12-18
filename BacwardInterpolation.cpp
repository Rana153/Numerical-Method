#include<bits/stdc++.h>
using namespace std;
class ALL{
    public:
	int n;
    double x[50], y[50][50] ,p;
}obj;
int findXn(int x){
	int i = 0;
	while( obj.x[i] < x && i < obj.n){
		i++;
	}
	return obj.x[i-1];
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
double operation(int n){
    double tmp = obj.p;
	for(int i = 1; i<n; i++)
    	tmp = tmp*(obj.p+i);
    
	return tmp;
}
int main(){
    cout << "Number of Input : ";
    cin >> obj.n;
    cout << "Input the value of X and Y "<<endl;
    for(int i = 0; i < obj.n; i++){
    	cin >> obj.x[i] >> obj.y[i][0];
	}
//	for(int i = 0; i < obj.n; i++){
//    	cout << obj.x[i] <<" " << obj.y[0][i];
//	}
	
	for(int i = 1; i < obj.n; i++){
		for(int j = 0; j < obj.n - i; j++){
			 obj.y[j][i] = obj.y[j + 1][i - 1] - obj.y[j][i - 1];
		}
	}
	 for (int i = 0; i < obj.n; i++) {
        cout << setw(4) << obj.x[i] 
             << "\t";
        for (int j = 0; j < obj.n - i; j++)
            cout << setw(4) << obj.y[i][j] 
                 << "\t";
        cout << endl;
    }
   // cout << obj.y[1][3] <<" " << obj.y[0][3] << endl;
	int x, xn, h;
	double p, sum = 0.0;
	cout <<"What is the finding value : ";
	cin >> x;
	xn = findXn(x);
	cout <<" Xn : " << xn << endl;
	h = obj.x[1] - obj.x[0];
	obj.p = (x - xn) / (1.0*h);
	cout <<" P : " << obj.p << endl;
	sum += obj.y[0][0];
	cout << sum << endl;
	for (int i = 1; i < obj.n; i++) {
        sum += (operation(i) * obj.y[0][i]) / fact(i);
    }
	cout << sum << endl;
	return 0;
}

/*
0 1.0
5 1.6
10 3.8 
15 8.2
20 15.4
*/
