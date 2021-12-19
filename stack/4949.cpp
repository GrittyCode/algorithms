#include<iostream>
#include<string>
#include<stack>

using namespace std;



//vps인지 아닌지 판단하는 기준은 괄호가 ()형태가 되어야한다. -> (만 push로 해주고 )는 pop을 해준다.
//이렇게 진행할 경우, stack이 empty가 아니거나 stack이 비어있을때 )를 더해주면 right 변수를 ++해줘서 오류라는것을 알려준다.

int main(void)
{
    stack<char> s; //string 괄호 저장

    string str;
    int overRight = 0;



    while (1)
    {

        getline(cin,str);
        if(str == ".")
            break;
            
        for(int i = 0; i < str.length(); ++i)
        {
           if(str[i] == '(' || str[i] == '[')
           {
               s.push(str[i]); 
           }
           else if(str[i] == ')')
           {
               if(s.empty() || s.top() == '[')
               {
                   overRight++;
                   break; // 바로 균형잡힌 문자열이 아니므로 break
               }
               else
               {
                   s.pop();
               }
           }
           else if(str[i] == ']')
           {
               if(s.empty() || s.top() == '(')
               {
                   overRight++;
                   break;
               }
               else
               {
                   s.pop();
               }
           }
        } 

        if(!s.empty() || overRight != 0) //스택이 비어있지않거나 틀린 문자열이라면
        {
            cout << "no" << "\n";
        }
        else //스택이 비어있고 overRight가 0이라면 YES
        {
            cout << "yes" << "\n";
        }

        overRight = 0;//overRight 0으로 초기화

        while (!s.empty())
        {
            s.pop(); //해당 문자열에서 삭제되지 않은 인수를 삭제
        }
        
    }
    
    return 0;

}