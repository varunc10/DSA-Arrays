class Solution {
public:
    #define ll long long
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<ll> v(nums.size() + 1, 0);
        ll sum = (ll)nums[0];
        v[1] = (ll)nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += (ll)nums[i];
            v[i + 1] = sum;
        }
        vector<int> ans(nums.size(), -1);
        if (nums.size() < k) {
            return ans;
        }
        for (int i = k; i < nums.size() - k; i++) {
            int l = i - k, r = i + k;
            // cout<<v[l]<<" "<<v[r + 1]<<" "<<r - l + 1<<endl;
            ans[i] = (v[r + 1] - v[l]) / (r - l + 1);
        }
        return ans;
    }
};