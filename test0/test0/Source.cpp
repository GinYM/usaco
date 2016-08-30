/*
PROG:milk6
ID:juan1973
LANG:C++
*/
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int e = 1005; const int v = 40;
struct arr{ int l, r, s, num; }a[e];
bool flag[v];
int map[v][v], f[v][v], x[v], pre[v], write[e];
int n, m, i, ans, temp, cnt, xx, y, z;
bool cmp(arr a, arr b) { return a.s>b.s || a.s == b.s&&a.num<b.num; }
bool cmp2(int a, int b) { return a<b; }
int flow(int k)
{
	int pop = 0, i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			map[i][j] = f[i][j];
	map[a[k].l][a[k].r] -= a[k].s;
	while (true)
	{
		int h = 0, t = 1; x[1] = 1;
		memset(pre, -1, sizeof(pre));
		while (h<t)
		{
			int now = x[++h];
			for (i = 1; i <= n; i++)
				if (pre[i]<0 && map[now][i]>0)
				{
					pre[i] = now; x[++t] = i;
				}
			if (pre[n]>0) break;
		}
		if (pre[n]<0) break; int aug = 2100000000;
		for (i = n; i != 1; i = pre[i]) aug = min(aug, map[pre[i]][i]);
		pop += aug;
		for (i = n; i != 1; i = pre[i])
		{
			map[pre[i]][i] -= aug; map[i][pre[i]] += aug;
		}
	}
	return pop;
}
int main()
{
	freopen("milk6.in", "r", stdin);
	freopen("milk6.out", "w", stdout);
	scanf("%ld%ld", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%ld%ld%ld", &xx, &y, &z);
		f[xx][y] += z;
		a[i].s = z; a[i].num = i;
		a[i].l = xx; a[i].r = y;
	}
	ans = flow(0); printf("%ld ", ans);
	sort(a + 1, a + m + 1, cmp);
	for (i = 1; i <= m; i++)
	{
		temp = flow(i);
		if (a[i].s + temp == ans)
		{
			f[a[i].l][a[i].r] -= a[i].s;
			write[++cnt] = a[i].num;
			ans = temp;
		}
	}
	printf("%ld\n", cnt);
	sort(write + 1, write + cnt + 1, cmp2);
	for (i = 1; i <= cnt; i++)
		printf("%ld\n", write[i]);

	return 0;
}

