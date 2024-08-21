#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > time(n);
    for(int i = 0; i < n; i++)
    {
        cin >> time[i].first;
        time[i].second = i + 1;
    }
    sort(time.begin(), time.end());

    for(int i = 0; i < n; i++)
    {
        cout << time[i].second << " ";
    }
    cout << endl;
    vector<int> wait(n, 0);
    for(int i = 1; i < n; i++)
    {
        wait[i] =  wait[i - 1] + time[i - 1].first;
    }
    double result = 0;
    for(int i = 0; i < n; i++)
    {
        result += wait[i];
    }
   result = result/10;
   cout << fixed << setprecision(2) << result;

    /*bool ten, hundred = false;
    result = (int) (result/n*100 + 0.5);
    int ans = result;
    if(ans%100 == 0)
    {
        hundred = true;
    }
    else if(ans%10 == 0)
    {
        ten = true;
    }
    result = result/100;
    
    if(ten)
    {
        cout << result << 0 << endl;
    }
    else if(hundred)
    {
        cout << result << 00 << endl;
    }
    else
    {
        cout << result << endl;
    }*/

}