#include <iostream>
#include <fstream>
#include <string>

void printMenu();
void printCredits();
void loadGame();
void saveGame(std::string saveName);
void loadData(std::string, std::string, int);
void loadPlayer(std::string, int, int);
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

      } 
      else if (input == "2") {
         //load game
         loadGame();
      } 
      else if (input == "3") {
         //credits
         printCredits();
      } 
      else if (input == "4") {
         //quit
         quit = true;
      } 
      else {
         //bad input, try again
         std::cout << "Choice not recognised, please choose an option from the list" << std::endl;
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
   std::cout << std::endl << "> ";
   std::cin >> input;
   return input;
}

void saveGame(std::string saveName) {

   std::ofstream savefile;
   savefile.open (saveName + ".txt");
   int currentLine = 0;

   while (currentLine <= 35) {
      std::string data;

      if (currentLine == 0) {
         // data = getBag();
      } 
      else if (currentLine == 1) {
         // data = getLid();
      } 
      else if (currentLine >= 2 && currentLine <= 5) {
         // data = getFactory(currentLine - 2);
      } 
      else if (currentLine == 6) {
         // data = getTable();
      } 
      else if (currentLine >= 7 && currentLine <= 34) {
         //14 lines of data for a player, * 2
         //Player player = getPlayer((currentLine - 7) / 14);
         int currentDataPoint = (currentLine - 7) % 14;
         if (currentDataPoint == 0) {
            //player.getName();
         } 
         else if (currentDataPoint == 1) {
            //player.getID()????
         } 
         else if (currentDataPoint >= 2 && currentDataPoint <= 6) {
            //player.getBufferLine(currentDataPoint-3);
         } 
         else if (currentDataPoint >= 7 && currentDataPoint <= 11) {
            //player.getWallLine(currentDataPoint-8);
         } 
         else if (currentDataPoint == 12) {
            //player.getFloor();
         } 
         else if (currentDataPoint == 13) {
            //player.getScore();
         }

      } 
      else if (currentLine == 35) {
         // data = getCurrentPlayerID();
      }

      savefile << data + "\n";
      currentLine++;
   }

   

   savefile.close();

}

void loadGame() {
   //get user input for which file to load
   std::string input;
   std::cout << "Enter the name of the file which you want to load." 
                  << std::endl << ">";
   std::cin >> input;

   //open specified file
   std::string line;
   std::ifstream loadFile (input +".txt");
   int currentLine = 0;
   if (loadFile.is_open()) {
      //read lines, discarding # or empty lines
      while (getline(loadFile,line)) {
         std::string lineCheck = line;
         //comments or empty
         if (line[0] == '#' || line[1] == '\0') {
            std::cout << "BING" << std::endl;
         }
         //read in the data
         else {
            std::string dataIdentifier;
            int dataIndex = 0;

            //identify what part of the file we are reading
            if (currentLine == 0) {
               dataIdentifier = "bag";
            } 
            else if (currentLine == 1) {
               dataIdentifier = "lid";
            } 
            else if (currentLine >= 2 && currentLine <= 5) {
               dataIdentifier = "factory";
               dataIndex = currentLine - 2;
            } 
            else if (currentLine == 6) {
               dataIdentifier = "table";
            } 
            else if (currentLine >= 7 && currentLine <= 34) {
               //14 lines of data for a player, * 2
               dataIdentifier = "player";
               dataIndex = currentLine - 7;
            } 
            else if (currentLine == 35) {
               dataIdentifier = "currentTurn";
            }

            //send that to our neat loading function
            loadData(lineCheck, dataIdentifier, dataIndex);

            currentLine++;
         }
      }
      loadFile.close();
   }
   else std::cout << "Unable to open file"; 

}

void loadData(std::string line, std::string dataIdentifier, int dataIndex) {
   if (dataIdentifier == "bag") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      //loadBag(line);
   } 
   else if (dataIdentifier == "lid") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      //loadLid(line);
   } 
   else if (dataIdentifier == "factory") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      //loadFactory(line,dataIndex);
   } 
   else if (dataIdentifier == "table") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      //loadTable(line);
   } 
   else if (dataIdentifier == "player") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      loadPlayer(line, dataIndex % 14, dataIndex / 14);
   } 
   else if (dataIdentifier == "currentTurn") {
      std::cout << line << std::endl;
      std::cout << " " << dataIdentifier << std::endl;
      //setPlayerTurn(line);
   } 
}

void loadPlayer(std::string line, int playerID, int dataLine) {
   //Player player = getPlayer(playerID);
   //data loaded in order
   //name
   //id?????
   //buffer 1
   //buffer 2
   //buffer ...
   //wall 1
   //wall 2
   //wall ...
   //floor
   //score

   if (dataLine == 0) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setName(line);
   } 
   else if (dataLine == 1) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setID(line)????
   } 
   else if (dataLine >= 2 && dataLine <= 6) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setBufferLine(line,dataLine-3);
   } 
   else if (dataLine >= 7 && dataLine <= 11) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setWallLine(line,dataLine-8);
   } 
   else if (dataLine == 12) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setFloor();
   } 
   else if (dataLine == 13) {
      std::cout << line << " " << playerID << " " << dataLine << std::endl;
      //player.setScore();
   }
}