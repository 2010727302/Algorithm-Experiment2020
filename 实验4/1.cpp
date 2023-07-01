#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<endl
#define ll long long
using namespace std;

int a[1000010];
int partition(int nums[],int low, int high)//划分 
{
	int randin=low+rand()%(high-low+1);
        swap(nums[randin],nums[low]);
	int pivot=nums[low];
    // debug(pivot);
    int l=low,r=high;
    while(l<r)
    {
        while(l<r&&nums[r]>pivot)r--;
        // debug(r);
        // debug(l);
        if(l<r)
        {
            nums[l] = nums[r];
            l++;
        }
        while(l<r&&nums[l]<pivot)l++;
        if(l<r)
        {
            nums[r] = nums[l];
            r--;
        }
        // debug(l); 
        // debug(nums[l]) ;
    }
    nums[r]=pivot;
    // debug(l);
    return l;
 } 

void qfind(int a[],int left,int right,int k)
{
	int mid=partition(a,left,right);
	if(k-1==mid)//第k小数，数组下标为k-1
		cout<<a[k-1];
	else if(k-1<mid)//在左区接着找
		qfind(a,left,mid-1,k);
	else qfind(a,mid+1,right,k);//在右区接着找 
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	qfind(a,0,n-1,k);
	return 0;
 } 

