#include <iostream>
#include <algorithm>

using namespace std;

int arr[100010];
int N;

//이분 탐색 -> target을 설정하여 (left + right)/ 2의 값을 갖는 mid와 비교해주는 알고리즘, 단 데이터 값들이 오름차순 혹 내림차순으로 정렬되어 있어야 된다.
//sort함수를 통해 먼저 정렬해놓자.
void solved(int target)
{
    int left = 0, right = N - 1;
    

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            cout << "1" << "\n";
            break;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

        if (left > right) //찾지못했을때 0을 출력해준다.
        {
            cout << "0" << "\n";
            break;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int M;
    cin >> M;

    sort(arr, arr + N);

    int *temp;
    temp = new int[M];

    for (int i = 0; i < M; ++i)
    {
        cin >> temp[i];
        solved(temp[i]);
    }

    delete temp;

    return 0;
}