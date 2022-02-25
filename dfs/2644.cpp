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
//�θ�� �ڽ� 1��, ���� �ƹ���, �ƹ����� �Ҿƹ����� ���� 1�� -> ���� �Ҿƹ����� 2�� �ƹ��� ������� �Ҿƹ����� 1�� ���� �ƹ��� ��������� 3��
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