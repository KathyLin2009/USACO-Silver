#include <iostream>
#include <vector>
using namespace std;

vector<int> a(11), b(11), c(11), d(11);
int n = 8, cnt = 0;

void print()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(a[i] == j)
            {
                cout << "Q";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}


void dfs(int pos)
{
    if(pos == n + 1)
    {
        cnt++;
        cout << cnt << endl;
        print();
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(b[i] == 0 && c[pos - 1 + i] == 0 && d[pos - i + 7] == 0)
        {
            a[pos - 1] = i;
            b[i] = 1;
            c[pos -1 + i] = 1;
            d[pos - i + 7] = 1;
            dfs(pos + 1);
            b[i] = 0;
            c[pos - 1 + i] = 0;
            d[pos - i + 7] = 0;
        }
    }
}

int main()
{
    dfs(1);
}

