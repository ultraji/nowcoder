// 0060.查找组成一个偶数最接近的两个素数

#include <iostream>
#include <cmath>
using namespace std;

bool isPrim(int n)
{
    if(n < 2) return false; 
    int t = sqrt(n);
    for(int i = 2; i <= t; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = n/2; i >= 2; i--)
        {
            if(isPrim(i) && isPrim(n-i)) {
                cout << i << endl << n-i << endl;
                break;
            }
        }
    }
    return 0;
}