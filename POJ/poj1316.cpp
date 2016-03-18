//
//  poj1316.cpp
//  MacACM
//
//  Created by yukon on 16/3/18.
//  Copyright © 2016年 yukon. All rights reserved.
//


/*
 POJ 1316 Self Number
 
 Description
 
 In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence
 
 33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
 The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. There are thirteen self-numbers less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97.
 
 Input
 No input for this problem.
 
 Output
 Write a program to output all positive self-numbers less than 10000 in increasing order, one per line.
 
 Sample Input
 
 Sample Output
 1
 3
 5
 7
 9
 20
 31
 42
 53
 64
 |
 |       <-- a lot more numbers
 |
 9903
 9914
 9925
 9927
 9938
 9949
 9960
 9971
 9982
 9993
 */

#include <iostream>

namespace POJ1316 {

#define Max_SelfNumer   10000

bool markNumber[Max_SelfNumer];

int main(int argc, const char * argv[])
{
    for ( int i = 0; i < Max_SelfNumer; ++i) {
        markNumber[i] = true;
    }
    
    markNumber[0] = false;
    for ( int i = 1; i < Max_SelfNumer; ++i) {
        
        int sum = i;
        int icheck = i;
        
        while ( icheck > 0 ) {
            sum += (icheck%10);
            icheck /= 10;
        }
        
        if ( sum < Max_SelfNumer ) {
            markNumber[sum] = false;
        }
    }
    
    for ( int i = 0; i < Max_SelfNumer; ++i) {
        if ( markNumber[i] ) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}

}



