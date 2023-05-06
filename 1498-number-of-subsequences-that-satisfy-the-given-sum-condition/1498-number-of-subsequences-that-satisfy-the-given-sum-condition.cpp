class Solution {
public:
    #define mod 1000000007
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, ans = 0;;
        vector<int> power(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            power[i] = (power[i - 1] * 2) % mod;
        } 
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                ans += power[j - i];
                ans %= mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};