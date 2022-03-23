#include <iostream>
#include <queue>
#define MAX 100001
#define INF 987654321

using namespace std;

int dist[MAX];
int N, K; // N�� ������ġ K�� ��ǥ��ġ
int dir[2] = {1, -1};

//Ǯ�̹��
/*
�켱, �ڽ��� ��ġ�� �޾��� ��, ��ǥ ��ġ�� �����Ѵ�. ���Ŀ�, ���ͽ�Ÿ�� �˰����� �����Ű�� �Ǵµ�
�� ��, �Ű������� ���� ��ġ�� ��ǥ ��ġ�� �޾��ֵ��� �Ѵ�. �� ��, �����켱Ž������ �������ִµ�
�� ��������, ������ �迭�� �������� �����ϵ��� �Ѵ�. �������� �� �������� 1,-1�� ��, ������ ���� ��ĭ��
������ �ִ°Ͱ� ���� �ڽ��� ��ǥ * 2�� �����̵����ִ°� 3������ �ִ�. �̷��� �������� ���� �� �ٶ�, �ڽ���
��ǥ���� ������ �ð��� �Է����ֵ��� �Ѵ�. ����, �ڽ��� ��ǥ�� ���� �� �� ������ �����ߴ� �ð����� �� ���� �ɷȴٸ�
�� ���� �ð����� �ʱ�ȭ ���ֵ��� �Ѵ�. �� ��, ��� dist[]�� �迭���� INF�� �������ְ�, ���� ��ġ�� dist���� 0���� �����ϰ�
���� ���ֵ��� �Ѵ�.
*/

void Dijkstra(int start, int end)
{
    for (int i = 0; i < MAX; ++i)
    {
        dist[i] = INF;
    }

    dist[start] = 0; //������ �ð�

    queue<int> q; //�ڱ� ��ġ
    q.push(start);

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

                for (int i = 0; i < 3; ++i)
        {
            if (i < 2) //������ �����̵��� ���
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
            else //�����̵��� ���
            {
                int nidx = idx * 2;
                if (nidx > 100000 || nidx < 0)
                    continue;
                if (dist[idx] < dist[nidx]) //0���� ������ �׳� �Ű��ָ� �ȴ�.
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