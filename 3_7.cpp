#include <bits/stdc++.h>
using namespace std;
class Dothi
{
    int n;
    int a[20][20];

public:
    bool chuaxet[20];
    void readData();
    void init();
    void DFS(int u);
    void xoadinh(int u);
    bool ktdinhtru(int u);
    void result();
    int demTPLT();
};
void Dothi::readData()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}
void Dothi::init()
{
    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
}
void Dothi::xoadinh(int u)
{
    chuaxet[u] = false;
}
int Dothi::demTPLT()
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (chuaxet[i])
        {
            DFS(i);
            t++;
        }
    }
    return t;
}
bool Dothi::ktdinhtru(int u)
{
    init();
    int s = demTPLT();
    init();
    xoadinh(u);
    int r = demTPLT();
    init();
    if (r > s)
        return true;
    return false;
}

void Dothi::result()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        if (ktdinhtru(i))
            cout << i << " ";
    }
    cout<<endl;
}
void Dothi::DFS(int u)
{
    stack<int> nganxep;
    nganxep.push(u);
    chuaxet[u] = false;
    while (!nganxep.empty())
    {
        int s = nganxep.top();
        nganxep.pop();
        for (int i = 1; i <= n; i++)
        {
            if (a[s][i] == 1 && chuaxet[i] == true)
            {
                chuaxet[i] = false;
                nganxep.push(s);
                nganxep.push(i);
                break;
            }
        }
    }
}
int main()
{
    Dothi G;
    G.readData();
    G.result();
    return 0;
}