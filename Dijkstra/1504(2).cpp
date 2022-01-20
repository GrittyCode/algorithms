#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX 800 + 1
#define INF 987654321
int N,E; //정점 간선 개수

int dist[MAX];

int V1,V2;

int sToV1,sToV2, V1TOV2, V1toN, V2toN;

vector<pair<int,int>> graph[MAX];// graph[idx] = {a,b} idx = 현재 정점 a = 연결된 정점 b = 가중치

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Dijkstra(int start)
{
    for(int i = 0; i <= N; ++i) //정점 초기화(여러번 돌리기 위한 코드)
    {
        dist[i] = INF;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //처음 first = 가중치 second = 연결된 다음 정점
    pq.push({0,start}); // 정점 start부터 시작.
    dist[start] = 0;

    while (!pq.empty())
    {
        int curIdx = pq.top().second;
        int curCost = pq.top().first;

        pq.pop();

        if(curCost > dist[curIdx])
            continue;

        for(int i = 0; i < graph[curIdx].size(); ++i)
        {
            int Next = graph[curIdx][i].first; //연결된 정점
            int NCost = graph[curIdx][i].second + curCost;
            if(dist[Next] > NCost) //현재 자기의 정점까지 도달했던것보다 가중치가 적다면 갱신해주고, queue에 다시 넣어줘서 연결된 정점들도 갱신한다.
            {
                dist[Next] = NCost;
                pq.push({NCost,Next});
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
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin >> V1 >> V2;

    Dijkstra(1); //1 ~ v1 1 ~ v2를 구해주자.
    sToV1 = dist[V1];
    sToV2 = dist[V2];
    Dijkstra(V1); //V1 ~ V2 ~ N 구해줌
    V1toN = dist[N];
    V1TOV2 = dist[V2];
    Dijkstra(V2);
    V2toN = dist[N];

    int minCost = INF;
    minCost = min(minCost, (sToV1 + V1TOV2 + V2toN)); 
    minCost = min(minCost, (sToV2 + V1TOV2 + V1toN));

    if(minCost == INF || V1TOV2 == INF) cout << -1 <<'\n';
    else cout << minCost;
    
    return 0;
}