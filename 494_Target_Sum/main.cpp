class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> sum(nums.size(), 0);
        sum[nums.size()-1] = nums[nums.size()-1];
        for (int i=nums.size()-2; i>=0; i--)
            sum[i] = sum[i+1] + nums[i];
        int res = 0;
        search(sum, nums, 0, S, 0, res);
        return res;
    }
    void search(vector<int>& sum, vector<int>& nums, int depth, int S, int cur, int &res){
        int n = nums.size();
        if (cur + sum[depth] < S || cur - sum[depth] > S)
            return;
        if (cur == S && depth == n){
            res++;
            return;
        }
        if (depth == n){
            return;
        }
        search(sum, nums, depth+1, S, cur+nums[depth], res);
        search(sum, nums, depth+1, S, cur-nums[depth], res);
    }
};