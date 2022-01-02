#include <iostream>
#include <vector>

using namespace std;

#define MAX 21

int dp[MAX][MAX][MAX]; // 20이상일 경우 다 같은 수 좌표값 a, b, ,c가 있으므로 3차원 배열로 선언

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1; //음수혹은 0이 나올 경우 바로 return 1
    }

    if (a >= MAX || b >= MAX || c >= MAX)
        return w(20, 20, 20);

    int &tmp = dp[a][b][c]; //주소 저장

    if (tmp != 0)
        return dp[a][b][c];

    if (a < b && b < c)
        tmp = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        tmp = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    

    return tmp;
}

int main(void)
{
    int a = 0, b = 0, c = 0;

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) // break 지점 확인
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") "
             << "= " << w(a, b, c) << "\n";
    }
    return 0;

    //v.begin()은 첫번째 원소를 가르키지만 v.end()는 마지막 원소 그 다음을 가르킨다. 즉 Null값을 가르킬것.
}