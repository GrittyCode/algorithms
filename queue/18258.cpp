#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>

using namespace std;

queue<int> q;


string s;
int iter, X;



int main(void)
{
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> iter;

	for (int i = 0; i < iter; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> X;
			q.push(X);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else cout <<  -1 << '\n';

		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty") 
		{
			cout << q.empty() << '\n';
		}
		else if (s == "front")
		{
			if (!q.empty()) 
                cout << q.front() << '\n';
			else 
                cout << -1 << '\n';
		}
		else
		{
			if (!q.empty()) 
                cout << q.back() << '\n';
			else 
                cout << -1 << '\n';
		}
	}

	return 0;
}