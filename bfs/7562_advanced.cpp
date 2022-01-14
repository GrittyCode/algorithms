#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>


using namespace std;

#define MAX 300

int l;
int iter;

int arr[MAX][MAX];
bool visited[MAX][MAX];


struct Dir
{
    int x; 
    int y;
    
    Dir(int nx, int ny) : x(nx), y(ny) { }
    Dir() { }
};

Dir startDir;
Dir goalDir;

Dir nightDir[8] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};


int bfs()
{
    queue<Dir> q;
    q.push(startDir);
    visited[startDir.x][startDir.y] = true;

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if(x == goalDir.x && y == goalDir.y)
            return arr[x][y];

        for(int i = 0; i < 8; ++i)
        {
            int nx = x + nightDir[i].x;
            int ny = y + nightDir[i].y;

            if(nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;
            
            if(visited[nx][ny] == false)
            {
                arr[nx][ny] = arr[x][y] + 1;
                visited[nx][ny] = true;
                q.push(Dir(nx,ny));
            }
        }
    }

    return -1;
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    cin >> iter;

    for(int i = 0; i < iter; ++i)
    {
        cin >> l;
        
        cin >> startDir.x >> startDir.y;
        cin >> goalDir.x >> goalDir.y;

        cout << bfs() << '\n';
        memset(visited,false,sizeof(visited));
        memset(arr,0,sizeof(arr));
    }


    return 0;
}