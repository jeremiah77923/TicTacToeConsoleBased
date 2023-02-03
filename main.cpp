#include <iostream>
#include <string>
#include <vector>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl.H>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl_Window.H>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl_Box.H>
#include "Board.h"
using namespace std;
static int gameChoice;
static bool Computer = false;
static bool twoPlayers = false;
 int gameType() {
     int gameType = 0;
    cout << "Select the game type you want to play(type the number):"
    << "/n#1. Player vs Player" << "/n #2.Player vs Computer(Easy mode):";
    cin >> gameType;
    return gameType;
}
bool validRowsCols(string rowsNum, string colsNum){

     if(rowsNum!=colsNum) {
         cout << "You must have the same number of columns as rows, in your tic tac toe board" << endl;
         return false;
     }
     return true;
 }
string takeInputs() {
    int type = gameType();
    string rowsNumber, colsNumber;
    string letterChoice1;
    string letterChoice2;

    switch (type) {
        case 1:
            twoPlayers = true;
            break;
        default:
            Computer = true;
            break;
    }
    if (Computer==true) {

        cout
                << "Please enter in how many rows you want(it must be the same number as the number of columns you want):\n";
        cin >> rowsNumber;
        cout
                << "Please enter in how many columns you want(it must be the same number as the number  of rows you want):\n";
        cin >> colsNumber;
        while(validRowsCols(rowsNumber, colsNumber)==false) {
            cout
                    << "Please enter in how many rows you want(it must be the same number as the number of columns you want):\n";
            cin >> rowsNumber;
            cout
                    << "Please enter in how many columns you want(it must be the same number as the number  of rows you want):\n";
            cin >> colsNumber;
        }
        cout << "Do you want to be X or O?";
        cin >> letterChoice1;
        return rowsNumber + "," + colsNumber + "," + letterChoice1;
    }
    else if(twoPlayers = true) {

        cout
                << "Please enter in how many rows you want(it must be the same number as the number of columns you want):\n";
        cin >> rowsNumber;
        cout
                << "Please enter in how many columns you want(it must be the same number as the number  of rows you want):\n";
        cin >> colsNumber;

        while(validRowsCols(rowsNumber, colsNumber)==false) {
            cout
                    << "Please enter in how many rows you want(it must be the same number as the number of columns you want):\n";
            cin >> rowsNumber;
            cout
                    << "Please enter in how many columns you want(it must be the same number as the number  of rows you want):\n";
            cin >> colsNumber;
        }
        cout << " Player 1: Do you want to be X or O?";
        cin >> letterChoice1;
        if(letterChoice1=="X") {
            letterChoice2 = "O";
        }
        else
            letterChoice2 = "X";
    }

    return rowsNumber + "," + colsNumber + "," + letterChoice1 + "," + letterChoice2;
}
vector<string> splitString(string inputStrings) {
    vector<string> inputVals;
    string tempString;
    for(int x=0;x<inputStrings.length();x++) {
        if(inputStrings[x]!=','||x==inputStrings.length()-1) {
            tempString+=inputStrings[x];
        }
        if(inputStrings[x]==',') {
            inputVals.push_back(tempString);
            tempString = "";
        }
        if(x==inputStrings.length()-1) {
            inputVals.push_back(tempString);
        }
            }

    return inputVals;
}

int main() {
    vector<string> inputs = splitString(takeInputs());
    Board boardObj(inputs);
    boardObj.print_Board();
    while(true) {

            if(Computer) {
                boardObj.playerTurn();
                boardObj.print_Board();
                if(boardObj.checkIfWon())
                    break;
                boardObj.computerTurn();
                boardObj.print_Board();
            }
            else if(twoPlayers) {


                boardObj.playerTurn();
                boardObj.print_Board();
                if(boardObj.checkIfWon())
                    break;
                boardObj.playerTurn();
                boardObj.print_Board();

            }

    }


    return 0;
}
