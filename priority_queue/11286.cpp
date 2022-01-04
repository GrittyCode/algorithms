#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

template <typename T> //절대값 abs math STL 사용으로 오름차순으로 비교해준다.
struct newAlign : public binary_function<T, T, bool>
{
    _GLIBCXX14_CONSTEXPR
    bool operator()(const T &__x, const T &__y) const
    {
        if(abs(__x) == abs(__y))
            return __x > __y;
        else
            return abs(__x) >= abs(__y);
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, newAlign<int>> pq; //함수 어댑터 사용으로 compare 기준을 오름차순으로 바꿔준다.

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