//
//  poj1083.cpp
//  MacPOJ
//
//  Created by yukon on 16/2/29.
//  Copyright © 2016年 yukon. All rights reserved.
//

#include <iostream>

namespace poj1083 {

#define MAX_ROOMS   (1 + 400)

int roomUserd[MAX_ROOMS];

int main_1083(int argc, const char * argv[]) {
 
    int t = 0;
    
    std::cin >> t;
    while ( t-- > 0 ) {
        
        memset(roomUserd, 0, MAX_ROOMS*sizeof(int));
        
        int n = 0;
        
        std::cin >> n;
        while ( n-- > 0 ) {
            
            int fromRoom = 0;
            int toRoom = 0;
            
            std::cin >> fromRoom >> toRoom;
            
            if ( fromRoom > toRoom ) {
                int swap = fromRoom;
                fromRoom = toRoom;
                toRoom = swap;
            }
            
            if ( 0 == fromRoom%2 ) {
                roomUserd[fromRoom-1] += 10;
                ++fromRoom;
            }
            for ( int i = fromRoom; i <= toRoom; i+=2 ) {
                roomUserd[i] += 10;
            }
        }
        
        //
        int maxWait = 0;
        for ( int i = 1; i < MAX_ROOMS; i+=2 ) {
            maxWait = ( maxWait > roomUserd[i] ? maxWait : roomUserd[i]);
        }
        
        std::cout << maxWait << std::endl;
    }
    
    return 0;
}

    
}


