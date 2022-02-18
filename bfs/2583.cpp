#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 100
using namespace std;

int arr[MAX][MAX];
int M,N,K;

int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};

struct Rectangle
{
    int X;
    int Y;

    Rectangle(int _x, int _y) : X(_x), Y(_y) { }
};



void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


void DrawRectangle(Rectangle start, Rectangle end)
{
    for(int i = start.Y; i < end.Y; ++i)
    {
        for(int j = start.X; j < end.X; ++j)
        {
            arr[i][j] = 1;
        }
    }
}


int Bfs(Rectangle start)
{
    queue<Rectangle> Rec;
    Rec.push(start);
    arr[start.Y][start.X] = 1;

    int cnt = 0;

    while (!Rec.empty())
    {
        int X = Rec.front().X;
        int Y = Rec.front().Y;
        Rec.pop();
        cnt++;

        for(int i = 0; i < 4; ++i)
        {
            int NextX = X + dirX[i];
            int NextY = Y + dirY[i];

            if(NextX >= N || NextY >= M || NextX < 0 || NextY < 0) continue;
            
            if(arr[NextY][NextX] == 0)
            {
                Rec.push(Rectangle(NextX,NextY));
                arr[NextY][NextX] = 1;
            }
        }
    }


    return cnt;
}
int main()
{

    Init();

    cin >> M >> N >> K;

    
    for(int i = 0; i < K; ++i)
    {
        int startX,startY,endX,endY;
        cin >> startX >> startY >> endX >> endY;
        DrawRectangle(Rectangle(startX,startY),Rectangle(endX,endY));
    }

    vector<int> vec;

    int RectangleCnt = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(arr[i][j] == 0)
            {
                RectangleCnt++;
                vec.push_back(Bfs(Rectangle(j,i)));
            }
        }
    }


    int size = vec.size();

    sort(vec.begin(),vec.end());


    cout << RectangleCnt << '\n'; //사각형 개수 출력


    for(int i = 0; i < size; ++i)
    {
       cout << vec[i] << " "; //범위들 출력
    }
    return 0;
}