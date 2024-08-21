#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int degree[100001];

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n; 
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
    }
    sort(degree+ 1, degree + 1 + n);
    cout << degree[n]+1;
    return 0;

}