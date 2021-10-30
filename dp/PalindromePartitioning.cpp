#include<bits/stdc++.h>
using namespace std;

int isPlaindrome(string s){
    int i =0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;j--;
    }
    return 1;
}

int palPartition(string s, int i, int j){
    if(i>=j)
        return 0;
    if(isPalindrome(s))
        return 0;

    int mn = INT_MAX;

    for(int k=i;k<=j-1;j++){
        int ans = palPartition(s,i,k)+palPartition(s,k+1,j)+1; 
        mn = min(mn,ans);
    }
    return mn;
}

int main(){
    string s = "ababbbabbababa";
    int i = 0,j=s.length()-1;
    cout<<palPartition(s,i,j)<<endl;
    return 0;
}
© 2021 GitHub, Inc.
Terms
