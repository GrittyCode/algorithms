#include <iostream>
#define MAX 8
using namespace std;


int aux[MAX]; //크기 8;


void InsertSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int ori_num = arr[i]; //비교하려는 값을 미리 저장한다.
        int j = i - 1; //왼쪽 한 칸 부터 비교를 시작.
        //내림 차순 비교하는 수 > arr[j], 현재는 오름차순
        while (j >= 0 && ori_num < arr[j]) //j가 0보다 작으면 종료 비교하는 값이 이전 인덱스보다 크거나 같으면 종료
        {
            arr[j + 1] = arr[j]; //비교하는 값이 더 작은 경우 arr[j]값이 더 크므로 arr[j + 1]칸으로 한 칸 앞으로 이동시킨다.(오름차순)
            j--; //인덱스를 왼쪽으로 하나 옮겨준다.
        }
        arr[j + 1] = ori_num; //작은 값을 찾은 후에도 j를 하나 빼줬으므로 원래의 위치를 찾기위해 j+1을 해준다.
    }
    
}

void Merge2(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    int low = left, k = left;
    int high = mid + 1;

    while (low <= mid && high <= right)
    {
        if (arr[low] <= arr[high])
        {
            aux[k++] = arr[low++];
        }
        else
        {
            aux[k++] = arr[high++];
        }
    }

    if (low >= mid) //오른쪽 배열이 남았을 경우
    {
        for (int i = high; i <= right; ++i)
        {
            aux[k++] = arr[i++];
        }
    }
    else
    {
        for (int i = low; i <= mid; ++i)
        {
            aux[k++] = arr[i++];
        }
    }

    for (int i = low; i <= right; ++i)
    {
        arr[i] = aux[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high) //종료조건
    {
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge2(arr, low, high);
}

int ArraySum(int arr[], int index)
{
    if (index == 0) return arr[index]; //종료조건
    return ArraySum(arr, index - 1) + arr[index];
}

int ArraySum3(int arr[], int low, int high) //반 씩 나눠서 재귀적으로 배열의 요소들을 더 해주는 함수
{
    //종료조건 작성
    if (low >= high) return arr[low]; //만약 더 low값이 high보다 크거나 같다면 배열의 요소가 하나만 존재하므로 종료하며 반환
    int mid = (low + high) / 2;
    return ArraySum3(arr, low, mid) + ArraySum3(arr, mid + 1, high);

}
int main()
{
    int arr[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        cin >> arr[i];
    }

    int size = MAX;

    MergeSort(arr, 0, size - 1);
    //int ISum = ArraySum(arr, size - 1);
    //int ISum2 = ArraySum3(arr, 0, size - 1);
    
    for (int i = 0; i < MAX; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    //cout << "총 합은" << ISum << "입니다. \n";
    //cout << "총 합은" << ISum2 << "입니다. \n";


    return 0;
}


/*
정렬
    숫자의 경우 숫자의 크기 순으로 정렬 보통은 오름차순, 특수한 경우 내림차순
    문자열은 사전 순서로 정렬 (대소문자)

    간단하지만 비효율적인 정렬 : 버블정렬, 삽입정렬, 선택정렬
    효율적이지만 복잡한 정렬 : 병합정렬, 퀵정렬, (힙정렬)
    특수한 상황에 쓰이는 정렬 : 기수정렬, 계수정렬, (버킷정렬)

    안정적 정렬 : 비교키가 같은 레코드의 경우 순서가 바뀌지 않는 정렬
    제자리 정렬 : 추가적인 메모리가 필요하지 않고 입력크기가 상관없는 정렬

    정렬은 주로 배열을 사용!
    배열의 특징 : 인덱스를 사용한 랜덤접근 가능, 연속된 메모리 공간에 데이터들이 저장된다

    정적 배열 : 최초 정적 할당한 배열의 크기는 바꿀 수 없다. 레코드의 추가 및 삭제가 없다.
    동적 배열 : c++의 vector와 같은 것. 레코드의 추가 삭제 가능, 배열의 크기가 바뀔 수 있다.


    삽입 정렬 : 카드를 한 장 뽑아 뒤의 원소들과 비교하여 작은곳으로 옮겨준다.
    //ex) 2 9 5 4 8 1 -> 2 9 5 4 8 1 -> 2 5 9 4 8 1 -> 2 4 5 9 8 1 -> 2 4 5 8 9 1 -> 1 2 4 5 8 9
    안정적 정렬 : O a[j] > x를 이용한 안정적 정렬 가능 ex) 2 "2" -> 2 > "2"는 옳지않으므로 옮기지 않는 것
    제자리 정렬 : O 추가적인 메모리 크기가 필요 없다.


    insertion_sort(a, n) for i=1,...,n-1
    x = a[i] j = i-1
    while( j >= 0 and a[j] > x) //내림차순 정렬 : a[j] < x
    a[j+1] = a[j] //한 칸씩 뒤로 이동
    j--
    a[j+1] = x //(j+1)이 a[i]의 삽입 위치

    삽입정렬의 최선의 경우는 선형시간 O(n)이고 평균적으로는 O(n^2)의 정렬시간이 걸린다.

    분할정복법
    step 1 -> 분할
    setp 2 -> 정복 분할된 것을 재귀적으로 정복
    step 3 -> 통합
    분할 정복법이 쓰인 정렬은 대표적으로 병합정렬, 퀵정렬이 있다.
    보통은 하향식 접근법이지만 동적 계획법의 경우 재귀를 꺼꾸로 상향식 접근법을 통해 푼다.

    재귀(순환) 알고리즘
    우아한 코드 작성 가능, 종료조건이 반드시 필요하다.

    마스터정리란?
    T(n) = aT(b/n) + c * n^k
    //if a < b^k  = o(n^k)
    // if a == b^k = o(n^k log n)
    // if a > b^k = o(n^log b ^ a)

    분할정복법을 피해야 하는 경우 -> 하노이탑, 지수시간알고리즘등

    병합 알고리즘의 시간복잡도는 선형시간이다! O(n)!
    병합 정렬 알고리즘의 시간복잡도가 O(n log n)인것!


*/
