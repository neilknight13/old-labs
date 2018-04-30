#include "Pathfinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

string Pathfinder::toString() const {
   stringstream ss;
   for(int row = 0; row < ROW_SIZE; row++) {
	   for(int col = 0; col < COL_SIZE; col++) {
	      for (int height = 0; height < HEIGHT_SIZE; height++) {
	         if (height == HEIGHT_SIZE - 1) {
	            if (arrayInitialized) {
	               ss << maze_grid[row][col][height];
	            }
	            else {
	               ss << "1";
	            }
	         }
	         else {
	            if (arrayInitialized) {
	               ss << maze_grid[row][col][height] << " ";
	            }
	            else {
	               ss << "1 ";
	            }
	         }
	      }
	      ss << endl;
      }
      if (row != ROW_SIZE - 1) {
         ss << endl;
      }
   }
   return ss.str();
}

void Pathfinder::createRandomMaze() {
   for (int row = 0; row < ROW_SIZE; row++) {
      for (int col = 0; col < COL_SIZE; col++) {
         for (int height = 0; height < HEIGHT_SIZE; height++) {
            maze_grid[row][col][height] = rand() % 2;
         }
      }
   }
   maze_grid[0][0][0] = 1;
   maze_grid[4][4][4] = 1;
   arrayInitialized = true;
}

bool Pathfinder::isNumber(string token) {
    stringstream ss(token);
    string::const_iterator it = token.begin();
    while (it != token.end() && isdigit(*it)) ++it;
    return !token.empty() && it == token.end();
}
   
bool Pathfinder::importMaze(string file_name) {
   string token;
   int intCount = 0;
   cout << "importMaze from " << file_name << endl;
   ifstream fileCheck (file_name.c_str());
   while (fileCheck >> token) {
      if (isNumber(token)) {
         intCount = intCount + 1;
      }
   }
   if (intCount != 125) {
      return false;
   }
   ifstream file (file_name.c_str());
   if (file.is_open()) {
      string line;
      int row_count = 0;
      for (int row = 0; row < ROW_SIZE; row++) {
         for (int col = 0; col < COL_SIZE; col++) {
            for (int height = 0; height < HEIGHT_SIZE; height++) {
               int value = 0;
               file >> value;
               maze_grid[row][col][height] = value;
            }
         }
      }
      if (maze_grid[0][0][0] == 1 && maze_grid[4][4][4] == 1) {
         arrayInitialized = true;
         return true;
      }
   }
   else {
      arrayInitialized = false;
      return false;
   }
}

bool Pathfinder::find_maze_path(int grid[ROW_SIZE][COL_SIZE][HEIGHT_SIZE], int r, int c, int h) {
	  solution.push_back("("+to_string(h)+", "+to_string(c)+", " + to_string(r)+")");
	  if (r < 0 || c < 0 || h < 0 || r >= ROW_SIZE || c >= COL_SIZE || h >= HEIGHT_SIZE) {
	     solution.pop_back(); //outside of maze
	     return false;
	  }
	  if (grid[r][c][h] == WALL) {
	     solution.pop_back();
	     return false;      // Cell is on barrier or dead end.
	  }
	  if (grid[r][c][h] == TEMPORARY) {
	     solution.pop_back();
	     return false;
	  }
	  if (r == ROW_SIZE - 1 && c == COL_SIZE - 1 && h == HEIGHT_SIZE - 1) {
	     return true; 
	  }
	  cout << "Got onto path ["<< r << "][" << c <<"]["<<h<<"]" << endl;
	  grid[r][c][h] = TEMPORARY;
	  if (find_maze_path(grid, r - 1, c, h) // Up
	        || find_maze_path(grid, r + 1, c, h) // Down
	        || find_maze_path(grid, r, c - 1, h) // Left
	        || find_maze_path(grid, r, c + 1, h) // Right
	        || find_maze_path(grid, r, c, h - 1) //Inward
	        || find_maze_path(grid, r, c, h + 1) ) { // Outward
	        return true;
	    }
	    else {
	       solution.pop_back();
	       return false;
	    }
}

vector<string> Pathfinder::solveMaze() {
   solution.clear();
   arrayInitialized = true;
   find_maze_path(maze_grid, 0, 0, 0);
   for (int i = 0; i < ROW_SIZE; ++i) {
	   for (int j = 0; j < COL_SIZE; ++j) {
         for (int k = 0; k < HEIGHT_SIZE; ++k) {
            if (maze_grid[i][j][k] == 2) {
               maze_grid[i][j][k] = 1;
            }
         }
	   }
   }
   return solution;
}