#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 1000

int N, M;

struct Dir
{
    int x;
    int y;
};

string arr[MAX];
int visitedCnt[MAX][MAX][2];

Dir dir[4]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1}); //좌표값, 부술 수 있는 횟수
    visitedCnt[0][0][1] = 1;
    while (!q.empty())
    {
        int c = q.front().first.first;
        int r = q.front().first.second;
        int block = q.front().second;

        if (c == N - 1 && r == M - 1)
        {
            return visitedCnt[c][r][block];
        }

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nc = c + dir[i].x;
            int nr = r + dir[i].y;

            if (nc < 0 || nr < 0 || nc >= N || nr >= M)
                continue;
            else if (arr[nc][nr] == '1' && block == 1)
            {
                if (visitedCnt[nc][nr][block - 1] > visitedCnt[c][r][block] + 1 || visitedCnt[nc][nr][block - 1] == 0)
                {
                    q.push({{nc, nr}, block - 1});
                    visitedCnt[nc][nr][block - 1] = visitedCnt[c][r][block] + 1;
                }
            }
            else if (arr[nc][nr] == '0')
            {
                if (visitedCnt[nc][nr][block] > visitedCnt[c][r][block] + 1 || visitedCnt[nc][nr][block] == 0)
                {
                    q.push({{nc, nr}, block});
                    visitedCnt[nc][nr][block] = visitedCnt[c][r][block] + 1;
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    init();

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    cout << bfs() << '\n';

    return 0;
}