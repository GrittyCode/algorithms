#include <iostream>
#include <queue>
#include<algorithm>
#include<string>

using namespace std;

#define MAXN 26

string arr[MAXN];
bool visited[MAXN][MAXN];
int N;

int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,1,-1};

int cnt;
vector<int> result;
int idx = 0;
queue<pair<int,int>> q;

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push({x,y});
    cnt++;

    int tx, ty;
    while(!q.empty())
    {        
        //뽑아 준 후 가장 먼저 들어온 원소의 연관 노드를 찾기위해 x y 값을 초기화
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i)
        {
           tx = a + nx[i];
           ty = b + ny[i];
           if(tx >= 0 && tx < N && ty >= 0 && ty < N && visited[tx][ty] == false && arr[tx][ty] == '1')
           {
               q.push({tx,ty});
               visited[tx][ty] = true;
               cnt++;
           }
        }
        
    }

    idx++; //집합 번호를 옮겨주기 위해
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
       cin >> arr[i];
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(visited[i][j] == false && arr[i][j] == '1')
            {
                cnt = 0;
                bfs(i,j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(),result.end());

    cout << result.size() << "\n";

    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "\n";
    }

    return 0;
}



