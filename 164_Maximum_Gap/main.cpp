class Solution {
public:
    vector<int> digits(vector<int>& nums, int digit){
        vector<int> sortDigit;
        for (int i=0; i<nums.size(); i++){
            sortDigit.push_back((nums[i] & (1<<digit)) >> digit);
        }
        return sortDigit;
    }
    
    vector<int> countingSort(vector<int>& nums, vector<int>& order, int k){
        vector<int> res, temp;
        res.resize(nums.size());
        for (int i=0; i<k; i++)
            temp.push_back(0);
        for (int i=0; i<order.size(); i++)
            temp[order[i]]++;
        for (int i=1; i<k; i++)
            temp[i] += temp[i-1];
        for (int i=order.size()-1; i>=0; i--){
            res[temp[order[i]]-1] = nums[i];
            temp[order[i]]--;
        }
        return res;
    }
    
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        vector<int> temp;
        // radix sort
        // Time complexity O(n)
        for (int i=0; i<32; i++){
            // sort nums on digit i
            temp = digits(nums, i);
            nums = countingSort(nums, temp, 2);
        }
        int maxDiff = -1;
        for (int i=1; i<nums.size(); i++)
            if (nums[i] - nums[i-1] > maxDiff)
                maxDiff = nums[i] - nums[i-1];
        return maxDiff;
    }
};