#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

//9
//6 3 1 7 5 8 9 2 4

int main() {
	
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
  		int t;
  		cin >> t;
  		q.push(t);
	}
	
	while(q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
        int a = q.front();
        q.pop();
        q.push(a);
    }

	return 0;
}
