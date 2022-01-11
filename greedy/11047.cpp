#include<iostream>
#define MAX 10
using namespace std;

int N,K;
int coin[MAX];

int main(void)
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
    {
        cin >> coin[i];
    }

    int money = K;
    int cnt = 0;
    
    for(int i = N - 1; i >= 0; --i)
    {
        while(K >= coin[i])
        {
            K -= coin[i];
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}