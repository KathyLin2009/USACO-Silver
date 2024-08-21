#include <iostream>
#include <queue>
using namespace std;
int indegree[100005],to[100005];
int n, cnt;
int main() {

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>to[i];
		indegree[to[i]]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0)
        {
            q.push(i);
            cnt++;
        }
	}
	while(q.size() > 0)
    {
        int u = q.front();
        q.pop();
        int v = to[u];
        indegree[v]--;
        if(indegree[v] == 0)
        {
            q.push(v);
            cnt++;
        }
    }
    cout << n - cnt;
	return 0;
}
