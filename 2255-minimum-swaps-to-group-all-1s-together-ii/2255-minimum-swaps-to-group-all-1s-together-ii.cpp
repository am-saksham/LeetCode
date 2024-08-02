class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for(int num : nums)
        {
            totalOnes += num;
        }

        if(totalOnes == 0 || totalOnes == n) return 0;

        vector<int> extended(nums.begin(), nums.end());
        extended.insert(extended.end(), nums.begin(), nums.end());

        int maxOnesInWindow = 0;
        int currentOnes = 0;
        for(int i = 0; i < totalOnes; i++)
        {
            currentOnes += extended[i];
        }
        maxOnesInWindow = currentOnes;

        for(int i = totalOnes; i < 2*n; i++)
        {
            currentOnes += extended[i] - extended[i - totalOnes];
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
    }
};