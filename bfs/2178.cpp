#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 101

int N, M;
string Array[MAX];
bool visited[MAX][MAX];
int MoveCnt[MAX][MAX];

int x[4]{1, -1, 0, 0};
int y[4]{0, 0, 1, -1};

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    MoveCnt[0][0] = 1;
    
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i)
        {
            int nx = a + x[i];
            int ny = b + y[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) //범위를 넘는다면 다음 for문 진행으로 넘어간다. 
                continue;
            
            if(Array[nx][ny] == '1' && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx,ny});
                MoveCnt[nx][ny] =  MoveCnt[a][b] + 1;
            }
            
        }
    }
    
    cout << MoveCnt[N - 1][M - 1] << "\n";
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    bfs(); //좌표 1, 1이 고정이고 한 번은 이미 갔기 때문에 1

    return 0;
}