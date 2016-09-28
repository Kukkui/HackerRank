#include <iostream>
#include <map>

int main (){
   std::string s1, s2;
   std::map <char, int> freq;
   std::cin >> s1;
   std::cin >> s2;
   unsigned int deleteCount = 0;
   for (auto it = s1.begin(); it != s1.end(); ++it){
      freq[*it]++;
   }
   for (auto it = s2.begin(); it != s2.end(); ++it){
      freq[*it]--;
   }
   for (auto it = freq.begin(); it != freq.end(); ++it){
      if (it->second != 0){
         deleteCount += abs(it->second);
      }
   }
   std::cout << deleteCount << std::endl;
   return 0;
}