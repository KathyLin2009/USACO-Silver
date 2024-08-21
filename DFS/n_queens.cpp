#include <iostream>
#include <vector>
using namespace std;

vector<int> a(11), b(11), c(11), d(11);
int n, cnt = 0, num = 0;

void print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] == j && num < 3)
            {
                cout << j + 1 << " ";
            }
            else
            {
                
            }
        }
    }
    num++;
    if(num < 4)
    {
        cout << endl;
    }
    
}


void dfs(int pos)
{
    if(pos == n + 1)
    {
        cnt++;
        //cout << cnt << endl;
        print();
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(b[i] == 0 && c[pos - 1 + i] == 0 && d[pos - i + n - 1] == 0)
        {
            a[pos - 1] = i;
            b[i] = 1;
            c[pos - 1 + i] = 1;
            d[pos - i + n - 1] = 1;
            dfs(pos + 1);
            b[i] = 0;
            c[pos - 1 + i] = 0;
            d[pos - i + n - 1] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << num;
}

