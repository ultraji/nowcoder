// 0098.自动售货系统

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct {
    int pri;
    int num;
} goods[7] = {{0,0}, {2,0}, {3,0}, {4,0}, {5,0}, {8,0}, {6,0}},
coins[5] = {{0,0}, {1,0}, {2,0}, {5,0}, {10,0}};

struct node
{
    string name;
    int pri;
    int num;
    bool operator < (node no) const {
        if (num == no.num) return name < no.name;
        return num > no.num;
    }
};


int pay = 0;

bool init(string cmd)
{
    int i;
    pay = 0;
    cmd = cmd.substr(2);
    string s = cmd.substr(0, cmd.find(' '));
    for(i = 1, s += '-'; i <= 6; i++)
    {
        int idx = s.find('-');
        string t = s.substr(0,idx);
        s = s.substr(idx+1);
        goods[i].num = stoi(t);
        goods[0].num += goods[i].num;
    }
    s = cmd.substr(cmd.find(' ')+1);
    for(i = 1, s += '-'; i <= 4; i++)
    {
        int idx = s.find('-');
        string t = s.substr(0, idx);
        s = s.substr(idx+1);
        coins[i].num = stoi(t);
    }
    cout << "S001:Initialization is successful" << endl;
    return true;
}

int check_pay(string cmd) {
    int p = stoi(cmd.substr(2));
    if (p != 1 && p != 2 && p != 5 && p != 10) {
        cout << "E002:Denomination error" << endl;
    }else if (p > coins[1].num + coins[2].pri * coins[2].num) {
        cout << "E003:Change is not enough, pay fail" << endl;
    }else if (p > 10) {
        cout << "E004:Pay the balance is beyond the scope biggest" << endl;
    }else if (goods[0].num == 0) {
        cout << "E005:All the goods sold out" << endl;
    } else {
        for(int i = 1; i <= 4; i++) {
            if(p == coins[i].pri) {
                coins[i].num ++;
                break;
            }
        }
        pay += p;
        cout << "S002:Pay success,balance=" << pay << endl;
    }
    return 0;
}
int buy(string cmd)
{
    string s = "A1A2A3A4A5A6";
    string name = cmd.substr(2);
    int g = name[1]-'0';
    if (s.find(name) == s.npos) {
        cout << "E006:Goods does not exist" << endl;
    } else if (goods[g].num == 0) {
        cout << "E007:The goods sold out" << endl;
    } else if (goods[g].pri > pay) {
        cout<<"E008:Lack of balance"<<endl;
    } else {
        pay -= goods[g].pri;
        goods[g].num --;
        goods[0].num --;
        cout<<"S003:Buy success,balance="<<pay<<endl;
    }
    return 0;
}

int return_coin()
{
    int i;
    int ret[5] = {0,0,0,0,0};
    if (pay == 0) {
        cout<<"E009:Work failure";
        return -1;
    }
    for(i = 4; pay != 0 && i>=1; i--)
    {
        while(pay >= coins[i].pri && coins[i].num > 0)
        {
            pay-=coins[i].pri;
            coins[i].num --;
            ret[i] ++;
        }
    }
    for(i = 1; i <= 4; i++)
        cout << coins[i].pri<<" yuan coin number=" << ret[i] << endl;
    return 0;
}

int query(string cmd)
{
    int num = -1;
    
    vector<node> v;
    cmd = cmd.substr(2);
    if(cmd.size()==1) num = cmd[0]-'0';
    if (num == 0) {
        for(int i = 1; i <= 6; i++)
        {
            string name = "A";
            name += '0' + i;
            node no = {name, goods[i].pri, goods[i].num};
            v.push_back(no);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i].name <<' '<< v[i].pri << ' ' << v[i].num << endl;
        }
    } else if (num == 1) {
        for(int i = 1; i <= 4; i++)
            cout << coins[i].pri << " yuan coin number=" << coins[i].num << endl;
    }
    else
        cout << "E010:Parameter error";
    return 0;
}
int main()
{
    string cmd;
    while(getline(cin,cmd))
    {
        pay = 0;
        while(!cmd.empty())
        {
            int idx = cmd.find(';');
            string tmp = cmd.substr(0, idx);
            if(tmp[0] == 'r') {
                init(tmp);
            } else if(tmp[0] == 'p') {
                check_pay(tmp);
            } else if(tmp[0] == 'b') {
                buy(tmp);
            } else if(tmp[0] == 'c') {
                return_coin();
            } else if(tmp[0] == 'q') {
                query(tmp);
            }
            cmd = cmd.substr(idx+1);
        }
    }
    return 0;
}