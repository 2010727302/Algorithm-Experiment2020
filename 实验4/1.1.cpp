#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
int n,k;
int a[1000010];
int getLeastNumbers(int nums[], int k) 
{
        //���ȶ���
        priority_queue<int,vector<int>,less<int>> q;
        for(int i =0; i< k; i++)//ǰk��Ԫ�����
        {
            q.push(nums[i]);
        }
        if(!k)return {};
        //������ʣ�µ�Ԫ�����,��top���ǵ�k��Ԫ��
        //���ʹ�ô���ѣ�����Ҫn��
        for(int i = k;i < n ;i++)
        {
            int t = q.top();//ȡ��ϵ�Ԫ��
            if(nums[i] < t)
            {
                q.pop();
                q.push(nums[i]);
            }
            //q.top������ǰi��Ԫ�صĵ�k�����Ԫ��
        }
        return q.top();
    }
int main()
{

	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<getLeastNumbers(a, k) <<endl;
	return 0;
 } 

