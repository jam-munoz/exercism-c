#include "robot_simulator.h"
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot = { direction, { x, y } };
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    for (int i = 0; i < (int)strlen(commands); i++)
    {
        if (commands[i] == 'R')
        {
            robot->direction++; 
            if (robot->direction == DIRECTION_MAX) 
                robot->direction = DIRECTION_NORTH;  
        }
        if (commands[i] == 'L')
        {
            if (robot->direction == 0)
                robot->direction = DIRECTION_WEST;
            else robot->direction--;
        }
        if (commands[i] == 'A')
        {
            if (robot->direction == DIRECTION_NORTH)
                robot->position.y++;
            if (robot->direction == DIRECTION_EAST)
                robot->position.x++;
            if (robot->direction == DIRECTION_SOUTH)
                robot->position.y--;
            if (robot->direction == DIRECTION_WEST)
                robot->position.x--;
        }
    }
}