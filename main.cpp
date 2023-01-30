#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
using namespace std;
/*
 *
 * General requriements:
 * 1. You want as little as possible to be put in main, most of the code should be put in other methods.
 * 2. You want as many classes as possible to start getting comfortable with OOP again.
 * 3. You
 *
 * Layout:
 * Class 1: Main in Main.cpp
 *   string CreateInputsMethod()
 *      1.Allows the user to create as large of a board as they want, takes in the # of rows
 *      and colummns they want to create.
 *      2. Let's also have them be able to choose what they want to be X or O.
 *      3. It will return a string with X or O choice, and the number of rows or cols in one string
 *      variable, they will seperated by a comma,using the split_string(method)
 *    vector<string> split_string(string str):
 *      1. Take in a string parameter
 *      2. Intalize a vector to the length of the string.
 *      3. Iterate over string
 *      4. Create a new string in the for loop and keep adding to it
 *      5. When/if you the current character you are iterating over is the delim(comma), clear the
 *      6. current for loop string, but before you do that add the string to the vector
 *      7. Repeat #1 - 6 untill the loop runs out
 *      8. Return the vector.
 *     int main():
 *
 * Class 2: Board.cpp
 *    Instance Variables:
 *    1. Create a private instance variable that is a 2D vector
 *    public:
 *     Board(int rows, int cols) {
 *     }
 *    print_board() {
 *     1. Prints the current board
 *     2. Do a nested for loop
 *     3. Before the first nested for loop print out the |---
 *     4. In the first nested for loop print out the -- and the actual value with a - for a
 *     5. space that has not been placed in.
 *     }
 * Class 3: GameLogic.cpp
 * Class 4: UpdateBoard.cpp
 *
 *
 *
 *
 *
 *
 *
 *
 */
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
    std::cout << "Hello, World!" << std::endl;
    vector<string> inputs = splitString(takeInputs());
    Board boardObj(inputs);
    int count = 0;
    while(count < boardObj.col) {
        boardObj.print_Board();

        boardObj.playerTurn();
        boardObj.print_Board();
        count++;
    }


    return 0;
}
