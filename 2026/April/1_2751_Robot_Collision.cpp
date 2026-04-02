class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        if(n==1) return healths;
        stack<int> st;
        vector<bool> alive(n,true);
        vector<int> ans;

        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
            temp.push_back({positions[i],i});

        sort(temp.begin(),temp.end());
        for(auto &i:temp){
            int curr=i.second;
            if(directions[curr]=='R')
                st.push(curr);
            else{
                while(!st.empty()){
                    int top=st.top();
                    if(healths[top]>healths[curr]){
                        alive[curr]=false;
                        healths[top]--;
                        break;
                    }
                    else if(healths[top]<healths[curr]){
                        alive[top]=false;
                        st.pop();
                        healths[curr]--;
                    }
                    else{
                        alive[top]=false;
                        alive[curr]=false;
                        st.pop();
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(alive[i])
            ans.push_back(healths[i]);
        }
        return ans;
    }
};