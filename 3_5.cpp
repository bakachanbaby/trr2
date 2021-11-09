#include<bits/stdc++.h>
using namespace std;
class Dothi{
    int n,s,t;
    int a[100][100];
    public:
        bool chuaxet[100];
        int b[100],count;
        void readData();
        void init();
        void result();
        void BFS(int u,int v);
        void DFS(int u,int v);
};
void Dothi::readData(){
    cin>>n;
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
}
void Dothi::init(){
    count=1;
    for(int i=1;i<=n;i++)
        chuaxet[i]=true;
}
void Dothi::BFS(int u,int v){
    queue<int> hangdoi;
    b[count]=v;
    hangdoi.push(v);
    chuaxet[v]=false;
    while(!hangdoi.empty()){
        int x=hangdoi.front();
        hangdoi.pop();
        for(int i=u;i>=v;i--){
            if(a[x][i]==1 && chuaxet[i]==true){
                chuaxet[i]=false;
                hangdoi.push(i);
                ++count;
                b[count]=hangdoi.front();
                break;
            }
        }
    }
}
void Dothi::DFS(int u,int v){
    stack<int> nganxep;
    b[count]=v;
    nganxep.push(v);
    chuaxet[v]=false;
    while(!nganxep.empty()){
        int x=nganxep.top();
        nganxep.pop();
        for(int i=v;i<=u;i++){
            if(a[x][i]==1 && chuaxet[i]==true && i>x){
                chuaxet[i]=false;
                ++count;
                b[count]=i;
                nganxep.push(x);
                nganxep.push(i);
                break;
            }
        }
    }
}
void Dothi::result(){
    DFS(t,s);
    if(b[1]==s && b[count]==t){
        cout<<"DFS path: ";
        for(int i=count;i>=1;i--)
            cout<<b[i]<<" ";
        cout<<endl;
    }
    else cout<<"no path: "<<endl;
    init();
    BFS(t,s);
    if(b[1]==s &&b[count]==t){
        cout<<" BFS path: ";
        for(int i=count;i>=1;i--)
            cout<<b[i]<<" ";
        cout<<endl;
    }
    else cout<<"no path: "<<endl;
}
 
int main(){
    Dothi G;
    G.readData();
    G.init();
    G.result();
    return 0;
}