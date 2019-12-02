#include <iostream>
#include <vector>

class AllSubSet{
    int n_;
    std::vector<int> subset_;
public:
    AllSubSet(int n) : n_(n)
    {
        subset_.reserve(n);
    }

    void search(int k)
    {
        if(k == n_+1) {
            std::cout << "{";
            for(const auto& i : subset_) {
                std::cout << i << " ";
            }
            std::cout << "}\n";
        } else {
            subset_.push_back(k);
            search(k+1);
            subset_.pop_back();
            search(k+1);
        }
    }
};

int main()
{
    int a;
    std::cin >> a;
    AllSubSet subs(a);
    subs.search(1);
}
