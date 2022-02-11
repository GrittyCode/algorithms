#include<iostream>
#include<queue>
#define MAX 50 + 1
using namespace std;

int w,h;

int dir[8][2] = {{-1,0},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{1,1},{1,-1}};
int graph[MAX][MAX];

void dfs(int row, int col)
{
    graph[row][col] = 0;

    for(int i = 0; i < 8; ++i)
    {
        int Nrow = row + dir[i][0];
        int Ncol = col + dir[i][1];

        if(Nrow >= h || Ncol >= w || Nrow < 0 || Ncol < 0) continue;

        if(graph[Nrow][Ncol] == 1)
        {
            dfs(Nrow,Ncol);
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


    while (1)
    {
        int cnt = 0;

        cin >> w >> h;

        if(w == 0 && h == 0)
            break;
        
        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                cin >> graph[i][j];
            }
        }

        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                if(graph[i][j] == 1)
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout << cnt << '\n'; 
    }
    
    return 0;
}