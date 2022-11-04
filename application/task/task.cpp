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

// implementation of move_forward() method from the class Mouse.
void rwa2group15::Mouse::move_forward(){
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

// implementation of is_wall() method from the class Cell
bool rwa2group15::Cell::is_wall(int wall){
    auto mouse_cell = std::make_unique<rwa2group15::Mouse>();
    if(wall == 0){
        if(mouse_cell->get_direction() == 'n'){
            if(Simulator::wallFront() == true){
                // std::cerr << "I was here." << std::endl;
                return true;
            }
        }
        else if(mouse_cell->get_direction() == 'e'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        }
        else if(mouse_cell->get_direction()== 'w'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the north wall." << std::endl;
        }
    }
    else if(wall == 1){
        if(mouse_cell->get_direction() == 'e'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(mouse_cell->get_direction() == 's'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(mouse_cell->get_direction()== 'n'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the east wall." << std::endl;
        }
    }

    else if(wall == 2){
        if(mouse_cell->get_direction() == 's'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(mouse_cell->get_direction() == 'w'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(mouse_cell->get_direction()== 'e'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the south wall." << std::endl;
        }
    }

    else if(wall == 3){
        if(mouse_cell->get_direction() == 'w'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(mouse_cell->get_direction() == 'n'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(mouse_cell->get_direction()== 's'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the west wall." << std::endl;
        }
    }

    // else if(mouse->get_direction() == 'e'){
    //     if(Simulator::wallFront() == false){
    //         return m_walls.at(1) == false;
    //     }
    //     else if(Simulator::wallLeft() == false){
    //         return m_walls.at(0) == false;
    //     }
    //     else if(Simulator::wallRight() == false){
    //         return m_walls.at(2) == false;
    //     }
    //     else{
    //         std::cerr << "Error in is_wall implementation of class Cell - Mouse facing east.";
    //     }
    // }

    // else if(mouse->get_direction() == 's'){
    //     if(Simulator::wallFront() == false){
    //         return m_walls.at(2) == false;
    //     }
    //     else if(Simulator::wallLeft() == false){
    //         return m_walls.at(1) == false;
    //     }
    //     else if(Simulator::wallRight() == false){
    //         return m_walls.at(3) == false;
    //     }
    //     else{
    //         std::cerr << "Error in is_wall implementation of class Cell - Mouse facing south.";
    //     }
    // }
    
    // else if(mouse->get_direction() == 'w'){
    //     if(Simulator::wallFront() == false){
    //         return m_walls.at(3) == false;
    //     }
    //     else if(Simulator::wallLeft() == false){
    //         return m_walls.at(2) == false;
    //     }
    //     else if(Simulator::wallRight() == false){
    //         return m_walls.at(0) == false;
    //     }
    //     else{
    //         std::cerr << "Error in is_wall implementation of class Cell - Mouse facing west.";
    //     }
    // }
    return false;
}

// implementation of set_wall() method from the class Cell
void rwa2group15::Cell::set_wall(int wall, bool is_wall){
    if(is_wall){
        m_walls.at(wall) = is_wall;
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

// implementation of set_front_wall() method from the class Algorithm.
void rwa2group15::Algorithm::set_front_wall(){
    // auto mouse_algorithm = std::make_unique<rwa2group15::Mouse>();
    // int x = mouse_algorithm->get_position().first;
    // int y = mouse_algorithm->get_position().second;
    // char z = mouse_algorithm->get_direction();

    // auto cell_algorithm = std::make_unique<rwa2group15::Cell>();
    // bool c = cell_algorithm->is_wall();



    // if(z == '')
}
