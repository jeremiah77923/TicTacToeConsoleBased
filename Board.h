//
// Created by Jeremiah Hawthorne on 1/25/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
};


#endif //TICTACTOECONSOLEBASED_BOARD_H
