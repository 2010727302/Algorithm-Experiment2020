#include <iostream>
#include <cstdio>
#include <cstring>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
const long long N = 1E3+10,mod=1e9+7,INF = 0x3f3f3f3f3f3f3f3f;
int l[N][N];//�洢��������֮��ľ���
int n;//��������
int res = INT_MAX;//���·��
int sum[N];//���ÿ��·�ߵ�·���ܳ���
int begcity;//��Ǵӵ�begcity�����г���
int visited[N]; //��i�������Ѿ�ȥ����visited[i]=1;��֮��Ϊvisited[i]=0;
int path_index = 1; //�Ѿ�ȥ���ĳ�����Ŀ��
int path[N][N];//�洢�������е�·��
int route = 0;//�洢�ڼ���·��
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
                //����
                path_index--;
                visited[i] = 0;
            }
        }
    }
    else
    {
        //·���м������һ�����к͵�һ�����У���Ҫ���ص�����ĳ��У�
        path[route][path_index] = index;
        path[route][path_index + 1] = begcity;
        //����ÿ��·�ߵ�·���ܳ���,�����·��
        printf("·��%dΪ��\n",route+1);
        sum[route] = 0;
        for(int i=1;i<=n;i++)
        {
            sum[route] += l[ path[route][i] ][ path[route][i+1] ];
            cout << path[route][i] << " --> ";
            //��route+1��path[route][i]��ǰ����Ҫ���֣�����仯��
            path[route+1][i] = path[route][i];
        }
        if(res > sum[route]&&sum[route]>0)
        {
            res = sum[route];
        }
        cout << path[route][n+1] << endl;
        cout << "��·���ܳ���Ϊ�� " << sum[route] << endl;
        route++;
    }
    return 0;
}

int main()
{
    memset(visited,0,sizeof(visited));
    memset(l,0x3f,sizeof(l));
    cout << "���������������";
	cin >> n;
    printf("��������е�����֮��ľ���:\n");
    
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
	cout << "�������������ĳ����ǵڼ������У�";
    cin >> begcity;
    visited[begcity] = 1;
    dfs(begcity);
    cout << "���·�̳���Ϊ: ";
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

