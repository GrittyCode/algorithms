#include<iostream>

using namespace std;

#define MAX 15

int col[MAX]; //이 안에 들어가는 것이 열의 크기이다.
int N;
int cnt = 0;

int Check(int colmn) //행을 매개변수로 받아준다.
{
    for(int i = 0; i < colmn; ++i)
    {
        //col[colm] == col[i]는 같은 열에 있는지 확인해주는 if문이다
        if(col[colmn] == col[i] || abs(col[colmn] - col[i]) == colmn - i)
            return 0;
    }

    return 1;
}

void SolveQueen(int colmn)
{
    if(colmn == N) //행이 N번째 까지 무리 없이 왔다면 카운트 +1
    {
        cnt++;
    }
    else
    {
        for(int i = 0; i < N; ++i)
        {
            col[colmn] = i;
            if(Check(colmn))
            {
                SolveQueen(colmn + 1); //행 + !
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;
    SolveQueen(0);
    cout << cnt;
    return 0;
}