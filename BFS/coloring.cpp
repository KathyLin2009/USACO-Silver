#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

queue<node> q;
int a[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;

void bfs(int sx,int sy)
{
    q.push({sx, sy});
    a[sx][sy] = 2;

    while(q.size() > 0)
    {
        node t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = t.x + dir[i][0];
            int ny = t.y + dir[i][1];
            if(nx < 1 || ny < 1 || nx > n || ny > n || a[nx][ny] != 0)
            {
                continue;
            }
            q.push({nx, ny});
            a[nx][ny] = 2;
            
        }
    }

}


int main() {

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if((i == 1 || i == n || j == 1 || j == n) && a[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                cout << 1 << " ";
            }
            else if(a[i][j] == 2)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

