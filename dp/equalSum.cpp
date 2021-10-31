#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[],int sum, int n){
    int t[n+1][sum+1];
    
    for(int i=0;i<=sum;i++)
        t[0][i]=false;
    
    for(int j=0;j<=n;j++)
        t[j][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            
            if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }else
            {
                t[i][j] = t[i-1][j]||t[i-1][j-arr[i-1]];
            }
            
        }
    }
    return t[n][sum];
}

int main(){
    int arr[] = {1,5,11,9};

    int sum = 0;

    for(auto x: arr)
        sum+=x;
    
    //if the total sum is odd we cannot make equal partition
    if(sum%2!=0)
        cout<<"No sum"<<endl;
    //else just check if there exits a subsequence with sum equals to range/2
    else
    {
        cout<<subsetSum(arr,sum/2,sizeof(arr)/sizeof(arr[0]))<<endl;
    }
    
    return 0;
}