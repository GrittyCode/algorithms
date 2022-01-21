#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 2000 + 1
#define INF 987654321

using namespace std;

int n, m, t; //교차로 도로 목적지
int s, g, h; //예술가 출발지, g와 h 사이에 있는 도로를 지나가야함.

int StoG, StoH, GtoH, GtoX, HtoX, StoX;

int dist[MAX];

//알고리즘 정리
//우선 Dijkstra 알고리즘을 짜고 난 후, 교차로 gh를 반드시 지나면서 최단거리 이동을 만족한다면 출력해주는것을 목표로한다.
// Dijkstra로 Start -> g -> h를 지나가며 최단거리를 만족하는지 판단해주는 Dijkstra를 짜주면 된다.

void Dijkstra(int start, vector<pair<int,int>> A[])
{
    for (int i = 0; i <= n; ++i)
    {
        dist[i] = INF; //모든 정점들까지의 가중치들을 초기화 해준다.
    }

    // first 도착하기까지의 가중치, second : 현재 정점
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int idx = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (int i = 0; i < A[idx].size(); ++i)
        {
            int Next = A[idx][i].first;
            int Ncost = A[idx][i].second + cost; //다음 정점까지의 가중치 값
            if (dist[Next] > Ncost)
            {
                dist[Next] = Ncost;
                pq.push({dist[Next], Next});
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


// s -> g -> h -> x or s -> h -> g - > x가 s -> x보다 거리가 짧다면 vector<int> goal에 넣어준다. 그 후, goal을 다 뽑아준다.
int main()
{
    Init();

    vector<int> goal;
    int x[100];

    int test;
    cin >> test;

    while (test--)
    {
        
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        vector<pair<int,int>> V[MAX];

        for (int i = 0; i < m; ++i)
        {
            int a, b, d; // from, to, 가중치
            cin >> a >> b >> d;
            V[a].push_back({b, d});
            V[b].push_back({a, d});
            //연결된 도로들과 가중치 입력
        }

        for (int i = 0; i < t; ++i)
        {
            cin >> x[i];
        }

        for (int i = 0; i < t; ++i)
        {
            Dijkstra(s,V);
            StoG = dist[g];
            StoH = dist[h];
            StoX = dist[x[i]];
            // S ~ G 거리 S ~ H 거리
            Dijkstra(g,V);
            GtoH = dist[h];
            GtoX = dist[x[i]];
            // G ~ H 거리 G ~ X 거리
            Dijkstra(h,V);
            HtoX = dist[x[i]];
            // H ~ X 거리

            // S -> G -> H -> X or S -> H -> G -> X 거리가 S -> X거리보다 짧다면 vector goal에 넣어주자.
            if (StoX == (StoG + GtoH + HtoX) || StoX == (StoH + GtoH + GtoX))
            {
                goal.push_back(x[i]);
            }
        }

        sort(goal.begin(), goal.end());

        for (int i = 0; i < goal.size(); ++i)
        {
            cout << goal[i] << " ";
        }

        goal.clear();

        cout << '\n';
    }

    return 0;
}