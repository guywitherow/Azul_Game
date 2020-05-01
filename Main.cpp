#include <iostream>
#include <string>

void printMenu();

int main(int argc, char const *argv[])
{
   printMenu();
   
   return 0;
}

void printMenu() {

   std::string menu[] = {"Welcome to Azul!","-------------------","Menu","----","1. New Game",
                     "2. Load Game","3. Credits (Show student information)","4. Quit"};
   int menuSize = 8;

   for (int i = 0; i < menuSize; i++) {
      std::cout << menu[i] << std::endl;
   }
}