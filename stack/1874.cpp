#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
    stack<int> s;

    int iter;
    cin >> iter;

    ios::sync_with_stdio(0); //c++ 출력만
    cin.tie(0); cout.tie(0); //연결끊기

    int temp;

    int cnt = 1;

    string str;


    //수열을 만들수 없는 경우는 지금까지 나온 수 ex)4가 나온다면 4,3,2는 괜찮지만 4,2,3은 틀린 수열이 된다.
    //정리하자면, 내림차수로 나와야 한다.
    //만약 자신보다 큰 수가 나온다면 또 다른 수열을 만든다고 생각하면 쉽다.
    //이 문제의 예시를 들자면 4,3,6,8,7,5,2,1인데  
    //처음에는 4,3,6의 수열 그 이후론 6의 수열 그 이후론 8,7,5,2,1의 수열이다. 
    //본 수열은 모두 내림차순을 어기지 않았기 때문에 NO가 출력되지 않고 수열을 만들 수 있다.
    //하지만, 2번째 1,2,5,3,4는 수열 1 그리고 2 그리고 5,3,4로 되는데
    //5,3,4가 내림차순의 성질을 성립 못하기 때문에 NO가 출력되게 된다.


    for(int i = 0; i < iter; ++i)
    {
        
        cin >> temp;

        if(cnt <= temp)
        {
            while (cnt <= temp)
            {
                s.push(cnt++);
                str += "+\n";
            }
            s.pop();
            str += "-\n";

        }
        else
        {
            if(temp == s.top())
            {
                s.pop();
                str += "-\n";
            }
            else
            {
                str = "NO"; //수열을 만들수 없다면 NO로 초기화한다.
                break;
            }
        }                 
    }

    cout << str;

    return 0;
 
}
