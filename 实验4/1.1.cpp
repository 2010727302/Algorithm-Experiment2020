#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;
int n,k;
int a[1000010];
int getLeastNumbers(int nums[], int k) 
{
        //优先队列
        priority_queue<int,vector<int>,less<int>> q;
        for(int i =0; i< k; i++)//前k个元素入队
        {
            q.push(nums[i]);
        }
        if(!k)return {};
        //将数组剩下的元素入队,则top就是第k个元素
        //如果使用大根堆，则需要n个
        for(int i = k;i < n ;i++)
        {
            int t = q.top();//取最顶上的元素
            if(nums[i] < t)
            {
                q.pop();
                q.push(nums[i]);
            }
            //q.top现在是前i个元素的第k个最大元素
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

