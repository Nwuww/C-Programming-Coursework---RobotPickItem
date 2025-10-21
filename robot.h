#ifndef ROBOT_H
#define ROBOT_H
#endif // ROBOT_H

#include "grids.h"

typedef struct 
{
    int id;
    char *name;
    int position[2]; // x, y coordinates in the grids
    enum orientation { NORTH, EAST, SOUTH, WEST } facing;
} Robot;

void initializeRobot(struct Robot *robot, int id, const char *name, int x, int y, enum orientation facing);
int checkMove(const struct Robot *robot, int steps, int areaWidth, int areaHeight);
void moveRobot(struct Robot *robot, int steps);
void rotateRobot(struct Robot *robot, enum orientation newFacing);
void getRobotPosition(const struct Robot *robot);
void printRobotStatus(const struct Robot *robot);