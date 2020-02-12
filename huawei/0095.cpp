// 0095.人民币转换

#include <iostream>
using namespace std;

string ge[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
string ot[17] = { "", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾",
     "佰", "仟", "万", "拾", "佰", "仟","万" };

void readItAfterPlot(string num)
{
    if(num == "00") {
        cout << "整";
        return ;
    }
    if (num[0] > '0') {
        cout << ge[num[0]-'0'] << "角";
    } else {
        cout << "零";
    }
    if (num[1] > '0') {
        cout << ge[num[1]-'0'] << "分";
    }
    return ;
}

void readItBeforePlot(string s)
{
    if (s != "0") return;
    int j = s.size()-1;
    if(!(j%4 == 1 && s[0] == '1')) {
        cout << ge[s[0]-'0'];
    }
    cout << ot[j];
    for(int i = 1; i < s.size(); i++)
    {
        if( (j-i)%4 == 0  && s[i] == '0') {
            cout << ot[j-i];
            continue;
        }
        if(s[i] != '0') {
            if(s[i-1] == '0') cout << "零";
            //if(!((j-i)%4 == 1 && s[i] == '1')) {
                // 513.00 是伍佰壹拾叁元还是伍佰拾叁元的区别。
                cout << ge[s[i]-'0'];
            //}
            cout << ot[j-i];
        }
    }
    cout << "元";
    return ;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        int idx = s.find('.');
        string t1 = s.substr(0, idx);
        string t2 = s.substr(idx+1);
        cout << "人民币";
        readItBeforePlot(t1);
        readItAfterPlot(t2);
        cout << endl;
    }
    return 0;
}