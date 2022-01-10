#include<iostream>
#include<queue>

using namespace std;

#define MAX 101


int arr[MAX][MAX][MAX]; //3차원  M 가로 N세로 높이
int ripeTime[MAX][MAX][MAX];

int M,N,H;

vector<pair<pair<int,int>,int>> ripeTomatoIdx_Vec; //몇번째 높이인지, 기본적인 좌표 

int x[6] {1,-1,0,0,0,0}; // 오른쪽 왼쪽
int y[6] {0,0,1,-1,0,0}; // 위 아래
int h[6] {0,0,0,0,1,-1}; // 앞 뒤

void bfs()
{
    int maxTime = 0; //maxTime 검사
    bool allRipe = true;

    queue<pair<pair<int,int>,int>> q;
    for(vector<pair<pair<int,int>,int>>::size_type i = 0; i < ripeTomatoIdx_Vec.size(); ++i)
    {
        q.push(ripeTomatoIdx_Vec[i]); //이미 익어있는 모든 토마토를 넣어준다. 그 후 bfs를 진행
    }

    while(!q.empty())
    {
        //M이 2차원 N이 1차원 
        int row = q.front().first.second;
        int colmn = q.front().first.first;
        int hegiht = q.front().second;

        q.pop();

        for(int i = 0; i < 6; ++i)
        {
            int nr = row + x[i];
            int nc = colmn + y[i];
            int nh = hegiht + h[i];
            //오른쪽 왼쪽 위 아래 앞 뒤 모두 검사

            if(nr < 0 || nc < 0 || nh < 0 || nr >= M || nc >= N || nh >= H)
                continue; //범위를 벗어난 경우에는 다음 for문으로 바로 넘어간다.
            else if(arr[nc][nr][nh] == 0)
            {
                q.push({{nc,nr},nh}); //arr[colmn][row][height]
                arr[nc][nr][nh] = 1;
                ripeTime[nc][nr][nh] = ripeTime[colmn][row][hegiht] + 1;//하루 경과
                maxTime = ripeTime[nc][nr][nh]; //마지막 bfs가 실행될 때 까지 maxTime 갱신
            }
        }
    }

    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < N; ++ j)
        {
            for(int w = 0; w < M; ++w)
            {
                if(arr[j][w][i] == 0)
                {
                    allRipe = false;
                }
            }
        }
    }

    if(allRipe)
        cout << maxTime << "\n";
    else
        cout << -1 << "\n";

}


int main()
{
    //기본적으로는 bfs 좌표값으로 하는게 똑같다. 하지만 층이 나뉘어있는것.
    //그냥 위 아래 좌표값만 bfs에 넣어주면 된다. 하지만, 시작할때, 모든 1을 미리 queue에 넣어줘야됨
    cin >> M >> N >> H; //가로 세로 높이
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < N; ++ j)
        {
            for(int w = 0; w < M; ++w)
            {
                cin >> arr[j][w][i]; //j가 행 w가 열 i는 높이
                if(arr[j][w][i] == 1)
                {
                    ripeTomatoIdx_Vec.push_back({{j,w},i}); //가로 idx w가 세로 idx i가 높이
                }
            }
        }
    }

    bfs();

    return 0;
}