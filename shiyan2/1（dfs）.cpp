#include<bits/stdc++.h>

#define debug(a) cout<<#a<<"="<<a<<endl

using namespace std;

const int N=110;

int n;//��Ʒ�ܸ���

int b;//��������

int nos;//�����Ӽ�����Ʒ����

int t[50];

int sum_v = 0, sum_w = 0;

vector<int>ans;//��¼���Ӽ�����Ʒ��ż�����

int w[N],v[N],flag[N];

int res;

//��¼��ǰ�Ӽ�

int record(int sum_v)

{

	int i;

	int count = 0;

	res = sum_v;

	ans.clear();

	for (i = 0; i <= n; i++)

	{

		if (flag[i])

			ans.push_back(i) ;

	}

	return count;

}



//�������Ž�

void findbest(int x)

{

	int i;

	if (sum_w > b)

		return;

	if (sum_v > res)

		nos = record(sum_v);

	for (i = x; i <= n; i++)

	{

		sum_v = sum_v + v[i];

		sum_w = sum_w + w[i];

		flag[i] = 1;



		findbest(i + 1);



		sum_v = sum_v - v[i];

		sum_w = sum_w - w[i];

		flag[i] = 0;

	}

}



int main()

{

	int i;

	printf("��������Ʒ������ ");

	cin >> n ;

	printf("�����뱳�����أ� ");

	cin >> b;

	printf("�������������������Լ���ֵ�� ");

	for (i = 0; i < n; i++)

	{

		cin>>w[i]>>v[i];

		

		flag[i] = 0;

	}



//	ans=findbest2();

	findbest(0);

	printf("���Ի�õ�����ֵ���Ӽ�Ϊ��\n");

	for (auto x:ans)

	{

		cout<<x<<" ";

	}

	cout<<endl;

	printf("�ܼ�ֵΪ %d\n", res);

	return 0;



}

