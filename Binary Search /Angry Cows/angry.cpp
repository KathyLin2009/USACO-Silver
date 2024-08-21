#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Run(vector<int> haybales, int R, int K, int N)
{
    int curr = 0;

    for(int i = 0; i < K; i++)
    {
        int temp = haybales[curr] + 2*R;
        if(temp >= haybales[N - 1])
        {
            return true;
        }
        for(int j = curr; j < N - 1; j++)
        {
            if(haybales[j] <= temp && haybales[j + 1] > temp)
            {
                curr = j + 1;
                break;
            }
        }
    }
    return false;
}


int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    vector<int> haybales(N);
    for(int i = 0; i < N; i++)
    {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());
    int l = 1, r = haybales[N - 1];

    while(l <= r)
    {
        int mid = (l + r)/2;
        if(Run(haybales, mid, K, N))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
}