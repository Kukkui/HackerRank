#include <iostream>
#include <map>

bool isReplicaNote();

int main (){
   if (isReplicaNote()){
      std::cout << "Yes" << std::endl;
   } else {
      std::cout << "No" << std::endl;
   }
   return 0;
}

bool isReplicaNote(){
   unsigned int numMag = 0, numRans = 0;
   std::string currWord;
   std::map<std::string, int> words;
   std::cin >> numMag >> numRans;
   for (unsigned int i = 0; i < numMag; ++i){
      std::cin >> currWord;
      words[currWord]++;
   }
   for (unsigned int i = 0; i < numRans; ++i){
      std::cin >> currWord;
      if (words.count(currWord)){
         words[currWord]--;
         if (words[currWord] < 0){
            return false;
         }
      } else {
          return false;
      }
   }
   return true;
}