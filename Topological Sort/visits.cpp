#include <iostream>
#include <queue>
using namespace std;
int indegree[100005],to[100005], cycle[100005], moo[1000005];
int n, cnt;
long long sum = 0;
int main() {
    
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>to[i] >> moo[i];
        sum+= moo[i];
		indegree[to[i]]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0)
        {
            q.push(i);
            cycle[i] = 1;
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
            cycle[v] = 1; 
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++)
    {
        if(cycle[i] == 0)
        {
            int minn = 1e9;
            int j = i;
            while(cycle[j] == 0)
            {
                cycle[j] = 1;
                minn = min(minn, moo[j]);
                j = to[j];
            }
            sum -= minn;

        }
    }
    cout << sum;
	return 0;
}
