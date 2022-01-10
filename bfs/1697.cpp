#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int arr[MAX] {0,0};
int x[3]{1, -1, 2};

void bfs()
{ // first가 좌표 위치 2번째가 좌표의 값
    queue<int> q;
    q.push(N); //현재 위치, 0초

    while (!q.empty())
    {
        int r = q.front();

        q.pop();

        for (int i = 0; i < 3; ++i)
        {
            if (i < 2)
            {
                int nr = r + x[i]; // arr[] 좌표의 위치
                if (nr >= MAX || nr < 0)
                    continue;
                else if ((arr[nr] > arr[r] + 1) || arr[nr] == 0) 
                {
                    arr[nr] = arr[r] + 1;
                    q.push(nr);
                }
            }
            else
            {
                int nr = r * x[i];

                if (nr >= MAX || nr < 0) //부모까지 걸린 시간 + 1이 현재 자신까지 도달한 시간보다 작다면 바꿔주고 또 다시 q.push()를 해줘서 그 원소의 자식값들도 리셋해준다.
                    continue;
                else if ((arr[nr] > arr[r] + 1) || arr[nr] == 0)
                {
                    arr[nr] = arr[r] + 1;
                    q.push(nr);
                }
            }
        }
    }

    cout << arr[K] << "\n";
}

int main()
{
    cin >> N >> K;
    if(N == K)
    {
        cout << 0 << endl;
    }
    else
    {
        bfs();
    }

    return 0;
}