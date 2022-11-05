#include "task.h"
#include "../simulator/simulator.h"

#include <cstdlib>
#include <iostream>


//////////////           MOUSE CLASS         ///////////////
// implementation of turn_left() method from the class Mouse.
void rwa2group15::Mouse::turn_left(){
    if(m_direction == 'n'){
        m_direction = 'w';
        Simulator::turnLeft();                  
    }

    else if(m_direction == 'w'){
        m_direction = 's';
        Simulator::turnLeft();
    } 

    else if(m_direction == 's'){
        m_direction = 'e';
        Simulator::turnLeft();
    } 

    else if(m_direction == 'e'){
        m_direction = 'n';
        Simulator::turnLeft();
    }
    move_forward();
} 

// implementation of turn_right() method from the class Mouse.
void rwa2group15::Mouse::turn_right(){
    if(m_direction == 'n'){
        m_direction = 'e';
        Simulator::turnRight();
    } 

    else if(m_direction == 'e'){
        m_direction = 's';
        Simulator::turnRight();
    } 

    else if(m_direction == 's'){
        m_direction = 'w';
        Simulator::turnRight();
    } 

    else if(m_direction == 'w'){
        m_direction = 'n';
        Simulator::turnRight();
    }
    move_forward();
} 

// implementation of move_forward() method from the class Mouse.
void rwa2group15::Mouse::move_forward(){
    if(m_direction == 'n'){
        m_position.second += 1;
    } 
    else if(m_direction == 'e'){
        m_position.first += 1;
    } 
    else if(m_direction == 's'){
        m_position.second -= 1;
    } 
    else if(m_direction == 'w'){
        m_position.first -=  1;
    }
    Simulator::moveForward(1);
}

void rwa2group15::Mouse::turn_back(){
    if(m_direction == 'n'){
        m_direction = 's';
        m_position.second -= 1;
    } 
    else if(m_direction == 'e'){
        m_direction = 'w';
        m_position.first -= 1;
    } 
    else if(m_direction == 's'){
        m_direction = 'n';
        m_position.second += 1;
    } 
    else if(m_direction == 'w'){
        m_direction = 'e';
        m_position.first +=  1;
    }
    Simulator::turnLeft();
    Simulator::turnLeft();
    Simulator::moveForward(1);
}


////////////////           CELL CLASS           /////////////////
// implementation of is_wall() method from the class Cell
bool rwa2group15::Cell::is_wall(int wall, char direction){
    if(wall == 0){
        if(direction == 'n'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(direction == 'e'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        }
        else if(direction== 'w'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the north wall." << std::endl;
        }
    }
    else if(wall == 1){
        if(direction == 'e'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(direction == 's'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(direction== 'n'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the east wall." << std::endl;
        }
    }

    else if(wall == 2){
        if(direction == 's'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(direction == 'w'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(direction== 'e'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the south wall." << std::endl;
        }
    }

    else if(wall == 3){
        if(direction == 'w'){
            if(Simulator::wallFront() == true){
                return true;
            }
        }
        else if(direction == 'n'){
            if(Simulator::wallLeft() == true){
                return true;
            }
        } 
        else if(direction== 's'){
            if(Simulator::wallRight() == true){
                return true;
            }
        }
        else{
            std::cerr << "Something is not working in method is_wall() of class Cell for the west wall." << std::endl;
        }
    }
    return false;
}

// implementation of set_wall() method from the class Cell
void rwa2group15::Cell::set_wall(int wall, bool is_wall){
    if(is_wall){
        m_walls.at(wall) = is_wall;
        // change cell color
    }  
}

// implementation of init_cell_walls() method from the class Cell 
void rwa2group15::Cell::init_cell_walls(){
    char direction{};
    switch (direction)
    {
    case 'n':
        for(auto wall=0; wall<4; wall++){
            set_wall(wall, is_wall(wall, 'n'));
        } 
        break;
    case 'e':
        for(auto wall=0; wall<4; wall++){
            set_wall(wall, is_wall(wall, 'e'));
        } 
        break;
    case 's':
        for(auto wall=0; wall<4; wall++){
            set_wall(wall, is_wall(wall, 's'));
        } 
        break;
    case 'w':
        for(auto wall=0; wall<4; wall++){
            set_wall(wall, is_wall(wall, 'w'));
        } 
        break;
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
    srand(time(0));
    int begin{rand() % 2};
    if(begin == 0){
        m_goal.first = rand() % 15;
        if(m_goal.first == 0 || m_goal.first == 15){
            m_goal.second = rand() % 15;
        }
        else{
            int temp{rand() % 2};
            if (temp == 0){
                m_goal.second = 0;
            }
            else{
                m_goal.second = 15;
            }
        }
    }
    else{
        m_goal.second = rand() % 15;
        if(m_goal.second == 0 || m_goal.second == 15){
            m_goal.first = rand() % 15;
        }
        else{
            int temp{rand() % 2};
            if(temp == 0){
                m_goal.first = 0;
            }
            else{
                m_goal.first = 15;
            }
        }
    }
    Simulator::setColor(m_goal.first, m_goal.second, 'r');
    Simulator::setText(m_goal.first, m_goal.second, "G");
}

// implementation of set_left_wall() method from the class Algorithm
void rwa2group15::Algorithm::set_left_wall(){
    char direction = m_mouse->get_direction();
    int x_position = m_mouse->get_position().first;
    int y_position = m_mouse->get_position().second;
    bool wall{};
    if(direction == 'n'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(3, 'n'))){
            m_maze.at(x_position).at(y_position).set_wall(3, wall);
            Simulator::setWall(x_position, y_position, 'w');
        }
    }
    else if(direction == 'e'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(0, 'e'))){
            m_maze.at(x_position).at(y_position).set_wall(0, wall);
            Simulator::setWall(x_position, y_position, 'n');
        }
    }
    else if(direction == 's'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(1, 's'))){
            m_maze.at(x_position).at(y_position).set_wall(1, wall);
            Simulator::setWall(x_position, y_position, 'e');
        }
    }
    else if(direction == 'w'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(2, 'w'))){
            m_maze.at(x_position).at(y_position).set_wall(2, wall);
            Simulator::setWall(x_position, y_position, 's');
        }
    }
    else{
        std::cerr << "Something didn't work." << std::endl;
    }
}

void rwa2group15::Algorithm::set_right_wall(){
    char direction = m_mouse->get_direction();
    int x_position = m_mouse->get_position().first;
    int y_position = m_mouse->get_position().second;
    bool wall{};
    if(direction == 'n'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(1, 'n'))){
            m_maze.at(x_position).at(y_position).set_wall(1, wall);
            Simulator::setWall(x_position, y_position, 'e');
        }
    }
    else if(direction == 'e'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(2, 'e'))){
            m_maze.at(x_position).at(y_position).set_wall(2, wall);
            Simulator::setWall(x_position, y_position, 's');
        }
    }
    else if(direction == 's'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(3, 's'))){
            m_maze.at(x_position).at(y_position).set_wall(3, wall);
            Simulator::setWall(x_position, y_position, 'w');
        }
    }
    else if(direction == 'w'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(0, 'w'))){
            m_maze.at(x_position).at(y_position).set_wall(0, wall);
            Simulator::setWall(x_position, y_position, 'n');
        }
    }
    else{
        std::cerr << "Something didn't work." << std::endl;
    }
}

// implementation of set_front_wall() method from the class Algorithm.
void rwa2group15::Algorithm::set_front_wall(){
    char direction = m_mouse->get_direction();
    int x_position = m_mouse->get_position().first;
    int y_position = m_mouse->get_position().second;
    bool wall{};
    if(direction == 'n'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(0, 'n')))
            {
                m_maze.at(x_position).at(y_position).set_wall(0, wall);
                Simulator::setWall(x_position, y_position, 'n');
            }
    }
    else if(direction == 'e'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(1, 'e')))
            {
                m_maze.at(x_position).at(y_position).set_wall(1, wall);
                Simulator::setWall(x_position, y_position, 'e');
            }
    }
    else if(direction == 's'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(2, 's')))
            {
                m_maze.at(x_position).at(y_position).set_wall(2, wall);
                Simulator::setWall(x_position, y_position, 's');
            }
    }
    else if(direction == 'w'){
        if((wall = m_maze.at(x_position).at(y_position).is_wall(3, 'w')))
            {
                m_maze.at(x_position).at(y_position).set_wall(3, wall);
                Simulator::setWall(x_position, y_position, 'w');
            }
    }
    else{
        std::cerr << "Something didn't work." << std::endl;
    }
}

void rwa2group15::Algorithm::set_cell_color(){
    int x_position = m_mouse->get_position().first;
    int y_position = m_mouse->get_position().second;
    Simulator::setColor(x_position, y_position, 'c');
    Simulator::setText(x_position, y_position, "bc");
}

void rwa2group15::Algorithm::follow_wall_left(){
    std::pair<int,int> position = m_mouse->get_position();
    while(position != m_goal){
        if(!Simulator::wallLeft()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_left();
        }
        else if(!Simulator::wallFront()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->move_forward();
        }
        else if(!Simulator::wallRight()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_right();
        }
        else{
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_back();
        }
        position = std::pair<int,int>{m_mouse->get_position().first, m_mouse->get_position().second};
    }
    set_cell_color();
    set_front_wall();
    set_left_wall();
    set_right_wall();
}

void rwa2group15::Algorithm::follow_wall_right(){
    std::pair<int,int> position = m_mouse->get_position();
    while(position != m_goal){
        if(!Simulator::wallRight()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_right();
        }
        else if(!Simulator::wallFront()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->move_forward();
        }
        else if(!Simulator::wallLeft()){
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_left();
        }
        else{
            set_cell_color();
            set_front_wall();
            set_left_wall();
            set_right_wall();
            m_mouse->turn_back();
        }
        position = std::pair<int,int>{m_mouse->get_position().first, m_mouse->get_position().second};
    }
    set_cell_color();
    set_front_wall();
    set_left_wall();
    set_right_wall();
}

void rwa2group15::Algorithm::run(){
    init_outer_walls();
    generate_goal();
    std::cerr << "bc: breadcrumbs" << std::endl;
    // follow_wall_left();
    follow_wall_right();
    std::cerr << "HOORAY" << std::endl;
}