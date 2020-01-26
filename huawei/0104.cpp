/* 连续输入字符串(输出次数为N,字符串长度小于100)，请按长度为8拆分每个字符串后输出到新的字符串数组，
 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 */

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    int n;
    while(cin >> n)
    {
        getchar();
        while(n--)
        {
            getline(cin, s);
            while (s.size() >= 8)
            {
                cout << s.substr(0, 8) << endl;
                s = s.substr(8);
            }
            if (s.size() > 0) {
                cout << s.append(8-s.size(), '0') << endl;
            }
        }
    }
    return 0;
}