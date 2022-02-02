#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 400 + 1
#define INF 987654321

using namespace std;

int V, E; //정점의 개수, 간선의 개수

int dist[MAX][MAX];

void FloydWarShall()
{
    vector<int> v;

    for (int k = 1; k <= V; ++k)
    {
        for (int i = 1; i <= V; ++i)
        {
            for (int j = 1; j <= V; ++j)
            {
                if (dist[i][k] == INF || dist[k][j] == INF || i == k)
                {
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j] || dist[i][j] == 0)
                //사이클을 판단해주기 위해 dist[i][j] == 0이라면 i와 j가 같아 자신으로 돌아올때를 판단해주는것.
                {
                    if (i == j) //자기 자신으로 돌아오는 사이클인 경우, vector에 더해준다.
                        v.push_back(dist[i][k] + dist[k][j]);
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    sort(v.begin(), v.end()); //벡터를 오름차순으로 정렬해줘 front()부문이 가장 작은 수가 되도록한다. 

    if (v.empty()) //vector가 비어있다는 것은 사이클이 없다는 뜻
        cout << -1;
    else
        cout << v.front();
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


    //입력부문
    cin >> V >> E;

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //2차원 배열에 간선 등록
        dist[a][b] = c;
    }

    //해결부문

    FloydWarShall();

    return 0;
}