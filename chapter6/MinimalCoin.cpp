#include <vector>
#include <iostream>
#include <algorithm>

class Solution{
private:
    int n_;
    const std::vector<int>& coin_;
    std::vector<int> value_;
    std::vector<char> ready_;
    std::vector<int> first_;
    const int INF = 1000000000;
public:
    Solution(const std::vector<int>& coin) : coin_(coin)
    {
    }
    
    template<int N=0>
    int resolve(int n)
    {
        n_ = n + 1;
        value_.resize(n_, INF);
        ready_.resize(n_, 0);
        first_.resize(n_, 0);

        if constexpr(N == 0) {
            return solve(n);
        } else {
            return solve2(n);
        }
    }
    /*recursive*/
    int solve(int x)
    {
        if(x < 0) return INF;
        if(x == 0) return 0;
        if(ready_[x]) return value_[x];
        int best = INF;
        for(const auto& i : coin_) 
            best = std::min(best, solve(x-i)+1);

        ready_[x] = 1;
        value_[x] = best;

        return best;
    }

    /*iterative*/

    int solve2(int x)
    {
        value_[0] = 0;
        for(int n = 1; n <= x; ++n) {
            value_[n] = INF;
            for(const auto& i : coin_) { 
                if(n >= i && value_[n] > value_[n-i] +1) {
                    value_[n] = value_[n - i]+1;
                    first_[n] = i; // record which coin that minimizes value_[n]
                }
            }
        }
        return value_[x];
    }

    std::vector<int> getSolution() const
    {
        int x = n_ - 1;
        std::vector<int> res;
        res.reserve(n_);
        while(x > 0) {
            int x1 = first_[x];
            res.push_back(x1);
            x -= x1;
        }
        return res;
    }

};

int main()
{
    std::vector<int> coin{1,3,4};
    Solution sl(coin);
    std::cout << "solution 1: minimal coin = " << sl.resolve<0>(10) << std::endl; 
    std::cout << "solution 2: minimal coin = " << sl.resolve<1>(10) << std::endl;
    std::cout << "solution set: {";
    auto ss = sl.getSolution();
    for(auto i : ss)
        std::cout << i << " ";
    std::cout << "}" << std::endl;
}
