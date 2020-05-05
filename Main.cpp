#include <iostream>
#include <string>

void printMenu();
void printCredits();
std::string takeMenuInput();

int main(int argc, char const *argv[])
{
   //loop until we quit
   bool quit = false;
   printMenu();
   while (!quit) {
      std::string input = takeMenuInput();
      
      //handle input
      if (input == "1") {
         //new game


      } else if (input == "2") {
         //load game


      } else if (input == "3") {
         //credits
         printCredits();
      } else if (input == "4") {
         //quit
         quit = true;

      } else{
         //bad input, try again
         std::cout << "Bad input" << std::endl;
      }

   }

   return 0;
}

void printMenu() {
   //just print these lines as the main menu
   std::cout << "Welcome to Azul!" << std::endl;
   std::cout << "-------------------" << std::endl;
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits (Show student information)" << std::endl;
   std::cout << "4. Quit" << std::endl;
}

void printCredits() {
   std::cout << "----------------------------------" << std::endl;
   std::cout << "Name:        Jordan Tori" << std::endl;
   std::cout << "Student ID:  s3542275" << std::endl;
   std::cout << "Email:       s3542275@student.rmit.edu.au" << std::endl;
   std::cout << "Name:        Merhawi Minassi" << std::endl;
   std::cout << "Student ID:  s3668396" << std::endl;
   std::cout << "Email:       s3668396@student.rmit.edu.au" << std::endl;
   std::cout << "Name:        Guy Witherow" << std::endl;
   std::cout << "Student ID:  s3783428" << std::endl;
   std::cout << "Email:       s3783428@student.rmit.edu.au" << std::endl;
   std::cout << "----------------------------------" << std::endl;

}



std::string takeMenuInput() {

   //TODO Ensure user input is valid
   std::string input;

   //user input space is indicated by an arrow
   std::cout << "> ";
   std::cin >> input;

   return input;
}