/*
 将一个字符中所有出现的数字前后加上符号“*”，其他字符保持不变
 public static String MarkNum(String pInStr)
 {
     return null;
 }
 注意：输入数据可能有多行
 */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        s.insert(0, 1, 'a');
        s.append(1, 'a');
        for(int i = 1; i < s.size(); i ++)
        {
            if (!isdigit(s[i-1]) && isdigit(s[i])) {
                cout << '*';
            }else if(isdigit(s[i-1]) && !isdigit(s[i])) {
                cout << '*';
            }
            if(i != s.size()-1) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}