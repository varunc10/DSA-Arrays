class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]==6){
                v[i]=9;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans*=10;
            ans+=v[i];
        }
        return ans;
    }
};