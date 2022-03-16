#include <iostream>
#define MIN -987654321
using namespace std;


int mcss1(int a[], int n)
{
    int max = MIN;
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i; j <= n - 1; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += a[k];
            }
            //n^3
            if (sum > max)
            {
                max = sum;
            }
        }
    }

    return max;
}


int mcss2(int a[], int n)
{
    int max = MIN;
    for (int i = 0; i <= n - 1; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n - 1; ++j)
        {                 
            sum += a[j];
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    //n^2
    return max;
}


int main()
{
    int a[] = {-7,4,-3,6,3,-8,3,4};
    int max1 = mcss1(a, sizeof(a) / sizeof(int));
    cout << "mcss1 : "<< max1 << endl;
    int max2 = mcss2(a, sizeof(a) / sizeof(int));
    cout << "mcss2 : "<< max1 << endl;
    return 0;
}


