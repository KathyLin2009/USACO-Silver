#include <iostream>
using namespace std;
int f[5005];
int find(int x)//找祖先
{
    if(x==f[x])
    {
        return x;
    }
    return f[x] = find(f[x]);
}
void merge(int u,int v)
{
    int fu = find(u);
    int fv = find(v);
    if(fu != fv)
    {
        f[fu] = fv;
    }
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i = 1; i <=n; i++)
    {
        f[i] = i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        merge(a, b);
    }
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a) == find(b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
   
    return 0;
}