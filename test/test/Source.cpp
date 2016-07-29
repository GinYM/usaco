/*
ID: dizzy_l1
LANG: C++
TASK: cowtour
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define MAXN 155
#define INF 0x3fffffff

using namespace std;

struct point
{
	double x, y;
} p[MAXN];
int flag[MAXN][MAXN], fat[MAXN];
double map[MAXN][MAXN], dist[MAXN];

int finds(int a)
{
	if (fat[a] == a)  return a;
	fat[a] = finds(fat[a]);
	return fat[a];
}

void floyd(int n)
{
	int i, j, k;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
}

double dist_ab(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	int n, fi, fj, i, j;
	if (scanf("%d", &n) == 1)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
			fat[i] = i;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				map[i][j] = ((i == j) ? 0 : INF);
				scanf("%1d", &flag[i][j]);
				//cout << flag[i][j];
				if (flag[i][j])
				{
					map[i][j] = dist_ab(p[i], p[j]);
					fi = finds(i); fj = finds(j);
					if (fi != fj) fat[fi] = fj;
				}
			}
			//cout << endl;
		}

		for (int i = 1; i <= n; i++)
		{
			finds(i);
		}

		floyd(n);
		double ans = INF;
		for (i = 1; i <= n; i++)
		{
			dist[i] = 0;
			for (j = 1; j <= n; j++)
			{
				if (map[i][j] != INF)
				{
					dist[i] = max(dist[i], map[i][j]);
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (flag[i][j] == 0 && fat[i] != fat[j])
				{
					cout << dist[i] + dist[j] + dist_ab(p[i], p[j]) << endl;
					ans = min(ans, dist[i] + dist[j] + dist_ab(p[i], p[j]));
				}
			}
		}
		for (i = 1; i <= n; i++)
			ans = max(ans, dist[i]);
		printf("%.6lf\n", ans);
		
	}
	return 0;
}