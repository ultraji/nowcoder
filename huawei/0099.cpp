// 0099.自守数

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int j = 10;
            for(; i%j != i; j *= 10);
            if (i*i % j== i) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}