// 0038.求小球落地5次后所经历的路程和第5次反弹的高度

#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        double sum = n;
        double hei = n;
        for (int i = 0; i < 4; i++) {
            hei /= 2;
            sum += hei*2;
        }
        cout << sum << endl;
        cout << hei/2 << endl;
    }
    return 0;
}