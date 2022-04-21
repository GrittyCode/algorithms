#include <iostream>
#define MAX 10
using namespace std;

//퀵정렬 -> 분할 알고리즘 사용 (첫번째 원소 선택) -> i(첫 번째 원소 + 1), j(마지막 원소) 선정 -> i와 j 첫번째 원소와 비교 ->
//i는 ++ j는 --하며 i가 비교하는 원소보다 클때까지 ++, 만약 크다면 그 자리에 멈춘다, j는 원소가 작을때까지 -- 또한 더 작으면 그자리에서 멈춘다.

//퀵정렬 알고리즘 -> 재귀함수를 사용
//파티션 구분 => 피벗값 설정 한 후, 왼쪽 배열과 오른쪽 배열의 값들을 피벗값과 비교하며 왼쪽 배열의 값이 피벗값보다 클 경우와
//오른쪽 배열의 값이 피벗값보다 작은 경우 서로 위치를 변경해준다. 종료 조건은 왼쪽 배열의 검색 인덱스와 오른쪽 배열의 검색 인덱스가
//크로스 된 경우 검사를 하는 것을 종료해준 후, 오른쪽 배열의 인덱스값과 피벗값과 서로 교환해준다. 이후, 오른쪽 배열의 값을 반환하여
//다음 재귀의 피벗값을 설정해준다.
//ex) 1 8 2 7 6 3 일때, 정렬 할 경우 

//퀵 정렬 -> 매개변수가 배열, low, high를 통해 받아준다. 또한, 파티션을 구분지어주기 위해 
//퀵정렬의 경우 제자리 정렬이지만 안정적 정렬이 아니다.


//퀵 정렬의 시간복잡도의 경우 최악의 경우는 O(n^2), 평균적으로 O(n * log n)이다.
//비교횟수는 병합정렬보다 많지만 메모리 이동 횟수는 더 적어 병합정렬보다 빠르다.

//비교에 기반한 알고리즘의 최적의 시간복잡도는 O(n log n)이다. 특수한 정렬의 경우는 선형시간도 가능하다. (기수정렬, 계수정렬, 버킷정렬)

//3방향 퀵정렬
//시스템 정렬 -> 안정성이 요구되는 정렬의 경우 사용 주의! 주로 병합정렬, 퀵정렬을 사용한다.


int Partition(int arr[], int low, int high)
{
    int pivot = arr[low]; //첫번째 원소를 피벗값으로 설정
    int i = low, j = high + 1;
    while (true)
    {
        while (pivot > arr[++i]) //왼쪽 배열의 값이 피벗값 보다 클 때까지 진행
        {
            if (i >= high) break;
        }

        while (pivot < arr[--j])
        {
            if (j <= low) break;
        }
        
        //i와 j인덱스 값 변경

        //만약 크로스 된 경우는 종료해준다.
        if (i >= j) break;

        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //pivot값과 j값을 교환 -> 왜 i와 교환 안하냐? ex) 6 3 5 7 9
    //                                            p   j i
    //보는것과 같이 j는 최종적으론 피벗값보다 더 작은 값을 가르키게 된다. 그러므로 초기 피벗값과 j를 바꿔주는게 옳다.
    int temp;
    arr[low] = arr[j];
    arr[j] = pivot;

    //이후에는 피벗값으로 선정된 j를 반환해준다. j기준 왼쪽 배열과 오른쪽 배열은 작은 수, 큰 수로 정렬되어 있기 때문이다. 
    return j;

}

void QuickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int pivot = Partition(arr, low, high);
    QuickSort(arr, low, pivot);
    QuickSort(arr, pivot + 1, high);

}

void QuickSort3(int arr[], int low, int high)
{
    if (low >= high) return;
    int i = low, lt = low, gt = high;
    int v = arr[low];
    while (i <= gt)
    {
        if (arr[i] < v) //피벗값과 비교하여 피벗값이 더 크다면
        {
            //arr[lt]와 arr[i]를 교환
            int temp;
            temp = arr[lt];
            arr[lt] = arr[i];
            arr[i] = temp;
            lt++; 
            i++;
        }
            
        else if (arr[i] > v) //피벗값과 비교하여 피벗값이 더 작다면
        {
            //arr[i]와 arr[gt]를 교환
            int temp;
            temp = arr[gt];
            arr[gt] = arr[i];
            arr[i] = temp;
            gt--;
        }
        else i++; //값이 같다면 그냥 다음 인덱스로 옮겨준다.
    }
    QuickSort3(arr, low, lt - 1);
    QuickSort3(arr, gt + 1, high);
}


int main()
{
    int arr[MAX];

    cout << "퀵 정렬하고 싶은 수를 10개 아무 수나 입력하세요 : \n";

    for (int i = 0; i < MAX; ++i)
    {
        cin >> arr[i];
    }
    cout << "=================  정렬 중 =====================\n";
    cout << "================  정렬 완료 ====================\n";
    cout << "오름차순 기준 정렬된 배열 : ";

    QuickSort3(arr, 0, MAX - 1);

    for (int i = 0; i < MAX; ++i)
    {
        cout << arr[i] << " ";
    }
}
