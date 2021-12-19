#include<iostream>

using namespace std;

int paper[128][128];
int white;
int blue;

void solve(int w, int h, int size)
{
    int color = paper[w][h];
    //color 흰색 0, 파란색 1
    for(int i = w; i < w + size; i++)
    {
        for(int j = h; j < h + size; j++)
        {
            if(paper[i][j] == 0 && color == 1)
            {
                color = 2;
            }
            else if(paper[i][j] == 1 && color == 0)
            {
                color = 2;
            }

            if(color == 2)
            {
                //쿼드 트리로 분할 정복 -> 사각형을 4분의 1 크기로 나눠서 실행해준다.
                solve(w,h, size/2);
                solve(w + size/2, h, size/2);
                solve(w, h + size / 2, size / 2);
                solve(w + size / 2, h + size / 2, size / 2);
                return;
            }
        }
    }

    if(color == 0)
        white++;
    else
        blue++;
}


int main(void)
{
    int n; 
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> paper[i][j];
        }
    }

    solve(0,0,n);

    cout << white << endl;
    cout << blue << endl;


    return 0;
}