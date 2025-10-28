#include "robot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Initialize the robot with given parameters
/// @param robot The robot to initialize
/// @param id The robot's ID
/// @param name The robot's name
/// @param x Position x coordinate
/// @param y Position y coordinate
/// @param facing Facing direction
void initializeRobot(Robot *robot, int id, const char *name, int x, int y, Orientation facing)
{
    robot->id = id;
    
    // Allocate memory and copy the name
    robot->name = (char*)malloc(strlen(name) + 1);

    if (robot->name != NULL)
        strcpy(robot->name, name);
    
    robot->position[0] = x;
    robot->position[1] = y;
    robot->facing = facing;
}

/// @brief Check if the robot can move the specified steps within the area boundaries
/// @param robot 
/// @param steps 
/// @param areaWidth 
/// @param areaHeight 
/// @return 1 if the move is valid, 0 otherwise
int checkMove(const Robot *robot, int steps, int areaWidth, int areaHeight)
{
    int newX = robot->position[0];
    int newY = robot->position[1];

    switch (robot->facing)
    {
    case NORTH:
        newY -= steps;
        break;
    case EAST:
        newX += steps;
        break;
    case SOUTH:
        newY += steps;
        break;
    case WEST:
        newX -= steps;
        break;
    default:
        break;
    }

    return (newX >= 0 && newX < areaWidth && newY >= 0 && newY < areaHeight);
}

/// @brief Move the robot by the specified number of steps
/// @param robot 
/// @param steps 
void moveRobot(Robot *robot, int steps)
{
    if (!checkMove(robot, steps, MAX_GRIDS_WIDTH, MAX_GRIDS_HEIGHT))
    {
        printf("Robot %s: Move out of bounds! Cannot move %d steps from (%d, %d)\n", 
               robot->name, steps, robot->position[0], robot->position[1]);
        return;
    }

    switch (robot->facing)
    {
    case NORTH:
        robot->position[1] -= steps;
        break;
    case EAST:
        robot->position[0] += steps;
        break;
    case SOUTH:
        robot->position[1] += steps;
        break;
    case WEST:
        robot->position[0] -= steps;
        break;
    default:
        break;
    }
    printf("Robot %s moved %d steps to (%d, %d)\n", 
           robot->name, steps, robot->position[0], robot->position[1]);
}

/// @brief Change the robot's facing direction
/// @param robot 
/// @param newFacing 
void rotateRobot(Robot *robot, Orientation newFacing)
{
    const char* directions[] = {"NORTH", "EAST", "SOUTH", "WEST"};
    printf("Robot %s rotated from %s to %s\n", 
           robot->name, 
           directions[robot->facing],
           directions[newFacing]);
    
    robot->facing = newFacing;
}

/// @brief Get the robot's current position
/// @param robot 
void getRobotPosition(const Robot *robot)
{
    printf("Robot %s is at position (%d, %d)\n", 
           robot->name, robot->position[0], robot->position[1]);
}

/// @brief Print the robot's current status
/// @param robot 
void printRobotStatus(const Robot *robot)
{
    const char* directions[] = {"NORTH", "EAST", "SOUTH", "WEST"};
    printf("=== Robot Status ===\n");
    printf("ID: %d\n", robot->id);
    printf("Name: %s\n", robot->name);
    printf("Position: (%d, %d)\n", robot->position[0], robot->position[1]);
    printf("Facing: %s\n", directions[robot->facing]);
    printf("====================\n");
}