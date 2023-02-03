//
// Created by Jeremiah Hawthorne on 1/25/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

#ifndef TICTACTOECONSOLEBASED_BOARD_H
#define TICTACTOECONSOLEBASED_BOARD_H


class Board {
private:
    bool twoPlayers;
    bool Computer;
    int playerNum = 0;
    string player1;
    string player2;
public:
    vector<vector<string>> inputs;
    int col;
protected:
    string playerChoice;
public:
    Board(vector<string> inputs1) {
        if(inputs1.size()>=4) {
            twoPlayers = true;
            Computer = false;
        }
        else if(inputs1.size()==3){
            Computer = true;
            twoPlayers = false;
        }

        srand(time(0));
        string rows = inputs1.at(0);
        string cols = inputs1.at(1);
        player1 = inputs1.at(2);
        if(inputs1.size()!=3)
            player2 = inputs1.at(3);
        int row = stoi(rows);
        col = stoi(cols);
        inputs.resize(row);

        for (int i = 0; i < inputs.size(); i++) {
            vector<string> temp;
            for (int x = 0; x < col; x++) {
                inputs.at(i).push_back("-");
            }
        }
    }

    void print_Board() {

        cout << "------------" << endl;
        for (int x = 0; x < inputs.size(); x++) {
            for (int y = 0; y < inputs.at(x).size(); y++) {
                cout << "|" << inputs.at(x).at(y) << "|" << "  ";
            }
            cout << endl;
        }
        cout << "------------" << endl;
    }

    void updateBoard(int row, int col, string letter) {

        for (int x = 0; x < inputs.size(); x++) {
            if (x == row) {
                for (int y = 0; y < inputs.at(x).size(); y++) {
                    if (y == col) {
                        inputs[x][y] = letter;
                    }
                }
            }
        }
    }

    int computerTurn() {
        int x =  (rand() % 3);
        int y = ( rand() % 3);


        while (inputs.at(x).at(y) != "-") {
            x =  (rand() % 3);
            y =  (rand() % 3);

        }
        inputs[x][y] = "O";
    }
    void playerTurn() {
        int row, col;
        cout << "Please enter the row of where you want to go";
        cin >> row;
        cout << "Please enter the col of where you want to go";
        cin >> col;
        while (inputs.at(row).at(col) != "-") {
            cout << "That space is already taken, please try again";
            cout << "Please enter the row of where you want to go";
            cin >> row;
            cout << "Please enter the col of where you want to go";
            cin >> col;
        }
        switch(Computer) {
            case false:
                if (playerNum == 0) {
                    inputs[row][col] = "X";
                    playerNum = 1;
                } else {
                    inputs[row][col] = "O";
                    playerNum = 0;
                }
                break;
                case true:
                    inputs[row][col] = "X";

        }
    }

    bool  checkIfWon() {
        for (int x = 0; x < inputs.size(); x++) {
            for (int y = 0; y < inputs.at(x).size() - 2; y++) {
                if (inputs.at(y).at(y) == "O" && inputs.at(y + 1).at(y + 1) == "O" &&
                    inputs.at(y + 2).at(y + 2) == "O") {
                    cout << "O" << " has won diagonally congratulations!";
                    return true;
                }
                if (inputs.at(y).at(y) == "X" && inputs.at(y + 1).at(y + 1) == "X" &&
                    inputs.at(y + 2).at(y + 2) == "X") {
                    cout << "X" << " has won diagonally congratulations!";
                    return true;
                }
                if (inputs.at(x).at(y) == "O" && inputs.at(x).at(y + 1) == "O" && inputs.at(x).at(y + 2) == "O") {
                    cout << "O" << " has won horizontally congratulations!";
                    return true;
                }
                if (inputs.at(x).at(y) == "X" && inputs.at(x).at(y + 1) == "X" && inputs.at(x).at(y + 2) == "X") {
                    cout << "X" << " has won horizontally congratulations!";
                    return true;
                }
                if (inputs.at(y).at(x) == "O" && inputs.at(y + 1).at(x) == "O" && inputs.at(y + 2).at(x) == "O") {
                    cout << "O" << " has won vertically congratulations!";
                    return true;
                }
                if (inputs.at(y).at(x) == "X" && inputs.at(y + 1).at(x) == "X" && inputs.at(y + 2).at(x) == "X") {
                    cout << "X" << " has won vertically congratulations!";
                    return true;
                }


            }

        }
        return false;
    }
};


#endif //TICTACTOECONSOLEBASED_BOARD_H
