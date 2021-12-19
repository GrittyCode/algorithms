#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
 
int main(void)
{
    cin.tie(NULL);

    int iter;
    cin >> iter;

    for (int test = 0; test < iter; ++test)
    {
        int N, M,cnt = 0;

        priority_queue <int> pq;
        queue <pair<int, int>> q;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            q.push({i,temp});
            pq.push(temp);
        }
        while (!q.empty()) //queue가 빌때까지
        {
            //현재 배열의 인덱스, 중요도
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();
 
            if (pq.top() == val)
            {
                pq.pop();
                cnt++;
                if (idx == M)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else {
                q.push({ idx,val });
            }
        }
    }
    return 0;
}