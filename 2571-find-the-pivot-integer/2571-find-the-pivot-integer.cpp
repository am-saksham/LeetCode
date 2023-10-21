class Solution {
public:
    int pivotInteger(int n)
{
    int sum = (n*(n+1))/2;
    int sq = std::sqrt(sum);
    if(sq*sq == sum)
    {
        return sq;
    } else
    {
        return -1;
    }
}

};