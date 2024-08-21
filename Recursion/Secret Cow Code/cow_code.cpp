#include <iostream>
#include <string>
using namespace std;

string s;
long long n;

char find(long long n)
{
    long long len = s.size();
    if(n <= len)
    {
        return s[n - 1];
    }
    while(len*2 < n)
    {
        len = len*2;
    }
    long long right = n - len;
    if(right == 1)
    {
        return find(n - 1);
    }
    else
    {
        return find(right - 1);
    }
}

int main()
{
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    cin >> s >> n;
    cout << find(n);
}
