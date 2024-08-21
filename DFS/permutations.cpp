#include <iostream>
#include <vector>
using namespace std;

vector<int> a(11), used(11, 0);
int ans, n;

void dfs(int pos)
{
    if(pos == n + 1)
    {
        ans++;
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            a[pos - 1] = i + 1;
            dfs(pos + 1);
            used[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans;
}

