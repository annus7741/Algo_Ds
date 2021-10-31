// C++ program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{

    vector< vector<int> >res;
    vector<int> temp(k+1,0);
	int C[k + 1];
	memset(C, 0, sizeof(C));

    if(k>n)
    return 0;

    if((n-k)<k) k = n-k;

	C[0] = 1; // nC0 is 1
    temp[0] = 1;

    

	for (int i = 1; i <= n; i++) {
		// Compute next row of pascal triangle using
		// the previous row
        //we are going from min(i, k) till 0
        temp.resize(i+1);
		for (int j = min(i, k); j > 0; j--)
			{
                C[j] = C[j] + C[j - 1];
                temp[j] = temp[j-1]+temp[j];
            }
            res.push_back(temp);
	}
	
    res.push_back(temp);

    for(auto& row: res){
        for(auto& x: row){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return C[k];    

}

/* Driver code*/
int main()
{
	int n = 5, k = 2;
    
	printf("Value of C(%d, %d) is %d ", n, k,
		binomialCoeff(n, k));
	return 0;
}