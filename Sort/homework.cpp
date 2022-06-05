#include<iostream>
#include<algorithm>

using namespace std;


class Time
{
   
public:
    int begin;
    int end;
    Time()
    {

    }
    Time(int p_begin, int p_end) : begin(p_begin), end(p_end)
    {

    }
};

bool Compare(Time A, Time B)
{
    if(A.begin == B.begin)
    {
        return A.end < B.end;
    }

    return A.begin < B.begin;
}

void PrintRealPlayPiano(Time time[], int size)
{
    cout << "\n============= 실제 수강생들의 연습시간 =============\n" ;
    int begin = 0, end = 0; //이전 수강생 시간이 끝난 시간 end 이전 수강생 시간이 시작한 시간 begin

    for(int i = 0; i < size ;++i)
    {       
        if(time[i].begin >= end)
        {
            end = time[i].end;
            cout << time[i].begin << " " << time[i].end << endl;
        }
    }
}

int main()
{
    int iter;
    cin >> iter;
    
    Time time[iter];
    for(int i = 0; i < iter; ++i)
    {
        int begin, end;
        cin >> begin >> end;
        time[i].begin = begin;
        time[i].end = end;
    }

    sort(time, time + iter,Compare);

    PrintRealPlayPiano(time, iter);

    return 0;
}