#include <bits/stdc++.h>

using namespace std;

int dp[1010];

int w[1010],v[1010];

int n=0,m=0;

int main()

{

	cin>>n>>m;

	for(int i=1;i<=n;i++)

	{

		cin>>v[i]>>w[i];

	}

	for(int i=1;i<=n;i++)

	{

		for(int j=m;j>=v[i];j--)

		{

			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);

		}

	}

	cout<<dp[m]<<endl;

}
