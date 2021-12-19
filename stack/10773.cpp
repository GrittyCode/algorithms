#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main(void)
{
    int iter; //반복 횟수
    cin >> iter;

    int temp;

    stack<int> s; //스택 생성

    for(int i = 0; i < iter; ++i)
    {
        cin >> temp;
        if(temp == 0)
        {
            s.pop(); //0이라면 가장 최근 수를 빼줘야 한다.
        }
        else
        {
            s.push(temp); //0이 아니라면 stack s에 해당 수를 더해준다.
        }
    }


    int sum = 0; //더해줄 변수


    //s.size()는 2부터 시작하지면 pop을 할 시 점점 크기가 줄어들게 되어 오류가 뜬다.

    int size = s.size();

    for(int i = 0; i < size; ++i) //stack의 사이즈 만큼 해당 인덱스에 있는 수를 더해준다.
    {
        temp = s.top(); //최상위 노드 접근
        s.pop(); //노드 삭제
        sum += temp;
    } 

    cout << sum;

    return 0;
}