#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long N;
    string cows;
    cin >> N >> cows;
    vector<long long> H (N + 1, 0), G (N + 1, 0), pre_H (N + 1, 0), pre_G (N + 1, 0);

    for(long long i = 1; i < N + 1; i++)
    {
        if(cows[i - 1] == 'H')
        {
            H[i] = 1;
        }
        else
        {
            G[i] = 1;
        }
    }
    for(long long i = 1; i < N + 1; i++)
    {
        pre_H[i] = pre_H[i - 1] + H[i];
        pre_G[i] = pre_G[i - 1] + G[i];
    }
    long long result = 0;
    for(long long i = 1; i < N - 1; i++)
    {
        for(long long j = i + 2; j < N + 1; j++)
        {
            if(pre_H[j] - pre_H[i - 1] == 1 ||pre_G[j] - pre_G[i - 1] == 1)
            {
                result++;
            }
        }
        
    }
    cout << result;

}