#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int iter;
    cin >> iter;

    stack<int> s;

    int origin[1000001];
    int solvedVec[1000001];

    //오큰수 -> 오른쪽 배열중에 큰 수중 가장 왼쪽에 있는 경우.

    int temp;

    for(int i = 0; i < iter; ++i) //배열 넣어주기
    {   
        cin >> origin[i];
    }


    for(int i = iter - 1; i >= 0; --i)
    {
        while (!s.empty() && origin[i] >= s.top())
        {
            s.pop();
            //오큰수는 가장 왼쪽의 것을 뽑기때문에 
            //s.top()보다 해당 origin[i]가 크다면 상관 없이 빼도 오류가 안난다.          
        }
        
        if(s.empty()) solvedVec[i] = -1;
        else solvedVec[i] = s.top();

        s.push(origin[i]);
            
    }

    for(int i = 0; i < iter; ++i)
    {
        cout << solvedVec[i] << " ";
    }

    return 0;
}