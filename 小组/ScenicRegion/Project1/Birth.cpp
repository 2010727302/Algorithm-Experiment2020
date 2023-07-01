#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<fstream>
using namespace std;

//�ڽӱ�д��
struct Edge2 
{
	int nex, vex2, weight;
}e[4005];

struct node 
{
	//xΪ��ǰֵ��gΪ��ֵ������maxxΪǰ������ֵ��step�ǵ�ǰ�ľ���
	int x, f, maxx, step;
	bool operator < (node A) const 
	{
		return A.f < f;//���ȶ��а���ֵ����
	}
};
int n, m, cnt, head[105], dis[105];
bool vis[105]; 
queue<int> q;
//��������add
//���ܣ����ߵ������Ϣ���뵽�ڽӱ���
//���������������Ȩֵ
//����ֵ��void
void add(int x, int y, int z) 
{
	e[++cnt].vex2 = y;
	e[cnt].weight = z;
	e[cnt].nex = head[x];//��һ���������߹�������
	head[x] = cnt;//head����xΪ�����������ıߵ����
	//cout << "head:"<< x <<" " << head[x] << " e:" << e[cnt].nex << " " << e[cnt].vex2 << " " << e[cnt].weight << endl;
}
//��������spfa
//���ܣ�����ÿ����㵽�յ�����·����
//������void
//����ֵ��void
void spfa() 
{
	memset(dis, 0x7ffffffff, sizeof(dis));
	memset(vis, false, sizeof(vis));
	q.push(n);//��ʼ�����que
	dis[n] = 0;
	vis[n] = 1;
	while (q.size()) //���зǿ�
	{
		int x = q.front();//�õ�ǰx����
		q.pop(); 
		vis[x] = 0;
		for (int i = head[x]; i!=0; i = e[i].nex) //����x���ӵĽڵ�
		{
			int y = e[i].vex2, we = e[i].weight;
			if (dis[y] > dis[x] + we)//������߶�Ӧ�ĵ���Ҫ�ɳ�
			{
				dis[y] = dis[x] + we;
				if (!vis[y]) q.push(y), vis[y] = 1;//��y��������У����
			}
		}
	}
}
//��������Astar
//���ܣ����������µ����ʱ��
//������void
//����ֵ������ʱ��
int Astar() 
{
	//��x�㻨���˶೤���ͽ�������С���Ի�����
	priority_queue<node> que; //���ȸ���Ԥ�⻨����С��
	node tmp; 
	tmp.step = 0;
	tmp.f = dis[1], tmp.maxx = 0, tmp.x = 1; //���ۺ�������ʼ�������������
	que.push(tmp);
	while (que.size())
	{
		node now = que.top();
		que.pop();
		if (now.x == n) //�����յ�
		{
			int ans = now.maxx + now.step;
			cout<< "������ʱ�Ϊ"<<ans<<"min"<<endl;
			return ans;
		}
		for (int i = head[now.x]; i!=0; i = e[i].nex) 
		{
			node temp; 
			temp.step = now.step + e[i].weight;//��㵽��ǰ������߾���
			//1���ܻ�����С��2��·��max��С��
			temp.maxx = max(now.maxx, e[i].weight);//֮ǰ�����ֵ
			temp.f = temp.step + temp.maxx + dis[e[i].vex2]; //f = ����ǰ��·���� + ·��max + ��end����Сֵ
			temp.x = e[i].vex2; 
			que.push(temp);
		}
	}
	return -1;
}
//��������BirthActivity
//���ܣ�����6��������
//������void
//����ֵ��void
void BirthActivity()
{
	int tim = 0;
	cout << "��ϲ�㴥�������¼������������񡱸��¼��������յ��촥��" << endl;
	cout << "�����������氿��-��Ծ��ƽ��,�����������ϣ�����������Ļ������ݡ����������ݴ����ͯ���Ǳ���ʼ��\n��Ϊ������������գ���ʿ����԰���������С���������Ա����������������澰����֡�\nΪ����ȡС����������Ҫ���һ������Ϸ�����������н��ٶȼ��롣\n����һ��̰�Ĺ֣���Ҫ����ϵ��Ǳ����ۿ������ϵĻ������ݣ�������Ҳ��Ҫ��ʿ���С���\n�����������ܵĹ����ֲ�����Ƿ����ü����������Ļ�������" << endl;
	cout << "��������7��00��ʼ,��������뻨�����ݿ�ʼʱ��" << endl;
	cin >> tim;
	ifstream TimeFile("Time.txt");
	if (!TimeFile) 
	{
		cout << "Time.txt�ļ���ʧ�ܣ����飡" << endl;
		return;
	}
	cout << "���ڼ���·��ʱ�����..." << endl;
	TimeFile >> n >> m;
	while (TimeFile)
	{
		int x = 0, y = 0, z = 0;
		TimeFile >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}/*
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x =0, y = 0, z = 0;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	*/
	spfa(); //����spfa���ÿ����㵽�յ����̾���
	int ans=Astar();
	if (ans >= tim)
	{
		cout << "���п��ܸϲ��ϻ������ͣ��ٻ�" << endl;
	}
	else
	{
		cout << "�����Թۿ�������������" << endl;
	}
	cout << endl;
}
