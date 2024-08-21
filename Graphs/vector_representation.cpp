#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[10001];

int main()
{
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		graph[x].push_back(y);
        graph[y].push_back(x);

	}
	for(int i=1;i<=n;i++)
	{
		for(int j: graph[i])
        {
            cout << j << " ";
        }
        cout << endl;

	}
    return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
5 1
*/