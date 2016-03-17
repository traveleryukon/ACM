//
//  poj1088.cpp
//  MacACM
//
//  Created by yukon on 16/2/28.
//  Copyright © 2016年 yukon. All rights reserved.
//

/*
 POJ 1088 滑雪
 
 Description
 Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
 16 17 18 19 6
 15 24 25 20 7
 14 23 22 21 8
 13 12 11 10 9
 
 一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
 
 Input
 输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
 
 Output
 输出最长区域的长度。
 
 Sample Input
 5 5
 1 2 3 4 5
 16 17 18 19 6
 15 24 25 20 7
 14 23 22 21 8
 13 12 11 10 9
 
 Sample Output
 25

 */

#include <iostream>

namespace POJ1088 {
    
#define MAX_MATRIX_LEN  100
    
// qsort
int compare(const void*a,const void*b)
{
    return *(int*)b - *(int*)a;
}


int matrix[MAX_MATRIX_LEN][MAX_MATRIX_LEN];

int maxLineLength(int r, int c)
{
    // 获得有序阶梯
    int* sortMatrix = new int[r*c];
    memset( sortMatrix, 0, r*c );
    int sortIndex = 0;
    for ( int iR = 0; iR < r; ++iR ) {
        for ( int iC = 0; iC < c; ++iC ) {
            sortMatrix[sortIndex++] = matrix[iR][iC];
        }
    }
    qsort(sortMatrix, r*c, sizeof(int), compare );
    
    //
    int lenMatrix[MAX_MATRIX_LEN][MAX_MATRIX_LEN];
    memset( lenMatrix, 0, MAX_MATRIX_LEN*MAX_MATRIX_LEN*sizeof(int) );
    
    int retMax = 0;
    for ( int i = 0; i < r*c; ++i ) {
        
        // 相等的数字就没必要重新算了
        if ( i > 0 && sortMatrix[i] == sortMatrix[i-1] ) {
            continue;
        }
        
        for ( int iR = 0; iR < r; ++iR ) {
            for ( int iC = 0; iC < c; ++iC ) {
                
                if ( sortMatrix[i] == matrix[iR][iC] ) {
                    
                    if ( iR > 0 && matrix[iR][iC] < matrix[iR-1][iC] && lenMatrix[iR][iC] <= lenMatrix[iR-1][iC] ) {
                        lenMatrix[iR][iC] = lenMatrix[iR-1][iC] + 1;
                    }
                    if ( iC+1 < c && matrix[iR][iC] < matrix[iR][iC+1] && lenMatrix[iR][iC] <= lenMatrix[iR][iC+1] ) {
                        lenMatrix[iR][iC] = lenMatrix[iR][iC+1] + 1;
                    }
                    if ( iR+1 < r && matrix[iR][iC] < matrix[iR+1][iC] && lenMatrix[iR][iC] <= lenMatrix[iR+1][iC] ) {
                        lenMatrix[iR][iC] = lenMatrix[iR+1][iC] + 1;
                    }
                    if ( iC > 0 && matrix[iR][iC] < matrix[iR][iC-1] && lenMatrix[iR][iC] <= lenMatrix[iR][iC-1] ) {
                        lenMatrix[iR][iC] = lenMatrix[iR][iC-1] + 1;
                    }
                    
                    if ( retMax < lenMatrix[iR][iC] ) {
                        retMax = lenMatrix[iR][iC];
                    }
                }
            }
        }
    }
    
    
    delete []sortMatrix;
    return retMax + 1;
}

int main(int argc, const char * argv[]) {
    
    int r = 0;
    int c = 0;
    while ( std::cin >> r >> c ) {
        
        memset( matrix, 0, MAX_MATRIX_LEN*MAX_MATRIX_LEN*sizeof(int) );
        
        for ( int iR = 0; iR < r; ++iR ) {
            for ( int iC = 0; iC < c; ++iC ) {
                std::cin >> matrix[iR][iC];
            }
        }
        
        std::cout <<  maxLineLength(r, c) << std::endl;
    }
    
    return 0;
}


}

