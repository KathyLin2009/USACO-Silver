#include <iostream>
#include <vector>
using namespace std;

vector<int> a(21), used(21, 0);
int ans, n;

void print()
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool isprime(int x)
{
    for(int i = 2; i < x; i++)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int pos)
{
    if(pos == n + 1)
    {
        if(isprime(a[n - 1] + 1))
        {
            print();
        }
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0 && isprime(a[pos - 2] + i + 1))
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
    a[0] = 1;
    used[0] = 1;
    dfs(2);
}

