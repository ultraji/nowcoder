// 0044.Sudoku-Java

// 测试数据含有非唯一解，不在尝试AC

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int v[9][9];
int lin[9][10], row[9][10], check[9][10];

bool test(int x, int y)
{
    int cnt = 0, t = 0, np[10];
    fill(np, np+10, 0);
    for(int i = 1; i < 10; i++) {
        np[i] = lin[x][i] + row[y][i] + check[x/3*3+y/3][i];
        if(np[i] != 0) {
            cnt ++;
        } else {
            t = i;
        }
    }   
    if(cnt == 8) {
        v[x][y] = t;
        lin[x][t] = 1;
        row[y][t] = 1;
        check[x/3*3+y/3][t] = 1;
        return true;
    }

    return false;
}

int main()
{
    queue<pair<int, int> > q;
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> v[i][j];
            lin[i][v[i][j]] = 1;
            row[j][v[i][j]] = 1;
            check[i/3*3+j/3][v[i][j]] = 1;
            if(v[i][j] == 0) {
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (!test(p.first, p.second)) q.push(p);
    }
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}