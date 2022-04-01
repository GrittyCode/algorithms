#include<iostream>
#include<vector>
#define MAX 100000

using namespace std;


/*
크기가 n인 배열 a를 삽입정렬하는 알고리즘

insertion_sort(a, n) for i=1,...,n-1
 x = a[i] j = i-1
 while( j >= 0 and a[j] > x) //내림차순 정렬 : a[j] < x
 a[j+1] = a[j] //한 칸씩 뒤로 이동
 j--
 a[j+1] = x //(j+1)이 a[i]의 삽입 위치
*/

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void Insertion_Sort(vector<int> v)
{
    for(int i = 1; i < v.size(); ++i)
    {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < temp) //j가 
        {
            v[j+1] = v[j];
            j--;
            v[j+1] = temp;
        }
    }

    cout << "<< 선택정렬로 내림차순 >>\n";
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';    
    }
    cout << '\n';
}




int main()
{
    Init();
    int iter;
    cin >> iter;
    int temp;
    vector<int> v;
    for(int i = 0; i < iter; ++i)
    {
        cin >> temp;    
        v.push_back(temp);
    }



    Insertion_Sort(v);


   



    return 0;
}