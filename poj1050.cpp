//
//  poj1050.cpp
//  MacPOJ
//
//  Created by yukon on 16/2/29.
//  Copyright © 2016年 yukon. All rights reserved.
//

/*
 POJ 1050 To the Max
 
 Description
 
 Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.
 As an example, the maximal sub-rectangle of the array:
 
 0 -2 -7 0
 9 2 -6 2
 -4 1 -4 1
 -1 8 0 -2
 is in the lower left corner:
 
 9 2
 -4 1
 -1 8
 and has a sum of 15.
 
 Input
 The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
 
 Output
 Output the sum of the maximal sub-rectangle.
 
 Sample Input
 4
 0 -2 -7 0 9 2 -6 2
 -4 1 -4  1 -1

 8  0 -2
 
 Sample Output
 15
 
 */

#include <iostream>

namespace poj1050 {
    
#define MAX_ArrayLen    100

int matrix[MAX_ArrayLen][MAX_ArrayLen];
int array[MAX_ArrayLen];

int maxSub(int count)
{
    int maxSub = array[0];
    int curSub = 0;
    for ( int i = 0; i < count; ++i) {
        curSub = (curSub > 0 ? (array[i]+curSub) : array[i] );
        maxSub = (maxSub > curSub ? maxSub : curSub);
    }
    
    return maxSub;
}

int main_1050(int argc, const char * argv[])
{
    int n = 0;
    while ( std::cin >> n ) {
        
        memset(matrix, 0, MAX_ArrayLen*MAX_ArrayLen*sizeof(int));
        for ( int iR = 0; iR < n; ++iR) {
            for ( int iC = 0; iC < n; ++iC) {
                std::cin >> matrix[iR][iC];
            }
        }
        
        int maxSubMatrix = matrix[0][0];
        
        // 枚举首行
        for (int iStartR = 0; iStartR < n; ++iStartR) {
            
            memset( array, 0, MAX_ArrayLen*sizeof(int) );
            // 枚举IR到X(n)行之和
            for ( int iR = iStartR; iR < n; ++iR) {
                
                // 计算IR到X(n)行之和
                for ( int iC = 0; iC < n; ++iC) {
                    array[iC] += matrix[iR][iC];
                }
                
                // 求最大子串和
                int curMaxSubMatrix = maxSub( n );
                maxSubMatrix = ( maxSubMatrix > curMaxSubMatrix ? maxSubMatrix : curMaxSubMatrix);
            }
        }
        
        std::cout << maxSubMatrix << std::endl;
    }
    
    return 0;
}

    
}
