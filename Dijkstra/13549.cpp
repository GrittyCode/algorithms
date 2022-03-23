#include <iostream>
#include <queue>
#define MAX 100001
#define INF 987654321

using namespace std;

int dist[MAX];
int N, K; // N은 현재위치 K가 목표위치
int dir[2] = {1, -1};

//풀이방법
/*
우선, 자신의 위치를 받아준 후, 목표 위치를 설정한다. 이후에, 다익스타라 알고리즘을 진행시키면 되는데
이 때, 매개변수로 시작 위치와 목표 위치를 받아주도록 한다. 이 후, 범위우선탐색으로 진행해주는데
이 문제에선, 일차원 배열의 움직임을 진행하도록 한다. 움직임은 총 세가지로 1,-1로 즉, 오른쪽 왼쪽 한칸씩
움직여 주는것과 현재 자신의 좌표 * 2로 순간이동해주는것 3가지가 있다. 이러한 움직임을 진행 해 줄때, 자신의
좌표까지 도달한 시간을 입력해주도록 한다. 만약, 자신의 좌표에 도달 할 때 이전에 도달했던 시간보다 더 적게 걸렸다면
더 적은 시간으로 초기화 해주도록 한다. 이 때, 모든 dist[]의 배열들은 INF로 설정해주고, 시작 위치의 dist값만 0으로 설정하고
진행 해주도록 한다.
*/

void Dijkstra(int start, int end)
{
    for (int i = 0; i < MAX; ++i)
    {
        dist[i] = INF;
    }

    dist[start] = 0; //도달한 시간

    queue<int> q; //자기 위치
    q.push(start);

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

                for (int i = 0; i < 3; ++i)
        {
            if (i < 2) //오른쪽 왼쪽이동의 경우
            {
                int nidx = idx + dir[i];
                if (nidx > 100000 || nidx < 0)
                    continue;

                if (dist[idx] + 1 < dist[nidx])
                {
                    dist[nidx] = dist[idx] + 1;
                    q.push({nidx});
                }
            }
            else //순간이동의 경우
            {
                int nidx = idx * 2;
                if (nidx > 100000 || nidx < 0)
                    continue;
                if (dist[idx] < dist[nidx]) //0초후 임으로 그냥 옮겨주면 된다.
                {
                    dist[nidx] = dist[idx];
                    q.push({nidx});
                }
            }
        }
    }

    cout << dist[K];
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

    cin >> N >> K;
    Dijkstra(N, K);
    return 0;
}