#include<iostream>

using namespace std;

#define MAX 9

int N, M;

int arr[MAX];



void dfs(int depth)
{
    if(depth == M)
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
        arr[depth + 1] = i;
        if(arr[depth + 1] >= arr[depth]) //비내림차순이라면 depth를 더 나아가도된다.
        {
            dfs(depth + 1);
        }

    }
}

int main(void)
{
    cin >> N >> M;

    dfs(0);

    return 0;


}