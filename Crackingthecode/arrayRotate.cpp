#include <iostream>

int main (){
   unsigned int size = 0, index = 0, numRot = 0, elem = 0;
   std::cin >> size >> numRot;
   int result[size];
   index = (size - numRot) % size;
   while (std::cin >> elem){
      index = index % size;
      result[index++] = elem;
   }
   for (unsigned int i = 0; i < size; ++i){
      if (i != 0){
         std::cout << " ";
      }
      std::cout << result[i];
   }
   std::cout << std::endl;
   return 0;
}