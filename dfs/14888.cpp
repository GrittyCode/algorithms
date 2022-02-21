#include<iostream>
#include<queue>

using namespace std;

#define VERTEXMAX 10001

int N,M,V;
bool visited[VERTEXMAX];
int Array[1000 + 1][1000 + 1];
queue<int> q;

void reset()
{
    for(int i = 0; i <= N; ++i)
        visited[i] = false;
}
void dfs(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = true;

    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false && (Array[vertex][i]) == 1)
        {
            dfs(i);
        }
    }
}

void bfs(int vertex)
{
    visited[vertex] = true;
    q.push(vertex); //첫 vertex를 넣어준다.

    while(!q.empty())
    {
        cout << q.front() << " ";

        for(int i = 1; i <= N; ++i)
        {
            if(Array[q.front()][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }

        q.pop();  
    }

}

int main(void)
{
   
    cin >> N >> M >> V;

    int col, row;
    for(int i = 1; i <= M; ++i)
    {
        cin >> col >> row;
        Array[col][row] = 1;
        Array[row][col] = 1;
    }

    dfs(V);

    reset();

    cout << "\n";

    bfs(V);

    return 0;
}
