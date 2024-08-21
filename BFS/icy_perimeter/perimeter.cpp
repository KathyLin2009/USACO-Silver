#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

queue<node> q;
char a[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int visited[1001][1001];
int n, max_area = 0, min_p = 1e9;

void bfs(int sx,int sy)
{
    q.push({sx, sy});
    visited[sx][sy] = 1;
    int area = 1, p = 0;

    while(q.size() > 0)
    {
        node t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = t.x + dir[i][0];
            int ny = t.y + dir[i][1];

            if(nx < 1 || ny < 1 || nx > n || ny > n || a[nx][ny] == '.')
            {
                p++;
                continue;
            }
            if(visited[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                area++;
            }
 
        }
    }
    if(area > max_area || (max_area == area && p < min_p))
    {
        max_area = area;
        min_p = p;
    }

}


int main() 
{

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == '#' && visited[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }

    cout << max_area << " " << min_p;
    
    return 0;
}

