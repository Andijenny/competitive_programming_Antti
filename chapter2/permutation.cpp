#include <iostream>
#include <vector>
#include "timer.h"
#include <algorithm>

template<typename T>
void print(const T& v)
{
    std::cout << "{";
    for(const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "}\n";
}

class permutation{
    int n_;
    std::vector<int> perm_;
    std::vector<char> chosen_;
public:
    permutation(int n) : n_(n)
    {
        perm_.reserve(n);
        chosen_.resize(n, 0);
    }

    void search()
    {
        if(perm_.size() == (size_t)n_) {
      //      print(perm_);
        } else {
            for(int i = 0; i < n_; ++i) {
                if(chosen_[i] == 1) continue;
                perm_.push_back(i+1);
                chosen_[i] = true;
                search();
                chosen_[i] = false;
                perm_.pop_back();
            }
        }
    }
};

void test(int n)
{
    std::vector<int> perm(n);

    for(uint32_t i = 0;i < n; ++i){
        perm[i] = i+1;
    }
    do{
    //    print(perm);
    }while(std::next_permutation(perm.begin(), perm.end()));
}

int main()
{
    int a;
    std::cin >> a;
    timer tic("my permutation");
    permutation p(a);
    p.search();
    tic.reset("std::next_permutation");
    test(a);
}
