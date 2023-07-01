#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
const int N = 10010;
int n,x[N],y[N],ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x[i] >> y[i];
    }

    sort(y + 1, y + n + 1);  // 按y坐标排序
    sort(x + 1, x + n + 1);  // 按x坐标排序
    for (int i = 1; i <= n; i++) x[i] -= i;  // 消除水平方向偏差
    sort(x + 1, x + n + 1);  // 按y方向偏差排序

    for (int i = 1; i <= n; i++)
        ans += abs(x[i] - x[(1 + n) / 2]) + abs(y[i] - y[(1 + n) / 2]);  // 计算步数

    cout << ans << endl;
    return 0;
}
