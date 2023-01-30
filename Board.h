//
// Created by Jeremiah Hawthorne on 1/25/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
using namespace std;

#ifndef TICTACTOECONSOLEBASED_BOARD_H
#define TICTACTOECONSOLEBASED_BOARD_H


class Board {
public:
    vector<vector<string>> inputs;
    int col;
private:
    vector<string> oneD_vector;
public:
    Board(vector<string> inputs1 ) {
        string rows = inputs1.at(0);
        string cols = inputs1.at(1);

        int row = stoi(rows);
        col = stoi(cols);
        inputs.resize(row);
        for(int i=0;i<row*col;i++) {
            oneD_vector.push_back("-");
            cout << oneD_vector.at(i);
        }
        for(int i = 0;i<inputs.size();i++) {
            vector<string> temp;
            for(int x = 0;x<col;x++) {
                inputs.at(i).push_back("-");
            }
        }
    }
    void print_Board() {

        cout << "-------------------" << endl;
        for(int x = 0;x<inputs.size();x++) {
            for(int y=0;y<inputs.at(x).size();y++) {
                cout << "|" << inputs.at(x).at(y) << "|" <<"  ";
            }
            cout << endl;
        }
        cout << "-------------------";
    }

    void updateBoard(int row, int col, string letter) {
        for(int x = 0;x<inputs.size();x++) {
            if(x==row) {
                for (int y = 0; y < inputs.at(x).size(); y++) {
                    if (y==col) {
                        inputs[x][y] = letter;
                    }
                }
            }
        }
    }
    int computerTurn() {
        srand(3);
        int x = 1 - rand() % 3;
        int y = 1 - rand() % 3;

    }
    void playerTurn() {
        int row, col;
        cout << "Please enter the row of where you want to go";
        cin >> row;
        cout << "Please enter the col of where you want to go";
        cin >> col;
        inputs[row][col] = "X";
    }
    bool checkIfWon() {
        int cols = inputs.size();
        for(int x = 0;x<inputs.size();x++) {
            /*
             * (0,0) (0,1) (3,0)
             * (1,0) (1,1)
             * (2,0) (2,1)
             */
            if(inputs.at(x).at(0)=="X"||inputs.at(x).at(1)=="X"||inputs.at(x).at(2)=="X") {
                cout << "X has won congratulations!";
            }
            if(inputs.at(x).at(0)=="O"||inputs.at(x).at(1)=="O"||inputs.at(2).at(x)=="O") {
                cout << "X has won congratulations!";
            }
            if(inputs.at(0).at(x)=="O"||inputs.at(1).at(x)=="O"||inputs.at(0).at(x)=="O") {
                cout << "O has won congratulations!";
            }
            if(inputs.at(0).at(x)=="X"||inputs.at(1).at(x)=="X"||inputs.at(0).at(x)=="X") {
                cout << "O has won congratulations!";
            }
        }
    }
};


#endif //TICTACTOECONSOLEBASED_BOARD_H
