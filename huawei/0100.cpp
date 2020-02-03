// 0100.等差数列

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        cout << n*(2+3*n-1)/2 << endl;
    }
    return 0;
}