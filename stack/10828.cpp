#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
#define MAX_STACK_SIZE 100001

class Stack
{
private:
    int data[MAX_STACK_SIZE];
    int topidx = - 1;

public:
    void push(int num)
    {
        data[++topidx] = num;
    }

    int pop()
    {
        if(topidx == -1)
            return -1;
        
        int temp = data[topidx];
        topidx--;
        return temp;
    }

    int size()
    {
        return topidx + 1;
    }

    int empty()
    {
        if(topidx == -1)
            return 1;
        else
            return 0;
    }

    int top()
    {
        if(topidx == -1)
            return - 1;

        return data[topidx];
    }
};

int main(void)
{
    Stack stack = Stack();

    int iter;

    cin >> iter;

    string input;
    int temp;

    for(int i = 0; i < iter; ++i)
    {
        cin >> input;

        if(input == "push")
        {
            cin >> temp;
            stack.push(temp);
        }
        else if(input == "top")
        {
            cout << stack.top() << endl;
        }
        else if(input == "size")
        {
            cout << stack.size() << endl;;
        }
        else if(input == "empty")
        {
            cout << stack.empty() << endl;
        }
        else if(input == "pop")
        {
            cout << stack.pop() << endl;
        }
    }

    return 0;
}

//gitconfi 갱신