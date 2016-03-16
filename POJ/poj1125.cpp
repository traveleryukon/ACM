//
//  poj1125.cpp
//  MacPOJ
//
//  Created by yukon on 16/3/9.
//  Copyright © 2016年 yukon. All rights reserved.
//

/*
 POJ 1125 Stockbroker Grapevine
 
 Description
 Stockbrokers are known to overreact to rumours. You have been contracted to develop a method of spreading disinformation amongst the stockbrokers to give your employer the tactical edge in the stock market. For maximum effect, you have to spread the rumours in the fastest possible way.
 
 Unfortunately for you, stockbrokers only trust information coming from their "Trusted sources" This means you have to take into account the structure of their contacts when starting a rumour. It takes a certain amount of time for a specific stockbroker to pass the rumour on to each of his colleagues. Your task will be to write a program that tells you which stockbroker to choose as your starting point for the rumour, as well as the time it will take for the rumour to spread throughout the stockbroker community. This duration is measured as the time needed for the last person to receive the information.
 
 Input
 Your program will input data for different sets of stockbrokers. Each set starts with a line with the number of stockbrokers. Following this is a line for each stockbroker which contains the number of people who they have contact with, who these people are, and the time taken for them to pass the message to each person. The format of each stockbroker line is as follows: The line starts with the number of contacts (n), followed by n pairs of integers, one pair for each contact. Each pair lists first a number referring to the contact (e.g. a '1' means person number one in the set), followed by the time in minutes taken to pass a message to that person. There are no special punctuation symbols or spacing rules.
 
 Each person is numbered 1 through to the number of stockbrokers. The time taken to pass the message on will be between 1 and 10 minutes (inclusive), and the number of contacts will range between 0 and one less than the number of stockbrokers. The number of stockbrokers will range from 1 to 100. The input is terminated by a set of stockbrokers containing 0 (zero) people.
 
 Output
 For each set of data, your program must output a single line containing the person who results in the fastest message transmission, and how long before the last person will receive any given message after you give it to this person, measured in integer minutes.
 It is possible that your program will receive a network of connections that excludes some persons, i.e. some people may be unreachable. If your program detects such a broken network, simply output the message "disjoint". Note that the time taken to pass the message from person A to person B is not necessarily the same as the time taken to pass it from B to A, if such transmission is possible at all.
 Sample Input
 
 3
 2 2 4 3 5
 2 1 2 3 6
 2 1 2 2 2
 5
 3 4 4 2 8 5 3
 1 5 8
 4 1 6 4 10 2 7 5 2
 0
 2 2 5 1 5
 0
 Sample Output
 
 3 2
 3 10
 */

#include <iostream>

namespace poj1125 {

#define MAX_TimeWait             9999
#define MAX_StockbrokersCount    100

int matrix[MAX_StockbrokersCount][MAX_StockbrokersCount];
void floyd(int nMatrix)
{
    for (int iMid = 0; iMid < nMatrix; ++iMid) {
        for (int iStart = 0; iStart < nMatrix; ++iStart) {
            for (int iEnd = 0; iEnd < nMatrix; ++iEnd) {
                if ( matrix[iStart][iEnd] > (matrix[iStart][iMid]+matrix[iMid][iEnd]) ) {
                    matrix[iStart][iEnd] = (matrix[iStart][iMid]+matrix[iMid][iEnd]);
                }
            }
        }
    }
}

int main_1125(int argc, const char * argv[])
{
    int n = 0;
    std::cin >> n;
    while ( n > 0 ) {
        
        // 初始化消息为不可达
        for ( int i = 0; i < MAX_StockbrokersCount; ++i ) {
            for ( int j = 0; j < MAX_StockbrokersCount; ++j ) {
                matrix[i][j] = (i == j ? 0 : MAX_TimeWait);
            }
        }
        
        // 录入消息可达时间到二维表
        for ( int i = 0; i < n; ++i ) {
            int nLink = 0;
            std::cin >> nLink;
            while ( nLink-- > 0 ) {
                int pIndex = 0;
                int pTime = 0;
                std::cin >> pIndex >> pTime;
                matrix[i][pIndex-1] = pTime;
            }
        }
        
        // 算法求图中所有两点间的最短距离
        floyd( n );
        
        // 找每一列的最大，行间最小
        int outIndex = 0;
        int outTime = MAX_TimeWait;
        for (int i = 0; i < n; ++i) {
            
            int rowMax = 0;
            for (int j = 0; j < n; ++j) {
                rowMax = (matrix[i][j] > rowMax ? matrix[i][j] : rowMax);
            }
            
            if ( rowMax < outTime ) {
                outIndex = i;
                outTime = rowMax;
            }
        }
        
        if ( outTime < MAX_TimeWait ) {
            std::cout << outIndex+1 << " " << outTime << std::endl;
        } else {
            std::cout << "disjoint" << std::endl;
        }
        
        
        std::cin >> n;
    }
    
    return 0;
}


}

