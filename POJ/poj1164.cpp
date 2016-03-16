//
//  poj1164.cpp
//  MacPOJ
//
//  Created by yukon on 16/3/13.
//  Copyright © 2016年 yukon. All rights reserved.
//
/*
 POJ 1164 The Castle
 
 Description
 
 1   2   3   4   5   6   7
 
 #############################
 
 1 #   |   #   |   #   |   |   #
 
 #####---#####---#---#####---#
 
 2 #   #   |   #   #   #   #   #
 
 #---#####---#####---#####---#
 
 3 #   |   |   #   #   #   #   #
 
 #---#########---#####---#---#
 
 4 #   #   |   |   |   |   #   #
 
 #############################
 
 (Figure 1)
 
 
 
 #  = Wall
 
 |  = No wall
 
 -  = No wall
 
 Figure 1 shows the map of a castle.Write a program that calculates
 1. how many rooms the castle has
 2. how big the largest room is
 The castle is divided into m * n (m<=50, n<=50) square modules. Each such module can have between zero and four walls.
 
 Input
 Your program is to read from standard input. The first line contains the number of modules in the north-south direction and the number of modules in the east-west direction. In the following lines each module is described by a number (0 <= p <= 15). This number is the sum of: 1 (= wall to the west), 2 (= wall to the north), 4 (= wall to the east), 8 (= wall to the south). Inner walls are defined twice; a wall to the south in module 1,1 is also indicated as a wall to the north in module 2,1. The castle always has at least two rooms.
 
 Output
 Your program is to write to standard output: First the number of rooms, then the area of the largest room (counted in modules).
 
 Sample Input
 4
 7
 11 6 11 6 3 10 6
 7 9 6 13 5 15 5
 1 10 12 7 13 7 5
 13 11 10 8 10 12 13
 
 Sample Output
 5
 9
 */



#include <iostream>

#define MAX_WALL_NUM    50

struct ST_Wall {
    bool west;
    bool north;
    bool east;
    bool south;
};
ST_Wall walls[MAX_WALL_NUM][MAX_WALL_NUM];
int zoom[MAX_WALL_NUM][MAX_WALL_NUM];

int searchZoom()
{
    
    return 0;
}

int main(int argc, const char * argv[])
{
    int rows = 0;
    int cloumns = 0;
    std::cin >> rows >> cloumns;
    
    // 记录墙
    int oneWall = 0;
    for ( int iRow = 0; iRow < rows; ++iRow ) {
        for ( int iCloumn = 0; iCloumn < cloumns; ++iCloumn ) {

            std::cin >> oneWall;
            
            if ( oneWall > 7 ) {
                walls[iRow][iCloumn].south = true;
                oneWall -= 8;
            }
            if ( oneWall > 3 ) {
                walls[iRow][iCloumn].east = true;
                oneWall -= 4;
            }
            if ( oneWall > 1 ) {
                walls[iRow][iCloumn].north = true;
                oneWall -= 2;
            }
            if ( oneWall > 0 ) {
                walls[iRow][iCloumn].west = true;
            }
        }
    }
    
    int color = 1;
    memset(zoom, 0, MAX_WALL_NUM*MAX_WALL_NUM*sizeof(int));
    for ( int iRow = 0; iRow < rows; ++iRow ) {
        for ( int iCloumn = 0; iCloumn < cloumns; ++iCloumn ) {
            
            if ( walls[iRow][iCloumn].west && iRow-1 > 0 && zoom[iRow][iCloumn] < zoom[iRow-1][iCloumn] ) {
                zoom[iRow][iCloumn] = zoom[iRow-1][iCloumn];
            }
            if ( walls[iRow][iCloumn].north && iCloumn-1 > 0 ) {
                
            }
            
        }
    }
    
    return 0;
}




