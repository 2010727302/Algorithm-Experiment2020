#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
double a[100010];
double b[100010];
double sum[100010];

int n, L;

int check(double mid)
{
	double mins;
	for(int i = 1; i <= n; i ++ )
	{//求i到j的和应该是sum[j]-sum[i-1] 
		b[i - 1] = a[i - 1] - mid;
		sum[i] = sum[i - 1] + b[i - 1];
	} 	
	//前缀和处理 
	mins = 1e9;
	for(int i = L; i <= n; i ++ )
	{
		
		mins = min(mins, sum[i - L]);
		if(sum[i] - mins >= 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> n >> L;
	double minn = 1e9, maxx = 0;
	for(int i = 0; i < n; i ++ )
	{
		cin>>a[i];
		minn = min(a[i], minn);
		maxx = max(a[i], maxx); 	
	}
	
	double l = minn;
	double r = maxx;
	
	while(r - l > 1e-5)
	{
		double mid = l+ (( r - l ) / 2);
		if(check(mid))
		{  //满足条件说明平均数可以更大 
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	l += 1e-5;
	printf("%d", int(l*1000));
	return 0;
}

