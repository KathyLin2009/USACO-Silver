#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C;

bool Run(vector<int> cows, int mid)
{
    int curr = 0;
    for(int i = 0; i < M; i++)
    {
        for(int j = curr; j < N; j++)
        {
            if(cows[j] <= cows[curr] + mid && cows[j + 1] > cows[curr] + mid || j == N - 1 && cows[j] <= cows[curr] + mid)
            {
                curr = min(C + curr, j + 1);
                break;
            }
        }
        if(curr > N - 1)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> N >> M >> C;
    vector<int> cows (N);
    for(int i = 0; i < N; i++)
    {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    int l = 1, r = cows[N - 1];
    int ans = 1e9;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(Run(cows, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}