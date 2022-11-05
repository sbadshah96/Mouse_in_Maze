#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "task/task.h"

int main(int argc, char *argv[])
{
  
    auto algorithm = std::make_unique<rwa2group15::Algorithm>();
    algorithm->run();
    return 0;
}
