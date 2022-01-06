#include<iostream>

using namespace std;

#define MAX 11
#define Oper 4


int num[MAX];
int oper[Oper];

int maxNum = -100000001;
int minNum = 100000001;

int N;

void dfs(int result, int cnt)
{
    if(cnt == N )
    {
        if(result > maxNum)
        {
            maxNum = result;
        }
        
        if(result < minNum)
        {
            minNum = result;
        }

        return;
    }


    for(int i = 0; i < Oper; ++i)
    {
        if(oper[i] > 0)
        {
            oper[i]--;
            if(i == 0)
            {
                dfs(result + num[cnt], cnt + 1);
            }
            else if(i == 1)
            {
                dfs(result - num[cnt], cnt + 1);
            }
            else if(i == 2)
            {
                dfs(result * num[cnt], cnt + 1);
            }
            else
            {
                dfs(result / num[cnt], cnt + 1);
            }
            oper[i]++; // 현재 트래킹의 모든 계산이 끝났다면 다시 더해줘서 다른 값들부터 넣어 줄 수 있게 해준다. 
        }
    }


}

int main(void)
{
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        cin >> num[i];
    }

    for(int i = 0; i < Oper; ++i)
    {
        cin >> oper[i];
    }
    
    dfs(num[0], 1);

    cout << maxNum << "\n";
    cout << minNum;


}