#include <bits/stdc++.h>
using namespace std;
#define N 3

int dirx[] = { 1,0,-1,0 };
int diry[] = { 0,-1,0,1 };
int total = -1;

class Node 
{
public:
	Node* parent;
	int matrix[N][N];
	int x, y;
	int cost;
	int layer;
};

Node* addnode(int newMatrix[N][N], int x, int y, int newX, int newY, int layer, Node* parent) 
{
	Node* node = new Node();
	node->parent = parent;
	memcpy(node->matrix, newMatrix, sizeof(node->matrix));
	swap(node->matrix[x][y], node->matrix[newX][newY]);
	node->cost = 1000;
	node->layer = layer;
	node->x = newX;
	node->y = newY;
	return node;
}

int getf(int start[N][N], int end[N][N]) 
{
	int count = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (start[i][j] != end[i][j]) 
			{
				count++;
			}
		}
	}
	return count;
}

bool isSafe(int x, int y) 
{
	return (x >= 0 && x < N&& y >= 0 && y < N);
}

// 用来比较的
struct comp
{
	bool operator()(const Node* first, const Node* second) const
	{
		return (first->cost + first->layer) > (second->cost + second->layer);
	}
};

void printm(int matrix[N][N]) 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// 打印每一步
void output(Node* node) 
{
	if (node == NULL) 
	{
		return;
	}
	total++;
	output(node->parent);
	printm(node->matrix);
	cout << endl;
}

void bfs(int start[3][3], int end[3][3], int x, int y) 
{
	priority_queue<Node*, std::vector<Node*>, comp> best;
	Node* root = addnode(start, x, y, x, y, 0, NULL);
	root->cost = getf(start, end);
	best.push(root);
	while (!best.empty()) 
	{
		Node* min = best.top();
		best.pop();
		// 找到了最优解
		if (min->cost == 0) 
		{
			//cout << "ddd" << endl;
			output(min);
			cout << "总共用了: " << total << " 次" << endl;
			return;
		}
		// 现在要把它上下左右塞进去
		for (int i = 0; i < 4; i++) 
		{
			if (isSafe(min->x + dirx[i], min->y + diry[i])) 
			{
				Node* son = addnode(min->matrix, min->x, min->y, min->x + dirx[i], min->y + diry[i], min->layer + 1, min);
				son->cost = getf(son->matrix, end);
				best.push(son);
			}
		}
	}
}

int main() 
{

	int start[N][N];
	int x = 0;
	int y = 0;

	cout << "输入初始的矩阵(3x3): " << endl;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		 
		{
			cin>>start[i][j];
		}
	}

	int judge[N*N];
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			judge[i * N + j] = start[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < N * N; i++) 
	{
		if (judge[i] != 0) 
		{
			for (int j = 0; j < i; j++) 
			{
				if (judge[j] > judge[i]) 
				{
					count++;
				}
			}
		}
	}
	if (count % 2 == 1) 
	{
		cout << "逆序和为: " << count << ", 该状态下八数码问题无解" << endl;
		return 0;
	}

	cout << "==============================开始解题==============================" << endl;

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (start[i][j] == 0) 
			{
				x = i;
				y = j;
			}
		}
	}
	
	int final[N][N] = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,0}
	};

	bfs(start, final, x,y);

	return 0;
}
