#include<iostream>
#include<queue>

using namespace std;

const int dir[2][2] = { {1,0},{0,1} };
int n, K, A, B, C, map[200][200];
int dp[200][200][50]; //�����(x,y)��ʣ��ȼ��Ϊp������µ���С����

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
	// ��ʼ��dp����
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
	// ¼���ͼ
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> map[i][j];
		}
	}
	// ��ʼ����һ����(1,1),������㲻��Ҫ�ķ�����
	for (int i = 0; i <= K; i++) 
	{
		dp[1][1][i] = 0;
	}
	q.push(node{ 1,1,K }); //����ʼ������б�
	node top; //�����е�һ��Ԫ�ض�
	node next;//���ǵ���һ��Ԫ��
	int cost; //����
	while (!q.empty()) 
	{
		top = q.front();
		q.pop();
		// �����߻���������
		for (int i = 0; i <= 1; i++) 
		{
			next = node{ top.x + dir[i][0],top.y + dir[i][1],top.fuel - 1 };
			if (check(next.x, next.y)) 
			{
				// ����һ�µ�ǰ�Ļ���
				cost = dp[top.x][top.y][top.fuel];
				// ����һ��next�����
				if (map[next.x][next.y] == 1) 
				{ //������
					cost += A;
					next.fuel = K;
				}
				if ((!next.fuel) && ((next.x != n) || (next.y != n))) 
				{ //û����,Ҳû���յ�
					cost += A + C;
					next.fuel = K;
				}
				if (cost >= dp[next.x][next.y][next.fuel]) 
				{ //�����ǰ�Ļ����Ƚ��������ǵ���һ���ڵ�Ļ�����, �����϶��������ŵ�
					continue;
				}
				else 
				{ //���ɵ�ǰ���Ϊ���ŵ�
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
		// �����߻���������
		for (int i = 0; i <= 1; i++) 
		{ //����ͬ��
			next = node{ top.x - dir[i][0],top.y - dir[i][1],top.fuel - 1 }; // �����߻���������
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
				// ���ɵ�ǰ���
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
 
