#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 10000001

int arr[MAX];


//QuickSort 접근법, KeyWord 재귀함수 사용, Pivot값 선정
//Pivot 자리 -> (맨 왼쪽 idx + 맨 오른쪽 idx) / 2
//맨 왼쪽 ~ Pivot값 까지 더 큰 값을 찾을때까지 left++
//Pivot ~ 맨 오른쪽 까지 더 작은 값을 찾을때까지 right--
//만약 둘다 찾았다면 서로 swap, 그리고 바로 left++ right-- 한 번 실행 해줌
//만약 left > right라면 while문 바로 탈출, 아니라면 다시 찾을때 까지 검사
//while문을 통과하지못하고 만약 못찾았다면 left right 둘 다 pivot값으로 동일한 곳에 이동
//동일할때는 if문에 들어가므로 left++ right-- 한 번 더 실행.
//left > right가 되므로 while()문 탈출,
//재귀함수로 constLeft ~ right left ~ constRight까지 실행 -> 계속 pivot값으로 한다면 pivot을 두 번 검사하며 겹치는 부분이 생겨서 오류 발생 위험
//만약 매개변수 left, right가 left >= right를 만족한다면 바로 함수 종료.
void QuickSort(int left, int right)
{
    if(left >= right)  return;
    
    const int constLeft = left; //인덱스의 맨 왼쪽 고정
    const int constRight = right; //인덱스의 맨 오른쪽 고정

    int pivot = arr[(left + right) / 2]; //가운데 값 피벗


    while(left <= right)
    {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        //pivot값과 같은것 까지 포함하면 피벗의 기준점을 넘어서 또 정렬하여 무한 반복이 될 위험이 있다.
        if(left <= right) //둘다 가운데 피벗값이 있을때까지 스왑해준다.
        {
            swap(arr[left],arr[right]);
            //만약 다 정렬한 경우, 둘 다 가운데에 있으므로 다음 while()문에 진입할때 바로 나가주기 위함. 
            left++; right--;
        }
    }

    QuickSort(constLeft, right); //right가 피벗값보다 한 칸 적게
    QuickSort(left, constRight); //left가 피벗의 가운데 ~ 맨 오른쪽까지 한 번 더 진행
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    QuickSort(0,N-1);

    for(int i = 0; i < N; ++i)
    {
        cout << arr[i] << "\n";
    }
    
    return 0;
}