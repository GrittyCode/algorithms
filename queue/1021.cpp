#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
    int N, M;
    cin >>  N >> M;
    deque<int> q;
    for(int i = 1; i <= N; ++i)
    {
        q.push_back(i);
    }
    int num;
    int idx;
    int cnt = 0;

    while (M--)
    {
        cin >> num;

        for(int i = 0; i < q.size(); ++i)
        {
            if(q[i] == num)
            {
                idx = i;
                break;
            }
        }


        if(idx < q.size() - idx)
        {
            while(true)
            {
                if(q.front() == num)
                {
                    q.pop_front();
                    break;
                }
                ++cnt;
                q.push_back(q.front());
                q.pop_front();
            }
        }
        else
        {
            while(true)
            {
                if(q.front() == num)
                {
                    q.pop_front();
                    break;
                }
                ++cnt;
                q.push_front(q.back());
                q.pop_back();
            }
        }
    }

    cout << cnt << "\n";

    return 0;       
}