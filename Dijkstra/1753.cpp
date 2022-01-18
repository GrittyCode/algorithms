#include<iostream>
#include<queue>

using namespace std;
#define INF 987654321
#define MAX 20000 + 1
int start, V, E;

int dist[MAX];
vector<pair<int,int>> graph[MAX]; //graph[idx] (first,second) idx = 해당 정점 first = 연결된 값 second = 가중치


void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DijkstraSolve()
{
    //first 가중치 second 정점
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int curidx = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int i = 0; i < graph[curidx].size(); ++i)
        {
            int next = graph[curidx][i].first; //연결된 인덱스
            int nCost = graph[curidx][i].second;  //연결된 인덱스까지의 가중치
            if(dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost; //정점까지 도달하는 가중치 갱신
                pq.push({-dist[next],next}); //갱신된 정점의 인덱스와, 가중치들을 우선순위 큐에 push해준다. 만약 가장 작은 가중치를 가졌다면 다음 idx로 선정.
            }
        }
    }

    for(int i = 1; i <= V; ++i)  //출력문 작성
    {
        if(dist[i] == INF) //설정한 INF와 같다면 문자열 INF 출력
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n'; //정점들의 가중치 출력
        }   
    }
}

int main()
{
    cin >> V >> E;

    cin >> start;

    int from, to, w;

    while(E--)
    {
        cin >> from >> to >> w;
        graph[from].push_back({to,w});
    }

    for(int i = 1; i <= V; ++i)
    {
        dist[i] = INF;
    }

    DijkstraSolve();

    return 0;
}