// 0069.矩阵乘法

#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    while(cin >> x >> y >> z)
    {
        int a[x][y], b[y][z];
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                cin >> a[i][j];
        for(int i = 0; i < y; i++)
            for(int j = 0; j < z; j++)
                cin >> b[i][j];
        for(int i = 0; i < x; i++)
        {   
            for(int j = 0; j < z; j++)
            {
                int tmp = 0;
                for(int k = 0; k < y; k++)
                    tmp += a[i][k]*b[k][j];
                cout << tmp << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}