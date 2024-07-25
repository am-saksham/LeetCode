class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        mergeSort(nums, low, high);
        return nums;
    }
    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        mergeArray(nums, low, mid, high);
    }
    void mergeArray(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> result;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                result.push_back(nums[left]);
                left++;
            } else {
                result.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            result.push_back(nums[left]);
            left++;
        }

        while(right <= high)
        {
            result.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            nums[i] = result[i-low];
        }
    }
};