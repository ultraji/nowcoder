// 0083.二维数组操作

#include <iostream>
using namespace std;

int main()
{
    int r, c, r1, c1, r2, c2, ri, ci, rt, ct;
    while(cin>>r>>c>>r1>>c1>>r2>>c2>>ri>>ci>>rt>>ct)
    {
        if(r>9||c>9)  cout<<"-1"<<endl;
        else cout<<"0"<<endl;
         
        if(r1>=0 && r1<r && c1>=0 && c1<c && r2>=0 && r2<r && c2>=0 && c2<c) cout<<"0"<<endl;       
        else cout<<"-1"<<endl;
         
        if(ri>=0 && ri<r) cout<<"0"<<endl;
        else cout<<"-1"<<endl;
         
        if(ci>=0 && ci<c) cout<<"0"<<endl;
        else cout<<"-1"<<endl;
         
        if(rt>=0 && rt<r && ct>=0 && ct<c) cout<<"0"<<endl;   
        else cout<<"-1"<<endl;
    }
}