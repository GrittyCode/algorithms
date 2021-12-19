#include<iostream>
#include<string>
#include<deque>

using namespace std;


int main(void)
{
    int iter;
    cin >> iter;

    int testcase;
    string orderStr; //명령줄
    string arrStr; //배열 명령줄
    deque<int> q;


    while(iter--)
    {      

        bool Reverse = false; //falseReverse
        bool error = false;

        cin >> orderStr >> testcase >> arrStr;

        for(int i = 0; i < arrStr.length(); ++i)
        {
            int x = 0;

            while((arrStr[i] >= '0' && arrStr[i] <= '9')) //숫자라면
            {      
                x *= 10;
                x += (int)(arrStr[i] - '0'); //더해주기    
                i++;           
            }

            if(x!=0)   
                q.push_back(x);
        }

        for(int i = 0; i < orderStr.length() ; ++i) //명령어 실행 구문
        {
            if(orderStr[i] == 'R') //R일때 실행하는 구문
            {
                Reverse = !Reverse; // R이 나올때 마다 반대로               
            }
            else if(orderStr[i] == 'D') //D일때 실행하는 구문
            {
                if(q.empty())
                {
                    cout << "error" << "\n";
                    error = true;
                    break;
                }
                if(Reverse)
                {
                    q.pop_back();
                }
                else
                {
                    q.pop_front();
                }
            }
        }

        if(!error) //error가 아니라면
        {
            cout << "[";
            while(!q.empty())
            {
  
                if(Reverse) //뒤집어져있다면
                {   
                    auto temp = q.back();
                    q.pop_back();
                    cout << temp;
                }
                else
                {
                    auto temp = q.front();
                    q.pop_front();
                    cout << temp;
                }
                if(!q.empty())
                    cout << ",";
            }
            cout << "]" << "\n";
        }   

        while(!q.empty())
        {
            q.pop_front(); //큐 비워주기.
        }
    }
    return 0;
}