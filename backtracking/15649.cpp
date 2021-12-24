#include<iostream>

using namespace std;

#define MAX 9

int arr[MAX] = {0,};
bool visited[MAX] = {0,};

int N, M;

void dfs(int cnt)
{
    if(cnt == M)
    {
        for(int i = 1; i <= cnt; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return; //함수 종료
    }


    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false)
        {
            arr[cnt + 1] = i; 
            visited[i] = true;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }


}


int main(void)
{
    cin >> N >> M;

    dfs(0);

    return 0;
}