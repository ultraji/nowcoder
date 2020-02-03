// 0082.将真分数分解为埃及分数

// 算法不同，埃及分数不唯一。故未AC属于正常现象。
// PS：目前也没有最优的算法获取项数最少的埃及分数。

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    int a, b;
    while(getline(cin, s))
    {
        vector<int> r;
        int f = s.find('/');
        a = stoi(s.substr(0, f));
        b = stoi(s.substr(f+1));
        while(b % a != 0)
        {
            int i = b / a + 1;
            a = a * i - b;
            b = b * i;
            r.push_back(i);
        }
        
        for(int i = 0; i < r.size(); i++)
        {
            cout << "1/" << r[i] << "+";
        }
        cout << "1/" << b/a << endl;
    }
    return 0;
}