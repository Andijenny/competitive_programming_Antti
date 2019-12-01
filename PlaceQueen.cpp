#include <iostream>
#include <vector>

class crossBoard {
    int n_; // n x n cross
    int placeCount_;
    std::vector<char>   col_;
    std::vector<char>   diag_;
    std::vector<char>   adiag_;
public:
    crossBoard(int n) : n_(n), placeCount_(0)
    {
        col_.resize(n, 0);
        diag_.resize(2*n-1, 0);
        adiag_.resize(2*n-1, 0);
    }

    int getQueenPlaceCount()
    {
        search(0);
        return placeCount_;
    }

    void search(int j)
    {
        if(j == n_) {
            placeCount_++;
            return;
        }
        for(int i = 0; i < n_; ++i) {
            if(col_[i] || diag_[i+j] || adiag_[n_-1+i-j]) continue;
            col_[i] = diag_[i+j] = adiag_[n_-1+i-j] = 1;  // current col , diagnal and anti-diagnal are signed with 1
            search(j+1);
            col_[i] = diag_[i+j] = adiag_[n_-1+i-j] = 0; // restore their values.
        }
    }
};

int main()
{
    int a;
    std::cin >> a;
    crossBoard queen(a);
    std::cout << "total number of placement: " << queen.getQueenPlaceCount() << std::endl;
}
