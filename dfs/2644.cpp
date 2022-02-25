#include<iostream>
#include<vector>
#define MAX 100 + 1
using namespace std;

vector<int> FamilyGraph[MAX];
bool isCheck[MAX];

int familyCnt = -1;


void dfs(int from, int to, int cnt)
{
    isCheck[from] = true;

    if(from == to)
    {
        familyCnt = cnt;
    }

    for(int i = 0; i < FamilyGraph[from].size(); ++i)
    {
        int child = FamilyGraph[from][i];
        if(!isCheck[child])
        {
            dfs(child, to, cnt + 1); 
        }
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//부모와 자식 1촌, 나와 아버지, 아버지와 할아버지는 각각 1촌 -> 나와 할아버지는 2촌 아버지 형제들과 할아버지는 1촌 나와 아버지 형제들과는 3촌
int main()
{
    Init();
    
    int N;
    cin >> N;
    int from, to;
    cin >> from >> to;
    int iter;
    cin >> iter;


    for(int i = 0; i < iter; ++i)
    {
        int a, b;
        cin >> a >> b;
        FamilyGraph[a].push_back(b);
        FamilyGraph[b].push_back(a);
    }

    dfs(from,to,0);

    cout << familyCnt;

    return 0;
}