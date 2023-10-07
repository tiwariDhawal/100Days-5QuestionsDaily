class Solution {
public:
    int solve(int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        int ans = solve(n-1) + solve(n-2);
        return ans;
    }
    int solve2(int n,vector<int>&dp){
        if(n == 0){
            return 1;

        }
        if(n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solve(n-1) + solve(n-2);
        return dp[n];
    }
    int solve3(int n,vector<int>&dp){
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i< n+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int solve4(int n){
        int prev2 = 1;
        int prev1 = 1;
        
        for(int i=2;i<=n;i++){
            int curr = (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n);
        // return solve2(n,dp);
        // return solve3(n,dp);
        return solve4(n);
    }
};