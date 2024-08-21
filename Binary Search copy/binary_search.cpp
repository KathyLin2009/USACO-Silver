#include <iostream>
using namespace std;

int a[12]={0 , 5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};

int main()
{
	int x; //21
	cin >> x;
	int l = 1, r = 11;
    while(l <= r)
    {
        int mid = (r + l)/2;
        if(a[mid] == x)
        {
            cout << mid;
            break;
        }
        else if(a[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(l > r)
    {
        cout << "Not Found";
    }
	return 0;	
}
/*
teacher

int n, tmax;
int t[10001];

bool check(int k) {

}

int main() {
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>tmax;
	for(int i=1; i<=n; i++) {
		cin>>t[i];
	}
	int left = 1, right = n, ans = n;
	while(left<=right) {
		int mid = (left+right)/2;
		//todo
	}
	cout<<ans<<endl;

	return 0;
}*/