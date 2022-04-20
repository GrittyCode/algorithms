#include <iostream>
using namespace std;
#define MAX 8

int sort_Array[MAX];

void Merge(int arr[], int low, int high)
{
	int mid = (low + high) / 2;
	int i = low, k = low;
	int j = mid + 1;
	//i는 왼쪽 배열의 인덱스 역할, j는 오른쪽 배열의 인덱스 역할. k는 보조배열의 현재 인덱스 역할

	while (i <= mid && j <= high)
	{
		if (arr[i] <= arr[j])
		{
			sort_Array[k++] = arr[i++];
		}
		else
		{
			sort_Array[k++] = arr[j++];
		}
	}

	if (i > mid)
	{
		for (int l = j; l <= high; ++l)
		{
			sort_Array[k++] = arr[l];
		}
	}
	else
	{
		for (int l = i; l <= mid; ++l)
		{
			sort_Array[k++] = arr[l];
		}
	}



	for (int l = low; l <= high; l++)
	{
		arr[l] = sort_Array[l];//정렬된 배열을 복사한다
	}
}


void MergeSort(int arr[], int low, int high)
{
	if (low >= high) return;


	int mid = (low + high) / 2;
	MergeSort(arr, low, mid);
	MergeSort(arr, mid + 1, high);
	Merge(arr, low, high);
}

int main()
{
	int arr[MAX];
	for (int i = 0; i < MAX; ++i)
	{
		cin >> arr[i];
	}

	MergeSort(arr, 0, MAX - 1);

	for (int i = 0; i < MAX; ++i)
	{
		cout << arr[i] << " ";
	}
}
