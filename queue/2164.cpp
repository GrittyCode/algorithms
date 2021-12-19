#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(void)
{
    int iter;
    cin >> iter;

    deque<int> q;
    
    for(int i = 1; i <= iter; ++i)
    {
        q.push_back(i);
    }

    int temp;

    for(int i = 0; i < iter; ++i)
    {
       if(q.size() > 1)
       {
            q.pop_front(); //queue의 가장 앞 부분을 빼준다. 
            temp = q.front();
            q.pop_front();
            q.push_back(temp);
       }
    }
    cout << q.front() << "\n";
    return 0;
}