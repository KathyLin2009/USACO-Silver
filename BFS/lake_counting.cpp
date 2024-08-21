#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

queue<node> q;
char a[101][101];
int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
bool visited[101][101];
int n, m, ans = 0;

void bfs(int sx,int sy)
{
    q.push({sx, sy});
    visited[sx][sy] = 1;

    while(q.size() > 0)
    {
        node t = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = t.x + dir[i][0];
            int ny = t.y + dir[i][1];
            if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == '.' || visited[nx][ny]==1)
            {
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = 1;
            
        }
    }

}


int main() {

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 'W' && visited[i][j] == 0)
            {
                bfs(i, j);
                ans++;

            }
        }
    }
	cout << ans;
    return 0;
}

