#include <iostream>
#include <queue>
using namespace std;

struct node {
    int v, r;
};

vector<node> graph[5005];
int n, q;
int bfs(int k,int v)
{
	int cnt = 0;
    int vis[5005] = {0};
    queue<int> qu;
    qu.push(v);
    vis[v] = 1;

    while(qu.size() > 0)
    {
        int t = qu.front();
        qu.pop();
        for(node i: graph[t])
        {
            if(vis[i.v] == 0 && i.r >= k)
            {
                qu.push(i.v);
                vis[i.v] = 1;
                cnt++;
            }
        }
    }
    return cnt;

}


int main() {

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin>>n>>q;
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    for(int i = 1; i <=q; i++)
    {
        int k, r;
        cin >> k >> r;
        cout << bfs(k, r) << endl;
    }
	
    return 0;
}
