#include <iostream>
#include <string>
#define MAX 100 + 1

using namespace std;

string graph[MAX];
bool isCheck[MAX][MAX];

int N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void Dfs(int row, int col, char color)
{
    isCheck[row][col] = true;

    for (int i = 0; i < 4; ++i)
    {
        int Nrow = row + dir[i][0];
        int Ncol = col + dir[i][1];

        if (Nrow >= N || Ncol >= N || Nrow < 0 || Ncol < 0)
            continue;

        if (graph[Nrow][Ncol] == color && !isCheck[Nrow][Ncol])
        {
            Dfs(Nrow, Ncol, color);
        }
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    Init();
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> graph[i];
    }

    int cntforAll = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!isCheck[i][j])
            {
                Dfs(i, j, graph[i][j]);
                cntforAll++;
            }
        }
    }

    fill(isCheck[0],isCheck[MAX],false);

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(graph[i][j] == 'G') graph[i][j] = 'R'; //색약 변환
        }
    }

    int cntforRedWeek = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!isCheck[i][j])
            {
                Dfs(i, j, graph[i][j]);
                cntforRedWeek++;
            }
        }
    }
    

    cout << cntforAll << " " << cntforRedWeek;
    return 0;
}