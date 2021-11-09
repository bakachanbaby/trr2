#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, v, l, r, x, y, chuaxet[1005], b[1005], dem;
vector <int> ve[1005];

void nhap(){
    cin>>v>>n>>l>>r;
    for(ll i = 0; i < n; i++)
    {
        cin>>x>>y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
}
void check(){
    for(ll i = 0; i < 1005; i++)
        b[i] = 0;
    for(ll i = 0; i < 1005; i++)
        chuaxet[i] = 0;
}
void DFS(ll u, ll v){
    if(chuaxet[v]) 
    return;
    chuaxet[u] = 1;
    for(int i = 0; i < ve[u].size(); i++)
    {
        if(!chuaxet[ve[u][i]])
        {
            b[ve[u][i]] = u;
            DFS(ve[u][i], v);
        }
    }
}
void in(int u, int v){
    DFS(v, u);
    if(!chuaxet[v])
    {
        cout<<-1<<endl;
        return;
    }
    vector <int> a;
    while (u != v)
    {
        a.push_back(u);
        u = b[u];
    }
    a.push_back(v);
    for(int i = a.size()-1; i >= 0; i--)
        cout<<a[i]<<" ";
    cout<<endl;
    
}
int main(){
    cin>>t;
    while (t--)
    {
        for(int i = 0; i < 1005; i++)
            ve[i].clear();
        nhap();
        check();
        in(r, l);
    }
    return 0;
}