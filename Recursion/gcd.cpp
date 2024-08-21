#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c = a%b;
    if(c == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, c);
    }
}

int main()
{
    cout << gcd(24, 18);
}