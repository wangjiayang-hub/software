#include<stdio.h>
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], dp[N];;
int n;
int ans;
const int INF = 0x3f3f3f;

int solve4(int l, int r)
{
	if (l == r)
		return a[l];
	int mid = (l + r) >> 1;
	int left_sum = solve4(l, mid);
	int right_sum = solve4(mid + 1, r);
	int sum1 = 0, sum2 = 0, s1 = 0, s2 = 0;
	for (int i = mid; i >= l; --i)
	{
		s1 += a[i];
		sum1 = max(sum1, s1);
	}
	for (int i = mid + 1; i <= r; ++i)
	{
		s2 += a[i];
		sum2 = max(sum2, s2);
	}
	int sum = sum1 + sum2;

	return max(max(left_sum, right_sum), sum);
}

int main()
{
	int n;
	int w = 0;
	cout << "please input size" << endl;
	cin >> n;
	cout << "please input data" << endl;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			w++;
		}
	}
	if (w == n)
	{
		cout << "0";
	}
	else
	{
		cout << "输出最大子段和为：" << endl;
		int ans = solve4(1, n);
		cout << ans << endl;
	}
	return 0;

}
