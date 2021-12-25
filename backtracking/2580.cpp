#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

int board[MAX][MAX];

int zerocount = 0;

bool found = false;

vector<pair<int, int>> points;

bool Check(pair<int,int> p)
{
    for(int i = 0; i < MAX; ++i) //행과 열 같은 요소 검사
    {
        if(board[p.first][p.second] == board[p.first][i] && p.second != i) //행의 열 요소 검열
        {
            return false;
        } 

        if(board[p.first][p.second] == board[i][p.second] && p.first != i)
        {
            return false;
        }
    }

    int x = p.first / 3.0;
    int y= p.second / 3.0;

    for(int i = x * 3; i < x * 3 + 3; ++i) // 3 x 3 타일 검사
    {
        for(int j = y * 3; j < y * 3 + 3; ++j)
        {
            if(board[p.first][p.second] == board[i][j])
            {
                if(!(i == p.first && j == p.second))
                {
                    return false;
                }
            }
        }
    }

    return true; //모든 조건에 부합한다면 true return

}



void SolveSudoKu(int N)
{
    if (N == zerocount)
    {
        found = true;
        for (int i = 0; i < MAX; ++i)
        {
            for (int j = 0; j < MAX; ++j)
            {
               cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        return;
    }


    for(int i = 1; i <= MAX; ++i) //1~9까지 넣어준다.
    {
        board[points[N].first][points[N].second] = i;
        if(Check(points[N])) //조건에 부합한다면 다음 0포인트로 이동
        {
            SolveSudoKu(N + 1);
        }

        if(found) //찾았다는 플래그가 세워진다면 모든 백트래킹 과정을 멈춘다.
        {
            return;
        }
    }

    board[points[N].first][points[N].second] = 0; //찾지 못했다면 진행하고 있던 백트래킹 과정을 0으로 되돌려주고 한 단계 상위 루트 진행 상황으로 돌아간다.
}

int main(void)
{
    pair<int, int> point;

    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                point.first = i;
                point.second = j;
                points.push_back(point);
                zerocount++;
            }
        }
    }

    SolveSudoKu(0);

    return 0;
}