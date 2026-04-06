class Solution {
public:
    char turn_left(char dir){
        if(dir=='N') return 'W';
        else if(dir=='S') return 'E';
        else if(dir=='E') return 'N';
        return 'S';
    }

    char turn_right(char dir){
        if(dir=='N') return 'E';
        else if(dir=='S') return 'W';
        else if(dir=='E') return 'S';
        return 'N';
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(auto& o:obstacles){
            st.insert({o[0],o[1]});
        } 

        int x=0,y=0,max_dist=0;char dir='N';
        for(int& c:commands){
            if(c==-2){
                dir=turn_left(dir);
            }
            else if(c==-1){
                dir=turn_right(dir);
            }
            else{
                int inc=c;
                if(dir=='N'){
                    while(inc>0){
                        int nx=x;
                        int ny=y+1;
                        if(st.count({nx,ny})!=0) break;
                        x=nx;
                        y=ny;
                        inc--;
                    }
                }
                else if(dir=='S'){
                    while(inc>0){
                        int nx=x;
                        int ny=y-1;
                        if(st.count({nx,ny})!=0) break;
                        x=nx;
                        y=ny;
                        inc--;
                    }
                }
                else if(dir=='E'){
                    while(inc>0){
                        int nx=x+1;
                        int ny=y;
                        if(st.count({nx,ny})!=0) break;
                        x=nx;
                        y=ny;
                        inc--;
                    }
                }
                else{
                    while(inc>0){
                        int nx=x-1;
                        int ny=y;
                        if(st.count({nx,ny})!=0) break;
                        x=nx;
                        y=ny;
                        inc--;
                    }
                }
                max_dist=max(max_dist,x*x + y*y);
            }
        }
        // cout<<x<<y<<endl;
        return max_dist;
    }
};