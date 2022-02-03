#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 800 + 1

const int INF = 987654321;
int N, E, v1, v2, res = INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;

vector<pair<int, int>> v[MAX]; // v[a] = (b,c) : a에서 b까지 c의 거리로 이동 가능
int dist[MAX];

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Dijkstra(int start)
{
    for (int i = 0; i <= N; ++i)
    {
        dist[i] = INF; // 987654321로 모든 정점 초기화
    }

    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});                                                                // 0가중치 start 정점 시작

    while (!pq.empty())
    {
        int Idx = pq.top().second;
        int Cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < v[Idx].size(); ++i)
        {
            int Next = v[Idx][i].first;          //현재 연결된 정점
            int Ncost = v[Idx][i].second + Cost; //현재 간선과 지금까지의 가중치

            if (dist[Next] > Ncost)
            {
                dist[Next] = Ncost;
                pq.push({Ncost, Next});
            }
        }
    }
}

int main()
{
    Init();

    cin >> N >> E;

    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c}); // a b b a 두 간선으로 취급
    }

    cin >> v1 >> v2;

    Dijkstra(1); // 1 정점 ~ v1 v2구해주자.
    sToV1 = dist[v1];
    sToV2 = dist[v2];

    Dijkstra(v1); // v1 ~ v2 , v1 ~ N을 구해주자.
    V1ToV2 = dist[v2];
    V1ToN = dist[N];

    Dijkstra(v2); // v2 ~ N을 구해보자
    V2ToN = dist[N];

    res = min(res, sToV1 + V1ToV2 + V2ToN);
	res = min(res, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || res == INF) cout << -1;
	else cout << res;

    return 0;
}