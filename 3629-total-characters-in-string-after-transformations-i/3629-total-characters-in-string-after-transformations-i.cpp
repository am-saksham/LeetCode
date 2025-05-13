class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1000000007;
        vector<long long> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        while(t--) {
            vector<long long> newFreq(26, 0);
            for(int i = 0; i < 25; i++) {
                newFreq[i+1] = (newFreq[i+1] + freq[i]) % MOD;
            }

            newFreq[0] = (newFreq[0] + freq[25]) % MOD;
            newFreq[1] = (newFreq[1] + freq[25]) % MOD;

            freq = newFreq;
        }

        long long result = 0;
        for(int i = 0; i < 26; i++) {
            result = (result + freq[i]) % MOD;
        }

        return result;
    }
};