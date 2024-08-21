#include <iostream>
#include <algorithm>
using namespace std;

int n,m,t,ex,ey,minn=1e9;
int ans = 0;
int maze[51][51];//标记一个位置是不是障碍物
bool visited[51][51];//标记一个位置是否走过
// 方向数组
int dir[4][2]= { {0,1},  //向右走
	{1,0},    //向下走
	{0,-1},   //向左1走
	{-1,0}    //向上走
} ;

void dfs(int x,int y,int step) {
	// 判断是否到终点
	//todo
	if(x == ex && y == ey)
    {
        minn = min(step, minn);
        return;
    }
	// 剪枝
	//todo
	if(step > minn)
    {
        return;
    }
	
	// 枚举每一个方向
	for(int i=0; i<4; i++) {
		//计算下一个点的坐标
		//todo
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
		
		//越界、走过、障碍物都不能走
		if(nx < 1 || ny < 1 || nx > n || ny > m || maze[nx][ny] == 1 || visited[nx][ny] == 1)
        {
            continue;
        }
		//能走
        visited[nx][ny] = 1;
        dfs(nx, ny, step + 1);
        visited[nx][ny] = 0;
		
	}

}

int main() {

	int i,j,startx,starty;
	cin>>n>>m;
	//读入迷宫
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			cin>>maze[i][j];

	cin>>startx>>starty>>ex>>ey;
	
	//todo
	visited[startx][starty] = 1;
    dfs(startx, starty, 0);
	
	cout<<minn<<endl;
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
