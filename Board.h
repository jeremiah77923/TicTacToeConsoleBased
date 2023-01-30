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
private:
    vector<string> oneD_vector;
public:
    Board(vector<string> inputs1 ) {
        string rows = inputs1.at(0);
        string cols = inputs1.at(1);

        int row = stoi(rows);
        int col = stoi(cols);
        inputs.resize(row * col);
        cout << inputs.size();
        for(int i=0;i<row*col;i++) {
            oneD_vector.push_back("-");
            cout << oneD_vector.at(i);
        }
    }
    void print_Board() {
        int cols = sqrt(inputs.size());
        for(int i = 0;i<inputs.size()/3;i++) {
            vector<string> temp;
            for(int x = 0;x<cols;x++) {
                    inputs.at(i).push_back("-");
            }

        }
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
    bool checkIfWon() {
        int cols = inputs.size();
        for(int x = 0;x<inputs.size();x++) {
            /*
             * (0,0) (0,1) (3,0)
             * (1,0) (1,1)
             * (2,0) (2,1)
             */
            if(inputs.at(x).at(0)=="X"||inputs.at(x).at(1)=="X"||inputs.at(2)=="X") {
                cout << "X has won congratulations!";
            }
            if(inputs.at(x).at(0)=="O"||inputs.at(x).at(1)=="O"||inputs.at(2)=="O") {
                cout << "X has won congratulations!";
            }
            if(inputs.at(0).at(x)=="O"||inputs
        }
    }
};


#endif //TICTACTOECONSOLEBASED_BOARD_H
