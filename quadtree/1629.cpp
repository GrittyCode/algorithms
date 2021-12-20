#include<iostream>

using namespace std;


long long pow(int A,int B, int C)
{
    if(B == 1)
    {
        return A;
    }
    else
    {
        long long temp = pow(A, B / 2, C);
        //B가 홀수면 A를 한번더 곱해준다
        if(B%2)
        {
            return ((temp*temp) % C * A) % C;
        }
        else
        {
            return (temp*temp) % C;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    cout << pow(A % C, B, C) << "\n";
    return 0;

}