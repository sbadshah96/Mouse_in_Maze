#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "task/task.h"

/**
 * @brief This is the main function - runs the algorithm for the mouse to reach to the goal.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    auto algorithm = std::make_unique<rwa2group15::Algorithm>();
    // algorithm->run_left();
    algorithm->run_right();
    return 0;
}
