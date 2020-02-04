// 0043.迷宫问题
// keywords: 树的遍历

// PS: 可以简化成树的层序遍历，唯一难点就是记录路径

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    int t[4][2] = {{-1,0}, {0,-1}, {1,0},{0,1}};
    int v[12][12];
    while(cin >> n >> m)
    {
        vector<pair<int,int> > r;
        stack<pair<int,int> > s;
        fill(v[0], v[0]+12*12, 1);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> v[i][j];
        s.push(make_pair(1,1));
        v[1][1] = 1;
        while(!s.empty())
        {
            pair<int, int> p = s.top();
            s.pop();
            for(int i = 0; i < 4; i++){
                int x = p.first + t[i][0];
                int y = p.second + t[i][1];
                if(v[x][y] == 0) {
                    v[x][y] = p.first * 100 + p.second; // 用于记录路径的上个点
                    if(x == n && y == m) break; //  到达终点跳出
                    s.push(make_pair(x,y));
                }
            }
        }
        for (int x = n, y = m, t = v[n][m]; v[x][y] != 1; x = t/100, y = t%100)
        {
            t = v[x][y];
            r.push_back(make_pair(x, y));
        }
        r.push_back(make_pair(1, 1));
        reverse(r.begin(), r.end());
        for(int i = 0; i < r.size(); i++)
        {
            cout << '(' << r[i].first-1 << ',' << r[i].second-1 << ')' << endl;
        }
    }
    return 0;
}