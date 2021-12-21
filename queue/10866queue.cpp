#include<iostream>
#include<string>

using namespace std;

#define MAX_SIZE 100000

class deque
{
private:
    int data[MAX_SIZE];
    int idx_front;
    int idx_rear;    
public:
    deque();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back(); 
    int size();
    int empty();
    int front();
    int back();
    
};

deque::deque()
{
    idx_front = 0;
    idx_rear = 0;
}

void deque::push_front(int x)
{
    data[idx_front] = x;
    idx_front = (idx_front - 1 + MAX_SIZE) % MAX_SIZE;
}

void deque::push_back(int x)
{
    idx_rear = (idx_rear + 1) % MAX_SIZE;
    data[idx_rear] = x;
}

int deque::pop_front()
{
    if(deque::empty())
    {
        return -1;
    }
    idx_front =  (idx_front + 1) % MAX_SIZE;
    return data[idx_front];
}

int deque::pop_back()
{
    if(deque::empty())
    {
        return -1;
    }
    int temp = data[idx_rear];
    idx_rear = (idx_rear - 1 + MAX_SIZE) % MAX_SIZE;
    return temp;
}

int deque::size()
{
    return (idx_rear - idx_front + MAX_SIZE) % MAX_SIZE;
}

int deque::empty()
{
    if(deque::size() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int deque::front()
{
     if(deque::empty())
    {
        return -1;
    }
    

    return data[(idx_front + 1) % MAX_SIZE];
}

int deque::back()
{
    if(deque::empty())
    {
        return -1;
    }

    return data[idx_rear];
}
int main(void)
{
    deque q = deque();

    int iter; //반복 횟수
    cin >> iter;

    string str;

    int temp;

    for(int i = 0; i < iter; ++i)
    {
        cin >> str;
        if(str == "push_front")
        {
            cin >> temp;
            q.push_front(temp);
        }
        else if(str == "push_back")
        {
            cin >> temp;
            q.push_back(temp);
        }
        else if(str == "pop_front")
        {   
            cout << q.pop_front() << "\n";
        }
        else if(str == "pop_back")
        {
            cout << q.pop_back() << "\n";
        }
        else if(str == "size")
        {
            cout << q.size() << "\n";
        }
        else if(str == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if(str == "front")
        {
            cout << q.front() << "\n";
        }
        else if(str == "back")
        {
            cout << q.back() << "\n";
        }
    }

    return 0;
}