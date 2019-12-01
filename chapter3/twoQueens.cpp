#include <iostream>


/*
 * q(n) all possible ways to place two queens on n x n chessboard
 * 当在(n-1) x (n-1) 棋盘上加入一行一列变成 n x n 棋盘后，新增加2n-1 个位置，
 * 对于每个位置来说，其垂直或水平的(n-1)个位置不可放第二个皇后，其对角线及反对角线有2*n-2个位置不允许，
 * 则总共允许的位置有(2n-1)*(n^2-1-(3*n-3)), 但这时重复考虑了一个皇后在最后一行，而另个在最后一列的情况。
 * 对于每个位置而言，除了其对角线和最后一个((n, n)位置)不允许，其它n-2个位置都是允许的，
 * 则重复计数了(n-1)*(n-2)次。
 * q(n) = q(n-1) + (2n-1)*(n^2-1-(3n-3)) - (n-1)(n-2)
 * */
int twoQueens(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += 2*(i-1)*(i-1)*(i-2);
    }
    return sum;
}
