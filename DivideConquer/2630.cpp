#include<iostream>

using namespace std;

#define MAX 128 + 1

int squre[MAX][MAX];
int N;

int white = 0, blue = 0;

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void QuadTree(int x, int y,int length)
{

    int half = length/ 2;

    for(int i = x; i < length + x; ++i)
    {
        for(int j = y; j < length + y; ++j)
        {
            if(squre[x][y] != squre[i][j])
            {
                QuadTree(x,y,half);
                QuadTree(x+half,y,half);
                QuadTree(x,y+half,half);
                QuadTree(x+half,y+half,half);
                return; //해당 분기에선 같지 않았으므로 return해서 함수 종료
            }
        }
    }

    if(squre[x][y] == 0)
    {
        white++;
    }
    else if(squre[x][y] == 1)
    {
        blue++;
    }

}


int main()
{
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> squre[i][j];
        }
    }

    QuadTree(0,0,N);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}