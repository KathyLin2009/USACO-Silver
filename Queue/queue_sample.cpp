#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;
	q.push(6);
	q.push(3);
	q.push(4);
	q.push(2);
	
	cout<<q.size()<<endl;
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.size()<<endl;
	//±éÀú
	while(q.size()>0)
	{
		cout<<q.front()<<" ";
		q.pop(); 
	} 
//	
	for(int i:q)
	{
		cout<<i<<" ";
	}
	
	return 0;
}
