#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<fstream>
using namespace std;

//邻接表写法
struct Edge2 
{
	int nex, vex2, weight;
}e[4005];

struct node 
{
	//x为当前值，g为估值函数，maxx为前面的最大值，step是当前的距离
	int x, f, maxx, step;
	bool operator < (node A) const 
	{
		return A.f < f;//优先队列按估值排序
	}
};
int n, m, cnt, head[105], dis[105];
bool vis[105]; 
queue<int> q;
//函数名：add
//功能：将边的相关信息插入到邻接表中
//参数：两个顶点和权值
//返回值：void
void add(int x, int y, int z) 
{
	e[++cnt].vex2 = y;
	e[cnt].weight = z;
	e[cnt].nex = head[x];//将一个顶点多个边关联起来
	head[x] = cnt;//head是以x为起点的最后输入的边的序号
	//cout << "head:"<< x <<" " << head[x] << " e:" << e[cnt].nex << " " << e[cnt].vex2 << " " << e[cnt].weight << endl;
}
//函数名：spfa
//功能：计算每个结点到终点的最短路径长
//参数：void
//返回值：void
void spfa() 
{
	memset(dis, 0x7ffffffff, sizeof(dis));
	memset(vis, false, sizeof(vis));
	q.push(n);//初始点放入que
	dis[n] = 0;
	vis[n] = 1;
	while (q.size()) //队列非空
	{
		int x = q.front();//用当前x更新
		q.pop(); 
		vis[x] = 0;
		for (int i = head[x]; i!=0; i = e[i].nex) //遍历x连接的节点
		{
			int y = e[i].vex2, we = e[i].weight;
			if (dis[y] > dis[x] + we)//如果出边对应的点需要松弛
			{
				dis[y] = dis[x] + we;
				if (!vis[y]) q.push(y), vis[y] = 1;//将y放入队列中，标记
			}
		}
	}
}
//函数名：Astar
//功能：计算最坏情况下的最短时间
//参数：void
//返回值：所需时间
int Astar() 
{
	//到x点花费了多长，和接下来最小可以花多少
	priority_queue<node> que; //优先更新预测花费最小的
	node tmp; 
	tmp.step = 0;
	tmp.f = dis[1], tmp.maxx = 0, tmp.x = 1; //估价函数，初始化，起点放入队列
	que.push(tmp);
	while (que.size())
	{
		node now = que.top();
		que.pop();
		if (now.x == n) //到达终点
		{
			int ans = now.maxx + now.step;
			cout<< "所需用时最长为"<<ans<<"min"<<endl;
			return ans;
		}
		for (int i = head[now.x]; i!=0; i = e[i].nex) 
		{
			node temp; 
			temp.step = now.step + e[i].weight;//起点到当前点的已走距离
			//1，总花费最小，2，路上max最小；
			temp.maxx = max(now.maxx, e[i].weight);//之前的最大值
			temp.f = temp.step + temp.maxx + dis[e[i].vex2]; //f = 到当前的路径和 + 路上max + 到end的最小值
			temp.x = e[i].vex2; 
			que.push(temp);
		}
	}
	return -1;
}
//函数名：BirthActivity
//功能：功能6的主函数
//参数：void
//返回值：void
void BirthActivity()
{
	int tim = 0;
	cout << "恭喜你触发隐藏事件：“生日献礼”该事件仅当生日当天触发" << endl;
	cout << "你现在在游玩翱翔-飞跃地平线,游玩结束后，你希望看到完整的花车表演。而花车表演从奇幻童话城堡开始。\n因为今天是你的生日，迪士尼乐园会给你派送小礼物，工作人员会在随机的两个游玩景点出现。\n为了领取小礼物，你可能需要完成一定的游戏，这会让你的行进速度减半。\n你是一个贪心怪，想要尽快赶到城堡来观看到晚上的花车表演，但是你也想要迪士尼的小礼物。\n你想请求万能的攻略手册计算是否来得及看到完整的花车表演" << endl;
	cout << "花车表演7：00开始,请输入距离花车表演开始时间" << endl;
	cin >> tim;
	ifstream TimeFile("Time.txt");
	if (!TimeFile) 
	{
		cout << "Time.txt文件打开失败，请检查！" << endl;
		return;
	}
	cout << "正在加载路径时间计算..." << endl;
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
	spfa(); //先用spfa求出每个结点到终点的最短距离
	int ans=Astar();
	if (ans >= tim)
	{
		cout << "您有可能赶不上花车观赏，速回" << endl;
	}
	else
	{
		cout << "您可以观看完整花车表演" << endl;
	}
	cout << endl;
}
