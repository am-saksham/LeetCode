class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.size() == 0)
    {
        return "";
    }
    
    if(strs.size() == 1)
    {
        return strs[0];
    }
    
    std::sort(strs.begin(), strs.end());
    
    int en = std::min(strs[0].size(), strs[strs.size()-1].size());
    
    std::string first = strs[0], last = strs[strs.size()-1];
    int i = 0;
    while(i < en && first[i] == last[i])
    {
        i++;
    }
    
    std::string pre = first.substr(0, i);
    return pre;
    }
};