class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jump(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            jump[l]=max(jump[l],r-l);
        }
        int k=0,ans=0,i=jump.size()-1;
        for(auto i:jump){
            cout<<i<<" ";
        }
        while(i>0){
            bool flag=false;
            for(int j=i-1;j>=0;j--){
                if(jump[j]>=i-j){
                    k=j;
                    flag=true;
                }
            }
            if(!flag){
                return -1;
            }
            i=k;
            ans++;
        }
        return ans;
    }
};