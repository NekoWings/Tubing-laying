#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#define stop system("pause")

#define MAXN 20
const int INF = 1 << 30;
double graph[MAXN][MAXN];//图数据
double tree[MAXN][MAXN];//最小生成树
bool visited[MAXN];//标记
int N, M;
double vedge[MAXN];//权值
double min_E = 0;//最短路

using namespace std;
void init()
{
	for (size_t i = 1; i <= N; i++)
		for (size_t j = 1; j <= N; j++)
		{
			graph[i][j] = (double)INF;
		}
}//Give min num to the graph

void prime()
{
	for (size_t i = 1; i <= N; i++)//初始化vedge
		vedge[i] = graph[1][i];

	int k = 1;
	double min;
	memset(tree, 0, sizeof(double));//Clear tree
	memset(visited, false, sizeof(visited));//Clear visited
	vedge[1] = 0;
	visited[1] = true;// stop;
	for (size_t i = 0; i < N; i++)//loop N-1 times(N-1 edge)
	{
		int t = k;
		min = INF;//MAX
		for (size_t j = 1; j <= N; j++)
		{
			if (!visited[j] && min > vedge[j])//未访问且权值最小
			{
				min = vedge[j];
				k = j;
				//stop; cout << min << endl;
			}
			for (int m = 0; m < N - 1; m++)//识别路径
			{
				if (visited[m] && m != t&&min == graph[k][m])
					t = m;
			}
		}
		//stop; cout << "min over\n\n" << endl;
		visited[k] = true; //stop; cout << vedge[k] << "vedge" << endl;//已访问
		tree[t][k] = vedge[k];//build tree //bug fixing...
		min_E = min_E + vedge[k];//最短路
		for (size_t j = 1; j <= N; j++)
		{
			if (!visited[j] && vedge[j] > graph[k][j])
				vedge[j] = graph[k][j];
			vedge[k] = 0;
		}
	}
}

int solve()
{
	cout << "How many Tubings:";
	cin >> N;
	init();
	/*
	for (size_t i = 1; i <= N; i++)
	{
	for (size_t j = 1; j <= N; j++)
	{
	cout << setw(10) << graph[i][j];
	}
	cout << endl;
	}
	*/
	cout << "Set Tubings(Input ctrl+z to stop):" << endl;
	int x, y;
	double c;
	for (size_t i = 1; i <= N; i++)
		for (size_t i = 1; i <= N; i++)
		{
			cin >> x >> y >> c;
			if (graph[x][y] > c)
				graph[x][y] = c;
			if (graph[y][x] > c)
				graph[y][x] = c;
		}
	/*
	cout << "Checking" << endl;

	for (size_t i = 1; i <= N; i++)
	{
	for (size_t j = 1; j <= N; j++)
	{
	cout << setw(4) << graph[i][j];
	}
	cout << endl;
	}
	stop;
	*/
	cout << "programming...\n" << endl;
	prime();
	cout << "|||complete|||" << endl;
	for (size_t i = 0; i <= N; i++)
	{
		if (i == 0)
		{
			cout << setw(5) << " * ";
			continue;
		}
		cout << "(" << setw(2) << i << ")";
	}
	cout << endl;
	for (size_t i = 1; i <= N; i++)
	{
		cout << "(" << setw(2) << i << ")";
		for (size_t j = 1; j <= N; j++)
		{
			cout << setw(4) << tree[i][j];
		}
		cout << endl;
	}
	cout << "MIN TREE:" << min_E << endl;
	stop;
	return 0;
}

/*Data
8
1 2 1.3
1 3 2.1
1 4 0.9
1 5 0.7
1 6 1.8
1 7 2.0
1 8 1.8
2 3 0.9
2 4 1.8
2 5 1.2
2 6 2.8
2 7 2.3
2 8 1.1
3 4 2.6
3 5 1.7
3 6 2.5
3 7 1.9
3 8 1.0
4 5 0.7
4 6 1.6
4 7 1.5
4 8 0.9
5 6 0.9
5 7 1.1
5 8 0.8
6 7 0.6
6 8 1.0
7 8 0.5
*/