#include <iostream>

#include <stack>

#define MAX 100

using namespace std;

class Dothi
{

    int n;

    int A[MAX][MAX];

public:
    bool chuaxet[MAX];

    void readdata();

    void init();

    void loopDFS(int u);
};

void Dothi::readdata()
{

    cout << "\nNhap so dinh cua do thi: n = ";
    cin >> n;

    cout << "\nNhap ma tran ke cua do thi:\n";

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= n; j++)
            cin >> A[i][j];
}

void Dothi::init()
{

    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
}

void Dothi::loopDFS(int u)
{

    //Khoi tao

    stack<int> nganxep;

    cout << " " << u;

    chuaxet[u] = false;

    nganxep.push(u);

    //Lap

    while (!nganxep.empty())
    {

        int s = nganxep.top();

        nganxep.pop();

        for (int t = 1; t <= n; t++)

            if ((A[s][t] == 1) && (chuaxet[t] == true))
            {

                cout << " " << t;

                chuaxet[t] = false;

                nganxep.push(s);

                nganxep.push(t);

                break;
            }
    }

    //Tra lai ket qua
}

int main()
{

    Dothi G;

    G.readdata();

    G.init();

    //cout << "\nKet qua duyet DFS ngan xep: ";

    G.loopDFS(1);
}