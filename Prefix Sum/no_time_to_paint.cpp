#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    string paint;
    cin >> N >> Q >> paint;
    vector<int> prefix (N + 1, 0), suffix (N + 2, 0), used (26, 0), used2 (26, 0);
    paint = ' ' + paint;
    for(int i = 1; i < N + 1; i++)
    {
        prefix[i] = prefix[i - 1];
        if(used[paint[i] - 'A'] == 0)
        {
            used[paint[i] - 'A'] = 1;
            prefix[i]++;
        }
        else
        {
            for(int j = i - 1; j >= 1; j--)
            {
                if(paint[j] < paint[i])
                {
                    prefix[i]++;
                    break;
                }
                else if(paint[j] == paint[i])
                {
                    break;
                }
            }
        }
    }
    for(int i = N; i >= 1; i--)
    {
        suffix[i] = suffix[i + 1];
        if(used2[paint[i] - 'A'] == 0)
        {
            used2[paint[i] - 'A'] = 1;
            suffix[i]++;
        }
        else
        {
            for(int j = i + 1; j < N + 1; j++)
            {
                if(paint[j] < paint[i])
                {
                    suffix[i]++;
                    break;
                }
                else if(paint[j] == paint[i])
                {
                    break;
                }
            }
        }
    }
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[a - 1] + suffix[b + 1] << endl;
    }
}