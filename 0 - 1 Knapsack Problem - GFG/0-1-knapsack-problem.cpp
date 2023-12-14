//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int memo[1001][1001];
    int helper(int W, int wt[], int val[], int n, int i) {
        if (i == n) {
            return 0;
        }
        if (memo[i][W] != -1) return memo[i][W];
        int notTake = helper(W, wt, val, n, i + 1);
        int take = INT_MIN;
        if (wt[i] <= W) take = val[i] + helper(W - wt[i], wt, val, n, i + 1);
        return memo[i][W] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(memo, -1, sizeof(memo));
       return helper(W, wt, val, n, 0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends