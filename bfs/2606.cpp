#include<iostream>
#include<queue>

using namespace std;
#define MAXCOM 101


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
    
    cout << cnt - 1;
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

    bfs();

    return 0;
}