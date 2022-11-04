#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "task/task.h"

int main(int argc, char *argv[])
{
    // colorize and add text
    // Simulator::setColor(0, 0, 'G');
    // Simulator::setText(0, 0, "A");
    // Simulator::setColor(0, 15, 'G');
    // Simulator::setText(0, 15, "B");
    // Simulator::setColor(15, 15, 'G');
    // Simulator::setText(15, 15, "C");
    // Simulator::setColor(15, 0, 'G');
    // Simulator::setText(15, 0, "D");
    
    auto algorithm = std::make_unique<rwa2group15::Algorithm>(); 

    // generating a random goal.
    algorithm->generate_goal(); 

    // setting outer walls.
    algorithm->init_outer_walls();

    // auto simulator = std::make_unique<Simulator>();

    // simulator->moveForward(2);
    // simulator->setColor(1, 1,'c');
    // if(simulator->wallFront()){
    //     simulator->setWall(0, 2, 'n');
    // }
    // simulator->turnRight();
    // simulator->moveForward(2);
    // if(simulator->wallFront()){
    //     simulator->setWall(2, 2, 'e');
    // }

    // simulator->mazeHeight();
    // simulator->mazeHeight();

    // simulator->ackReset();
    // simulator->moveForward(15);

    auto mouse = std::make_unique<rwa2group15::Mouse>();
    auto cell = std::make_unique<rwa2group15::Cell>();

    mouse->move_forward();
    mouse->move_forward();
    std::cerr << cell->is_wall(0) << std::endl;
    // std::cerr << cell->get_walls(0) << std::endl;
    mouse->turn_right();
    mouse->move_forward();
    mouse->turn_right();
    cell->get_walls();
    
    // std::cerr << cell->is_wall(1) << std::endl;
    std::cerr << "(" << mouse->get_position().first << ", " << mouse->get_position().second << ") " << std::endl;
    std::cerr << typeid(mouse->get_position().first).name() << std::endl;
    std::cerr << "facing "<< mouse->get_direction() << std::endl;
    std::cerr << typeid(mouse->get_direction()).name() << std::endl;
    // std::cerr << "Error" << std::endl;

    // setting some walls
    // Simulator::setWall(7, 0, 's');
    // Simulator::setWall(8, 0, 's');

    // move the robot back and forth
    // while (true)
    // {
    //     Simulator::moveForward();
    //     if (Simulator::wallFront())
    //     {
    //         std::cerr << "--- turn left ---" << std::endl;
    //         Simulator::turnLeft();
    //         std::cerr << "--- turn left ---" << std::endl;
    //         Simulator::turnLeft();
    //     }
    // }

    return 0;
}
