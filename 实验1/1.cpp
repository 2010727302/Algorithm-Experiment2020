#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
const long long N = 1E5+10,mod=1e9+7,INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> PII;
string d;
string a="ABC";
string b="BABC";
string c="CCAABB";
int n,q,w,e; 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>d;
    for(int i=0;i<d.size();i++)
    {
        if (d[i] == a[i % 3])
		{
			q++;
		}
		if (d[i] == b[i % 4])
		{
			w++;
		}
		if (d[i] == c[i % 6])
		{
			e++;
		}
    }
    int maxx=max(max(q,w),e);
    cout<<maxx<<endl;
	if (q == maxx)
	{
		cout<<"Adrian\n";
	}
	 if (w == maxx)
	{
		cout<<"Bruno\n";
	}
	 if (e == maxx)
	{
		cout<<"Goran\n";
	}
	return 0;	
}
