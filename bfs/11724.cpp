#include <iostream>
#include <queue>
#define MAX 1000 + 1

using namespace std;

int N, M;

vector<int> v[MAX];
bool isCheck[MAX];

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    isCheck[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); ++i)
        {
            int Next = v[cur][i];
            if (!isCheck[Next])
            {
                isCheck[Next] = true;
                q.push(Next);
            }
        }
    }
}

int main()
{
    Init();
    cin >> N >> M;

    int cnt = 0;

    for(int i = 0; i < M; ++i)
    {
        int from,to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!isCheck[i])
        {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
