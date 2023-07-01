#include <iostream>
#include <cstdio>
#include <cstring>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
const long long N = 1E3+10,mod=1e9+7,INF = 0x3f3f3f3f3f3f3f3f;
int l[N][N];//存储两个城市之间的距离
int n;//城市数量
int res = INT_MAX;//最短路径
int sum[N];//标记每条路线的路程总长度
int begcity;//标记从第begcity个城市出发
int visited[N]; //第i个城市已经去过：visited[i]=1;反之则为visited[i]=0;
int path_index = 1; //已经去过的城市数目。
int path[N][N];//存储经过城市的路线
int route = 0;//存储第几条路线
int dfs(int index)
{
    if(path_index != n)
    {
        for(int i=1;i <= n;i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                path[route][path_index] = index;
                path_index++;
                dfs(i);
                //回溯
                path_index--;
                visited[i] = 0;
            }
        }
    }
    else
    {
        //路线中加上最后一个城市和第一个城市（需要返回到最初的城市）
        path[route][path_index] = index;
        path[route][path_index + 1] = begcity;
        //计算每条路线的路程总长度,并输出路线
        printf("路线%d为：\n",route+1);
        sum[route] = 0;
        for(int i=1;i<=n;i++)
        {
            sum[route] += l[ path[route][i] ][ path[route][i+1] ];
            cout << path[route][i] << " --> ";
            //当route+1后，path[route][i]的前面需要保持，后面变化。
            path[route+1][i] = path[route][i];
        }
        if(res > sum[route]&&sum[route]>0)
        {
            res = sum[route];
        }
        cout << path[route][n+1] << endl;
        cout << "该路线总长度为： " << sum[route] << endl;
        route++;
    }
    return 0;
}

int main()
{
    memset(visited,0,sizeof(visited));
    memset(l,0x3f,sizeof(l));
    cout << "请输入城市数量：";
	cin >> n;
    printf("请输入城市到城市之间的距离:\n");
    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//        	if(i!=j)
//            	cin >> l[i][j];    
//        }
//    }
	l[1][2]=8,l[1][5]=9,l[1][6]=1;
	l[2][3]=5,l[2][4]=7,l[2][6]=4;
	l[3][2]=5,l[3][4]=8;
	l[4][2]=7,l[4][3]=8,l[4][5]=6,l[4][6]=7;
	l[5][1]=9,l[5][4]=6,l[5][6]=3;
	l[6][1]=1,l[6][2]=4,l[6][4]=7,l[6][5]=3;
	cout << "请输入您出发的城市是第几个城市：";
    cin >> begcity;
    visited[begcity] = 1;
    dfs(begcity);
    cout << "最短路程长度为: ";
    cout << res << endl;
    return 0;
}
/*
4
3 6 7
12 2 8
8 6 2
3 7 6
*/

