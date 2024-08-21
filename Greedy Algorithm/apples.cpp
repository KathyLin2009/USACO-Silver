#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> power;
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    for(int i = 0; i < n; i++)
    {
        int h, p;
        cin >> h >> p;
        if(h <= a + b)
        {
            power.push_back(p);
        }
    }
    sort(power.begin(), power.end());
    int result = 0;
    for(int i: power)
    {
        if(i <= s)
        {
            result++;
            s-=i;
        }
        else
        {
            break;
        }
    }
    cout << result;
}