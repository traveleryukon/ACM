//
//  poj1001.cpp
//  MacACM
//
//  Created by yukon on 16/2/26.
//  Copyright © 2016年 yukon. All rights reserved.
//

/*
 POJ 1001 Exponentiation
 
 Description
 
 Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems.
 
 This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
 
 Input
 The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
 
 Output
 The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
 
 Sample Input
 95.123 12
 0.4321 20
 5.1234 15
 6.7592  9
 98.999 10
 1.0100 12
 
 Sample Output
 548815620517731830194541.899025343415715973535967221869852721
 .00000005148554641076956121994511276767154838481760200726351203835429763013462401
 43992025569.928573701266488041146654993318703707511666295476720493953024
 29448126.764121021618164430206909037173276672
 90429072743629540498.107596019456651774561044010001
 1.126825030131969720661201

*/

// 注意：0^n n^0

#include <iostream>
#include <string>

namespace POJ1001 {

#define MAX_BigIntBuffer    50
#define MAX_AddIn           1000

// 1000next
int bufferBigInt[MAX_BigIntBuffer];
void multiplicationBufferBigInt(int factor)
{
    bufferBigInt[MAX_BigIntBuffer-1] *= factor;
    for ( int i = MAX_BigIntBuffer-2; i >= 0; --i) {
        
        bufferBigInt[i] *= factor;
        
        for ( int j = i; j < MAX_BigIntBuffer-1 && bufferBigInt[j] > MAX_AddIn; ++j) {
            bufferBigInt[j+1] += bufferBigInt[j]/MAX_AddIn;
            bufferBigInt[j] = bufferBigInt[j]%MAX_AddIn;
        }
        
    }
}
void printfBufferBigInt(int decimal)
{
    // 去除左边无用位
    int startIndex = MAX_BigIntBuffer-1;
    while ( bufferBigInt[startIndex] <= 0 && startIndex*3 > decimal) {
        --startIndex;
    }
    
    std::string strPrintf = "";
    for ( int i = startIndex; i >= 0; --i ) {
        strPrintf += ( '0' + bufferBigInt[i]/100 );
        strPrintf += ( '0' + (bufferBigInt[i]/10)%10 );
        strPrintf += ( '0' + bufferBigInt[i]%10 );
    }

    if ( decimal > 0 ) {
        strPrintf.insert( strPrintf.length() - decimal, "." );
    }
    
    int leftZero = 0;
    while ( strPrintf[leftZero] == '0' ) {
        leftZero++;
    }
    int rightZero = strPrintf.length() - 1;
    if ( decimal > 0 ) {
        while ( strPrintf[rightZero] == '0' && leftZero < rightZero ) {
            --rightZero;
        }
    }
    
    strPrintf = strPrintf.substr(leftZero, rightZero-leftZero+1);
    
    if ( '.' == strPrintf[strPrintf.length()-1] ) {
        strPrintf = strPrintf.substr(0, strPrintf.length()-1);
        if ( strPrintf.length() <= 0 ) {
            strPrintf = "0";
        }
    }
    
    std::cout << strPrintf << std::endl;
}

int main(int argc, const char * argv[])
{
    float r = 0;
    int n = 0;
    
    while ( std::cin >> r >> n ) {
        
        memset(bufferBigInt, 0, MAX_BigIntBuffer*sizeof(int));
        
        // 小数转整数，并记录小数点位置
        int decimal = 0;
        if ( r < 1 ) {
            r *= 10000;
            decimal = 4;
        } else {
            while ( r < 10000 ) {
                r *= 10;
                decimal += 1;
            }
        }
        decimal *= n;
        
        bufferBigInt[0] = 1;
        for (int i = 0; i < n; ++i) {
            multiplicationBufferBigInt( r );
        }
        
        printfBufferBigInt(decimal);
    }
    
    return 0;
}



    
}



