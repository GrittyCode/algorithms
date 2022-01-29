#include <iostream>
#include <vector>

using namespace std;

#define MAX 500 + 1
#define INF 987654321

int N, M; //정점, 간선의 개수

long long dist[MAX];                     //정점들의 최소비용을 적어줄 배열
vector<pair<pair<int, int>, int>> graph; // graph first.first = from first.second = to second = 가중치
void TimeMachine(int start)
{
    //시작 정점 초기화
    dist[start] = 0;
    bool cycle = false;

    for (int i = 0; i < N; ++i)
    {
        // 모든 간선들을 정점 - 1만큼 반복하며 확인한다.
        for (int j = 0; j < graph.size(); ++j)
        {
            int from = graph[j].first.first;
            int to = graph[j].first.second;
            int cost = graph[j].second;
            if (dist[from] == INF)
                continue;

            if (dist[to] <= dist[from] + cost)
                continue;

            dist[to] = dist[from] + cost;

            if (i == N - 1)
            {
                cycle = true;
            }
        }
    }

    if (cycle)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 2; i <= N; ++i)
    {
        if (dist[i] == INF)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < MAX; ++i) //정점 최소거리 초기화
    {
        dist[i] = INF;
    }

    for (int i = 0; i < M; ++i) // 그래프 그려주기
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({{from, to}, cost});
    }

    TimeMachine(1);

    return 0;
}