#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n;
int col[N],dg[N],udg[N];
char path[110][110];
int ans=0;
int isvalid(int u,int i)
{
	if(col[i]==1||dg[i-u+n]||udg[u+i])
		return 0;
	return 1;
}
void dfs(int u)
{
	if(u==n)
	{
// 		for(int i=0;i<n;i++)
// 		{
// 			for(int j=0;j<n;j++)
// 			{
// 				cout<<path[i][j];
// 			}
// 			cout<<endl;
// 		}
// 		cout<<endl;
        ans++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!isvalid(u,i))continue;
		path[u][i]='Q';
		col[i]=1;
		dg[i-u+n]=1;
		udg[u+i]=1;
		dfs(u+1);
		path[u][i]='.';
		col[i]=0;
		dg[i-u+n]=0;
		udg[u+i]=0;

	}
}
int main()
{
	while(cin>>n)
	{
		memset(path,'.',sizeof(path));
		ans=0;
		dfs(0) ;
		
		cout<<ans<<endl;
	}
    
    return 0;
}

