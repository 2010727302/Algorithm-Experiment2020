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

    sort(y + 1, y + n + 1);  // ��y��������
    sort(x + 1, x + n + 1);  // ��x��������
    for (int i = 1; i <= n; i++) x[i] -= i;  // ����ˮƽ����ƫ��
    sort(x + 1, x + n + 1);  // ��y����ƫ������

    for (int i = 1; i <= n; i++)
        ans += abs(x[i] - x[(1 + n) / 2]) + abs(y[i] - y[(1 + n) / 2]);  // ���㲽��

    cout << ans << endl;
    return 0;
}
