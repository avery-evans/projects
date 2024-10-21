//Avery Evans
//at home project
//Tic-Tac-toe game


#include <iostream>
#include <cmath>
#include <string>
#define Dimension 3
using namespace std;

//class to get the player
class Player{
    private:
    string name;

    public:

    //constructor
    Player(string n) {
        name = n;
    }

    //accessor function
    string getName() {
        return this->name;
    }
};

//game class
class Game {
    private:

    char gameBoard[3][3];
    char currentPlayer;
    int count;
     public:
    
    //to create the tic-tac-toe board
    void createBoard() {

    //for loops to illreate through the gameboard
    for(int i = 0; i < 3; ++i) 
    
    for(int j = 0; j < 3; ++j) 
    gameBoard[i][j] = ' ';

    showBoard();
}

//to show the board
void showBoard() {

   printf("\n\n");

    //get the rows of the board
    for(int i = 0; i < 3; ++i) {
        cout << "\t\t\t";

        //get the colunms of the board
        for(int j = 0; j < 3; ++j) 
            cout << gameBoard[i][j] << " | ";
            
        cout << "  |\n\t\t\t---------" << endl;
        }
}

//to check if the board is full
bool fullBoard() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            gameBoard[i][j] = ' ';
            return false;
        }
    }
}

//player function with object to make the game run
void playerTurn(Player &player) {
    int position;
    int row;
    
    //get the name of the player
    cout << "Turn of " << player.getName() << ": " << endl;

    //enter the position to be marked
    cout << "Enter the position to be marked";
    cin >> position;

    //compute the row
    row = ceil((float)position/Dimension);

    //compute the column
    int column = (position -  1) % Dimension;

    //if the position is empty
    if(gameBoard[row - 1][column] != ' ') {
        cout <<"Position already marked. Select a new position.";
    
    playerTurn(player);
    } else {
        player.getName().compare("Player 1") == 0 ? gameBoard[row - 1][column] = 'X' : gameBoard[row - 1][column] = 'O'; 
        cout << "Marked position at: " << position << endl;

        //increment count 
        ++count;
    }

    showBoard();

}

//computer turn
void computerTurn() {
    int random;

    //turn of computer
    cout << "Turn of computer: " << endl;
    random = rand() % (Dimension * Dimension + 1);

    //compute the row
    int row = ceil((float)random/Dimension);

    //compute the column
    int column = (random -  1) % Dimension;

      //if the position is empty
    if(gameBoard[row - 1][column] != ' ') {
        computerTurn();
    } else {
        cout << "mark position at: " << random << endl;
        gameBoard[row - 1][column] = '0';

        count++;

        showBoard();

    }





}

//to check and see who won
string checkWin() {
    //horizontal check
    int r1;
    int r2;

    //vertical check
    int v1;
    int v2;

    //dialongal check
    int d1;
    int d2;

    char x = 'X';
    char o = 'O';

    //illerate threw the 2d array
    for(int i = 0; i < 3; ++i) {
        r1 = 0;
        r2 = 0;
        v1 = 0;
        v2 = 0; 
    

    //check dialongial
    if(gameBoard[i][i] == x) {
        d1++;
    } else if(gameBoard[i][i] == 0) {
        d2++;
        }
    

    //go thorugh the columns
    for(int j = 0; j < 3; ++j) {

        //horzontial
        if(gameBoard[i][j] == x) {
            r1++;
        } else if(gameBoard[i][j] == 0 ) {
            r2++;
        }

        //vertical 
        if(gameBoard[i][j] == x) {
            v1++;
        } else if(gameBoard[i][j] == 0) {
            v2++;
        }
    }


    //if won horzontial
    if(r1 == Dimension || r2 == Dimension) {
        return (r1== Dimension) ? "player 1" : "player 2";
    } else 

     //if won vertically
    if(v1 == Dimension || v2 == Dimension) {
        return (v1== Dimension) ? "player 1" : "player 2";
    } else 
       //if won diagonally
    if(d1 == Dimension || d2 == Dimension) {
        return (d1== Dimension) ? "player 1" : "player 2";
    } 
}

//to see if its a draw
if(count == Dimension * Dimension) {
    return "Draw";
}

return "";

}


};


int main() {

    //object for the game
    Game *newGame = new Game;
    int choice;
    //2D array
    newGame->createBoard();


    //Select the mode
    cout << "Select 1 for single player or 2 for multiplayer game." << endl;
    cin >> choice;

    //string to sotre the result
    string store = "";

    //to show when the next player can go
    bool go = true;

    //switch statements for the single player
    switch(choice) {
        case 1:
        Player player("Player 1");
        while(go) {
            
            //player turn
            newGame->playerTurn(player);

            //check and see if player 1 has won the game
            store = newGame->checkWin();

            if(store != "" ) {
                goto point;
            } 

            //machine turn
            newGame->computerTurn();

              //check and see if computer has won the game
            store = newGame->checkWin();

            point:
            if(store == "Player 1") {
                cout << "Player 1 wins";
                go = false;
            } else if(store == "Player 2") {
                cout << "Computer wins";
                go = false;
            } else if(store == "Draw") {
                cout << "The game has ended in a draw";
                go = false;
            }
        }
    

    //case 2 for 2 player game
    case 2: {
        Player player("Player 1"); 
        Player player2("Player 2");

        //go through while loop until there is a winner
        while(go) {

            //player 1 turn
            newGame->playerTurn(player);

            //player 2 turn
            store = newGame->checkWin();
            if(store != "") {
                goto point2;
            }
            newGame->playerTurn(player2);
            //if there is a winner
            store = newGame->checkWin();

            point2:
            if(store == "Player 1") {
                cout << "Player 1 wins";
                go = false;
            } else if(store == "Player 2") {
                cout << "Player 2 wins";
                go = false;
            } else if(store == "Draw") {
                cout << "The game has ended in a draw";
                go = false;
            }


        }
    }

    //default case
    default: {
        exit(0);
    }
}
return 0;
}