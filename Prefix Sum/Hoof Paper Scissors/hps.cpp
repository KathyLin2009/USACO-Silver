#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N;
    cin >> N;
    vector<char> moves (N + 1);
    for(int i = 1; i < N + 1; i++)
    {
        cin >> moves[i];
    }
    vector<int> preH (N + 1, 0), preP (N + 1, 0), preS (N + 1, 0);

    for(int i = 1; i < N + 1; i++)
    {
        preH[i] = preH[i - 1];
        preP[i] = preP[i - 1];
        preS[i] = preS[i - 1];
        if(moves[i] == 'H')
        {
            preH[i]++;
        }
        else if(moves[i] == 'P')
        {
            preP[i]++;
        }
        else
        {
            preS[i]++;
        }
    }
    int result = 0;
    for(int i = 1; i < N + 1; i++)
    {
        result = max(max(max(preH[i], preP[i]), preS[i]) + max(max(preH[N] - preH[i], preP[N] - preP[i]), preS[N] - preS[i]), result);
    }
    cout << result;

}