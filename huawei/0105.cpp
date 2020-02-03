// 0105.记负均正II

#include <iostream>
using namespace std;

int main()
{
    double sum = 0;
    int a, c = 0, cnt = 0;
    while(cin >> a)
    {
        if (a < 0) {
            cnt ++;
        }else {
            c ++;
            sum += a;
        }
    }
    printf("%d\n%.1lf", cnt, sum/c);
    return 0;
}