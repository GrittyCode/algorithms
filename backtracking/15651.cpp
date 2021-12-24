#include<iostream>

using namespace std;

#define MAX 9
int N,M;

int arr[MAX];
int visited[MAX];

void dfs(int dpeth)
{
    if(dpeth == M)
    {
        for(int i = 1; i <= M; ++i)
        {
            cout << arr[i] << " ";
        }

        cout << "\n";

        return;
    }

    for(int i = 1; i <= N; ++i)
    {
        arr[dpeth + 1] = i;
        dfs(dpeth + 1);
    }
}


int main(void)
{
    cin >> N >> M;

    dfs(0);

    return 0;

}