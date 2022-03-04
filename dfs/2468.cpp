#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100 + 1

using namespace std;

int N;
int graph[MAX][MAX];
bool safeVec[MAX][MAX];

int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int row, int col)
{
    safeVec[row][col] = false; //안전함 확인했으니 무시하기 위해 침수된걸로 취급

    for(int i = 0; i < 4; ++i)
    {
        int Nrow = row + dir[i][0];
        int Ncol = col + dir[i][1];

        if(Nrow < 0 || Ncol < 0 || Nrow >= N || Ncol >= N) continue;

        if(safeVec[Nrow][Ncol] == true)
        {
            dfs(Nrow,Ncol);
        }
    }
}

void safeAreaCheck(int deep)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; ++j)
        {
            if (graph[i][j] > deep)
            {
                safeVec[i][j] = true; //안전함
            }
        }
    }
}

int main()
{
    Init();

    cin >> N;

    int numMax = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
            numMax = max(graph[i][j], numMax);
        }
    }

    int maxArea = 0;

    for (int w = 0; w < numMax; ++w)
    {
        int tmp = 0;
        safeAreaCheck(w);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; ++j)
            {
                if(safeVec[i][j] == true)
                {
                    dfs(i,j);
                    tmp++;
                }
            }
        }
        maxArea = max(maxArea, tmp);
    }
    cout << maxArea;

    return 0;
}