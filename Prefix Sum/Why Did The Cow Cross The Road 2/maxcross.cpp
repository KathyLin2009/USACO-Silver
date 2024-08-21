#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;
    vector<int> lights (N + 1, 0);
    vector<int> prefix (N + 1, 0);
    for(int i = 0; i < B; i++)
    {
        int temp;
        cin >> temp;
        lights[temp] = 1;
    }
    for(int i = 1; i < N + 1; i++)
    {
        prefix[i] = prefix[i - 1] + lights[i];
    }
    int result = INT_MAX;
    for(int i = 1; i < N - K + 2; i++)
    {
        for(int j = i + K - 1; j < N + 1; j++)
        {
            result = min(result, prefix[j] - prefix[i - 1]);
        }
    }

    cout << result;
    
}