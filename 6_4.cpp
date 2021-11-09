#include <bits/stdc++.h>
#define max 100
#define inf 1000000
using namespace std;
class dothi
{
    int n, c[max][max];

public:
    int s, d[max], truoc[max];
    void readdata();
    void init(int s);
    void be(int s);
};
void dothi::readdata()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 0)
                c[i][j] = inf;
        }
}
void dothi::init(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        truoc[i] = s;
    }
    d[s] = 0;
}
void dothi::be(int s)
{   
    init(s);
    for (int k = 1; k <= n - 2; k++)
        for (int v = 1; v <= n; v++)
            if (v != s)
                for (int u = 1; u <= n; u++)
                    if ((c[u][v] != inf) && (d[u] != inf) && (d[v] > d[u] + c[u][v]))
                    {
                        d[v] = d[u] + c[u][v];
                        truoc[v] = u;
                    }
    for (int t = 1; t <= n; t++)
        if (d[t] == inf)
            cout << "\nK/c"<< " " << s << " ->"<< " " << t << " = INF;";
        else
        {
            cout << "\nK/c" << " " << s << " ->" << " " << t << " = " << d[t] << ";";
            cout << "\t" << t << " <- ";
            int truoct = truoc[t];
            while (truoct != s)
            {
                cout << truoct << " <- ";
                truoct = truoc[truoct];
            }
            cout << s;
        }
}
int main()
{
    dothi g;
    g.readdata();
    g.be(g.s);
}