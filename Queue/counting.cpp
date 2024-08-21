#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> circle;
    for(int i = 1; i < n + 1; i++)
    {
        circle.push(i);
    }

    while(circle.size() > 0)
    {
        for(int i = 1; i < m; i++)
        {
            circle.push(circle.front());
            circle.pop();
        }
        cout << circle.front() << " ";
        circle.pop();
    }
}