#include <iostream>
#include <string>
#include <vector>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl.H>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl_Window.H>
//#include </Users/jeremiahhawthorne/CLionProjects/TicTacToeConsoleBased/fltk-1.3.8/FL/Fl_Box.H>
#include "Board.h"
using namespace std;

string takeInputs() {
    string rowsNumber, colsNumber;
    string letterChoice;
    cout << "Please enter in how many rows you want(it must be the same number as the number of columns you want):\n";
    cin >> rowsNumber;
    cout << "Please enter in how many columns you want(it must be the same number as the number  of rows you want):\n";
    cin >> colsNumber;
    cout << "Do you want to be X or O?";
    cin >> letterChoice;
    return rowsNumber + "," + colsNumber + "," + letterChoice;
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
    while(boardObj.checkIfWon()==false) {
        boardObj.playerTurn();
        boardObj.print_Board();
        boardObj.computerTurn();
        boardObj.print_Board();
    }


    return 0;
}
