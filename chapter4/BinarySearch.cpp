#include <iostream>
#include <vector>

using namespace std;
//method 1
template<int N = 1>
int BinarySearch(const vector<int>& arr, int key)
{
    int n = arr.size();
    int a = 0, b = n-1;
    while(a <= b) {
        int m = (a+b)/2;
        if(arr[m] == key) return m;
        else if(arr[m] < key) a = m + 1;
        else b = m - 1;
    }
    return -1;
}

//method 0
template<>
int BinarySearch<0>(const vector<int>& arr, int key)
{
    int n = arr.size();
    int k = 0;
    for(int b = n/2; b >= 1; b /= 2) {
        while(b+k < n && arr[b+k] <= key) k += b;
    }
    if(arr[k] == key) return k;
    return -1;
}

int main()
{
    std::vector<int> arr{1,3,4,6,7,7,8,9};
    std::cout << "find 8: " << BinarySearch<0>(arr, 8) << std::endl;
}
