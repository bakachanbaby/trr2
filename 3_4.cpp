#include <bits/stdc++.h>
using namespace std;

class Dothi{
    int n, a[100][100];
    public:
    bool chuaxet[100];
    void readData();
    void init();
    int demTPLT();
    void DFS(int u);
    void kq();
};
void Dothi::readData(){
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];
    }
}
void Dothi::init(){
    for(int i = 1; i < n; i++)
        chuaxet[i] = true;
}
int Dothi::demTPLT(){
    int dem = 0;
    init();
    for(int i = 1; i <= n; i++)
    {
        if(chuaxet[i])
        {
            DFS(i);
            dem++;
        }
    }
    return dem;
}
void Dothi::DFS(int u){
    stack<int> s;
    chuaxet[u] = false;
    s.push(u);
    while(s.size())
    {
        int k = s.top();
        s.pop();
        for(int i = 1; i <= n; i++)
        {
            if(a[k][i] && chuaxet[i])
            {
                chuaxet[i] = false;
                s.push(k);
                s.push(i);
                break;
            }
        }
    }
}
void Dothi::kq(){
    cout<<demTPLT();
}
int main(){
    Dothi g;
    g.readData();
    g.kq();
    return 0;
}
































