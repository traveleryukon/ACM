//
//  poj1095.cpp
//  MacACM
//
//  Created by yukon on 16/2/21.
//  Copyright © 2016年 yukon. All rights reserved.
//

#include <iostream>

namespace  POJ1095 {

#define Max_CatalanBuffer  20
// 计算规律常数（卡特兰数）
unsigned long catalan[Max_CatalanBuffer];

void initCatalan()
{
    catalan[0] = 1;
    catalan[1] = 1;
    for (int n = 2; n < Max_CatalanBuffer; ++n) {
        catalan[n] = 0;
        for (int i = 0; i < n; ++i) {
            catalan[n] += catalan[i] * catalan[n-i-1];
        }
    }
}

// nodes:节点数  index:第几种树
void buildTree( int nodes, unsigned long index )
{
    if ( 0 == nodes ) {
        return;
    }
    if ( 1 == nodes ) {
        std::cout << "X";
        return;
    }
    
    --nodes;
    
    // 找左子树节点数，右子树序号
    int lNodes = 0;
    int lIndex = 0;
    while ( index > catalan[nodes] ) {
        
        int i = 0;
        while ( i < catalan[lNodes] && index > catalan[nodes] ) {
            index -= catalan[nodes];
            ++i;
        }
        
        if ( i >= catalan[lNodes] ) {
            --nodes;
            ++lNodes;
        } else {
            lIndex = i+1;
        }
    }
    
    // 左子树
    if ( lNodes > 0 ) {
        std::cout << "(";
        buildTree( lNodes, lIndex );
        std::cout << ")";
    }
    
    std::cout << "X";
    
    // 右子树
    if ( nodes > 0 ) {
        std::cout << "(";
        buildTree( nodes, index );
        std::cout << ")";
    }
}

int main(int argc, const char * argv[])
{
    //
    initCatalan();
    
    //
    unsigned long inValue;
    std::cin >> inValue;
    while ( inValue > 0 ) {
        
        // 找树总节点数及树序号
        int nodes = 1;
        while ( inValue > catalan[nodes] ) {
            inValue -= catalan[nodes];
            ++nodes;
        }
        buildTree( nodes, inValue );
        
        std::cout << std::endl;
        
        std::cin >> inValue;
    }
    
    return 0;
}


    
}


