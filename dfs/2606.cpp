#include<iostream>
#include<queue>

using namespace std;
#define MAXCOM 101

int cnt2 = -1;
int N,M;
int Arr[MAXCOM][MAXCOM];
bool visited[MAXCOM];
queue<int> q;

void bfs()
{
    q.push(1);
    visited[1] = true;

    int cnt = 0;
    while(!q.empty())
    {       
        for(int i = 1; i <= N; ++i)
        {
            if(visited[i] == false && Arr[q.front()][i] == 1)
            {
                visited[i] = true;
                q.push(i);
            }
        }
        cnt++;
        q.pop();
    }
    
    cout << cnt - 1; //본인은 빼줘야한다.
}


void dfs(int vertex)
{
    cnt2++;
    
    for(int i = 2; i <= N; ++i)
    {
        if(visited[i] == false && Arr[vertex][i] == 1)
        {
            visited[i] = true;
            dfs(i);
        }
    }
}
int main(void)
{
    cin >> N;
    cin >> M;

    int col, row;
    for(int i = 1; i <= M; ++i)
    {
        cin >> col >> row;
        Arr[col][row] = 1;
        Arr[row][col] = 1;
    } 

    dfs(1);

    cout << cnt2;

    return 0;
}