class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        if(coins[0][0]>=0)
        {
            for(int i=0;i<3;i++)
            dp[0][0][i]=coins[0][0];
        }
        else{
            dp[0][0][0]=coins[0][0];
            dp[0][0][1]=0;
            dp[0][0][2]=0;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) continue;
                int right_0=INT_MIN,right_1=INT_MIN,right_2=INT_MIN;
                int down_0=INT_MIN,down_1=INT_MIN,down_2=INT_MIN;
                
                if(coins[i][j]>=0){
                    if(i>0){
                        down_0=dp[i-1][j][0]+coins[i][j];
                        down_1=dp[i-1][j][1]+coins[i][j];
                        down_2=dp[i-1][j][2]+coins[i][j];
                    }
                    
                    if(j>0){
                        right_0=dp[i][j-1][0]+coins[i][j];
                        right_1=dp[i][j-1][1]+coins[i][j];
                        right_2=dp[i][j-1][2]+coins[i][j];
                    }
                }
                else{
                    if(i>0){
                        down_0=dp[i-1][j][0]+coins[i][j];
                        down_1=max(dp[i-1][j][0],dp[i-1][j][1]+coins[i][j]);
                        down_2=max(dp[i-1][j][1],dp[i-1][j][2]+coins[i][j]);
                    }
                    if(j>0){
                        right_0=dp[i][j-1][0]+coins[i][j];
                        right_1=max(dp[i][j-1][0],dp[i][j-1][1]+coins[i][j]);
                        right_2=max(dp[i][j-1][1],dp[i][j-1][2]+coins[i][j]);
                    }

                }
                dp[i][j][0]=max(down_0,right_0);
                dp[i][j][1]=max(down_1,right_1);
                dp[i][j][2]=max(down_2,right_2);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<3;i++)
            ans=max(ans,dp[m-1][n-1][i]);

        return ans;
    }
};