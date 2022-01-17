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
                dist[next] = cost + nCost;
                pq.push({-dist[next],next});
            }
        }
    }

    for(int i = 1; i <= V; ++i)
    {
        if(dist[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
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