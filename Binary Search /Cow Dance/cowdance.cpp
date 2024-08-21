#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmax;
vector<int> d(10001);

bool check(int k)
{
    vector<int> a (k + 1);

    for(int i = 1; i <= k; i++)
    {
        a[i] = d[i];
    }
    for(int i = k + 1; i <= n; i++)
    {
        sort(a.begin() + 1, a.end());
        a[1] += d[i];
    }
    sort(a.begin() + 1, a.end());
    return a[k] <= tmax;

}

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> tmax;
    for(int i = 1; i < n + 1; i++)
    {
        cin >> d[i];
    }
    int l = 1, r = n, ans = n;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(check(mid) == true)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    
    
}