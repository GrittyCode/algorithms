#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 1000 + 1
#define INF 987654321
using namespace std;



int Dist[MAX], Res[MAX];
vector<pair<int,int>> graph[MAX];

void Dijkstra(int start)
{
    priority_queue<pair<int,int>> pq;
    Dist[start] = 0;
    pq.push({0,start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int Next = graph[cur][i].first;
            int Ncost = graph[cur][i].second;
            if(Dist[Next] > Ncost + cost)
            {
                Dist[Next] = Ncost + cost;
                pq.push({-Dist[Next], Next});
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

    int N,M,X;
    cin >> N >> M >> X;
    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    for(int i = 1; i <= N; ++i)
    {
        for(int i = 1; i <= N; ++i) Dist[i] = INF;
        Dijkstra(i);
        Res[i] = Dist[X];
        
    }

    for(int i = 1; i <= N; ++i) Dist[i] = INF;
    Dijkstra(X);

    int student = 0;
    
    for(int i = 1; i <= N; ++i)
    {
        student = max(student,Res[i] + Dist[i]);
    }

    cout << student << endl;

    return 0;
}