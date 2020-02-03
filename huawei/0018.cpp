// 0018.识别有效的IP地址和掩码并进行分类统计

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool maskIsTrue(string s)
{
    unsigned long mask = 0;
    int tmp = 0;
    if (count(s.begin(), s.end(), '.') < 3) {
        return false;
    }
    s += '.';
    while(!s.empty())
    {
        int idx = s.find('.');
        string st = s.substr(0,idx);
        if (st.empty()) return false;
        tmp = stoi(st);
        if (tmp > 255 || tmp < 0) return false;
        mask = (mask<<8) | tmp;
        s = s.substr(idx+1);
    }
    bool firstOne = false;
    while(mask != 0)
    {
        if (mask%2 == 1) {
            firstOne = true;
        }
        else if(firstOne) {
            return false;
        }
        mask /= 2;
    }
    if(tmp == 255) return false;
    return true;
}

bool ipIsTrue(string s)
{
    unsigned long ip = 0;
    if (count(s.begin(), s.end(), '.') < 3) {
        return false;
    }
    s += '.';
    while(!s.empty())
    {
        int idx = s.find('.');
        string st = s.substr(0,idx);
        if (st.empty()) return false;
        int tmp = stoi(st);
        if (tmp > 255 || tmp < 0) return false;
        s = s.substr(idx+1);
    }
    return true;
}

void whichIp(string s, int &a, int &b, int &c, int &d, int &e, int &pri){
    int idx = s.find('.');
    int tmp = stoi(s.substr(0, idx));
    s = s.substr(idx+1);
    if (tmp > 0 && tmp < 127) {
        if (tmp == 10) {
            pri ++;
        }
        a ++;
    } else if (tmp < 192 && tmp > 127) {
        b ++;
        int tmp1 = stoi(s.substr(0, s.find('.')));
        if(tmp == 172 && tmp1 >= 16 && tmp1 <= 31){
            pri ++;
        }
    } else if (tmp >= 192 && tmp < 224) {
        c ++;
        int tmp1 = stoi(s.substr(0, s.find('.')));
        if(tmp == 192 && tmp1 == 168){
            pri ++;
        } 
    }else if (tmp >= 224 && tmp < 240) {
        d ++;
    } else if(tmp >= 240){
        e ++;
    }
    return ;
}

int main()
{
    string s;
    int a=0,b=0,c=0,d=0,e=0,err=0,pri=0;
    while(getline(cin, s))
    {
        int idx = s.find('~');
        string ip = s.substr(0,idx);
        string mask = s.substr(idx+1);
        if (!ipIsTrue(ip) || !maskIsTrue(mask)) {
            err ++;
            continue;
        }
        whichIp(ip,a,b,c,d,e,pri);
    }
    printf("%d %d %d %d %d %d %d", a,b,c,d,e,err,pri);
    return 0;
}