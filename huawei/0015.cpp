#include <iostream>
using namespace std;

int cnt(int num)
{
    int cnt = 0;
    while(num != 0)
    {
        if( num % 2 ) cnt ++;
        num /= 2;
    }
    return cnt;
}

int main()
{
    int num;
    cin >> num;
    cout << cnt(num);
    return 0;
}