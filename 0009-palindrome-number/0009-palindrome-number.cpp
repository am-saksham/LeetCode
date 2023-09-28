class Solution {
public:
    bool isPalindrome(int x)
    {
        string num = to_string(x);
        string str = num;
        
        reverse(str.begin(), str.end());
        
        if(num == str)
        {
            return true;
        } else
        {
            return false;
        }
    }
};
