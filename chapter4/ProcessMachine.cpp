#include <iostream>
#include <vector>

using namespace std;
/* total job k = 8,
 * machine number n = 3,
 * processing time p1 = 2, p2 = 3, p3 = 7
 * the minimal time to finish?*/

// valid(x) = [x/2] + [x/3] + [x/7] >= 8
//

int minimalTime(const vector<int>& p, int job)
{
    int n = p.size();

    auto valid = [&, job](int t) {
        int sum = 0;
        for(const auto& i : p)
            sum += (int) t/i;
        return sum >= job;
    };

    int x = -1;
    for(int b = p[0]*job; b >= 1; b /= 2) {
       while(!valid(x+b))  x += b;
    }
    return x+1;
}


int main()
{
    vector<int> p{2,3,7};

    std::cout << "minimal time: " << minimalTime(p, 8) << std::endl;
}
