#include <iostream>
#include <queue>
using namespace std;

priority_queue <int,vector<int>,greater<int> > q;
int main() {
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a;
		q.push(a);
	}
	for(int i=m+1;i<=n;i++){
		cin>>a;
        q.push(a + q.top());
        q.pop();
	}
    while(q.size() > 1)
    {
        q.pop();
    }
    cout << q.top();

	return 0;
}
