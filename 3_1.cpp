#include <bits/stdc++.h>
using namespace std;
const int mx = 105;
class Dothi
{
private:
    int n, a[mx][mx];
public:
    bool chuaxet[mx];
    void nhap();
    void check();
    void dfs(int u);
};
void Dothi::nhap(){
    cout<<"Nhap so dinh: n = ";
    cin>>n;
    cout<<"Nhap ma tran ke: \n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin>> a[i][j];
    }
}
void Dothi::check(){
    for(int i = 1; i <= n; i++)
        chuaxet[i] = true;
}
void Dothi::dfs(int u){
    cout<<" "<<u;
    chuaxet[u]=false;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] && chuaxet[v])
        dfs(v);
    }
}
int main(){
    Dothi g;
    g.nhap();
    g.check();
    g.dfs(1);
}
