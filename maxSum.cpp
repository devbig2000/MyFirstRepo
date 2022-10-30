
// maximun sum expect two adjacent element [2,3,4,5]=>(5+3)=8

// #include<bits/stdc++.h>
// using namespace std;
// int getMaxSum(int idx,int arr[],int n)
// {
//     if(idx==0)
//         return arr[idx];
//     int pick = arr[idx];
//     if(idx>1)
//         pick+=getMaxSum(idx-2,arr,n);
//     int nopick = getMaxSum(idx-1,arr,n);
//     return max(pick,nopick);
// }
// int main()
// {
//     int arr[]={1,5,2,3};
//     int n = 4;
//     int sum = getMaxSum(n-1,arr,n);
//     cout<<sum;
//     return 0;
// }

//memoiation 

// #include<bits/stdc++.h>
// using namespace std;
// int getMaxSum(int idx,int arr[],int n,vector<int> &dp)
// {
//     if(idx==0)
//         return arr[idx];
//     if(dp[idx]!=-1) return dp[idx];
//     int pick = arr[idx];
//     if(idx>1)
//         pick+=getMaxSum(idx-2,arr,n,dp);
//     int nopick = getMaxSum(idx-1,arr,n,dp);
//     return dp[idx]=max(pick,nopick);
// }
// int main()
// {
//     int arr[]={1,5,2,3};
//     int n = 4;
//     vector<int> dp(n,-1);
//     int sum = getMaxSum(n-1,arr,n,dp);
//     cout<<sum;
//     return 0;
// }

//tabulation

#include<bits/stdc++.h>
using namespace std;
int getMaxSum(int idx,int arr[],int n,vector<int> &dp)
{
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        int pick = arr[i];
        if(i>1)
            pick+=dp[i-2];
        int nopick = dp[i-1];
         dp[i]=max(pick,nopick);
    }
    return dp[n-1];
}
int main()
{
    int arr[]={1,5,2,3,1,9};
    int n = 6;
    vector<int> dp(n,-1);
    int sum = getMaxSum(0,arr,n,dp);
    cout<<sum;
    return 0;
}
