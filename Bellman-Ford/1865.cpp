#include <iostream>
#include <queue>
#define MAX 500 + 1
#define INF 987654321
using namespace std;

struct Graph
{
    int from;
    int to;
    int cost;
    Graph(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
};

int N, M, W; //정점의개수, 도로의 개수

vector<Graph> v;

int graph[MAX][MAX];


void Bellmanford(int start)
{
    vector<int> dist(N + 1, MAX);

    dist[start] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            int From = v[j].from;
            int to = v[j].to;
            int cost = v[j].cost;
            if(dist[to] > dist[From] + cost) 
            {
                dist[to] = dist[From] + cost;
                if(i == N)
                {
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
    return;

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
    int T;
    cin >> T;

    while (T--)
    {
        v.clear();
        
        cin >> N >> M >> W;
        for (int i = 0; i < M; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            v.push_back(Graph(S, E, T));
            v.push_back(Graph(E, S, T));
        }
        for (int i = 0; i < W; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            v.push_back(Graph(S, E, -T));
        }

        Bellmanford(1);
        
    } 

    return 0;
}
