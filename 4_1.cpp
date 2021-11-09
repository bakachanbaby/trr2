#include <bits/stdc++.h>
using namespace std;
class Dothi
{
    int n, k, a[100][100];

public:
    stack<int> CE;
    void readData();
    void init();
    void result();
    void eulerCycle();
};
void Dothi::readData()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}
void Dothi::result()
{
    while (!CE.empty())
    {
        cout << CE.top() << " ";
        CE.pop();
    }
}
void Dothi::eulerCycle()
{
    stack<int> nganxep;
    nganxep.push(k);
    while (!nganxep.empty())
    {
        int tg = 0;
        int s = nganxep.top();
        for (int i = 1; i <= n; i++)
        {
            if (a[s][i] == 1)
            {
                nganxep.push(i);
                a[s][i] = a[i][s] = 0;
                tg = 1;
                break;
            }
        }
        if (tg == 0)
        {
            CE.push(s);
            nganxep.pop();
        }
    }
}
int main()
{
    Dothi G;
    G.readData();
    G.eulerCycle();
    G.result();
}