#ifndef ROBOT_H
#define ROBOT_H

#include "grids.h"  // 如果需要使用Grid相关定义

// 先定义orientation枚举
typedef enum { NORTH, EAST, SOUTH, WEST } Orientation;

// 定义Robot结构体
typedef struct Robot 
{
    int id;
    char *name;
    int position[2]; // x, y coordinates in the grids
    Orientation facing;
} Robot;

// 函数声明 - 现在使用Robot而不是struct Robot
void initializeRobot(Robot *robot, int id, const char *name, int x, int y, Orientation facing);
int checkMove(const Robot *robot, int steps, int areaWidth, int areaHeight);
void moveRobot(Robot *robot, int steps);
void rotateRobot(Robot *robot, Orientation newFacing);
void getRobotPosition(const Robot *robot);
void printRobotStatus(const Robot *robot);

#endif // ROBOT_H