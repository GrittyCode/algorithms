#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2187;

int N;
int result[3];
int arr[MAX][MAX];

void SolveQuadTree(int N, int y, int x)
{
    bool minus = true, zero = true, plus = true;

    if (N == 1)
    {
        result[arr[y][x] + 1]++;
        return;
    }

    for (int i = y; i < y + N; ++i)
    {
        for (int j = x; j < x + N; ++j)
        {
            if (arr[i][j] == -1)
            {
                zero = false;
                plus = false;
            }
            else if (arr[i][j] == 0)
            {
                plus = false;
                minus = false;
            }
            else
            {
                zero = false;
                minus = false;
            }
        }
    }

    if (minus)
    {
        result[0]++;
    }
    else if (zero)
    {
        result[1]++;
    }
    else if (plus)
    {
        result[2]++;
    }
    else //모두 false가 된 경우 반복문의 모든 수가 같지 않는다는 의미이므로 9트리로 나눠준다.
    {
        int div = N / 3;
        SolveQuadTree(div,y,x);
        SolveQuadTree(div,y,x + div);
        SolveQuadTree(div,y,x + div * 2);


        SolveQuadTree(div,y + div,x);
        SolveQuadTree(div,y + div,x + div);
        SolveQuadTree(div,y + div,x + div * 2);

        SolveQuadTree(div,y + div * 2,x);
        SolveQuadTree(div,y + div * 2,x + div);
        SolveQuadTree(div,y + div * 2,x + div * 2);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    //입출력 시 c++의  iostream과 c의 stdio의 양쪽 버퍼를 모두 사용(cin,cout, scanf, printf를 혼재해서 사용) 하도록 되어있고
    //작동에 문제가 없도록 동기화 처리가 필요한데 cin,cout, scanf, printf를 혼재해서 사용하지 않는다면 특별히 동기화 처리가 필요하지 않기에
    //이것을 꺼줌으로써 성능의 향상을 얻을 수 있다고 합니다.

    //줄바꿈은 endl보단 \n으로
    // endl은 개행 뿐 아니라 버퍼를 비우는 용도로도 사용된다.

    cin.tie(NULL);
    // cin, cout 연결을 끊어줌으로서 성능향상

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    SolveQuadTree(N, 0, 0);

    for(int i = 0; i < 3; ++i)
    {
        cout << result[i] << "\n";
    }

    return 0;
}