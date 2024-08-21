#include <iostream>
#include <vector>
using namespace std;
int n, m, ans = 1e9;
vector<int> temp (1000005), conditioner(11);
vector<int> a(11), b(11), p(11), cost(11);

void check()
{
    vector<int> cnt(1000005, 0);
    int sum = 0;
    for(int i = 1; i <= m; i++)
    {
        if(conditioner[i] == 1)
        {
            for(int j = a[i]; j <= b[i]; j++)
            {
                conditioner[j] +=p[i];
            }
            sum+=cost[i];
        }
    }
    for(int i = 1; i <= 1e6; i++)
    {
        if(cnt[i] < temp[i])
        {
            return;
        }
    }
    ans = min(ans, sum);
}

void dfs(int pos)
{
    if(pos == m + 1)
    {
        check();
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        conditioner[pos] = i;
        dfs(pos + 1);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int s, t, c;
        cin >> s >> t >> c;
        for(int j = s; j <=t; j++)
        {
            temp[j]+=c;
        }
    }
    for(int i = 1; i <=m; i++)
    {
        cin >> a[i] >> b[i] >> p[i] >> cost[i];
    }
    dfs(1);
    cout << ans;
}