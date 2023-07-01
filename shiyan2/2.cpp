#include <bits/stdc++.h>
using namespace std;

int n;
int pay[21][21];   //pay[i][j]��ʾ������i�������j���˵ķ���Ϊpay[i][j]
int minn=INT_MAX;   //��ΪҪ����Сֵ�����Խ�minn��ʼ��Ϊ���������int�ͣ�
int sum=0;   //��¼���������еõ��Ĺ������ú�
int book[21];   //���ڱ��һ�����Ƿ��ѱ����乤����book[i]=0��ʾû�б����乤����book[i]=1��ʾ�Ѿ������乤��

void dfs(int t)
{
    if(t>=n)   //�Ѿ�����Ҷ�ӽ�㣬�����ж��Ƿ��ҵ�����С�ܷ���
    {
        if(minn>sum)   //û���ҵ���С�ܷ���
        {
            minn=sum;   //������С�ܷ���
            return;
        }
    }
    for(int i=0;i<n;i++)   //Ϊ�ڹ���t������
    {
        if(!book[i])   //��i���˻�û�б����Ź���
        {
            book[i]=1;   //������t�������i����
            sum+=pay[t][i];   //�����ܷ���
            if(sum<minn)   //�����ǰ�õ���sumС����Сֵ�����������������������֦
                dfs(t+1);
            book[i]=0;   //û�еõ���minn��С�ĺͣ�����
            sum-=pay[t][i];
        }
    }

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>pay[i][j];
        }
        book[i]=0;
    }
    dfs(0);
    cout<<minn<<endl;
    return 0;
}

