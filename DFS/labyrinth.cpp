#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,t,ex,ey;
vector<vector<char> > maze;
bool visited[51][51];
bool works;
// 方向数组
int dir[4][2]= { {0,1},  //向右走
	{1,0},    //向下走
	{0,-1},   //向左1走
	{-1,0}    //向上走
} ;

void dfs(int x,int y,int step) {

	if(x == ex && y == ey)
    {
        works = true;
        return;
    }


	for(int i=0; i<4; i++) {

        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
		

		if(nx < 1 || ny < 1 || nx > n || ny > n || maze[nx][ny] == '#' || visited[nx][ny] == 1)
        {
            continue;
        }

        visited[nx][ny] = 1;
        dfs(nx, ny, step + 1);
        visited[nx][ny] = 0;
		
	}

}

int main() {

    int startx,starty;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        works = false;
        vector<char> stuff(n + 1);
        maze.push_back(stuff);
        for(int k = 1; k <= n; k++)
        {
            vector<char> temp(n + 1);
            for(int j = 1; j<=n; j++)
            {
                cin >> temp[j];
            }
            maze.push_back(temp);
        }
        cin>>startx>>starty>>ex>>ey;
        startx++;
        starty++;
        ex++;
        ey++;
        
        visited[startx][starty] = 1;
        dfs(startx, starty, 0);
        if(works == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
	
	
	return 0;
}


