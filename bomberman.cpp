#include <iostream>
#include <vector>
#include <string>

void print(const std::vector<std::vector<char>> &grid, int &nRow, int &nCol);
void initializeGrid (std::vector<std::vector<char>> &grid, int &nRow, int &nCol);

int main (){

   int nRow = 0, nCol = 0, n = 0;
   std::cin >> nRow >> nCol >> n;
   std::vector<std::vector<char>> grid(nRow, std::vector<char>(nCol, '.'));
   initializeGrid(grid, nRow, nCol);
   
   
   return 0;
}





void initializeGrid (std::vector<std::vector<char>> &grid, int &nRow, int &nCol){
   std::string curr;
   for (int i = 0; i < nRow; ++i){
      std::cin >> curr;
      for (int j = 0; j < nCol; ++j){
         if (curr[j] == '0') grid[i][j] = '0';
      }
   }
}



void detonate (){



   
}

void print(const std::vector<std::vector<char>> &grid, int &nRow, int &nCol){
   for (int i = 0; i < nRow; ++i){
      for (int j = 0; j < nCol; ++j){
         std::cout << grid[i][j];
      }
      std::cout << std::endl;
   }
}
