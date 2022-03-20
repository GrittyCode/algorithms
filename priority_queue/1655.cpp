#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin >> n; //반복할 횟수

    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;

    //우선순위 큐를 두개 설정하는데, 하나는 큰 수가 가장 높은 우선순위, 또 하나는 가장 작은 수가 가장 높은 순위를 갖는 우선순위 큐를 만든다.
    //그 후, 가장 작은 수의 큐가 가장 큰 수의 큐보다 더 큰 수를 가지게 만들어준다.
    //또한, size를 비교해가며 가장 큰 수의 큐가 가장 작은 수의 큐보다 크기가 한 개 크게 진행하도록 값들을 순서대로 넣어준다.
    //이렇게 진행 할 경우, 큰 값의 큐의 가장 큰 값을 중간값으로 뽑아 올 수 있다.
    //오류를 없게 하기 위해 작은 수의 큐는 무조건 큰 수의 큐보다 큰 요소들만을 가져올수 있다. 이를 위해 요소를 넣을때마다 두 큐의 top을 비교해준다.
    // minQueue는 가장 작은 값을 우선순위로 가지기 떄문에 top에 minQueue의 가장 작은 수와 maxQueue의 가장 큰 값을 비교하여 교환 트리거를 설정한다.
    //만약 작은 큐의 가장 작은 수가 큰 큐의 가장 큰 수보다 작다면 서로 바꿔준 후, maxQueue의 top 값을 출력해준다.

    int temp;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (maxQueue.size() == 0) // maxQueue에 넣어진 원소가 아무것도 없을시 넣어주기만하고 출력. 그 후 maxQueue 사이즈가 1 더 크므로 minQueue와 오류 없이 비교 가능
        {
            maxQueue.push(temp);
        }
        else
        {
            if (maxQueue.size() > minQueue.size())
            {
                minQueue.push(temp);
            }
            else
            {
                maxQueue.push(temp);
            }

            if (maxQueue.top() > minQueue.top()) //내림차순 정렬인 maxqueue의 top이 minQueue의 top보다 크다면 minQueue와 매번 옮겨준다.
            {
                temp = maxQueue.top();
                maxQueue.pop();
                maxQueue.push(minQueue.top());
                minQueue.pop();
                minQueue.push(temp);
            }
        }
        cout << maxQueue.top() << "\n";
    }
    return 0;
}