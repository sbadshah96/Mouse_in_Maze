#ifndef __TASK_H__
#define __TASK_H__

#include<string>
#include<iostream>
#include<array>
#include<memory>

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
     // turn robot to left side and move
     void turn_left();
     
     // turn robot to right side and move
     void turn_right();

     // move robot forward
     void move_forward();

     // turn robot to back side and move
     void turn_back();

     // return the direction of the robot
     const char& get_direction(){                     
        return m_direction;
     }

     // return the position of the robot
     const std::pair<int, int>& get_position(){       
        return m_position;
     }

    private:
     std::pair<int, int> m_position;
     char m_direction;

}; // class Mouse

/**
 * @brief This class represents a cell (walls) in the maze.
 * 
 */
class Cell{
    
    public:
     Cell(): // 1-param ctor
            m_walls{0,0,0,0}{
            // std::cout << "Initializing cell walls." << std::endl;
        }
     
     // initialize all 4 wall of a cell
     void init_cell_walls();

     // set one of the walls based on is_wall
     void set_wall(int wall, bool is_wall);
     
     // return true if wall is closed
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

     // initialize outer walls, generate goals, execute search algorithm etc
     void run();

     // color outer walls
     void init_outer_walls();

     // algorithm for left hand rule approach
     void follow_wall_left();

     // algorithm for right hand rule approach
     void follow_wall_right();

     // generate random goal adjacent to an outer wall
     void generate_goal();

     // set left wall in m_maze and simulator
     void set_left_wall();

     // set right wall in m_maze and simulator
     void set_right_wall();

     // set front wall in m_maze and simulator
     void set_front_wall();

     // set the color of the cell on Mouse's path.
     void set_cell_color();

     //
   //   void set_mouse(std::shared_ptr<Mouse> mouse){
   //       m_mouse = mouse;
   //   }

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