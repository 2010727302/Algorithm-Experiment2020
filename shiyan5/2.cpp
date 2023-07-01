#include<iostream>
#include<queue>

using namespace std;

const int dir[2][2] = { {1,0},{0,1} };
int n, K, A, B, C, map[200][200];
int dp[200][200][50]; //到达点(x,y)且剩余燃料为p的情况下的最小开销

struct node 
{
	int x;
	int y;
	int fuel;
};
queue<node> q;

int check(int x, int y) 
{
	if (x<1 || x >n || y<1 || y>n) 
	{
		return 0;
	}
	return 1;
}

int main() 
{
	cin >> n >> K >> A >> B >> C;
	// 初始化dp数组
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j <= n; j++) 
		{
			for (int k = 0; k <= K; k++) 
			{
				dp[i][j][k] = INT_MAX;
			}
		}
	}
	// 录入地图
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> map[i][j];
		}
	}
	// 初始化第一个点(1,1),到达这点不需要耗费能量
	for (int i = 0; i <= K; i++) 
	{
		dp[1][1][i] = 0;
	}
	q.push(node{ 1,1,K }); //将初始点加入列表
	node top; //队列中第一个元素额
	node next;//考虑的下一个元素
	int cost; //花销
	while (!q.empty()) 
	{
		top = q.front();
		q.pop();
		// 往右走或者往下走
		for (int i = 0; i <= 1; i++) 
		{
			next = node{ top.x + dir[i][0],top.y + dir[i][1],top.fuel - 1 };
			if (check(next.x, next.y)) 
			{
				// 更新一下当前的花销
				cost = dp[top.x][top.y][top.fuel];
				// 考虑一下next的情况
				if (map[next.x][next.y] == 1) 
				{ //加油了
					cost += A;
					next.fuel = K;
				}
				if ((!next.fuel) && ((next.x != n) || (next.y != n))) 
				{ //没油了,也没到终点
					cost += A + C;
					next.fuel = K;
				}
				if (cost >= dp[next.x][next.y][next.fuel]) 
				{ //如果当前的花销比接下来考虑的下一个节点的花销大, 那它肯定不是最优的
					continue;
				}
				else 
				{ //接纳当前情况为最优点
					dp[next.x][next.y][next.fuel] = cost;
					for (int j = next.fuel - 1; j >= 0; j--) 
					{
						if (dp[next.x][next.y][j] > cost) 
						{
							dp[next.x][next.y][j] = cost;
						}
						else 
						{
							break;
						}
					}
					q.push(next);
				}
			}
		}
		// 往左走或者往上走
		for (int i = 0; i <= 1; i++) 
		{ //基本同上
			next = node{ top.x - dir[i][0],top.y - dir[i][1],top.fuel - 1 }; // 往左走或者往上走
			if (check(next.x, next.y)) 
			{
				cost = dp[top.x][top.y][top.fuel] + B;
				if (map[next.x][next.y] == 1) 
				{
					cost += A;
					next.fuel = K;
				}
				if ((!next.fuel) && ((next.x != n) || (next.y != n))) 
				{
					cost += A + C;
					next.fuel = K;
				}
				if (cost >= dp[next.x][next.y][next.fuel]) 
				{
					continue;
				}
				// 接纳当前情况
				dp[next.x][next.y][next.fuel] = cost;
				for (int j = next.fuel - 1; j >= 0; --j)
				{
					if (dp[next.x][next.y][j] > cost) 
					{
						dp[next.x][next.y][j] = cost;
					}
					else 
					{
						break;
					}
				}
				q.push(next);
			}
		}
	}
	cout << dp[n][n][0];
	return 0;
}
//9 3 2 3 6
//0 0 0 0 1 0 0 0 0
//0 0 0 1 0 1 1 0 0
//1 0 1 0 0 0 0 1 0
//0 0 0 0 0 1 0 0 1
//1 0 0 1 0 0 1 0 0
//0 1 0 0 0 0 0 1 0
//0 0 0 0 1 0 0 0 1
//1 0 0 1 0 0 0 1 0
//0 1 0 0 0 0 0 0 0
 
