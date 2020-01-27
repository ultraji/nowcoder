/* DNA序列 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    while(getline(cin, s))
    {
        int sum = 0, maxidx = 0, maxsum = 0;
        cin >> n;
        getchar();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'C' || s[i] == 'G') {
                sum += 1;
            }
        }
        maxsum = sum;
        maxidx = 0;
        for(int i = n; i < s.size(); i++)
        {
            if (s[i] == 'C' || s[i] == 'G') {
                sum += 1;
            }
            if (s[i-n] == 'C' || s[i-n] == 'G') {
                sum -= 1;
            }
            if (maxsum < sum) {
                maxidx = i-n+1;
                maxsum = sum;
            }
        }
        for(int i = maxidx; i < maxidx + n; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}