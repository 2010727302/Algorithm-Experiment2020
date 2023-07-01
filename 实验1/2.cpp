#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
const long long N = 1E5+10,mod=1e9+7,INF = 1e2+10;
typedef pair<int, int> PII;

int n,q,w,e,r,c; 
int m; 
char g[INF][INF],d[INF][INF];

PII pprev[INF][INF];
int dir[5][3]={{0,0},{0,-1},{-1,0},{0,1},{1,0}};
vector<PII>xpos;
int cnt[6];
int check(int i,int j)
{
    if(g[i][j]!='#'&&g[i][j]!='X')return 1;
    return 0;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>g[i][j];
            d[i][j]=g[i][j];
//            if(g[i][j]=='X')
//            {
//                vector.push_back({i,j});
//            }
        }
    }
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<c-1;j++)
        {
            if(g[i][j]!='#'&&g[i][j]!='X'
               &&g[i][j+1]!='#'&&g[i][j+1]!='X'
               &&g[i+1][j]!='#'&&g[i+1][j]!='X'
               &&g[i+1][j+1]!='#'&&g[i+1][j+1]!='X')
            {
                cnt[0]++;
            }
            else if(g[i][j]=='X'&&check(i,j+1)&&check(i+1,j)&&check(i+1,j+1)
               ||(check(i,j)&&g[i][j+1]=='X'&&check(i+1,j)&&check(i+1,j+1))
              ||(check(i,j)&&check(i,j+1)&&g[i+1][j]=='X'&&check(i+1,j+1))
              ||(check(i,j)&&check(i,j+1)&&check(i+1,j)&&g[i+1][j+1]=='X'))
            {
                cnt[1]++;
            }
            else if(g[i][j]=='X'&&g[i][j+1]=='X'&&check(i+1,j)&&check(i+1,j+1)
               ||(g[i][j]=='X'&&check(i,j+1)&&g[i+1][j]=='X'&&check(i+1,j+1))
               ||(g[i][j]=='X'&&check(i,j+1)&&check(i+1,j)&&g[i+1][j+1]=='X')
               ||(check(i,j)&&g[i][j+1]=='X'&&g[i+1][j]=='X'&&check(i+1,j+1))
              ||(check(i,j)&&check(i,j+1)&&g[i+1][j]=='X'&&g[i+1][j+1]=='X')
              ||(check(i,j)&&g[i][j+1]=='X'&&check(i+1,j)&&g[i+1][j+1]=='X'))
            {
                cnt[2]++;
            }
            else if(g[i][j]=='X'&&g[i][j+1]=='X'&&g[i+1][j]=='X'&&check(i+1,j+1)
               ||(g[i][j]=='X'&&g[i][j+1]=='X'&&check(i+1,j)&&g[i+1][j+1]=='X')
               ||(g[i][j]=='X'&&check(i,j+1)&&g[i+1][j]=='X'&&g[i+1][j+1]=='X')
               ||(check(i,j)&&g[i][j+1]=='X'&&g[i+1][j]=='X'&&g[i+1][j+1]=='X'))
            {
                cnt[3]++;
            }
            else if(g[i][j]=='X'&&g[i][j+1]=='X'&&g[i+1][j]=='X'&&g[i+1][j+1]=='X')
            {
                cnt[4]++;
            }        
        }
        
    }
   for(int i=0;i<=4;i++)
        {
            cout<<cnt[i]<<endl;
        }
	return 0;	
}
