#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define MAX 51
int T,N,M,K;

int arr[MAX][MAX];
bool visited[MAX][MAX];

int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,1,-1};

int cnt = 0;


void reset()
{   
    cnt = 0;

    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int,int>> q;

    cnt++;
    visited[x][y] = true;
    q.push({x,y});

    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i)
        {
            int ta = a + nx[i];
            int tb = b + ny[i];
            if(ta >= 0 && tb >= 0 && ta < M && tb < N)
            {
                if(arr[ta][tb] == 1 && visited[ta][tb] == false)
                {                  
                    q.push({ta,tb});
                    visited[ta][tb] = true;
                }
            }
        }

    }
}

int main(void)
{
    cin >> T;
    int x,y;

    for(int i = 0; i < T; ++i)
    {
        cin >> M >> N >> K;

        for(int j = 0; j < K; ++j)
        {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        for(int j = 0; j < M; ++j)
        {
            for(int w = 0; w < N; ++w)
            {
                if(arr[j][w] == 1 && visited[j][w] == false)
                {
                    bfs(j,w);
                }
            }
        }       
        cout << cnt << "\n";
        reset();
    }
    

    return 0;

}