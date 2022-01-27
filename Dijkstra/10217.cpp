#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, k;

struct Airport
{
    int node;
    int c, d;
};

vector<vector<Airport>> edges;
int dp[101][10001];

void dijkstra()
{

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {1, 0}}); // time, node, cost
    dp[1][0] = 0;

    while (!pq.empty())
    {

        int here = pq.top().second.first;
        int time = -pq.top().first;
        int cost = pq.top().second.second;
        pq.pop();

        if (dp[here][cost] < time)
            continue;

        for (int i = 0; i < edges[here].size(); i++)
        {
            int next = edges[here][i].node;
            int next_time = time + edges[here][i].d;
            int next_cost = cost + edges[here][i].c;

            // 시간과 비용 조건 확인
            if (next_cost <= m && next_time < dp[next][next_cost])
            {
                // 불필요한 시간 재설정
                for (int j = next_cost + 1; j <= m; j++)
                {
                    if (dp[next][j] <= next_time)
                        break;
                    dp[next][j] = next_time;
                }

                dp[next][next_cost] = next_time;
                pq.push({-next_time, {next, next_cost}});
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m >> k;
        // 배열 초기화
        edges.clear();
        edges.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = INF;
            }
        }

        int u, v, c, d;
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v >> c >> d;
            Airport info;
            info.node = v;
            info.c = c;
            info.d = d;

            edges[u].push_back(info);
        }

        dijkstra();

        int answer = INF;
        for (int i = 0; i <= m; i++)
        {
            if (dp[n][i] < answer)
                answer = dp[n][i];
        }

        if (answer == INF)
            cout << "Poor KCM" << endl;
        else
            cout << answer << endl;
    }
}