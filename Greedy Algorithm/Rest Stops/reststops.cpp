#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
struct stop
{
	int loc,tast;
};
stop st[100001];

bool cmp(stop a,stop b)
{
	return a.tast>b.tast;
}

int main() {

	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	int L,n;
	ll rf,rb;
	cin>>L>>n>>rf>>rb;
	for(int i=1;i<=n;i++){
		cin>>st[i].loc>>st[i].tast;
	}
	sort(st+1,st+1+n,cmp);
	ll lastpos=0,ans=0;
	for(int i=1;i<=n;i++){
		if(st[i].loc > lastpos)
        {
            ans += (rf - rb)*(st[i].loc - lastpos)*(st[i].tast);
            lastpos = st[i].loc;
        }
	}
	cout<<ans;
	return 0;
}
