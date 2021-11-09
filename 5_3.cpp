#include <iostream>
#define MAX 100
using namespace std;
struct edg
{
    int dau, cuoi, h;
};
class dothi
{
    int n, a[MAX][MAX], ne, atree[MAX][MAX];
    edg graph[MAX], tree[MAX];

public:
    int s;
    bool chuaxet[MAX];
    void readdata();
    void init();
    void dfstree(int u);
    void bubblesort();
    void prim(int s);
};
void dothi::readdata()
{
    cin >> n >> s;
    ne = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if ((a[i][j] > 0) && (i < j))
            {
                ne++;
                graph[ne].dau = i;
                graph[ne].cuoi = j;
                graph[ne].h = a[i][j];
            }
        }
}
void dothi::init()
{
    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
}
void dothi::dfstree(int u)
{ //Duyet dfs tren cay
    chuaxet[u] = false;
    for (int i = 1; i <= n; i++)
        if ((atree[u][i] == 1) && (chuaxet[i] == true))
            dfstree(i);
}
void dothi::bubblesort()
{
    for (int i = 1; i < ne; i++)
        for (int j = ne; j >= i + 1; j--)
            if (graph[j].h < graph[j - 1].h)
                swap(graph[j], graph[j - 1]);
}
void dothi::prim(int s)
{
    int dH = 0;
    int net = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            atree[i][j] = 0;
    bubblesort();
    while (net != n - 1)
    {
        for (int i = 1; i <= ne; i++)
        { //moi lan se lay 1 canh be nhat co 1 dinh thuoc VH, 1 dinh thuoc V
            init();
            dfstree(s); //cac dinh thuoc VH deu bi doi chuaxet[] tu true -> false
            int dau = graph[i].dau, cuoi = graph[i].cuoi;
            //if(((chuaxet[dau]&&chuaxet[cuoi])==false)&&((chuaxet[dau]||chuaxet[cuoi])==true))
            if (chuaxet[dau] != chuaxet[cuoi])
            { //canh i thoa man
                net++;
                tree[net].dau = dau;
                tree[net].cuoi = cuoi;
                dH += graph[i].h;
                atree[dau][cuoi] = atree[cuoi][dau] = 1;
                break;
            }
        }
    }
    cout << "dH = " << dH << endl;
    for (int i = 1; i <= net; i++)
        cout << tree[i].dau << "   " << tree[i].cuoi << endl;
}
int main()
{
    dothi g;
    g.readdata();
    g.prim(g.s);
}
