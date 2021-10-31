#include<bits/stdc++.h>
using namespace std;
//recursive solution of matrix chain multiplication problem
int solve(int arr[], int i, int j){
    //base condition for a single array
    if(i>=j)
    return 0;

    //returning the minimum cost by placing brackets between i to j
    //eg (A)(BCD), (AB)(CD), (ABC)(D)
    int mn = INT_MAX;
    for(int k=i; k<j; k++){
        //cost of multiplying the result matrices of the two solve function
        int cost = arr[i-1]*arr[k]*arr[j];
        int temp = solve(arr, i,k) + solve(arr,k+1,j)+ cost;
        if(temp<mn) mn = temp;
    }
    
    return mn;
}


int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr, 1,n-1)<<endl;
    return 0;
}