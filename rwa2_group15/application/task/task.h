#ifndef __TASK_H__
#define __TASK_H__

/**
 * @file task.h
 * @author Shreejay Badshah (sbadshah@umd.edu)
 * @brief Functions to move the mouse in a maze, keeping track of mouse's location and direction, and setting maze cell data in an array.
 * @version 1.0
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<string>
#include<iostream>
#include<array>
#include<memory>

/**
 * @brief Working under rwa2group15 namespace.
 * 
 */

namespace rwa2group15{

/**
 * @brief This class controls the movement of the mouse.
 * 
 */

class Mouse{

    public:
     Mouse(int x_pos = 0, int y_pos = 0, char direction = 'n'): // 3-param ctor.
                                                             m_position{std::make_pair(x_pos,y_pos)},
                                                             m_direction{direction}{
               //  std::cerr << "Starting position: (0,0), facing north." << std::endl;
        }

     /**
      * @brief Turn robot to left side and move
      * 
      * 
      */
     void turn_left();
     
     /**
      * @brief Turn robot to right side and move
      * 
      * 
      */
     void turn_right();

     /**
      * @brief Move robot forward
      * 
      * 
      */
     void move_forward();

     /**
      * @brief Turn robot to back side and move
      * 
      * 
      */
     void turn_back();

     /**
      * @brief Get the direction object
      * 
      * @return const char& 
      */
     const char& get_direction(){                     
        return m_direction;
     }

     /**
      * @brief Get the position object
      * 
      * @return const std::pair<int, int>& 
      */
     const std::pair<int, int>& get_position(){       
        return m_position;
     }

    private:
     std::pair<int, int> m_position;
     char m_direction;

}; // class Mouse

/**
 * @brief This class represents a cell (walls) in the maze
 * 
 */
class Cell{
    
    public:
     Cell(): // 1-param ctor
            m_walls{0,0,0,0}{
            // std::cout << "Initializing cell walls." << std::endl;
        }
     
     /**
      * @brief Initialize all 4 wall of a cell
      * 
      * 
      */
     void init_cell_walls();

     /**
      * @brief Set the wall object based on is_wall method
      * 
      * @param wall 
      * @param is_wall 
      */
     void set_wall(int wall, bool is_wall);
     
     /**
      * @brief Check if the wall exists or not
      * 
      * @param wall 
      * @param direction 
      * @return true 
      * @return false 
      */
     bool is_wall(int wall, char direction);

     void get_walls(){
         for(auto i{0}; i < 4; i++){
            std::cerr << m_walls.at(i) << " ";
         }
         std::cerr << "\n" << std::endl;
      }

    private:
     //!<@brief The walls of the cell.
     //!< false means the wall is open
     //!< true means the wall is closed
     //!< 0 = North, 1 = East, 2 = South, 3 = West
     std::array<bool,4> m_walls;
}; // class Cell


/**
 * @brief This class implements the search algorithm.
 * 
 */
class Algorithm{

    public:
     Algorithm(): // 1-param c-tor
                  m_maze{},
                  m_goal{14,0},
                  m_maze_height{0},
                  m_maze_weight{0}{
         m_mouse = std::make_unique<Mouse>();
         // std::cout << "Starting Algorithm Class" << std::endl;
         // std::cerr << "Starting Algorithm Class" << std::endl;
      }

     /**
      * @brief Initialize outer walls, generate goals, and execute search algorithm
      * 
      * 
      */
     void run();

     /**
      * @brief Color outer walls
      * 
      * 
      */
     void init_outer_walls();

     /**
      * @brief Algorithm for left hand rule approach
      * 
      * 
      */
     void follow_wall_left();

     /**
      * @brief Algorithm for right hand rule approach
      * 
      * 
      */
     void follow_wall_right();

     /**
      * @brief Generate random goal adjacent to an outer wall
      * 
      * 
      */
     void generate_goal();

     /**
      * @brief Set left wall in m_maze and simulator
      * 
      * 
      */
     void set_left_wall();

     /**
      * @brief Set the right wall object in m_maze and simulator
      * 
      * 
      */
     void set_right_wall();
 
     /**
      * @brief Set the front wall object in m_maze and simulator
      * 
      * 
      */
     void set_front_wall();

     /**
      * @brief Set the color of the cell on Mouse's path.
      * 
      */
     void set_cell_color();

     private:
     //!<@brief A maze is a 2D array of cells.
      std::array<std::array<Cell,16>,16> m_maze;
      std::shared_ptr<Mouse> m_mouse;
      std::pair<int,int> m_goal;
      int m_maze_height;
      int m_maze_weight;

}; //class Algorithm
}  // namespace rwa2group15

#endif