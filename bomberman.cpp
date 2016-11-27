/* Solution by Alex Li
 * 
 * Notes:
 *  - Passed in vector of vector as a const reference to avoid copying
 *  - Compile with g++ -std=c++14 -Wall -Werror -o bomberman bomberman.cpp
 *  - YOU MUST COMPILE WITH the -std=c++14 flag because of the templating syntax change.
*/

#include <iostream>
#include <vector>
#include <string>

void print(const std::vector<std::vector<char>> &grid, int R, int C);
void read(std::vector<std::vector<char>> &grid, int R, int C);
void detonate (std::vector<std::vector<char>> &grid, std::vector<std::vector<char>> &map, int R, int C);
void set (std::vector<std::vector<char>> &grid, int R, int C, char ch);

int main (){
   int R = 0, C = 0, n = 0;
   std::cin >> R >> C >> n;
   std::vector<std::vector<char>> grid(R, std::vector<char>(C, '.'));
   std::vector<std::vector<char>> map(R, std::vector<char>(C, 'O'));
   read(grid, R, C);
   if (n % 2 == 0){
      set(grid, R, C, 'O');
   } else if ((n + 1) % 4 == 0){
      detonate(grid, map, R, C);
   } else if ((n - 1) % 4 == 0 && n != 1) {
      detonate(grid, map, R, C);
      detonate(grid, map, R, C);
   }
   print(grid, R, C);
   return 0;
}

void set (std::vector<std::vector<char>> &grid, int R, int C, char ch){
   for (int i = 0; i < R; ++i){
      for (int j = 0; j < C; ++j){
         grid[i][j] = ch;
      }
   }
}

void detonate (std::vector<std::vector<char>> &grid, std::vector<std::vector<char>> &map, int R, int C){
   for (int i = 0; i < R; ++i){
      for (int j = 0; j < C; ++j){
         if (grid[i][j] == 'O'){
            if (i - 1 >= 0 && grid[i-1][j] != 'O') map[i-1][j] = '.';
            if (i + 1 < R && grid[i+1][j] != 'O') map[i+1][j] = '.';
            if (j - 1 >= 0 && grid[i][j-1] != 'O') map[i][j-1] = '.';
            if (j + 1 < C && grid[i][j+1] != 'O') map[i][j+1] = '.';
            map[i][j]='.';
         }
      }
   }
   grid = map;
   set(map, R, C, 'O');
}

void read(std::vector<std::vector<char>> &grid, int R, int C){
   std::string curr;
   for (int i = 0; i < R; ++i){
      std::cin >> curr;
      for (int j = 0; j < C; ++j){
         if (curr[j] == 'O') grid[i][j] = 'O';
      }
   }
}

void print(const std::vector<std::vector<char>> &grid, int R, int C){
   for (int i = 0; i < R; ++i){
      for (int j = 0; j < C; ++j){
         std::cout << grid[i][j];
      }
      std::cout << std::endl;
   }
}
