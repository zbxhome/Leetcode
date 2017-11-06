class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size()), result(nums.size(), 0);
        for (int i=0; i<nums.size(); i++)
            index[i] = i;
        divideAndConquer(nums, 0, nums.size()-1, index, result);
        return result;
    }
    
    void divideAndConquer(vector<int>& nums, int l, int r, vector<int>& index, vector<int>& result){
        if (l >= r)
            return;
        int mid = l + (r-l)/2;
        divideAndConquer(nums, l, mid, index, result);
        divideAndConquer(nums, mid+1, r, index, result);
        merge(nums, l, mid, r, index, result);
    }
    
    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& index, vector<int>& result){
        int x1 = l, x2 = mid+1;
        vector<int> c, d;
        while (x1<=mid && x2 <= r){
            if (nums[x1] <= nums[x2]){
                c.push_back(nums[x1]);
                d.push_back(index[x1]);
                // difference
                result[index[x1]]+=(x2-mid-1);
                x1++;
            }else{
                c.push_back(nums[x2]);
                d.push_back(index[x2]);
                //for (int i=x1; i<=mid; i++)
                    //result[index[i]]++;
                x2++;
            }
        }
        while (x1<=mid){
            c.push_back(nums[x1]);
            d.push_back(index[x1]);
            // difference
            result[index[x1]]+=(x2-mid-1);
            x1++;
        }
        while (x2 <= r){
            c.push_back(nums[x2]);
            d.push_back(index[x2]);
            x2++;
        }
        for (int i=0; i<c.size(); i++){
            nums[l+i] = c[i];
            index[l+i] = d[i];
        }
    }
};