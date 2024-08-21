#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

queue<node> q;
int a[51][51];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // 方向数组 
bool visited[51][51];
int n, m, sx, sy, ex, ey;
void bfs(int sx,int sy)
{
	//todo
    q.push({sx, sy, 0});
    visited[sx][sy] = 1;

    while(q.size() > 0)
    {
        node t = q.front();
        q.pop();
        if(t.x == ex && t.y == ey)
        {
            cout << t.step;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = t.x + dir[i][0];
            int ny = t.y +dir[i][1];
            if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == 1 || visited[nx][ny == 1])
            {
                continue;
            }
            q.push({nx, ny, t.step + 1});
            visited[nx][ny] = 1;


        }
    }

}


int main() {

    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>a[i][j];
        }
    }

    cin>>sx>>sy>>ex>>ey;
	
	//todo
	bfs(sx,sy);
	
    return 0;
}

/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3

输出
7
*/ 