#include "task.h"
#include "../simulator/simulator.h"

#include <cstdlib>
#include <iostream>


//////////////           MOUSE CLASS         ///////////////
// implementation of turn_left() method from the class Mouse.
void rwa2group15::Mouse::turn_left(){
    if(m_direction == 'n'){
        m_direction = 'w';
        m_position.first = m_position.first - 1;
        Simulator::turnLeft();
        Simulator::moveForward(1);                      
    }

    else if(m_direction == 'w'){
        m_direction = 's';
        m_position.second = m_position.second - 1;
        Simulator::turnLeft();
        Simulator::moveForward(1);
    } 

    else if(m_direction == 's'){
        m_direction = 'e';
        m_position.first = m_position.first + 1;
        Simulator::turnLeft();
        Simulator::moveForward(1);
    } 

    else if(m_direction == 'e'){
        m_direction = 'n';
        m_position.second = m_position.second + 1;
        Simulator::turnLeft();
        Simulator::moveForward(1);
    }
} 

// implementation of turn_right() method from the class Mouse.
void rwa2group15::Mouse::turn_right(){
    if(m_direction == 'n'){
        m_direction = 'e';
        m_position.first = m_position.first + 1;
        Simulator::turnRight();
        Simulator::moveForward(1);
    } 

    else if(m_direction == 'e'){
        m_direction = 's';
        m_position.second = m_position.second - 1;
        Simulator::turnRight();
        Simulator::moveForward(1);
    } 

    else if(m_direction == 's'){
        m_direction = 'w';
        m_position.first = m_position.first - 1;
        Simulator::turnRight();
        Simulator::moveForward(1);
    } 

    else if(m_direction == 'w'){
        m_direction = 'n';
        m_position.second = m_position.second + 1;
        Simulator::turnRight();
        Simulator::moveForward(1);
    }
} 

// implementation of move_foreward() method from the class Mouse.
void rwa2group15::Mouse::move_foreward(){
    if(m_direction == 'n'){
        // m_direction = 'e';
        m_position.second = m_position.second + 1;
        Simulator::moveForward(1);
        // std::cerr << m_direction << std::endl;
    } 

    else if(m_direction == 'e'){
        // m_direction = 's';
        m_position.first = m_position.first + 1;
        Simulator::moveForward(1);
        // std::cerr << m_direction << std::endl;
    } 

    else if(m_direction == 's'){
        // m_direction = 'w';
        m_position.second = m_position.second - 1;
        Simulator::moveForward(1);
    } 

    else if(m_direction == 'w'){
        // m_direction = 'n';
        m_position.first = m_position.first - 1;
        Simulator::moveForward(1);
    }
} 






////////////////           CELL CLASS           /////////////////
// implementation of init_cell_walls() method from the class Cell
void rwa2group15::Cell::init_cell_walls(){
    m_walls = {0,0,0,0};
}

// implmentation of is_wall() method from the class Cell
bool rwa2group15::Cell::is_wall(int wall){
    // if(rwa2group15::Mouse::get_direction() == 'n')
    
    if(m_walls.at(wall) == 0){
        return true;
    }

    else{
        return false;
    }
}

// implementation of set_wall() method from the class Cell
void rwa2group15::Cell::set_wall(int wall, bool is_wall){
    if(is_wall == false){
        m_walls.at(wall) = false;
    }
    
}




////////////////          ALGORITHM CLASS           /////////////////
// implementation of init_out_wall() method from the class Algorithm
void rwa2group15::Algorithm::init_outer_walls(){
    for(auto i{0}; i < 16; i++){
        for(auto j{0}; j < 16; j++){
            if(i == 0){
                Simulator::setWall(i, j, 'w');

                if(j == 0){
                    Simulator::setWall(i, j, 's');
                }

                else if(j == 15){
                    Simulator::setWall(i, j, 'n');
                }

            }

            else if(i == 15){
                Simulator::setWall(i, j, 'e');
                
                if(j == 0){
                    Simulator::setWall(i, j, 's');
                }

                else if(j == 15){
                    Simulator::setWall(i, j, 'n');
                }
            }

            else{
                if(j == 0){
                    Simulator::setWall(i, j, 's');
                }

                else if(j == 15){
                    Simulator::setWall(i, j, 'n');
                }
            } 
        }
    }
}

// implementation of generate_goal() method from the class Algorithm.
void rwa2group15::Algorithm::generate_goal(){
    
    m_goal.first = rand() % 16;

    if(m_goal.first == 0 || m_goal.first == 15){
        m_goal.second = rand() % 16;
    }

    else{
        unsigned short k{};
        k = rand() % 2;
        if (k == 0){
            m_goal.second = 0;
        }

        else{
            m_goal.second = 1;
        }
    }

    Simulator::setColor(m_goal.first, m_goal.second, 'r');
    Simulator::setText(m_goal.first, m_goal.second, "G");
}
