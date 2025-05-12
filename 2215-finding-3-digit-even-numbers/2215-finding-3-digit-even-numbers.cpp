class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count[10] = {0};
    for (int d : digits) count[d]++;

    vector<int> result;

    for (int num = 100; num <= 998; num += 2) {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        int needed[10] = {0};
        needed[a]++;
        needed[b]++;
        needed[c]++;

        bool valid = true;
        for (int d = 0; d < 10; ++d) {
            if (needed[d] > count[d]) {
                valid = false;
                break;
            }
        }

        if (valid)
            result.push_back(num);
    }

    return result;
    }
};