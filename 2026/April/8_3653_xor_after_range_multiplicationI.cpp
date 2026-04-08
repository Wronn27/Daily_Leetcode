class Solution {
public:
    int MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(auto& q:queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            while(l<=r){
                nums[l]=(1LL*nums[l]*v)%MOD;
                l+=k;
            }
        }
        int xori=0;
        for(int i=0;i<n;i++){
            xori^=nums[i];
        }
        return xori;
    }
};