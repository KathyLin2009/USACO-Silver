//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    vector<int> H (N + 1, 0), G (N + 1, 0), J (N + 1, 0), pre_H (N + 1, 0), pre_G (N + 1, 0), pre_J (N + 1, 0);
    for(int i = 1; i < N + 1; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 1)
        {
            H[i] = 1;
        }
        else if(temp == 2)
        {
            G[i] = 1;
        }
        else
        {
            J[i] = 1;
        }
    }
    for(int i = 1; i < N + 1; i++)
    {
        pre_H[i] = pre_H[i - 1] + H[i];
        pre_G[i] = pre_G[i - 1] + G[i];
        pre_J[i] = pre_J[i - 1] + J[i];
    }
    /*for(int i = 0; i < N + 1; i++)
    {
        cout << pre_H[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N + 1; i++)
    {
        cout << pre_G[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N + 1; i++)
    {
        cout << pre_J[i] << " ";
    }
    cout << endl;*/
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << pre_H[b] - pre_H[a - 1] << " " << pre_G[b] - pre_G[a - 1] << " " << pre_J[b] - pre_J[a - 1] << endl;

    }

}
