#include <bits/stdc++.h>
using namespace std;
struct edg
{
    int n1, n2, h, id;
};
class Dothi
{
    int n, a[100][100], atree[100][100], ne, dh, net;
    edg edglst[100], edgtree[100];

public:
    bool chuaxet[100];
    void readData();
    void init();
    void DFS(int u);
    void bobbleSort();
    void kruskal();
    void result();
};
void Dothi::readData()
{
    cin >> n;
    ne = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] > 0 && i < j)
            {
                ++ne;
                edglst[ne].h = a[i][j];
                edglst[ne].n1 = i;
                edglst[ne].n2 = j;
                edglst[ne].id = ne;
            }
        }
}
void Dothi::init()
{
    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
}
void Dothi::DFS(int u)
{
    chuaxet[u] = false;
    for (int i = 1; i <= n; i++)
        if (atree[u][i] == 1 && chuaxet[i] == true)
            DFS(i);
}
void Dothi::bobbleSort()
{
    for (int i = 1; i <= ne; i++)
    {
        for (int j = ne; j >= i; j--)
        {
            if (edglst[j].h < edglst[j - 1].h)
            {
                edg tg = edglst[j];
                edglst[j] = edglst[j - 1];
                edglst[j - 1] = tg;
            }
        }
    }
}
void Dothi::kruskal()
{
    int net = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            atree[i][j] = 0;
    }
    dh = 0;
    bobbleSort();
    for (int i = 1; i <= ne; i++)
    {
        int n1 = edglst[i].n1;
        int n2 = edglst[i].n2;
        init();
        DFS(n1);
        if (chuaxet[n2] == true)
        {
            ++net;
            dh += edglst[i].h;
            edgtree[net].n1 = n1;
            edgtree[net].n2 = n2;
            atree[n1][n2] = atree[n2][n1] = 1;
        }
    }
    if (net == n - 1)
    {
        cout << "DH= " << dh << endl;
        for (int i = 1; i <= net; i++)
            cout << edgtree[i].n1 << " " << edgtree[i].n2 << endl;
    }
}
int main()
{
    Dothi G;
    G.readData();
    G.kruskal();
    return 0;
}