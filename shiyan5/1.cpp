#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long

/*S:ȫ�̳���*/
using namespace std;
//int x[] = { 10,20,35,40,50,65,75,85,100 };	/*����x:����վλ��(��������λ��)*/							
int main() 
{
    int d=0, n=0;
    cin >> d;
    cin >> n;
    int position[n + 1];/*����position:���͵��λ��*/	
    position[0] = 0;
    for (int i = 1; i <= n; i++) 
	{
        cin >> position[i];
    }
    int ans = 0;
    int curIndex = 1;
    bool hasArrived = false;
    while (true) 
	{
        if (hasArrived == true) 
		{
            break;
        }
        int cur = 0;
        for (; curIndex <= n; curIndex++) 
		{
            cur += position[curIndex];
            if (d < cur) 
			{
                ans++;
                break;
            } 
			else if (d >= cur && curIndex == n) 
			{
                hasArrived = true;
            }
        }
    }
    cout << "���ٵļ��ʹ���: " << ans << endl;
    return 0;
}
//10 20 35 40 50 65 75 85 100

//8
//4 8 5 7 6 2 3 4
