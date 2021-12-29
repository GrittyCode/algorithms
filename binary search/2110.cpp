#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 200000

int N, C;

int houseX[MAX];

bool isPossible(int distance)
{
    unsigned int cnt = 1; //첫 좌표에는 무조건 설치를 해야 한다.

    unsigned int prevX = houseX[0];

    for (int i = 1; i < N; ++i)
    {
        if (houseX[i] - prevX >= distance)
        {
            cnt++;
            prevX = houseX[i]; //갱신
        }
    }

    if (cnt >= C)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        cin >> houseX[i];
    }

    sort(houseX, houseX + N);

    unsigned int low = 1, high = houseX[N - 1] - houseX[0], mid, result = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (isPossible(mid)) //가능하다면 low값을 mid + 1늘려줘서 더 높은 값으로 시도해본다.
        {
            low = mid + 1;
            result = max(result, mid);
        }
        else
        {
            high = mid - 1;
        }
        //불가능하다면 더 낮은 값으로 시도하기 위해 high를 mid - 1로 설정한다.
        //이때, high = mid - 1이 low값보다 작아지게 되면 모든 경우의 수를 체크한 것이므로 반복문을 나와준다.
    }

    cout << result;

    return 0;
}