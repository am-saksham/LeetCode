class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = nums.size()/2;
        int i;
        if(nums[mid] == target)
        {
            return mid;
        } else if(target < nums[mid])
        {
            for(i = 0; i < mid; i++)
            {
                if(nums[i] < target && (i + 1 == nums.size() || nums[i + 1] >= target))
                {
                    return i+1;
                }
            }
            return 0;
        } else {
            for(i = mid; i < nums.size(); i++)
            {
                if(nums[i] < target && (i + 1 == nums.size() || nums[i + 1] >= target))
                {
                    return i+1;
                }
            }
            return nums.size();
        }
        
    }
};