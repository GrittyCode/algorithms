#include<iostream>

using namespace std;

#define MAX 100
int arr[MAX];
int N,M;

//3장을 고르고, M

int main(void)
{
    
    cin >> N >> M;
    
    int min = 0;

    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N - 2; ++i)
    {
        for(int j = i + 1; j < N -1; ++j)
        {
            for(int w = j + 1; w < N; ++w)
            {
                if(arr[i] + arr[j] + arr[w] <= M && M - (arr[i] + arr[j] + arr[w]) < M - min)
                {
                    min = arr[i] + arr[j] + arr[w];
                }
            }
        }
    }

    cout << min;
    
    return 0;
}