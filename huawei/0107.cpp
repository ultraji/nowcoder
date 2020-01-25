#include <iostream>
using namespace std;

// 牛顿迭代法

#define E 0.01

double f(double x, double num)
{
	return x*x*x - num;
}

double _f(double x)
{
	return 3*x*x;
}

double cubeRoot(double num)
{
	double r = 1;
    double x0;
	do{
		x0 = r;
        r = x0 - f(x0, num)/_f(x0);
	}while(f(r,num) > E || f(r, num) < -E);

    return r;
}

int main()
{
    double num;
    cin >> num;
    printf("%.1lf", cubeRoot(num));
    return 0;
}