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
    void recursiveDFS(int u);
    void result();  
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
void Dothi::recursiveDFS(int u)
{
    stack<int> nganxep;
    chuaxet[u] = false;
    nganxep.push(u);
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
void Dothi::result()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                a[i][j] = 0;
                recursiveDFS(1);
                for (int k = 1; k <= n; k++)
                {
                    if (chuaxet[k] == true)
                    {
                        cout << i << " " << j << endl;
                        break;
                    }
                }
                a[i][j] = 1;
                init();
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