#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
    int N,K;
    cin >> N >> K;

    deque<int> q;

    int multiply;

    for(int i = 1; i <= N; ++i)
    {
        q.push_back(i); 
    }

    int queueARR[1001];

    int temp;

    //q.pop_front()을 K - 1 만큼 진행한 후, 임시 변수에 데이터들을 담고 q.push_back()으로 다시 넣어준다.
    // 그 이후로 front값을 수열에 담고 다시 pop_front()를 해준다. 
   
    for(int i = 0; i < N; ++i)
    {
       for(int j = 0; j < (K - 1); ++j)
       {          
           temp = q.front();
           q.pop_front();
           q.push_back(temp);
       }

       
       queueARR[i] = q.front();   
       q.pop_front();   
    }
    cout << "<";
    for(int i = 0; i < N - 1; ++i)
    {
        cout << queueARR[i] << "," << " ";
    }
    cout << queueARR[N-1];
    cout << ">";

    return 0;
}