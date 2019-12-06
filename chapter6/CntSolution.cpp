#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    Solution(const vector<int>& coin)
        : coin_(coin)
    {
    }
    int search(int n)
    {
        vector<int> count(n+1, 0);

        count[0] = 1;
        for(int x = 1; x <= n; ++x) {
            for(const auto& i : coin_) {
                if(x - i >= 0)
                    count[x] += count[x-i];
            }
        }
        return count[n];
    }
private:
    const vector<int>&     coin_;
};

int main()
{
    vector<int> coin{1,3,4};
    Solution sl(coin);
    std::cout << sl.search(5) << std::endl;
}
