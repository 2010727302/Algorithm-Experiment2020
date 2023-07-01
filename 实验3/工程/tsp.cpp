#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
#define INF 1e7
using namespace std;

int m[100][100];//�洢·������1��ʼ
int bestx[100];//���Ž�·��
int bestl;//���Žⳤ��
int n;//������Ŀ

//�������Ľڵ㶨��
struct node
{
    int cl;//��ǰ�߹���·������
    int id;//����ĵڼ�������
    int x[100];//��¼��ǰ·�����±��1��ʼ

    node() {}
    node(int cl_,int id_)
    {
        cl=cl_;
        id=id_;
        memset(x,0,sizeof(x));
    }
};



//���ڹ�����С��
struct cmp 
{
    //��ǰ·�����ȶ̵����ȼ���
    bool operator()(node n1, node n2)
    {
        return n1.cl > n2.cl;
    }
};

void bfs()
{
    //ѡ����С��
    priority_queue<node,vector<node>,cmp> q;
    //����һ���ڵ㣬�Ӹýڵ㿪ʼ����Ϊ1�ǹ̶�λ����ʵ�Ǵ�1��ʼ̽��
    node next_node(0,2);
    //��ʼ��������
    for(int i=1; i<=n; ++i)
        next_node.x[i]=i;
    q.push(next_node);
    node cur;//��ǰ�ڵ㣬Ҳ���ǻ�ڵ�
    int t;
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        t=cur.id;
        cout<<"cur.id:"<<cur.id<<" cur.cl"<<cur.cl<<" ·����" ;
        for(auto m:cur.x)
        {
        	cout<<m<<" ";
		}
		cout<<endl; 
        //���������ڶ�������
        if(t==n)
        {
            //����Լ����������·��
            //���ͼG�Ƿ����һ���Ӷ���x[n-1]������x[n]�ıߺ�һ���Ӷ���x[n]������1�ı�
            //�����ǰ������۲��ֲ�ͬ����Ϊ�����Ǵ�1��ʼ��������0��ʼ
            if(m[cur.x[t-1]][cur.x[t]]!=INF&&m[cur.x[t]][1]!=INF)
            {
                if(cur.cl+m[cur.x[t-1]][cur.x[t]]+m[cur.x[t]][1]<bestl)
                {
                    //�������Ž������·��
                    bestl=cur.cl+m[cur.x[t-1]][cur.x[t]]+m[cur.x[t]][1];
                    for(int i=1; i<=n; ++i)
                        bestx[i]=cur.x[i];
                }
            }
			continue;
        }
        //���ڵ�������·����û��Ҫ����̽���ˣ�����һ���ڵ㿪ʼ
        if(cur.cl>=bestl)
            continue;
        //�ӵ�ǰ�ڵ㿪ʼ̽��t-1 -> t,t+1,t+2...
        for(int j=t; j<=n; ++j)
        {
            //����Լ���������޽�����
            if(m[cur.x[t-1]][cur.x[j]]!=INF&&cur.cl+m[cur.x[t-1]][cur.x[j]]<bestl)
            {
                next_node=node(cur.cl+m[cur.x[t-1]][cur.x[j]],t+1);
                //����ҵ���һ���¼��ڵ㣬��ô�ýڵ㵽����Ϊֹ��ͬ���Ľڵ�·����ͬ�����˵�ǰ��һ���Ĳ�ͬ
                for(int k=1; k<=n; ++k)
                    next_node.x[k]=cur.x[k];
                swap(next_node.x[t],next_node.x[j]);
                q.push(next_node);
            }
        }
    }
}

int main()
{
    cout<<"�����������Ŀ:";
    cin>>n;

    //�Ƚ��г�ʼ��
    int i,j;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            m[i][j]=INF;
    memset(bestx,0,n);
    bestl=INF;
	m[1][2]=8,m[1][5]=9,m[1][6]=1;
	m[2][3]=5,m[2][4]=7,m[2][6]=4;
	m[3][2]=5,m[3][4]=8;
	m[4][2]=7,m[4][3]=8,m[4][5]=6,m[4][6]=7;
	m[5][1]=9,m[5][4]=6,m[5][6]=3;
	m[6][1]=1,m[6][2]=4,m[6][4]=7,m[6][5]=3;
//    for(int i=1;i<=n;i++) 
//	{
//        cout << "�������" << i << "�����е�·����Ϣ(��ͨ������-1):";
//        for (int j = 1; j <= n; j++) 
//		{
//            int next_node;
//            cin>>next_node;
//            if(next_node==-1)
//			{
//                continue;
//            }
//            m[i][j] = next_node;
//        }
//    }
    //����̽��
    bfs();
    cout<<"����ֵΪ��"<<bestl<<endl;
    cout<<"���Ž�Ϊ��";
    for(int i=1; i<=n; ++i)
        cout<<bestx[i]<<" ";
    cout<<bestx[1]<<endl;
    return 0;
}

