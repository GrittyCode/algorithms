#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 1000000
int N,M;


unsigned height = 0;
unsigned int longLength = 0;

unsigned int tree[MAX];



int main(void)
{
    cin >> N >> M;

    for(int i = 0; i < N; ++i)
    {
        cin >>tree[i];
        longLength = max(longLength, tree[i]); // 최대값 구하기
    }

    unsigned int shortLength = 0, middle;


    while (shortLength <= longLength)
    {
        long long sum = 0; //자료형 조심! 최대 20억 길이가 필요하므로 21억으로는 턱없이 부족하다 그러므로 2^64를 받아주는 long long 자료형사용!
        middle = (longLength + shortLength) / 2; //가운데 값 구하기

        for(int i = 0; i < N; ++i)
        {
            if(tree[i] >= middle) //길이가 같으면 베이지 않는다.
            {
                sum += tree[i] - middle;
            }
        }

        if(M <=sum) //자른 나무의 길이가 같거나 더 크다면 높이를 늘려본다.
        {
            shortLength = middle + 1;
            height = max(height, middle);
        }
        else if(M > sum) //자른 나무의 길이가부족하다면 높이를 줄여서 자른다.
        {
            longLength = middle - 1;
        }
        
    }

    cout << height;
    
    return 0;
}