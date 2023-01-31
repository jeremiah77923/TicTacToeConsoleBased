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
public:
    vector<vector<string>> inputs;
    int col;
private:
    vector<string> oneD_vector;
protected:
    string playerChoice;
public:
    Board(vector<string> inputs1) {

        srand(time(0));
        string rows = inputs1.at(0);
        string cols = inputs1.at(1);
        playerChoice = inputs1.at(2);
        int row = stoi(rows);
        col = stoi(cols);
        inputs.resize(row);
        for (int i = 0; i < row * col; i++) {
            oneD_vector.push_back("-");
            cout << oneD_vector.at(i);
        }
        for (int i = 0; i < inputs.size(); i++) {
            vector<string> temp;
            for (int x = 0; x < col; x++) {
                inputs.at(i).push_back("-");
            }
        }
    }

    void print_Board() {

        cout << "-------------------" << endl;
        for (int x = 0; x < inputs.size(); x++) {
            for (int y = 0; y < inputs.at(x).size(); y++) {
                cout << "|" << inputs.at(x).at(y) << "|" << "  ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
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
        int x = 1 + (rand() % 2);
        int y = 1 - rand() % 2;
        while (inputs.at(x).at(y) != "-") {
            int x = 1 + (rand() % 2);
            int y = 1 - rand() % 2;
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
        inputs[row][col] = "X";
    }

    bool checkIfWon() {
        int cols = inputs.size();
        /*
         * 0,0 0,1 0,2
         * 1,0 1,1 1,2
         *
         * 2,0 2,1 2,2
         */
        cout << inputs.size();

        for (int x = 0; x < inputs.size(); x++) {
            for (int y = 0; y < inputs.size()-2; y++) {

                if (inputs.at(x).at(y) == "O" && inputs.at(x).at(y+1) == "O" && inputs.at(x ).at(y+2) == "O") {
                    cout << playerChoice << " has won horizationally congratulations!";
                    return true;
                }
                if (inputs.at(x).at(y) == "X" && inputs.at(x).at(y+1) == "X" && inputs.at(x ).at(y+2) == "X") {
                    cout << playerChoice << " has won horizationally congratulations!";
                    return true;
                }
                if (inputs.at(y).at(x) == "O" && inputs.at(y+1).at(x) == "O" && inputs.at(y+2).at(x) == "O") {
                    cout << playerChoice << " has won vertically congratulations!";
                    return true;
                }
                if (inputs.at(y).at(x) == "X" && inputs.at(y+1).at(x) == "X" && inputs.at(y+2 ).at(x) == "X") {
                    cout << playerChoice << " has won vertically congratulations!";
                    return true;
                }

            }
        }
        return false;
    }
};


#endif //TICTACTOECONSOLEBASED_BOARD_H
