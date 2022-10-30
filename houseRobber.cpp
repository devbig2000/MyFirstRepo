
//house robber problem to accure max money if the two adjecent house will not be broken. and first and last are also not broken at a time because they are neighbour.

#include<bits/stdc++.h>
using namespace std;
int getMaxSum(vector<int> v,int n)
{
    vector<int>dp(n,-1);
    dp[0]=v[0];
    for(int i=1;i<n;i++)
    {
        int pick = v[i];
        if(i>1)
            pick+=dp[i-2];
        int nopick=dp[i-1];
        dp[i]=max(pick,nopick);
    }
    return dp[n-1];
}
int main()
{
    int arr[]={1,5,2,3,9};
    int n = 4;
    vector<int>v1;
    vector<int>v2;

    for(int i=0;i<n;i++)
    {
        if(i!=0)
            v1.push_back(arr[i]);
        if(i!=n-1)
            v2.push_back(arr[i]);
    }
    int l1=v1.size();
    int l2=v2.size();
    int sum1 = getMaxSum(v1,l1);
    int sum2 = getMaxSum(v2,l1);

    cout<<max(sum1,sum2);
    return 0;
}
