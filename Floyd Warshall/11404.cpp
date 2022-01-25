#include <iostream>
#include<algorithm>

using namespace std;

#define MAX 200 + 1
#define INF 987654321

int n, m; // n 정점 m 간선

int dist[MAX][MAX]; // 1번 정점에서 200번정점까지 ~ 200정점에서 1정점까지등을 저장해준다

void solve()
{
    // k가 거쳐가는 정점을 표현한다.
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i) //출발 정점 표현
        {
            for (int j = 1; j <= n; ++j) // 도착 정점 표현
            {
                dist[i][j] = min(dist[i][j] , (dist[i][k] + dist[k][j]));              
            }
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
    
    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) //정점들간의 거리 간선 초기화
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    solve();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}