#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
using namespace std;
const int N=110;
int n;//物品总个数
int b;//背包承重
int nos;//最优子集的物品数量
int t[50];
int sum_v = 0, sum_w = 0;
vector<int>ans;//记录该子集的物品编号及重量
int w[N],v[N],flag[N];
int res;
//记录当前子集
int record(int sum_v)
{
	int i;
	int count = 0;
	res = sum_v;
	ans.clear();
	for (i = 0; i <= n; i++)
	{
		if (flag[i])
			ans.push_back(i) ;
	}
	return count;
}

//计算最优解
void findbest(int x)
{
	int i;
	if (sum_w > b)
		return;
	if (sum_v > res)
		nos = record(sum_v);
	for (i = x; i <= n; i++)
	{
		sum_v = sum_v + v[i];
		sum_w = sum_w + w[i];
		flag[i] = 1;

		findbest(i + 1);

		sum_v = sum_v - v[i];
		sum_w = sum_w - w[i];
		flag[i] = 0;
	}
}
//利用二进制来决定哪一个装，哪一个不装
/*
例如 31:
二进制为 1 1 1 1 1 
这个就说明是所有物品1，2，3，4，5都装进去
*/
vector<int> findbest2()
{
	vector<int> myans;
	for(int i=0; i<1<<n; i++)
	{
        int sum=0;
        int wei=0;
        vector<int>ans;
        for(int j=0; j<n; j++)
        {
        	if(i >> j & 1)
        	{
        		wei += w[j];
        		sum += v[j];
        		ans.push_back(j+1);
			}    
		} 
		debug(wei);
		if(wei>=b)
		{
			continue;
		} 
		 
        if(sum>=res)
        {
//        	printf("可以获得的最大价值的子集为：\n");
			
        	myans=ans;
			res=sum;
		}
    }
    return myans;
} 
int main()
{
	int i;
	printf("请输入物品总数： ");
	cin >> n ;
	printf("请输入背包承重： ");
	cin >> b;
	printf("请输入各个物体的重量以及价值： ");
	for (i = 0; i < n; i++)
	{
		cin>>w[i]>>v[i];
		
		flag[i] = 0;
	}

//	ans=findbest2();
	findbest(0);
	printf("可以获得的最大价值的子集为：\n");
	for (auto x:ans)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	printf("总价值为 %d\n", res);
	return 0;

}
/*
4
10
7 42
3 12
4 40
5 25
*/
//3
//25
//20 20
//15 30
//10 25
