#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1000;


struct Node
{
	int used, f;
	int id;
	bool operator < (const Node &rhs) const
	{
		return f < rhs.f || (f == rhs.f && id > rhs.id);
	}
} a[N];

int f[N];
int d[N];
int t[N];
int pre_t[N];
int ans[N];
int temp_ans[N];
bool judge(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == temp_ans[i])
			continue;
		else
			return temp_ans[i] > ans[i];
	}
	return false;
}
int main()
{
	int n, h;
	int ka = 0 ;
	while (cin >> n && n)
	{
		cin >> h;
		int Max = -1;
		for (int i = 1; i <= n; i++)
			cin >> f[i];
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		for (int i = 1; i < n; i++)
		{
			cin >> t[i];
		}
		for (int i = 2; i <= n; i++)
			pre_t[i] = pre_t[i - 1] + t[i - 1];
		for (int i = 1; i <= n; i++)
		{
			int res = 0;
			priority_queue<Node>q;
			memset(temp_ans, 0, sizeof(temp_ans));
			while (!q.empty())
				q.pop();
			for (int j = 1; j <= i; j++)
			{
				a[j].id = j, a[j].used = 0, a[j].f = f[j];
				q.push(a[j]);
			}
			int cur_h = 60 * h - pre_t[i] * 5;
			cur_h /= 5;
			memset(temp_ans, 0, sizeof(temp_ans));
			while (cur_h > 0)
			{
				Node temp = q.top();
				cur_h --;
				q.pop();
				res += temp.f;
				temp.f -= d[temp.id];
				temp_ans[temp.id] ++;
				if (temp.f < 0)
					temp.f = 0;
				q.push(temp);
			}
			if (res > Max)
			{
				Max = res;
				for (int j = 1; j <= n; j++)
					ans[j] = temp_ans[j];
			}
		}
		if (ka ++)
			cout << endl;
		for (int i =  1; i <= n; i++)
			i == 1 ? cout << ans[i] * 5 : cout << ", " << ans[i] * 5;
		cout << endl;
		cout << "Number of fish expected: " << Max << endl;
	}
}
