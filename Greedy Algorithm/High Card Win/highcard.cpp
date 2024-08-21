#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> Elsie, Bessie, visited(2*N+1, 0);

    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        visited[a] = 1;
    }
    for(int i = 1; i < 2*N + 1; i++)
    {
        if(visited[i] == 1)
        {
            Elsie.push_back(i);
        }
        else
        {
            Bessie.push_back(i);
        }
    }
    int e_cur = 0, b_cur = 0, result = 0;
    while(e_cur < N && b_cur < N)
    {
        if(Elsie[e_cur] < Bessie[b_cur])
        {
            e_cur++;
            b_cur++;
            result++;
        }
        else
        {
            b_cur++;
        }
    }
    cout << result;

}