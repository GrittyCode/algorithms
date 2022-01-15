#include<iostream>
#include<queue>

using namespace std;
#define MAX 20000 + 1

#define RED 1
#define BLUE 2


int V,E;



int colored[MAX];
vector<int> vecVer[MAX]; //간선 표현


void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    colored[start] = RED; //RED부터 시작

    int curColor;
    int idx;

    while(!q.empty())
    {
        idx = q.front();
        curColor = colored[idx]; //현재 자신의 색깔을 받아준다.
        q.pop();

        for(int i = 0; i < vecVer[idx].size(); ++i) //자신과 연결되어 있는 모든 간선들을 방문해주기 위한 반복문
        {
            if(colored[vecVer[idx][i]] == 0) //idx 1이라면 1의 모든 자식 객체들의 색깔들을 확인한다.
            {
                if(curColor == RED)
                {
                    colored[vecVer[idx][i]] = BLUE;
                    q.push(vecVer[idx][i]);
                }
                else if(curColor == BLUE)
                {
                    colored[vecVer[idx][i]] = RED;
                    q.push(vecVer[idx][i]);
                }
            }
        }
    }
}

void dfs(int start, int color)
{
    colored[start] = color;
    for(int i = 0; i < vecVer[start].size(); ++i)
    {
        int next = vecVer[start][i];
        
        if(colored[next] == 0)
        {
            dfs(next, 3 - color);
        }
    }
}


bool Bipartitegraph()
{
    for(int i = 1; i <= V; ++i)
    {
        for(int j = 0; j < vecVer[i].size(); ++j)
        {
            if(colored[i] == colored[vecVer[i][j]])
            {
                return false;
            }
        }
    }

    return true;

}

int main()
{

    Init();
    
    int K;
    cin >> K;

    
    int from, to;


    while(K--)
    {
        cin >> V >> E;

        for(int i = 1; i <= V; ++i)
        {
            colored[i] = 0;
            vecVer[i].clear();
        }

        for(int i = 0; i < E; ++i)
        {
            cin >> from >> to;
            vecVer[from].push_back(to);
            vecVer[to].push_back(from);
        }

        for(int i = 1; i <= V; ++i)
        {
            if(colored[i] == 0)
            {
                dfs(i,1); //기본 처음 시작은 RED로 고정
            }
        }

        if(Bipartitegraph())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

    }
    return 0;
}