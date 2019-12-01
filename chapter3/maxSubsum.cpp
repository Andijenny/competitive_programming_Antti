#include <iostream>
#include <vector>
#include <algorithm>

/*O(n)*/
int maxSubSum(const std::vector<int>& array)
{
    int maxSum = 0, sum = 0;
    for(int i = 0; i < array.size(); ++i) {
        sum = std::max(array[i], sum+array[i]);
        maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}

int main()
{
    std::vector<int> arr{-1,2,4,-3,5,2,-5,2};
    std::cout << maxSubSum(arr) << std::endl;
}


