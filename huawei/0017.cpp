// 0017.坐标移动

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int x = 0, y = 0;
        while(!s.empty())
        {
            int idx = s.find(';');
            if (idx == 0) {
                s = s.substr(idx+1);
                continue;
            }
            string s1 = s.substr(0, idx);
            char c = s1[0];
            int err = 0;
            for(int i = 1; i < s1.size(); i++)
            {
                if(!isdigit(s1[i])) {
                    err = 1;
                    break;
                }
            }
            if(!err && s1.size() != 1)
            {
                int num = stoi(s1.substr(1));
                switch (c)
                {
                    case 'A':
                        x -= num;
                        break;
                    case 'D':
                        x += num;
                        break;
                    case 'W':
                        y += num;
                        break;
                    case 'S':
                        y -= num;
                        break;
                    default:
                        break;
                }
            }
            s = s.substr(idx+1);
        }
        cout << x << ',' << y << endl;
    }
    return 0;
}