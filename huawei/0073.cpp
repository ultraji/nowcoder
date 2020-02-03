// 0073.计算日期到天数转换

#include <iostream>
using namespace std;

int isLeap(int y)
{
    if(y%400 == 0) return 1;
    else if(y%100 && y%4 == 0) return 1;
    else return 0;
}

int main()
{
    int month[13] = {0,0,31,28,31,30,31,30,31,31,30,31,30};
    for(int i = 1; i < 13; i++)
    {
        month[i] += month[i-1];
    }
    int y, m, d;
    while(cin >> y >> m >> d)
    {
        int day = 0;
        if(m > 2) {
            day = isLeap(y); 
        }
        day += month[m] + d;
        cout << day << endl;
    }
    return 0;
}