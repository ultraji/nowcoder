// 0104.字符串分割

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