#include <bits/stdc++.h>
using namespace std;
class Dothi
{
    int n, s;
    int a[100][100];

public:
    int s1;
    bool chuaxet[100];
    stack<int> T;
    queue<int> B;
    void init();
    void readData();
    void resultDFS();
    void resultBFS();
    void treeDFS(int u);
    void treeGraphDFS(int u);
    void treeBFS(int u);
    void treeGraphBFS(int u);
};
void Dothi::readData()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}
void Dothi::init()
{
    s1 = s;
    while (!T.empty())
    {
        T.pop();
    }
    while (!B.empty())
    {
        B.pop();
    }
    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
}
void Dothi::resultDFS()
{
    cout << "DFS tree" << endl;
    int tg[100], count = 1, size = T.size();
    while (!T.empty())
    {
        tg[count] = T.top();
        T.pop();
        ++count;
    }
    for (int i = size; i >= 1; i -= 2)
    {
        cout << tg[i] << " " << tg[i - 1] << endl;
    }
}
void Dothi::resultBFS()
{
    cout << "BFS tree " << endl;
    while (!B.empty())
    {
        cout << B.front() << " ";
        B.pop();
        cout << B.front() << endl;
        B.pop();
    }
}
void Dothi::treeDFS(int u)
{
    chuaxet[u] = false;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && chuaxet[v] == true)
        {
            T.push(u);
            T.push(v);
            treeDFS(v);
        }
    }
}
void Dothi::treeBFS(int u)
{
    queue<int> hangdoi;
    chuaxet[u] = false;
    hangdoi.push(u);
    while (!hangdoi.empty())
    {
        int t = hangdoi.front();
        hangdoi.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[t][v] == 1 && chuaxet[v] == true)
            {
                chuaxet[v] = false;
                hangdoi.push(v);
                B.push(t);
                B.push(v);
            }
        }
    }
    if (B.size() < n - 1)
        ;
    else
        resultBFS();
}
void Dothi::treeGraphDFS(int u)
{
    init();
    treeDFS(u);
    if (T.size() < n - 1)
        ;
    else
        resultDFS();
}
int main()
{
    Dothi G;
    G.readData();
    G.init();
    G.treeGraphDFS(G.s1);
    G.init();
    G.treeBFS(G.s1);
    return 0;
}