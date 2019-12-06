#include <iostream>
#include <algorithm>

// square(y, x) = max(square(y-1,x), square(y, x-1)) + val(y, x);
int pathInGrid(int arr[][5], int m, int n)
{
    int sum[m+1][n+1];
    for(int i = 0; i <= m; ++i) {
        sum[i][0] = 0;
    }
    for(int i = 0; i <= n; ++i) {
        sum[0][i] = 0;
    }

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j)
            sum[i][j] = std::max(sum[i-1][j], sum[i][j-1]) + arr[i-1][j-1];
    }
    return sum[m][n];
}

int main()
{
    int arr[5][5] = {3,7,9,2,7,9,8,3,5,5,1,7,9,8,5,3,8,6,4,10,6,3,9,7,8};

    std::cout << pathInGrid(arr, 5, 5) << std::endl;
}
