#include <iostream>
using namespace std;

int n, a[1001], prefix[1001];

int main()
{

	cin>>n;
    int ans = -1e9;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}

    for(int i = 1; i <=n; i++)
    {
        for(int j = i; j <=n; j++)
        {
            ans = max(prefix[j] - prefix[i - 1], ans);
        }
    }

	cout << ans << endl;
	
	return 0;	
}

//5
//1 -2 3 1 -4