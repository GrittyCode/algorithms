#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N;
    priority_queue<int> pq;

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