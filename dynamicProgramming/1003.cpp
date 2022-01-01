#include<iostream>

using namespace std;

#define MAX 40

int Fibo[MAX] = {0,1};


long long fibonacci(int n) 
{
   if(n == 0 || n == 1)
   {
      return Fibo[n];
   }
   else if(Fibo[n] == 0) //등록되지 않다면
   {
       Fibo[n] =  fibonacci(n - 1) + fibonacci(n - 2);
   }
   
   return Fibo[n];

}



//다이나믹 프로그래밍 -> 점화식을 이용한다. (재귀함수를 사용할 시 겹치는 부분이 발견될 경우 다이나믹 프로그래밍 사용할 필요가 있다.)
//0과 1의 나타나는 횟수의 점화식을 구한다.
//0의 경우 1 0 1 1 2... 의 피보나치 수열인데 1부터 시작하는 피보나치 수열이고 0의 경우 특수하게 1을 넣어준다.
//1의 경우 0 1 1 2 3....의 전형적인 피보나치 수열이므로 0부터 진행 된다.

int main(void)
{
    int  T;
    cin >> T;
    
    int tmp;

    for(int i = 0; i < T; ++i)
    {
        cin >> tmp;
        if(tmp == 0)
        {
            cout << "1 0" << "\n";
        }
        else
        {
            cout << fibonacci(tmp - 1) << " " << fibonacci(tmp) << "\n";
        }
    }


    return 0;
}