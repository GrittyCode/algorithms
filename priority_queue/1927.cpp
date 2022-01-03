#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq; //함수 어댑터 사용으로 compare 기준을 오름차순으로 바꿔준다.

    cin >> N;

    int tmp = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            pq.push(tmp);
        }
    }
    return 0;
}