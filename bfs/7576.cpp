#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int arr[MAX][MAX];
int moveCnt[MAX][MAX];

vector<pair<int, int>> ripeTomatoVertex;
int M, N;

int x[4]{1, -1, 0, 0};
int y[4]{0, 0, 1, -1};

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < ripeTomatoVertex.size(); ++i)
    {
        q.push({ripeTomatoVertex[i].first, ripeTomatoVertex[i].second});
    }

    while (!q.empty())
    {

        int r2 = q.front().first;
        int c2 = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = r2 + x[i];
            int nc = c2 + y[i];

            if (arr[nr][nc] == 0 && nr >= 0 && nc >= 0 && nc < M && nr < N)
            {
                q.push({nr, nc});
                arr[nr][nc] = 1;                       // c2가 가로 r2가 세로
                moveCnt[nr][nc] = moveCnt[r2][c2] + 1; //자신의 부모 노드보다 하루 더 걸렸으므로
            }
        }
    }

    bool isripe = true; //다 익었다고 가정
    int max = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == 0)
            {
                isripe = false;
                break;
            }
            if (moveCnt[i][j] > max)
            {
                max = moveCnt[i][j];
            }
        }
    }

    if (isripe) // 다 익었을 경우
    {
        cout << max << "\n";
    }
    else //다 익는게 실패했을 경우
    {
        cout << -1 << "\n";
    }
}

int main(void)
{
    cin >> M >> N; // M은 가로 N은 세로

    int r, c;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                ripeTomatoVertex.push_back({i, j});
            }
        }
    }
    bfs();

    return 0;
}