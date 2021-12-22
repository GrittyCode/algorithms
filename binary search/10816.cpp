#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

#define MAX 500000


int arr[MAX];
int N,M,card;

int main(void)
{

    //lowerbound(~,~,-10) : -10 이상의 값이 처음나타나는 위치
    //upperbound(~,~,-10) : -10 초과하는 값이 처음 나타나는 위치
    //ex)arr[] ={-10,-10,-10,5,6,8,9}
    // lowerbound = 0, upperbound =  3
    //upperbound - lowerbound = 3;

    //algorithm STL에 속한 upperbound와 lowerbound를 사용하면 쉽게 풀 수 있다.
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> card;
        arr[i] = card;
    }

    sort(arr,arr + N);

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        cin >> card;
        cout << upper_bound(arr, arr + N, card) - lower_bound(arr,arr+N,card) << " ";
    }

    return 0;

    
}