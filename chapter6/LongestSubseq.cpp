#include <iostream>
#include <vector>

using namespace std;
int longestSubseq(const vector<int>& arr, vector<int>& sets)
{
    vector<int> length(arr.size(), 0);
    vector<int> path(arr.size(), -1);
    int b = 0;
    for(int k = 0; k < arr.size(); ++k) {
        length[k] = 1;
        for(int i = 0; i < k; ++i)
            if(arr[i] < arr[k] && length[k] < length[i] + 1) { 
                length[k] = length[i]+1;
                path[k] = i;
            }
        if(length[b] < length[k]) b = k;
    }
    sets.reserve(length[b]);
    sets.push_back(arr[b]);
    int i = path[b];
    while(i > -1) {
        sets.push_back(arr[i]);
        i = path[i];
    }
    return length[b];
}

int main()
{
   vector<int> arr{6,2,5,1,7,4,8,3};
   vector<int> path;

   int b = longestSubseq(arr, path);
   std::cout << "{";
   for(const auto& i : path)
       std::cout << i << " ";
   std::cout << "}" << std::endl;
}
