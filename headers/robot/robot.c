#include "robot.h"

/// @brief initialize a robot with given parameters
/// @param robot The robot object to initialize
/// @param id The robot's ID
/// @param name The robot's name
/// @param x initial x coordinate
/// @param y initial y coordinate
/// @param facing initial orientation
void initializeRobot(Robot *robot, int id, const char *name, double x, double y, enum orientation facing)
{
    robot->id = id;
    robot->name = strdup(name);
    robot->position[0] = (int)x;
    robot->position[1] = (int)y;
    robot->facing = facing;
}

/// @brief Check if the robot can move a certain number of steps in the direction it is facing without going out of bounds
/// @param robot The robot object to check
/// @param steps The number of steps to move
/// @param areaWidth The width of the area
/// @param areaHeight The height of the area
/// @return 1 if the move is valid, 0 otherwise
int checkMove(const Robot *robot, int steps, int areaWidth, int areaHeight)
{
    int newX = robot->position[0];
    int newY = robot->position[1];

    switch (robot->facing)
    {
    case NORTH:
        newY += steps;
        break;
    case EAST:
        newX += steps;
        break;
    case SOUTH:
        newY -= steps;
        break;
    case WEST:
        newX -= steps;
        break;
    default:
        break;
    }

    return (int)(newX >= 0 && newX < areaWidth && newY >= 0 && newY < areaHeight);
}

/// @brief Move the robot a certain number of steps in the direction it is facing
/// @param robot The robot object to move
/// @param steps The number of steps to move
void moveRobot(Robot *robot, int steps)
{
    if (!checkMove(robot, steps, MAX_GRIDS_WIDTH, MAX_GRIDS_HEIGHT))
    {
        printf("Move out of bounds!\n");
        return;
    }

    switch (robot->facing)
    {
    case NORTH:
        robot->position[1] += steps;
        break;
    case EAST:
        robot->position[0] += steps;
        break;
    case SOUTH:
        robot->position[1] -= steps;
        break;
    case WEST:
        robot->position[0] -= steps;
        break;
    default:
        break;
    }
}

void rotateRobot(Robot *robot, enum orientation newFacing)
{
    robot->facing = newFacing;
}
