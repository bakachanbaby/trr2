#include <iostream>
#define MAX 100
#define INF 1e9
using namespace std;
class dothi
{
    int n, c[MAX][MAX];

public:
    bool chuaxet[MAX];
    int s, d[MAX], truoc[MAX];
    void readdata();
    void init(int s);
    void dijkstra(int s);
};
void dothi::readdata()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 0)
                c[i][j] = INF;
        }
}
void dothi::init(int s)
{
    for (int v = 1; v <= n; v++)
    {
        d[v] = c[s][v];
        truoc[v] = s;
        chuaxet[v] = true;
    }
    //co dinh dinh s
    d[s] = 0;
    chuaxet[s] = false;
}
void dothi::dijkstra(int s)
{
    init(s);
    for (int i = 1; i <= n; i++)
    {
        if (chuaxet[i] == true)
        { //Neu con dinh chua co dinh -> moi lan co dinh 1 dinh. Neu chuaxet[i]=false voi moi i -> stop
            int u = 0, du = INF;
            //Tim u voi d[u] min de co dinh
            for (int z = 1; z <= n; z++)
                if ((chuaxet[z] == true) && (d[z] < du))
                {
                    u = z;
                    du = d[z];
                }
            if (u != 0)
            {
                chuaxet[u] = false;
                //Cap nhat nhan tam thoi
                for (int v = 1; v <= n; v++)
                    if ((chuaxet[v] == true) && (d[v] > du + c[u][v]))
                    {
                        d[v] = du + c[u][v];
                        truoc[v] = u;
                    }
            }
            else
            { //ko tim duoc min -> do thi khong lien thong
                chuaxet[i] = false;
            }
            //Cap nhat cac nhan khac
            //Sau khi co dinh duoc 1 dinh thi quay lai tu dau, xet toan bo tap dinh
            i = 0;
        }
    }
    //in kq
    for (int t = 1; t <= n; t++)
        if (d[t] == INF)
        {
            cout << "\nK/c " << s << " -> " << t << " = INF;";
        }
        else
        {
            cout << "\nK/c " << s << " -> " << t << " = " << d[t] << ";";
            ;
            cout << "\t" << t << " <- ";
            int truoctmp = truoc[t];
            while (truoctmp != s)
            {
                cout << truoctmp << " <- ";
                truoctmp = truoc[truoctmp];
            }
            cout << s;
        }
}
int main()
{
    dothi g;
    g.readdata();
    g.dijkstra(g.s);
}