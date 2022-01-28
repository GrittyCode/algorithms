#include <iostream>
#include <queue>
#define MAX 1000 + 1
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

int N, M; //도시의 개수 버스의 개수

void Dijkstra(int start, int goal)
{

    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curIdx = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();

        //우선순위 큐는 삽입한 순서에 상관없이 가장 비용이 작은것 부터 계산하므로 
        //우선순위 큐에 있는 정점까지의 최소 거리 계산이 이미 이루어져서 우선순위큐에 있는 원소까지 가는 비용이 더 클 경우 쓸모 없어져있으므로
        //contine를 통해 의미없는 for문 진입을 방지하여 시간을 빠르게 해준다.  
        if (dist[curIdx] < curCost)
            continue;

        for (int i = 0; i < graph[curIdx].size(); ++i)
        {
            int Next = graph[curIdx][i].first;
            int Ncost = graph[curIdx][i].second + curCost; //다음 정점까지 가는데 걸린 비용 -> 현재까지 온 비용 + 다음 정점까지의 비용
            if (dist[Next] > Ncost)
            {
                dist[Next] = Ncost;
                pq.push({-Ncost, Next});
            }
        }
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();

    int start, goal;

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    cin >> start >> goal;

    for (int i = 0; i <= N; ++i)
    {
        dist[i] = INF;
    }

    Dijkstra(start, goal);

    cout << dist[goal] << '\n';

    return 0;
}