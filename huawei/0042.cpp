// 0042.学英语

#include <iostream>
using namespace std;

string ge[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine"};
string ot[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string shi[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string printfHundred(int n)
{
    string s = "";
    bool hasHundred = false;
    if(n/100 != 0) {
        s += ge[n/100] + " hundred";
        hasHundred = true;
    }
    n %= 100;
    if(n != 0) {
        if (hasHundred) {
            s += " and ";
        }
        if (n < 10) {
            s += ge[n];
        }else if (n < 20) {
            s += ot[n-10];
        }else {
            s += shi[n/10];
            if(n%10){
                s += " " + ge[n%10];
            }
        }
    }
    return s;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) {
            cout << "zero" << endl;
            continue;
        }
        if (n/1000000000 != 0) {
            cout << ge[n/1000000000] << " billion ";
        } 
        n %= 1000000000;
        if(n/1000000 != 0) {
            cout << printfHundred(n/1000000) << " million ";
        }
        n %= 1000000;
        if(n/1000 != 0) {
            cout << printfHundred(n/1000) << " thousand ";
        }
        n %= 1000;
        if(n != 0) {
            cout << printfHundred(n);
        }
        cout << endl;
    }
    return 0;
}