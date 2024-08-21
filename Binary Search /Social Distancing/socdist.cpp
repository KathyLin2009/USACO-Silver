#include <iostream>
#include <vector>
using namespace std;

int N, M;

int Run(vector<pair<int, int> > intervals, D)
{
    int curr = intervals[0].first;
    int place = 0;
    for(int i = 0; i < N - 1; i++)
    {
        if(intervals[place].second >= curr += D)
        {
            curr += D;
        }
        else
        {
            place++;
            curr = intervals[place].first;
        }
    }


}

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> N >> M;
    vector<pair<int, int> > intervals (M);
    for(int i = 0; i < M; i++)
    {
        cin >> intervals[i].first;
        cin >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    int l = 1, r = intervals[N - 1].second;
    while(l <= r)
    {
        int mid = (l + r)/2;
        
        if(Run(intervals, mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}