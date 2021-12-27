#include <iostream>
#include<math.h>

using namespace std;

#define MAX 20

#define MAXNUM 1000000000;
int N;

int minScore = MAXNUM;

int team[MAX][MAX];

bool visited[MAX];

void dfs(int teamCount, int first)
{
    if (teamCount == N / 2) // start팀에 2~10명까지 구했다면
    {
        int start = 0;
        int link = 0;

        for(int i = 0; i < N; ++i)
        {
            for(int j = i + 1; j < N; ++j)
            {
                if(visited[i] && visited[j])
                {
                    start += team[i][j];
                    start += team[j][i];
                }
                else if(!visited[i] && !visited[j])
                {
                    link += team[i][j];
                    link += team[j][i];
                }
            }           
        }

        //괄호 제거
        //minScore = min(minScore,abs(start-link));
    }

    for (int i = 0; i < N; ++i) // 0 ~ N - 1번째 인덱스까지 실행하는데 이미 뽑힌 선수는 제외한다.
    {
        if(visited[i] == false && i > first) //시작점 기준 왼쪽에 있는것을 넣은 조합은 이미 중복되는 조합이다 ex) 1,2,3과 2,1,3과 3,2,1은 같은 조합이므로 빼주기위해 
        //매개변수 first로 처음 조합의 시작 숫자를 받아와준다. 만약 1이라면 1초과의 수만 조합으로 포함하고 first가 4라면 4초과의 수만 조합으로 뽑아온다.
        {
            visited[i] = true;
            dfs(teamCount + 1, i);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> team[i][j];
        }
    }

    dfs(0,-1);

    cout << minScore;
    return 0;
}