//
//  poj1220.cpp
//  MacACM
//
//  Created by yukon on 16/3/9.
//  Copyright © 2016年 yukon. All rights reserved.
//

/*
 POJ 1220 NUMBER BASE CONVERSION
 
 Description
 Write a program to convert numbers in one base to numbers in a second base. There are 62 different digits:
 { 0-9,A-Z,a-z }
 HINT: If you make a sequence of base conversions using the output of one conversion as the input to the next, when you get back to the original base, you should get the original number.
 
 Input
 The first line of input contains a single positive integer. This is the number of lines that follow. Each of the following lines will have a (decimal) input base followed by a (decimal) output base followed by a number expressed in the input base. Both the input base and the output base will be in the range from 2 to 62. That is (in decimal) A = 10, B = 11, ..., Z = 35, a = 36, b = 37, ..., z = 61 (0-9 have their usual meanings).
 
 Output
 The output of the program should consist of three lines of output for each base conversion performed. The first line should be the input base in decimal followed by a space then the input number (as given expressed in the input base). The second output line should be the output base followed by a space then the input number (as expressed in the output base). The third output line is blank.
 
 Sample Input
 8
 62 2 abcdefghiz
 10 16 1234567890123456789012345678901234567890
 16 35 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
 35 23 333YMHOUE8JPLT7OX6K9FYCQ8A
 23 49 946B9AA02MI37E3D3MMJ4G7BL2F05
 49 61 1VbDkSIMJL3JjRgAdlUfcaWj
 61 5 dl9MDSWqwHjDnToKcsWE1S
 5 10 42104444441001414401221302402201233340311104212022133030
 
 Sample Output
 62 abcdefghiz
 2 11011100000100010111110010010110011111001001100011010010001
 
 10 1234567890123456789012345678901234567890
 16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
 
 16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
 35 333YMHOUE8JPLT7OX6K9FYCQ8A
 
 35 333YMHOUE8JPLT7OX6K9FYCQ8A
 23 946B9AA02MI37E3D3MMJ4G7BL2F05
 
 23 946B9AA02MI37E3D3MMJ4G7BL2F05
 49 1VbDkSIMJL3JjRgAdlUfcaWj
 
 49 1VbDkSIMJL3JjRgAdlUfcaWj
 61 dl9MDSWqwHjDnToKcsWE1S
 
 61 dl9MDSWqwHjDnToKcsWE1S
 5 42104444441001414401221302402201233340311104212022133030
 
 5 42104444441001414401221302402201233340311104212022133030
 10 1234567890123456789012345678901234567890
 */

#include <iostream>
#include <string>

namespace POJ1220 {

#define BufferLen_BigInt        500
#define Max_BaseBigInt          62

int bufferBigInt[BufferLen_BigInt];
int outBuffer[BufferLen_BigInt];

bool checkZero(int length)
{
    for ( int i = 0; i < length; ++i) {
        if ( bufferBigInt[i] > 0 ) {
            return false;
        }
    }
    
    return true;
}

int divisionBigInt(int divisor, int base, int length)
{
    int mod = 0;
    for ( int i = length-1; i >= 0; --i) {
        
        bufferBigInt[i] += mod*base;
        
        mod = bufferBigInt[i]%divisor;
        bufferBigInt[i] /=divisor;
    }
    
    return mod;
}

int main(int argc, const char * argv[])
{
    int n = 0;
    std::cin >> n;
    
    while ( n-- > 0 ) {
        
        memset(bufferBigInt, 0, BufferLen_BigInt*sizeof(int));
        memset(outBuffer, 0, BufferLen_BigInt*sizeof(int));
        
        int sBase = 0;
        int dBase = 0;
        std::string inString = "";
        std::cin >> sBase >> dBase >> inString;
        
        // 转存
        for ( int index = 0, i = inString.length()-1; i >= 0 ; --i, ++index) {
            // 计算当前位的值
            if ( inString[i] >= 'a' && inString[i] <= 'z' ) {
                bufferBigInt[index] = (inString[i] - 'a') + 36;
            }
            else if ( inString[i] >= 'A' && inString[i] <= 'Z' ) {
                bufferBigInt[index] = (inString[i] - 'A') + 10;
            }
            else if ( inString[i] >= '0' && inString[i] <= '9' ) {
                bufferBigInt[index] = inString[i] - '0';
            }
        }
        
        // 保证单个数比可能的进制大
        int length = inString.length();
        int newSBase = sBase;
        while ( newSBase < Max_BaseBigInt ) {
            
            for (int i = 0, index = 0; i < length; i+=2, ++index) {
                bufferBigInt[index] = bufferBigInt[i];
                if ( i+1 < length ) {
                    bufferBigInt[index] += bufferBigInt[i+1]*newSBase;
                }
            }
            
            length = (0 == length%2 ? length/2 : length/2+1);
            newSBase *= newSBase;
        }
        for ( int i = Max_BaseBigInt-1; i >= length; --i) {
            bufferBigInt[i] = 0;
        }
        
        // 转换进制，求摸求余数
        int index = 0;
        while ( !checkZero(length) ) {
            outBuffer[index] = divisionBigInt(dBase, newSBase, length);
            ++index;
        }
        index = ( 0 == index ? 1 : index);
        
        std::cout << sBase << " " << inString << std::endl << dBase << " ";
        //输出
        while ( index-- > 0 ) {
            
            if ( outBuffer[index] < 10 ) {
                std::cout << outBuffer[index];
            }
            else if ( outBuffer[index] >= 10 && outBuffer[index] < 36 ) {
                char outChar = 'A';
                outChar += (outBuffer[index]-10);
                std::cout << outChar;
            }
            else if ( outBuffer[index] >= 36 && outBuffer[index] < 62 ) {
                char outChar = 'a';
                outChar += (outBuffer[index]-36);
                std::cout << outChar;
            }
        }
        std::cout << std::endl << std::endl;
    }
    
    return 0;
}


}




