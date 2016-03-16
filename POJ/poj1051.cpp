//
//  poj1051.cpp
//  MacPOJ
//
//  Created by yukon on 16/2/19.
//  Copyright © 2016年 yukon. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

namespace poj1051 {

int main_1051(int argc, const char * argv[])
{
    std::map<char, std::string> mapMorse;
    mapMorse['A'] = ".-";
    mapMorse['B'] = "-...";
    mapMorse['C'] = "-.-.";
    mapMorse['D'] = "-..";
    mapMorse['E'] = ".";
    mapMorse['F'] = "..-.";
    mapMorse['G'] = "--.";
    mapMorse['H'] = "....";
    mapMorse['I'] = "..";
    mapMorse['J'] = ".---";
    mapMorse['K'] = "-.-";
    mapMorse['L'] = ".-..";
    mapMorse['M'] = "--";
    mapMorse['N'] = "-.";
    mapMorse['O'] = "---";
    mapMorse['P'] = ".--.";
    mapMorse['Q'] = "--.-";
    mapMorse['R'] = ".-.";
    mapMorse['S'] = "...";
    mapMorse['T'] = "-";
    mapMorse['U'] = "..-";
    mapMorse['V'] = "...-";
    mapMorse['W'] = ".--";
    mapMorse['X'] = "-..-";
    mapMorse['Y'] = "-.--";
    mapMorse['Z'] = "--..";
    mapMorse['_'] = "..--";
    mapMorse['.'] = "---.";
    mapMorse[','] = ".-.-";
    mapMorse['?'] = "----";
    
    std::map<std::string, char> mapLetter;
    mapLetter[".-"] = 'A';
    mapLetter["-..."] = 'B';
    mapLetter["-.-."] = 'C';
    mapLetter["-.."] = 'D';
    mapLetter["."] = 'E';
    mapLetter["..-."] = 'F';
    mapLetter["--."] = 'G';
    mapLetter["...."] = 'H';
    mapLetter[".."] = 'I';
    mapLetter[".---"] = 'J';
    mapLetter["-.-"] = 'K';
    mapLetter[".-.."] = 'L';
    mapLetter["--"] = 'M';
    mapLetter["-."] = 'N';
    mapLetter["---"] = 'O';
    mapLetter[".--."] = 'P';
    mapLetter["--.-"] = 'Q';
    mapLetter[".-."] = 'R';
    mapLetter["..."] = 'S';
    mapLetter["-"] = 'T';
    mapLetter["..-"] = 'U';
    mapLetter["...-"] = 'V';
    mapLetter[".--"] = 'W';
    mapLetter["-..-"] = 'X';
    mapLetter["-.--"] = 'Y';
    mapLetter["--.."] = 'Z';
    mapLetter["..--"] = '_';
    mapLetter["---."] = '.';
    mapLetter[".-.-"] = ',';
    mapLetter["----"] = '?';
    
    // map or strlen
    std::map<char, short>   mapLength;
    mapLength['A'] = 2;
    mapLength['B'] = 4;
    mapLength['C'] = 4;
    mapLength['D'] = 3;
    mapLength['E'] = 1;
    mapLength['F'] = 4;
    mapLength['G'] = 3;
    mapLength['H'] = 4;
    mapLength['I'] = 2;
    mapLength['J'] = 4;
    mapLength['K'] = 3;
    mapLength['L'] = 4;
    mapLength['M'] = 2;
    mapLength['N'] = 2;
    mapLength['O'] = 3;
    mapLength['P'] = 4;
    mapLength['Q'] = 4;
    mapLength['R'] = 3;
    mapLength['S'] = 3;
    mapLength['T'] = 1;
    mapLength['U'] = 3;
    mapLength['V'] = 4;
    mapLength['W'] = 3;
    mapLength['X'] = 4;
    mapLength['Y'] = 4;
    mapLength['Z'] = 4;
    mapLength['_'] = 4;
    mapLength['.'] = 4;
    mapLength[','] = 4;
    mapLength['?'] = 4;
    
    int count;
    std::string strcode;
    std::string strMorse;
    unsigned short arrayLength[100];
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        
        std::cin >> strcode;
        
        unsigned short codeLength = strcode.length();
        strMorse = "";
        for (int index = 0; index < codeLength; ++index) {
            strMorse += mapMorse[ strcode[index] ];
            arrayLength[index] = mapLength[ strcode[index] ];
        }
        
        int startPos = 0;
        strcode = "";
        for (int index = 0; index < codeLength; ++index) {
            
            char letter = mapLetter[ strMorse.substr(startPos, arrayLength[ codeLength-index-1 ]) ];
            strcode += letter;
            
            startPos += arrayLength[ codeLength-index-1 ];
        }
        
        std::cout << i+1 << ": " << strcode << std::endl;
    }
    
    return 0;
}

}

