#include<iostream>

using namespace std;

#define MAX  1000000 + 1
#define MODULER 15746

int N;

int dp[MAX] {0,1,2};


int DpSolve(int cnt)
{
    if(cnt <= 2)
        return cnt;
        
    if(dp[cnt] == 0)
    {
        return dp[cnt] = (DpSolve(cnt - 1) + DpSolve(cnt - 2)) % MODULER; //등록
    }

    return dp[cnt];
    
}


int main(void)
{
    cin >> N;
    
    cout << DpSolve(N) % MODULER << "\n";
    return 0;
}