#include <iostream>
#include <algorithm>

using namespace std;

unsigned int K, N, MAXI = 0;

unsigned int lenLength[10000];

unsigned int ans;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> K >> N;

    for (int i = 0; i < K; ++i)
    {
        cin >> lenLength[i];
        MAXI = max(MAXI, lenLength[i]);
    }

    unsigned int min = 1, max2 = MAXI, middle;

    while (min <= max2)
    {

        middle = (min + max2) / 2;

        unsigned int cnt = 0;

        
        for (int i = 0; i < K; ++i)
        {
            cnt += lenLength[i] / middle;
        }

        if (cnt >= N)
        {
            min = middle + 1;
            ans = max(ans, middle);
        }
        else
        {
            max2 = middle - 1;
        }
    }


    cout << ans;

    return 0;
}