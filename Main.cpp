#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h> 
#include <cstdlib>
#include <iterator>
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include "Tile.h"
#include "Bag.h"
#include <vld.h>

void printMenu();
void printCredits();
void printReferenceBoard();
void loadGame();
void saveGame(std::string saveName);
void game(int seed);
void takePlayerTurn(Factory* (*factories)[NUM_FACTORIES], Factory* table, Player* player);
void loadData(std::string, std::string, int);
void loadPlayer(std::string, int, int);
void printFactories(Factory* (*factories)[NUM_FACTORIES], Factory* table);
void printPlayerWall(Player* player);
std::vector<std::string> takeUserInput();

int main(int argc, char const *argv[])
{
   //loop until we quit
   bool quit = false;
   printMenu();
   while (!quit) {
      std::string input = takeUserInput().at(0);
      
      //handle input
      if (input == "1") {
         int seed = 0;
         //new game
         if (argc == 2) {
            //TODO check seed is a valid seed
            seed = atoi(argv[1]);
            srand(seed);
         }
         else {
            //generate a random seed
            // srand(time(0));
            srand(1);
         }

         seed = rand();
         game(seed);
         
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
      else if (input == "save") {
         saveGame("bigtest");
      }
      else {
         //bad input, try again
         std::cout << "Choice not recognised, please choose an option from the list" << std::endl;
      }
   }

   return 0;
}

void game(int seed) {
   std::cout << "Starting a new game" << std::endl;

   //bag init
   Bag* bag = new Bag(seed);
   bag->shuffle();
   Factory* table = new Factory();

   Factory* factories[NUM_FACTORIES];
   for (int i = 0; i < NUM_FACTORIES; i++) {
      factories[i] = new Factory();
   }
   //player names

   std::cout << "Enter a name for player 1" << std::endl << std::endl;
   std::string name = takeUserInput().at(0);
   Player* player1 = new Player(name);

   std::cout << "Enter a name for player 2" << std::endl << std::endl;
   name = takeUserInput().at(0);
   Player* player2 = new Player(name);

   std::cout << "Let's Play!" << std::endl << std::endl;

   bool roundLoop = true;
   while (roundLoop) {
      //ensure clear factories, then fill
      for (int i = 0; i < NUM_FACTORIES; i++) {
         factories[i]->clearFactory();
         for (int j = 0; j < 4; j++) {
            factories[i]->addTile(bag->getTopTile());
         }
      }
      //ensure clean table, add first player tile
      table->clearFactory();
      table->addTile(Tile(TileType::FIRST_PLAYER));


      bool tileLoop = true;
      while (tileLoop) {
         printFactories(&factories, table);
         printPlayerWall(player1);
         takePlayerTurn(&factories, table, player1);
         //selection
         //player 2 loops
         printFactories(&factories, table);
         printPlayerWall(player2);
         //loop until we have no tiles on table
         //factories check

         int factoryTileCount = 0;
         int tableTileCount = 0;

         tableTileCount = table->getTileCount();
         for (int i = 0; i < NUM_FACTORIES; i++) {
            //check all factories
            factoryTileCount = factories[i]->getTileCount();
            if (factoryTileCount != 0) {
               i = 5;
            }
         }
         //if any factory has tiles left, wait.
         if (tableTileCount > 0 || factoryTileCount > 0) {
            tileLoop = true;
         }
         else {
            tileLoop = false;
         }
      }

      //SCORE HERE


      //stop looping the rounds when a player wins
      roundLoop = false;
   }
   std::cout << "Game Over." << std::endl;
   delete bag;
   delete player1;
   delete player2;
   delete table;
   for (int i = 0; i < 5; i++) {
      delete factories[i];
   }
}

void takePlayerTurn(Factory* (*factories)[NUM_FACTORIES], Factory* table, Player* player) {
   bool valid = false;
   while (!valid) {
      std::vector<std::string> turn = takeUserInput();
      if (turn.size() > 0) {
         std::string command = turn.at(0);
         if (command == "help" || command == "h") {
            std::cout << "This is where you take your turn. Use the command 'turn', ";
            std::cout << "along with your selections to take your turn!" << std::endl;
            std::cout << "eg: '> turn 3 L 3' moves all light blue tiles, from ";
            std::cout << "factory 3, and puts them in storage line 3" << std::endl;
         }
         else if (command == "turn") {
            if (turn.size() != 4) {
               std::cout << "Please use the command format, 'turn <factory> <color_code> <buffer>" << std::endl;
               std::cout << turn.at(1) << std::endl;
            }
            else {
               //check turn input is valid
               int factory = -1;
               int bufferLine = -1;

               //factory int interp
               try {
                  factory = std::stoi(turn.at(1));
               }
               //catch oob or invalid
               catch (...) {
                  std::cout << "Please input a valid factory ID, between 0 and 5." << std::endl;
               }
               //bufferline in interp
               try {
                  bufferLine = std::stoi(turn.at(3));
               }
               //same as above
               catch (...) {
                  std::cout << "Please input a valid buffer ID, between 1 and 5." << std::endl;
               }

               //change tile string to TileType
               TileType userTileType = Tile::stringToType(turn.at(2));

               std::string errorCheck = "";

               //errorCheck += checkValidFactory(factory);
               //errorCheck += checkValidTile(tileChar);
               //errorCheck += checkValidBuffer(bufferLine);

               if (errorCheck == "") {
                  int tiles = -1;
                  if (factory == 0) {
                     tiles = table->removeTile(userTileType);
                     if (table->removeTile(TileType::FIRST_PLAYER) != 0) {
                        player->getWall()->addToFloorLine(TileType::FIRST_PLAYER, 1);
                     }
                  }
                  else {
                     tiles = (*factories)[factory - 1]->removeTile(userTileType);
                  }

                  if (tiles > 0) {
                     valid = true;
                     player->getWall()->addToStorageLine(userTileType, tiles, bufferLine);
                     std::vector<Tile> moveToTable = (*factories)[factory]->getTiles();
                     (*factories)[factory]->clearFactory();
                  }
                  else {
                     std::cout << "Factory number " + std::to_string(factory) + " has no tiles of type ";
                     std::cout << Tile::tileToString(userTileType) << ". Please make a valid selection.";
                     //the player has chosen to take a type of tile that is not in that factory
                  }

               }
               else {
                  //some blah about valid tile types, as well as buffers and factories
               }
            }
         }
         else if (command == "quit") {
            //exit the game
         }
         else if (command == "save") {
            //save the game
         }
      }
      else {
         std::cout << "Please input a command." << std::endl;
      }
   }
   
      
   
}

void printFactories(Factory* (*factories)[NUM_FACTORIES], Factory* table) {

   std::cout << "Factories: " << std::endl << "0: ";
   table->printFactory();
   std::cout << std::endl;

   for (int i = 0; i < NUM_FACTORIES; i++) {
      if (factories != nullptr) {
         std::cout << i + 1 << ": ";
         (*factories)[i]->printFactory();
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

void printPlayerWall(Player* player) {
   std::string playerName = player->getName();
   std::string wallString = player->getWall()->getPlayerWallString();

   std::cout << "Mosaic for " << playerName << ":" << std::endl;
   std::cout << wallString << std::endl;
   std::cout << std::endl;
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

void printReferenceBoard() {
   std::cout << "This is the pattern each board follows!" << std::endl;
   //maybe add command to bring this up?
   char tiles[WALL_DIM] = { 'B', 'Y', 'R', 'U', 'L' };
   for (int i = 0; i < WALL_DIM; i++) {
      for (int j = 0; j < WALL_DIM; j++) {
         int tileNumber = (j + i) % 5;
         std::cout << tiles[tileNumber] << " ";
      }
      std::cout << std::endl;
   }

   std::cout << std::endl;

   std::cout << "Please make moves using the format 'turn <factory number> <tile color letter> <storage row>" << std::endl;
}

std::vector<std::string> takeUserInput() {
   //TODO Ensure user input is valid
   std::string input = "";
   //user input space is indicated by an arrow
   std::cout << std::endl << "> ";
   std::getline(std::cin,input);

   //break string into arguments
   std::istringstream stream{input};
   using StrIt = std::istream_iterator<std::string>;
   std::vector<std::string> container{ StrIt{stream}, StrIt{} };

   if (container.size() == 0) {
      container.push_back(" ");
   }

   return container;
}

void saveGame(std::string saveName) {

   std::ofstream savefile;
   savefile.open(saveName + ".txt");
   int currentLine = 0;

   while (currentLine <= 35) {
      std::string data = "a";

      if (currentLine == 0) {
         // data = getBag();
      }
      else if (currentLine == 1) {
         // data = getLid();
      }
      else if (currentLine >= 2 && currentLine <= 6) {
         // data = getFactory(currentLine - 2);
      }
      else if (currentLine == 7) {
         // data = getTable();
      }
      else if (currentLine >= 8 && currentLine <= 35) {
         //14 lines of data for a player, * 2
         //Player player = getPlayer((currentLine - 7) / 14);
         int currentDataPoint = (currentLine - 7) % 14;
         if (currentDataPoint == 0) {
            //data = player.getName();
         }
         else if (currentDataPoint == 1) {
            //data = player.getID()????
         }
         else if (currentDataPoint >= 2 && currentDataPoint <= 6) {
            //data = player.getBufferLine(currentDataPoint-3);
         }
         else if (currentDataPoint >= 7 && currentDataPoint <= 11) {
            //data = player.getWallLine(currentDataPoint-8);
         }
         else if (currentDataPoint == 12) {
            //data = player.getFloor();
         }
         else if (currentDataPoint == 13) {
            //data = player.getScore();
         }

      }
      else if (currentLine == 36) {
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
      << std::endl << "> ";
   std::cin >> input;

   //open specified file
   std::string line;
   std::ifstream loadFile(input + ".txt");
   int currentLine = 0;
   if (loadFile.is_open()) {
      //read lines, discarding # or empty lines
      while (getline(loadFile, line)) {
         std::string lineCheck = line;
         if (line[0] == '#' || line.length() == 0) {
            //do nothin
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
            else if (currentLine >= 2 && currentLine <= 6) {
               dataIdentifier = "factory";
               dataIndex = currentLine - 2;
            }
            else if (currentLine == 7) {
               dataIdentifier = "table";
            }
            else if (currentLine >= 8 && currentLine <= 35) {
               //14 lines of data for a player, * 2
               dataIdentifier = "player";
               dataIndex = currentLine - 8;
            }
            else if (currentLine == 36) {
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
      //loadBag(line);
   }
   else if (dataIdentifier == "lid") {
      //loadLid(line);
   }
   else if (dataIdentifier == "factory") {
      //loadFactory(line,dataIndex);
   }
   else if (dataIdentifier == "table") {
      //loadTable(line);
   }
   else if (dataIdentifier == "player") {
      loadPlayer(line, dataIndex / 14, dataIndex % 14);
   }
   else if (dataIdentifier == "currentTurn") {
      //setPlayerTurn(line);
   }

   if (dataIdentifier != "player") {
      std::cout << line << std::endl;
      std::cout << "is data for : " << dataIdentifier << std::endl;
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
      //player.setName(line);
   }
   else if (dataLine == 1) {
      //player.setID(line)????
   }
   else if (dataLine >= 2 && dataLine <= 6) {
      //player.setBufferLine(line,dataLine-3);
   }
   else if (dataLine >= 7 && dataLine <= 11) {
      //player.setWallLine(line,dataLine-8);
   }
   else if (dataLine == 12) {
      //player.setFloor();
   }
   else if (dataLine == 13) {
      //player.setScore();
   }

   std::cout << line << std::endl;
   std::cout << "is player " << playerID << "'s data for " << dataLine << std::endl;
}
