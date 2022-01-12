#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct time
{
    int start;
    int end;

    time(int s, int e) : start(s), end(e) {} 
};

bool compaere(time a, time b)
{
    if(a.end == b.end)
    {
        return a.start < b.start;
    }
    else
        return a.end < b.end;
}

vector<time> vec;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(void)
{
    init();

    int N;
    cin >> N;

    int start_temp, end_temp;
    for(int i = 0; i < N; ++i)
    {
        cin >> start_temp >> end_temp;
        vec.push_back({start_temp,end_temp});
    }

    sort(vec.begin(),vec.end(),compaere);

    int cnt = 1;
    int curtime = vec[0].end;

    for(int i = 1; i < vec.size(); ++i)
    {
        if(curtime <= vec[i].start)
        {
            curtime = vec[i].end;
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}
