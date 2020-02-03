// 0068.成绩排序

#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    int num;
    string name;
    int score;
};

bool cmp1(student s1, student s2)
{
    if(s1.score == s2.score) return s1.num < s2.num;
    return s1.score > s2.score;
}

bool cmp2(student s1, student s2)
{
    if(s1.score == s2.score) return s1.num < s2.num;
    return s1.score < s2.score;
}

int main()
{
    int n, m;
    string s;
    student st[1000];
    while(cin >> n >> m)
    {
        getchar();
        for(int i = 0; i < n; i++)
        {
            getline(cin, s);
            int f = s.find(' ');
            st[i].num = i;
            st[i].name = s.substr(0, f);
            st[i].score = stoi(s.substr(f+1));
        }
        if(m)
            sort(st, st+n, cmp2);
        else
            sort(st, st+n, cmp1);
        for(int i = 0; i < n; i++)
        {
            cout << st[i].name << ' ' << st[i].score << endl;
        }
    }
    return 0;
}