#include<iostream>
#include<string>
#include<stack>

using namespace std;



//vps인지 아닌지 판단하는 기준은 괄호가 ()형태가 되어야한다. -> (만 push로 해주고 )는 pop을 해준다.
//이렇게 진행할 경우, stack이 empty가 아니거나 stack이 비어있을때 )를 더해주면 right 변수를 ++해줘서 오류라는것을 알려준다.

int main(void)
{
    stack<char> s; //string 괄호 저장

    int iter; //실행 반복 횟수
    cin >> iter;
    cin.ignore(); //버퍼에 남아있는 값들을 모두 제거해주므로 cin을 받지 못하는 경우를 지워줌.

    string str;
    int overRight = 0;



    while (iter--)
    {

        getline(cin, str);

        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i] == '(')
            {
                s.push(str[i]);
            }
            else if(str[i] == ')')
            {
                if(!s.empty()) //스택이 비어있지 않으면 pop
                {
                    s.pop();
                }
                else //스택이 비어있다면 
                {
                    overRight++;//오버된 )괄호가 1이되는 순간 해당 문자열은 VPS가 아니다.
                }
            }
        } 

        if(!s.empty()) //스택이 비어있지않다면 NO
        {
            cout << "NO" << "\n";
        }
        else if(overRight != 0) //overRight가 0이 아니라면 NO
        {
            cout << "NO" << "\n";
        }
        else //스택이 비어있고 overRight가 0이라면 YES
        {
            cout << "YES" << "\n";
        }

        overRight = 0;//overRight 0으로 초기화

        while (!s.empty())
        {
            s.pop(); //해당 문자열에서 삭제되지 않은 인수를 삭제
        }
        

    }
    
    return 0;

}