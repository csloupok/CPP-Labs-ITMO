#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 0 = GREEN     //              //
// 1 = BLUE      //  STICKERS:   //      FLAT CUBE:
// 2 = ORANGE    //    0 1 2     //         U(0)
// 3 = RED       //    3 4 5     //  R(1)   F(2)   L(3)   B(4)
// 4 = WHITE     //    6 7 8     //         D(5)
// 5 = YELLOW    //              //

class Cube {
private:
    int sides[6][9];

    bool IsSolved() const {
        return sides[2][0] == 0 && sides[2][1] == 0 && sides[2][2] == 0 && sides[2][3] == 0 && sides[2][4] == 0 &&
               sides[2][5] == 0 && sides[2][6] == 0 && sides[2][7] == 0 &&
               sides[2][8] == 0 &&
               sides[4][0] == 1 && sides[4][1] == 1 && sides[4][2] == 1 && sides[4][3] == 1 && sides[4][4] == 1 &&
               sides[4][5] == 1 && sides[4][6] == 1 && sides[4][7] == 1 &&
               sides[4][8] == 1 &&
               sides[1][0] == 3 && sides[1][1] == 3 && sides[1][2] == 3 && sides[1][3] == 3 && sides[1][4] == 3 &&
               sides[1][5] == 3 && sides[1][6] == 3 && sides[1][7] == 3 &&
               sides[1][8] == 3 &&
               sides[3][0] == 2 && sides[3][1] == 2 && sides[3][2] == 2 && sides[3][3] == 2 && sides[3][4] == 2 &&
               sides[3][5] == 2 && sides[3][6] == 2 && sides[3][7] == 2 &&
               sides[3][8] == 2 &&
               sides[0][0] == 4 && sides[0][1] == 4 && sides[0][2] == 4 && sides[0][3] == 4 && sides[0][4] == 4 &&
               sides[0][5] == 4 && sides[0][6] == 4 && sides[0][7] == 4 &&
               sides[0][8] == 4 &&
               sides[5][0] == 5 && sides[5][1] == 5 && sides[5][2] == 5 && sides[5][3] == 5 && sides[5][4] == 5 &&
               sides[5][5] == 5 && sides[5][6] == 5 && sides[5][7] == 5 && sides[5][8] == 5;
    }

    bool CheckCorner() const {
        return ((sides[0][8] == 4 && sides[2][2] == 0 && sides[1][0] == 3) ||
                (sides[0][8] == 4 && sides[2][2] == 3 && sides[1][0] == 0) ||
                (sides[0][8] == 0 && sides[2][2] == 4 && sides[1][0] == 3) ||
                (sides[0][8] == 0 && sides[2][2] == 3 && sides[1][0] == 4) ||
                (sides[0][8] == 3 && sides[2][2] == 0 && sides[1][0] == 4) ||
                (sides[0][8] == 3 && sides[2][2] == 4 && sides[1][0] == 0)) ||
               ((sides[2][0] == 0 && sides[3][2] == 2 && sides[0][6] == 4) ||
                (sides[2][0] == 0 && sides[3][2] == 4 && sides[0][6] == 2) ||
                (sides[2][0] == 2 && sides[3][2] == 4 && sides[0][6] == 0) ||
                (sides[2][0] == 2 && sides[3][2] == 0 && sides[0][6] == 4) ||
                (sides[2][0] == 4 && sides[3][2] == 2 && sides[0][6] == 0) ||
                (sides[2][0] == 4 && sides[3][2] == 0 && sides[0][6] == 2)) ||
               ((sides[0][2] == 4 && sides[1][2] == 3 && sides[4][8] == 1) ||
                (sides[0][2] == 4 && sides[1][2] == 1 && sides[4][8] == 3) ||
                (sides[0][2] == 3 && sides[1][2] == 4 && sides[4][8] == 1) ||
                (sides[0][2] == 3 && sides[1][2] == 1 && sides[4][8] == 4) ||
                (sides[0][2] == 1 && sides[1][2] == 3 && sides[4][8] == 4) ||
                (sides[0][2] == 1 && sides[1][2] == 4 && sides[4][8] == 3)) ||
               ((sides[0][0] == 4 && sides[4][6] == 1 && sides[3][0] == 2) ||
                (sides[0][0] == 4 && sides[4][6] == 2 && sides[3][0] == 1) ||
                (sides[0][0] == 2 && sides[4][6] == 1 && sides[3][0] == 4) ||
                (sides[0][0] == 2 && sides[4][6] == 4 && sides[3][0] == 1) ||
                (sides[0][0] == 1 && sides[4][6] == 4 && sides[3][0] == 2) ||
                (sides[0][0] == 1 && sides[4][6] == 2 && sides[3][0] == 4));
    }

    bool CheckCorners() const {
        return ((sides[0][8] == 4 && sides[2][2] == 0 && sides[1][0] == 3) ||
                (sides[0][8] == 4 && sides[2][2] == 3 && sides[1][0] == 0) ||
                (sides[0][8] == 0 && sides[2][2] == 4 && sides[1][0] == 3) ||
                (sides[0][8] == 0 && sides[2][2] == 3 && sides[1][0] == 4) ||
                (sides[0][8] == 3 && sides[2][2] == 0 && sides[1][0] == 4) ||
                (sides[0][8] == 3 && sides[2][2] == 4 && sides[1][0] == 0)) &&
               ((sides[2][0] == 0 && sides[3][2] == 2 && sides[0][6] == 4) ||
                (sides[2][0] == 0 && sides[3][2] == 4 && sides[0][6] == 2) ||
                (sides[2][0] == 2 && sides[3][2] == 4 && sides[0][6] == 0) ||
                (sides[2][0] == 2 && sides[3][2] == 0 && sides[0][6] == 4) ||
                (sides[2][0] == 4 && sides[3][2] == 2 && sides[0][6] == 0) ||
                (sides[2][0] == 4 && sides[3][2] == 0 && sides[0][6] == 2)) &&
               ((sides[0][2] == 4 && sides[1][2] == 3 && sides[4][8] == 1) ||
                (sides[0][2] == 4 && sides[1][2] == 1 && sides[4][8] == 3) ||
                (sides[0][2] == 3 && sides[1][2] == 4 && sides[4][8] == 1) ||
                (sides[0][2] == 3 && sides[1][2] == 1 && sides[4][8] == 4) ||
                (sides[0][2] == 1 && sides[1][2] == 3 && sides[4][8] == 4) ||
                (sides[0][2] == 1 && sides[1][2] == 4 && sides[4][8] == 3)) &&
               ((sides[0][0] == 4 && sides[4][6] == 1 && sides[3][0] == 2) ||
                (sides[0][0] == 4 && sides[4][6] == 2 && sides[3][0] == 1) ||
                (sides[0][0] == 2 && sides[4][6] == 1 && sides[3][0] == 4) ||
                (sides[0][0] == 2 && sides[4][6] == 4 && sides[3][0] == 1) ||
                (sides[0][0] == 1 && sides[4][6] == 4 && sides[3][0] == 2) ||
                (sides[0][0] == 1 && sides[4][6] == 2 && sides[3][0] == 4));
    }

    void F() {
        int sticker0 = sides[2][0];
        int sticker1 = sides[2][1];
        int sticker2 = sides[2][2];
        int sticker3 = sides[2][3];
        int sticker4 = sides[2][4];
        int sticker5 = sides[2][5];
        int sticker6 = sides[2][6];
        int sticker7 = sides[2][7];
        int sticker8 = sides[2][8];

        sides[2][0] = sticker6;
        sides[2][1] = sticker3;
        sides[2][2] = sticker0;
        sides[2][3] = sticker7;
        sides[2][4] = sticker4;
        sides[2][5] = sticker1;
        sides[2][6] = sticker8;
        sides[2][7] = sticker5;
        sides[2][8] = sticker2;

        int temp1 = sides[1][6];
        sides[1][6] = sides[0][8];
        int temp2 = sides[5][0];
        sides[5][0] = temp1;
        temp1 = sides[3][2];
        sides[3][2] = temp2;
        sides[0][8] = temp1;

        temp1 = sides[1][3];
        sides[1][3] = sides[0][7];
        temp2 = sides[5][1];
        sides[5][1] = temp1;
        temp1 = sides[3][5];
        sides[3][5] = temp2;
        sides[0][7] = temp1;

        temp1 = sides[1][0];
        sides[1][0] = sides[0][6];
        temp2 = sides[5][2];
        sides[5][2] = temp1;
        temp1 = sides[3][8];
        sides[3][8] = temp2;
        sides[0][6] = temp1;

        cout << "F";
    }

    void CF() {
        int sticker0 = sides[2][0];
        int sticker1 = sides[2][1];
        int sticker2 = sides[2][2];
        int sticker3 = sides[2][3];
        int sticker4 = sides[2][4];
        int sticker5 = sides[2][5];
        int sticker6 = sides[2][6];
        int sticker7 = sides[2][7];
        int sticker8 = sides[2][8];

        sides[2][0] = sticker2;
        sides[2][1] = sticker5;
        sides[2][2] = sticker8;
        sides[2][3] = sticker1;
        sides[2][4] = sticker4;
        sides[2][5] = sticker7;
        sides[2][6] = sticker0;
        sides[2][7] = sticker3;
        sides[2][8] = sticker6;

        int temp1 = sides[0][8];
        sides[0][8] = sides[1][6];
        int temp2 = sides[3][2];
        sides[3][2] = temp1;
        temp1 = sides[5][0];
        sides[5][0] = temp2;
        sides[1][6] = temp1;

        temp1 = sides[0][7];
        sides[0][7] = sides[1][3];
        temp2 = sides[3][5];
        sides[3][5] = temp1;
        temp1 = sides[5][1];
        sides[5][1] = temp2;
        sides[1][3] = temp1;

        temp1 = sides[0][6];
        sides[0][6] = sides[1][0];
        temp2 = sides[3][8];
        sides[3][8] = temp1;
        temp1 = sides[5][2];
        sides[5][2] = temp2;
        sides[1][0] = temp1;

        cout << "F\'";
    }

    void B() {
        int sticker0 = sides[4][0];
        int sticker1 = sides[4][1];
        int sticker2 = sides[4][2];
        int sticker3 = sides[4][3];
        int sticker4 = sides[4][4];
        int sticker5 = sides[4][5];
        int sticker6 = sides[4][6];
        int sticker7 = sides[4][7];
        int sticker8 = sides[4][8];

        sides[4][0] = sticker6;
        sides[4][1] = sticker3;
        sides[4][2] = sticker0;
        sides[4][3] = sticker7;
        sides[4][4] = sticker4;
        sides[4][5] = sticker1;
        sides[4][6] = sticker8;
        sides[4][7] = sticker5;
        sides[4][8] = sticker2;

        int temp1 = sides[3][0];
        sides[3][0] = sides[0][2];
        int temp2 = sides[5][6];
        sides[5][6] = temp1;
        temp1 = sides[1][8];
        sides[1][8] = temp2;
        sides[0][2] = temp1;

        temp1 = sides[3][3];
        sides[3][3] = sides[0][1];
        temp2 = sides[5][7];
        sides[5][7] = temp1;
        temp1 = sides[1][5];
        sides[1][5] = temp2;
        sides[0][1] = temp1;

        temp1 = sides[3][6];
        sides[3][6] = sides[0][0];
        temp2 = sides[5][8];
        sides[5][8] = temp1;
        temp1 = sides[1][2];
        sides[1][2] = temp2;
        sides[0][0] = temp1;

        cout << "B";
    }

    void CB() {
        int sticker0 = sides[4][0];
        int sticker1 = sides[4][1];
        int sticker2 = sides[4][2];
        int sticker3 = sides[4][3];
        int sticker4 = sides[4][4];
        int sticker5 = sides[4][5];
        int sticker6 = sides[4][6];
        int sticker7 = sides[4][7];
        int sticker8 = sides[4][8];

        sides[4][0] = sticker2;
        sides[4][1] = sticker5;
        sides[4][2] = sticker8;
        sides[4][3] = sticker1;
        sides[4][4] = sticker4;
        sides[4][5] = sticker7;
        sides[4][6] = sticker0;
        sides[4][7] = sticker3;
        sides[4][8] = sticker6;

        int temp1 = sides[1][8];
        sides[1][8] = sides[0][2];
        int temp2 = sides[5][6];
        sides[5][6] = temp1;
        temp1 = sides[3][0];
        sides[3][0] = temp2;
        sides[0][2] = temp1;

        temp1 = sides[1][5];
        sides[1][5] = sides[0][1];
        temp2 = sides[5][7];
        sides[5][7] = temp1;
        temp1 = sides[3][3];
        sides[3][3] = temp2;
        sides[0][1] = temp1;

        temp1 = sides[1][2];
        sides[1][2] = sides[0][0];
        temp2 = sides[5][8];
        sides[5][8] = temp1;
        temp1 = sides[3][6];
        sides[3][6] = temp2;
        sides[0][0] = temp1;

        cout << "B\'";
    }

    void R() {
        int sticker0 = sides[1][0];
        int sticker1 = sides[1][1];
        int sticker2 = sides[1][2];
        int sticker3 = sides[1][3];
        int sticker4 = sides[1][4];
        int sticker5 = sides[1][5];
        int sticker6 = sides[1][6];
        int sticker7 = sides[1][7];
        int sticker8 = sides[1][8];

        sides[1][0] = sticker6;
        sides[1][1] = sticker3;
        sides[1][2] = sticker0;
        sides[1][3] = sticker7;
        sides[1][4] = sticker4;
        sides[1][5] = sticker1;
        sides[1][6] = sticker8;
        sides[1][7] = sticker5;
        sides[1][8] = sticker2;

        int temp1 = sides[0][2];
        sides[0][2] = sides[2][2];
        int temp2 = sides[4][2];
        sides[4][2] = temp1;
        temp1 = sides[5][2];
        sides[5][2] = temp2;
        sides[2][2] = temp1;

        temp1 = sides[0][5];
        sides[0][5] = sides[2][5];
        temp2 = sides[4][5];
        sides[4][5] = temp1;
        temp1 = sides[5][5];
        sides[5][5] = temp2;
        sides[2][5] = temp1;

        temp1 = sides[0][8];
        sides[0][8] = sides[2][8];
        temp2 = sides[4][8];
        sides[4][8] = temp1;
        temp1 = sides[5][8];
        sides[5][8] = temp2;
        sides[2][8] = temp1;

        cout << "R";
    }

    void CR() {
        int sticker0 = sides[1][0];
        int sticker1 = sides[1][1];
        int sticker2 = sides[1][2];
        int sticker3 = sides[1][3];
        int sticker4 = sides[1][4];
        int sticker5 = sides[1][5];
        int sticker6 = sides[1][6];
        int sticker7 = sides[1][7];
        int sticker8 = sides[1][8];

        sides[1][0] = sticker2;
        sides[1][1] = sticker5;
        sides[1][2] = sticker8;
        sides[1][3] = sticker1;
        sides[1][4] = sticker4;
        sides[1][5] = sticker7;
        sides[1][6] = sticker0;
        sides[1][7] = sticker3;
        sides[1][8] = sticker6;

        int temp1 = sides[0][2];
        sides[0][2] = sides[4][2];
        int temp2 = sides[2][2];
        sides[2][2] = temp1;
        temp1 = sides[5][2];
        sides[5][2] = temp2;
        sides[4][2] = temp1;

        temp1 = sides[0][5];
        sides[0][5] = sides[4][5];
        temp2 = sides[2][5];
        sides[2][5] = temp1;
        temp1 = sides[5][5];
        sides[5][5] = temp2;
        sides[4][5] = temp1;

        temp1 = sides[0][8];
        sides[0][8] = sides[4][8];
        temp2 = sides[2][8];
        sides[2][8] = temp1;
        temp1 = sides[5][8];
        sides[5][8] = temp2;
        sides[4][8] = temp1;

        cout << "R\'";
    }

    void L() {
        int sticker0 = sides[3][0];
        int sticker1 = sides[3][1];
        int sticker2 = sides[3][2];
        int sticker3 = sides[3][3];
        int sticker4 = sides[3][4];
        int sticker5 = sides[3][5];
        int sticker6 = sides[3][6];
        int sticker7 = sides[3][7];
        int sticker8 = sides[3][8];

        sides[3][0] = sticker6;
        sides[3][1] = sticker3;
        sides[3][2] = sticker0;
        sides[3][3] = sticker7;
        sides[3][4] = sticker4;
        sides[3][5] = sticker1;
        sides[3][6] = sticker8;
        sides[3][7] = sticker5;
        sides[3][8] = sticker2;

        int temp1 = sides[0][0];
        sides[0][0] = sides[4][0];
        int temp2 = sides[2][0];
        sides[2][0] = temp1;
        temp1 = sides[5][0];
        sides[5][0] = temp2;
        sides[4][0] = temp1;

        temp1 = sides[0][3];
        sides[0][3] = sides[4][3];
        temp2 = sides[2][3];
        sides[2][3] = temp1;
        temp1 = sides[5][3];
        sides[5][3] = temp2;
        sides[4][3] = temp1;

        temp1 = sides[0][6];
        sides[0][6] = sides[4][6];
        temp2 = sides[2][6];
        sides[2][6] = temp1;
        temp1 = sides[5][6];
        sides[5][6] = temp2;
        sides[4][6] = temp1;

        cout << "L";
    }

    void CL() {
        int sticker0 = sides[3][0];
        int sticker1 = sides[3][1];
        int sticker2 = sides[3][2];
        int sticker3 = sides[3][3];
        int sticker4 = sides[3][4];
        int sticker5 = sides[3][5];
        int sticker6 = sides[3][6];
        int sticker7 = sides[3][7];
        int sticker8 = sides[3][8];

        sides[3][0] = sticker2;
        sides[3][1] = sticker5;
        sides[3][2] = sticker8;
        sides[3][3] = sticker1;
        sides[3][4] = sticker4;
        sides[3][5] = sticker7;
        sides[3][6] = sticker0;
        sides[3][7] = sticker3;
        sides[3][8] = sticker6;

        int temp1 = sides[0][0];
        sides[0][0] = sides[2][0];
        int temp2 = sides[4][0];
        sides[4][0] = temp1;
        temp1 = sides[5][0];
        sides[5][0] = temp2;
        sides[2][0] = temp1;

        temp1 = sides[0][3];
        sides[0][3] = sides[2][3];
        temp2 = sides[4][3];
        sides[4][3] = temp1;
        temp1 = sides[5][3];
        sides[5][3] = temp2;
        sides[2][3] = temp1;

        temp1 = sides[0][6];
        sides[0][6] = sides[2][6];
        temp2 = sides[4][6];
        sides[4][6] = temp1;
        temp1 = sides[5][6];
        sides[5][6] = temp2;
        sides[2][6] = temp1;

        cout << "L\'";
    }

    void U() {
        int sticker0 = sides[0][0];
        int sticker1 = sides[0][1];
        int sticker2 = sides[0][2];
        int sticker3 = sides[0][3];
        int sticker4 = sides[0][4];
        int sticker5 = sides[0][5];
        int sticker6 = sides[0][6];
        int sticker7 = sides[0][7];
        int sticker8 = sides[0][8];

        sides[0][0] = sticker6;
        sides[0][1] = sticker3;
        sides[0][2] = sticker0;
        sides[0][3] = sticker7;
        sides[0][4] = sticker4;
        sides[0][5] = sticker1;
        sides[0][6] = sticker8;
        sides[0][7] = sticker5;
        sides[0][8] = sticker2;

        int temp1 = sides[2][0];
        sides[2][0] = sides[1][0];
        int temp2 = sides[3][0];
        sides[3][0] = temp1;
        temp1 = sides[4][8];
        sides[4][8] = temp2;
        sides[1][0] = temp1;

        temp1 = sides[2][1];
        sides[2][1] = sides[1][1];
        temp2 = sides[3][1];
        sides[3][1] = temp1;
        temp1 = sides[4][7];
        sides[4][7] = temp2;
        sides[1][1] = temp1;

        temp1 = sides[2][2];
        sides[2][2] = sides[1][2];
        temp2 = sides[3][2];
        sides[3][2] = temp1;
        temp1 = sides[4][6];
        sides[4][6] = temp2;
        sides[1][2] = temp1;

        cout << "U";
    }

    void CU() {
        int sticker0 = sides[0][0];
        int sticker1 = sides[0][1];
        int sticker2 = sides[0][2];
        int sticker3 = sides[0][3];
        int sticker4 = sides[0][4];
        int sticker5 = sides[0][5];
        int sticker6 = sides[0][6];
        int sticker7 = sides[0][7];
        int sticker8 = sides[0][8];

        sides[0][0] = sticker2;
        sides[0][1] = sticker5;
        sides[0][2] = sticker8;
        sides[0][3] = sticker1;
        sides[0][4] = sticker4;
        sides[0][5] = sticker7;
        sides[0][6] = sticker0;
        sides[0][7] = sticker3;
        sides[0][8] = sticker6;

        int temp1 = sides[1][0];
        sides[1][0] = sides[2][0];
        int temp2 = sides[4][8];
        sides[4][8] = temp1;
        temp1 = sides[3][0];
        sides[3][0] = temp2;
        sides[2][0] = temp1;

        temp1 = sides[1][1];
        sides[1][1] = sides[2][1];
        temp2 = sides[4][7];
        sides[4][7] = temp1;
        temp1 = sides[3][1];
        sides[3][1] = temp2;
        sides[2][1] = temp1;

        temp1 = sides[1][2];
        sides[1][2] = sides[2][2];
        temp2 = sides[4][6];
        sides[4][6] = temp1;
        temp1 = sides[3][2];
        sides[3][2] = temp2;
        sides[2][2] = temp1;

        cout << "U\'";
    }

    void D() {
        int sticker0 = sides[5][0];
        int sticker1 = sides[5][1];
        int sticker2 = sides[5][2];
        int sticker3 = sides[5][3];
        int sticker4 = sides[5][4];
        int sticker5 = sides[5][5];
        int sticker6 = sides[5][6];
        int sticker7 = sides[5][7];
        int sticker8 = sides[5][8];

        sides[5][0] = sticker2;
        sides[5][1] = sticker5;
        sides[5][2] = sticker8;
        sides[5][3] = sticker1;
        sides[5][4] = sticker4;
        sides[5][5] = sticker7;
        sides[5][6] = sticker0;
        sides[5][7] = sticker3;
        sides[5][8] = sticker6;

        int temp1 = sides[2][6];
        sides[2][6] = sides[1][6];
        int temp2 = sides[3][6];
        sides[3][6] = temp1;
        temp1 = sides[4][2];
        sides[4][2] = temp2;
        sides[1][6] = temp1;

        temp1 = sides[2][7];
        sides[2][7] = sides[1][7];
        temp2 = sides[3][7];
        sides[3][7] = temp1;
        temp1 = sides[4][1];
        sides[4][1] = temp2;
        sides[1][7] = temp1;

        temp1 = sides[2][8];
        sides[2][8] = sides[1][8];
        temp2 = sides[3][8];
        sides[3][8] = temp1;
        temp1 = sides[4][0];
        sides[4][0] = temp2;
        sides[1][8] = temp1;

        cout << "D";
    }

    void CD() {
        int sticker0 = sides[5][0];
        int sticker1 = sides[5][1];
        int sticker2 = sides[5][2];
        int sticker3 = sides[5][3];
        int sticker4 = sides[5][4];
        int sticker5 = sides[5][5];
        int sticker6 = sides[5][6];
        int sticker7 = sides[5][7];
        int sticker8 = sides[5][8];

        sides[5][0] = sticker2;
        sides[5][1] = sticker5;
        sides[5][2] = sticker8;
        sides[5][3] = sticker1;
        sides[5][4] = sticker4;
        sides[5][5] = sticker7;
        sides[5][6] = sticker0;
        sides[5][7] = sticker3;
        sides[5][8] = sticker6;

        int temp1 = sides[1][6];
        sides[1][6] = sides[2][6];
        int temp2 = sides[4][2];
        sides[4][2] = temp1;
        temp1 = sides[3][6];
        sides[3][6] = temp2;
        sides[2][6] = temp1;

        temp1 = sides[1][7];
        sides[1][7] = sides[2][7];
        temp2 = sides[4][1];
        sides[4][1] = temp1;
        temp1 = sides[3][7];
        sides[3][7] = temp2;
        sides[2][7] = temp1;

        temp1 = sides[1][8];
        sides[1][8] = sides[2][8];
        temp2 = sides[4][0];
        sides[4][0] = temp1;
        temp1 = sides[3][8];
        sides[3][8] = temp2;
        sides[2][8] = temp1;

        cout << "D\'";
    }

public:
    void read() {
        ifstream input("Cube.in");
        input >> sides[0][0] >> sides[0][1] >> sides[0][2] >> sides[0][3] >> sides[0][4] >> sides[0][5] >> sides[0][6]
              >> sides[0][7] >> sides[0][8];
        input >> sides[3][0] >> sides[3][1] >> sides[3][2] >> sides[3][3] >> sides[3][4] >> sides[3][5] >> sides[3][6]
              >> sides[3][7] >> sides[3][8];
        input >> sides[2][0] >> sides[2][1] >> sides[2][2] >> sides[2][3] >> sides[2][4] >> sides[2][5] >> sides[2][6]
              >> sides[2][7] >> sides[2][8];
        input >> sides[1][0] >> sides[1][1] >> sides[1][2] >> sides[1][3] >> sides[1][4] >> sides[1][5] >> sides[1][6]
              >> sides[1][7] >> sides[1][8];
        input >> sides[4][0] >> sides[4][1] >> sides[4][2] >> sides[4][3] >> sides[4][4] >> sides[4][5] >> sides[4][6]
              >> sides[4][7] >> sides[4][8];
        input >> sides[5][0] >> sides[5][1] >> sides[5][2] >> sides[5][3] >> sides[5][4] >> sides[5][5] >> sides[5][6]
              >> sides[5][7] >> sides[5][8];
        input.close();
    }

    void write() const {
        ofstream output("Cube.out");
        output << "       " << sides[0][0] << " " << sides[0][1] << " " << sides[0][2] << "\n";
        output << "       " << sides[0][3] << " " << sides[0][4] << " " << sides[0][5] << "\n";
        output << "       " << sides[0][6] << " " << sides[0][7] << " " << sides[0][8] << "\n" << "\n";
        output << sides[3][0] << " " << sides[3][1] << " " << sides[3][2] << "  " << sides[2][0] << " " << sides[2][1]
               << " " << sides[2][2] << "  ";
        output << sides[1][0] << " " << sides[1][1] << " " << sides[1][2] << "  " << sides[4][0] << " " << sides[4][1]
               << " " << sides[4][2] << "\n";
        output << sides[3][3] << " " << sides[3][4] << " " << sides[3][5] << "  " << sides[2][3] << " " << sides[2][4]
               << " " << sides[2][5] << "  ";
        output << sides[1][3] << " " << sides[1][4] << " " << sides[1][5] << "  " << sides[4][3] << " " << sides[4][4]
               << " " << sides[4][5] << "\n";
        output << sides[3][6] << " " << sides[3][7] << " " << sides[3][8] << "  " << sides[2][6] << " " << sides[2][7]
               << " " << sides[2][8] << "  ";
        output << sides[1][6] << " " << sides[1][7] << " " << sides[1][8] << "  " << sides[4][6] << " " << sides[4][7]
               << " " << sides[4][8] << "\n" << "\n";
        output << "       " << sides[5][0] << " " << sides[5][1] << " " << sides[5][2] << "\n";
        output << "       " << sides[5][3] << " " << sides[5][4] << " " << sides[5][5] << "\n";
        output << "       " << sides[5][6] << " " << sides[5][7] << " " << sides[5][8] << "\n";
        output.close();
    }

    bool check() const {
        vector<int> colors(6, 0);

        colors[sides[0][0]]++;
        colors[sides[0][1]]++;
        colors[sides[0][2]]++;
        colors[sides[0][3]]++;
        colors[sides[0][4]]++;
        colors[sides[0][5]]++;
        colors[sides[0][6]]++;
        colors[sides[0][7]]++;
        colors[sides[0][8]]++;

        colors[sides[1][0]]++;
        colors[sides[1][1]]++;
        colors[sides[1][2]]++;
        colors[sides[1][3]]++;
        colors[sides[1][4]]++;
        colors[sides[1][5]]++;
        colors[sides[1][6]]++;
        colors[sides[1][7]]++;
        colors[sides[1][8]]++;

        colors[sides[2][0]]++;
        colors[sides[2][1]]++;
        colors[sides[2][2]]++;
        colors[sides[2][3]]++;
        colors[sides[2][4]]++;
        colors[sides[2][5]]++;
        colors[sides[2][6]]++;
        colors[sides[2][7]]++;
        colors[sides[2][8]]++;

        colors[sides[3][0]]++;
        colors[sides[3][1]]++;
        colors[sides[3][2]]++;
        colors[sides[3][3]]++;
        colors[sides[3][4]]++;
        colors[sides[3][5]]++;
        colors[sides[3][6]]++;
        colors[sides[3][7]]++;
        colors[sides[3][8]]++;

        colors[sides[4][0]]++;
        colors[sides[4][1]]++;
        colors[sides[4][2]]++;
        colors[sides[4][3]]++;
        colors[sides[4][4]]++;
        colors[sides[4][5]]++;
        colors[sides[4][6]]++;
        colors[sides[4][7]]++;
        colors[sides[4][8]]++;

        colors[sides[5][0]]++;
        colors[sides[5][1]]++;
        colors[sides[5][2]]++;
        colors[sides[5][3]]++;
        colors[sides[5][4]]++;
        colors[sides[5][5]]++;
        colors[sides[5][6]]++;
        colors[sides[5][7]]++;
        colors[sides[5][8]]++;

        return (colors, [](int i) { return i != 9; });
        return true;
    }

    void console() const {
        cout << "\n\n";
        cout << "       " << sides[0][0] << " " << sides[0][1] << " " << sides[0][2] << "\n";
        cout << "       " << sides[0][3] << " " << sides[0][4] << " " << sides[0][5] << "\n";
        cout << "       " << sides[0][6] << " " << sides[0][7] << " " << sides[0][8] << "\n" << "\n";
        cout << sides[3][0] << " " << sides[3][1] << " " << sides[3][2] << "  " << sides[2][0] << " " << sides[2][1]
             << " " << sides[2][2] << "  ";
        cout << sides[1][0] << " " << sides[1][1] << " " << sides[1][2] << "  " << sides[4][0] << " " << sides[4][1]
             << " " << sides[4][2] << "\n";
        cout << sides[3][3] << " " << sides[3][4] << " " << sides[3][5] << "  " << sides[2][3] << " " << sides[2][4]
             << " " << sides[2][5] << "  ";
        cout << sides[1][3] << " " << sides[1][4] << " " << sides[1][5] << "  " << sides[4][3] << " " << sides[4][4]
             << " " << sides[4][5] << "\n";
        cout << sides[3][6] << " " << sides[3][7] << " " << sides[3][8] << "  " << sides[2][6] << " " << sides[2][7]
             << " " << sides[2][8] << "  ";
        cout << sides[1][6] << " " << sides[1][7] << " " << sides[1][8] << "  " << sides[4][6] << " " << sides[4][7]
             << " " << sides[4][8] << "\n" << "\n";
        cout << "       " << sides[5][0] << " " << sides[5][1] << " " << sides[5][2] << "\n";
        cout << "       " << sides[5][3] << " " << sides[5][4] << " " << sides[5][5] << "\n";
        cout << "       " << sides[5][6] << " " << sides[5][7] << " " << sides[5][8] << "\n";
        cout << "\n";
    }

    void scramble() {
        int n = abs(rand() % 10);
        for (int i = 0; i < n; i++) {
            int random = abs(rand() % 12);
            if (random == 0) R();
            if (random == 1) CR();
            if (random == 2) L();
            if (random == 3) CL();
            if (random == 4) F();
            if (random == 5) CF();
            if (random == 6) B();
            if (random == 7) CB();
            if (random == 8) U();
            if (random == 9) CU();
            if (random == 10) D();
            if (random == 11) CD();
        }
    }

    void solve() {
        if (!IsSolved() && check()) {
            // Stage 1 (flower)
            while (sides[0][1] != 5 || sides[0][3] != 5 || sides[0][5] != 5 || sides[0][7] != 5) {
                if (sides[2][5] == 5) {
                    while (sides[0][5] == 5) {
                        U();
                    }
                    R();
                }
                if (sides[2][3] == 5) {
                    while (sides[0][3] == 5) {
                        U();
                    }
                    CL();
                }
                if (sides[1][3] == 5) {
                    while (sides[0][7] == 5) {
                        U();
                    }
                    CF();
                }
                if (sides[1][5] == 5) {
                    while (sides[0][1] == 5) {
                        U();
                    }
                    B();
                }
                if (sides[3][5] == 5) {
                    while (sides[0][7] == 5) {
                        U();
                    }
                    F();
                }
                if (sides[3][3] == 5) {
                    while (sides[0][1] == 5) {
                        U();
                    }
                    CB();
                }
                if (sides[4][5] == 5) {
                    while (sides[0][5] == 5) {
                        U();
                    }
                    CR();
                }
                if (sides[4][3] == 5) {
                    while (sides[0][3] == 5) {
                        U();
                    }
                    L();
                }
                if (sides[5][5] == 5) {
                    while (sides[0][5] == 5) {
                        U();
                    }
                    R();
                    R();
                }
                if (sides[5][7] == 5) {
                    while (sides[0][1] == 5) {
                        U();
                    }
                    CB();
                    CB();
                }
                if (sides[5][3] == 5) {
                    while (sides[0][3] == 5) {
                        U();
                    }
                    CL();
                    CL();
                }
                if (sides[5][1] == 5) {
                    while (sides[0][7] == 5) {
                        U();
                    }
                    F();
                    F();
                }

                if (sides[2][7] == 5) {
                    F();
                    while (sides[0][3] == 5) {
                        U();
                    }
                    CL();
                }
                if (sides[2][1] == 5) {
                    F();
                    while (sides[0][5] == 5) {
                        U();
                    }
                    R();
                }
                if (sides[1][7] == 5) {
                    R();
                    while (sides[0][7] == 5) {
                        U();
                    }
                    CF();
                }
                if (sides[1][1] == 5) {
                    R();
                    while (sides[0][1] == 5) {
                        U();
                    }
                    B();
                }
                if (sides[4][1] == 5) {
                    CB();
                    while (sides[0][3] == 5) {
                        U();
                    }
                    L();
                }
                if (sides[4][7] == 5) {
                    CB();
                    while (sides[0][5] == 5) {
                        U();
                    }
                    CR();
                }
                if (sides[3][7] == 5) {
                    CL();
                    while (sides[0][7] == 5) {
                        U();
                    }
                    F();
                }
                if (sides[3][1] == 5) {
                    CL();
                    while (sides[0][1] == 5) {
                        U();
                    }
                    CB();
                }
            }

            // Stage 2 (white-cross)
            while (sides[2][1] != sides[2][4] || sides[0][7] != 5) {
                U();
            }
            F();
            F();
            while (sides[1][1] != sides[1][4] || sides[0][5] != 5) {
                U();
            }
            R();
            R();
            while (sides[4][7] != sides[4][4] || sides[0][1] != 5) {
                U();
            }
            B();
            B();
            while (sides[3][1] != sides[3][4] || sides[0][3] != 5) {
                U();
            }
            L();
            L();

            // Stage 3 (second corner)
            int current = 0;
            while (sides[5][0] != 5 || sides[5][2] != 5 || sides[5][6] != 5 || sides[5][8] != 5) {
                if (sides[4][8] == 5) {
                    if ((sides[0][2] == 3 && sides[1][2] == 1) || (sides[0][2] == 1 && sides[1][2] == 3)) {
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }

                    }
                    if ((sides[0][2] == 3 && sides[1][2] == 0 && sides[4][8] == 5) ||
                        (sides[0][2] == 0 && sides[1][2] == 3 && sides[4][8] == 5)) {
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][2] == 0 && sides[1][2] == 2 && sides[4][8] == 5) ||
                        (sides[0][2] == 2 && sides[1][2] == 0 && sides[4][8] == 5)) {
                        U();
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][2] == 2 && sides[1][2] == 1 && sides[4][8] == 5) ||
                        (sides[0][2] == 1 && sides[1][2] == 2 && sides[4][8] == 5)) {
                        CU();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[0][2] == 5) {
                    if ((sides[4][8] == 3 && sides[1][2] == 1) || (sides[4][8] == 1 && sides[1][2] == 3)) {
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[4][8] == 3 && sides[1][2] == 0 && sides[0][2] == 5) ||
                        (sides[4][8] == 0 && sides[1][2] == 3 && sides[0][2] == 5)) {
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[4][8] == 0 && sides[1][2] == 2 && sides[0][2] == 5) ||
                        (sides[4][8] == 2 && sides[1][2] == 0 && sides[0][2] == 5)) {
                        U();
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[4][8] == 2 && sides[1][2] == 1 && sides[0][2] == 5) ||
                        (sides[4][8] == 1 && sides[1][2] == 2 && sides[0][2] == 5)) {
                        CU();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[1][2] == 5) {
                    if ((sides[0][2] == 3 && sides[4][8] == 1) || (sides[0][2] == 1 && sides[4][8] == 3)) {
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][2] == 3 && sides[4][8] == 0 && sides[1][2] == 5) ||
                        (sides[0][2] == 0 && sides[4][8] == 3 && sides[1][2] == 5)) {
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][2] == 0 && sides[4][8] == 2 && sides[1][2] == 5) ||
                        (sides[0][2] == 2 && sides[4][8] == 0 && sides[1][2] == 5)) {
                        U();
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][2] == 2 && sides[4][8] == 1 && sides[1][2] == 5) ||
                        (sides[0][2] == 1 && sides[4][8] == 2 && sides[1][2] == 5)) {
                        CU();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }
                if (sides[4][6] == 5) {
                    if ((sides[0][0] == 3 && sides[3][0] == 1) || (sides[0][0] == 1 && sides[3][0] == 3)) {
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 3 && sides[3][0] == 0 && sides[4][6] == 5) ||
                        (sides[0][0] == 0 && sides[3][0] == 3 && sides[4][6] == 5)) {
                        U();
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 3 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 0 && sides[3][0] == 2 && sides[4][6] == 5) ||
                        (sides[0][0] == 2 && sides[3][0] == 0 && sides[4][6] == 5)) {
                        CU();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 2 && sides[3][0] == 1 && sides[4][6] == 5) ||
                        (sides[0][0] == 1 && sides[3][0] == 2 && sides[4][6] == 5)) {
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[0][0] == 5) {
                    if ((sides[4][6] == 3 && sides[3][0] == 1) || (sides[4][6] == 1 && sides[3][0] == 3)) {
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[4][6] == 3 && sides[3][0] == 0 && sides[0][0] == 5) ||
                        (sides[4][6] == 0 && sides[3][0] == 3 && sides[0][0] == 5)) {
                        U();
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[4][6] == 0 && sides[3][0] == 2 && sides[0][0] == 5) ||
                        (sides[4][6] == 2 && sides[3][0] == 0 && sides[0][0] == 5)) {
                        CU();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[4][6] == 2 && sides[3][0] == 1 && sides[0][0] == 5) ||
                        (sides[4][6] == 1 && sides[3][0] == 2 && sides[0][0] == 5)) {
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[3][0] == 5) {
                    if ((sides[0][0] == 3 && sides[4][6] == 1) || (sides[0][0] == 1 && sides[4][6] == 3)) {
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 3 && sides[4][6] == 0 && sides[3][0] == 5) ||
                        (sides[0][0] == 0 && sides[4][6] == 3 && sides[3][0] == 5)) {
                        U();
                        U();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 0 && sides[4][6] == 2 && sides[3][0] == 5) ||
                        (sides[0][0] == 2 && sides[4][6] == 0 && sides[3][0] == 5)) {
                        CU();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][0] == 2 && sides[4][6] == 1 && sides[3][0] == 5) ||
                        (sides[0][0] == 1 && sides[4][6] == 2 && sides[3][0] == 5)) {
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                // Stage 4 (third corner)
                if (sides[2][0] == 5) {
                    if ((sides[0][6] == 3 && sides[3][2] == 1) || (sides[0][6] == 1 && sides[3][2] == 3)) {
                        U();
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 3 && sides[3][2] == 0 && sides[2][0] == 5) ||
                        (sides[0][6] == 0 && sides[3][2] == 3 && sides[2][0] == 5)) {
                        CU();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 0 && sides[3][2] == 2 && sides[2][0] == 5) ||
                        (sides[0][6] == 2 && sides[3][2] == 0 && sides[2][0] == 5)) {
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 2 && sides[3][2] == 1 && sides[2][0] == 5) ||
                        (sides[0][6] == 1 && sides[3][2] == 2 && sides[2][0] == 5)) {
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[0][6] == 5) {
                    if ((sides[2][0] == 3 && sides[3][2] == 1) || (sides[2][0] == 1 && sides[3][2] == 3)) {
                        U();
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[2][0] == 3 && sides[3][2] == 0 && sides[0][6] == 5) ||
                        (sides[2][0] == 0 && sides[3][2] == 3 && sides[0][6] == 5)) {
                        CU();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[2][0] == 0 && sides[3][2] == 2 && sides[0][6] == 5) ||
                        (sides[2][0] == 2 && sides[3][2] == 0 && sides[0][6] == 5)) {
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[2][0] == 2 && sides[3][2] == 1 && sides[0][6] == 5) ||
                        (sides[2][0] == 1 && sides[3][2] == 2 && sides[0][6] == 5)) {
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[3][2] == 5) {
                    if ((sides[0][6] == 3 && sides[2][0] == 1) || (sides[0][6] == 1 && sides[2][0] == 3)) {
                        U();
                        U();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 3 && sides[2][0] == 0 && sides[3][2] == 5) ||
                        (sides[0][6] == 0 && sides[2][0] == 3 && sides[3][2] == 5)) {
                        CU();
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 0 && sides[2][0] == 2 && sides[3][2] == 5) ||
                        (sides[0][6] == 2 && sides[2][0] == 0 && sides[3][2] == 5)) {
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][6] == 2 && sides[2][0] == 1 && sides[3][2] == 5) ||
                        (sides[0][6] == 1 && sides[2][0] == 2 && sides[3][2] == 5)) {
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                // Stage 4 (white side)
                if (sides[2][2] == 5) {
                    if ((sides[0][8] == 3 && sides[1][0] == 1) || (sides[0][8] == 1 && sides[1][0] == 3)) {
                        CU();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[0][8] == 3 && sides[1][0] == 0 && sides[2][2] == 5) ||
                        (sides[0][8] == 0 && sides[1][0] == 3 && sides[2][2] == 5)) {
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[0][8] == 0 && sides[1][0] == 2 && sides[2][2] == 5) ||
                        (sides[0][8] == 2 && sides[1][0] == 0 && sides[2][2] == 5)) {
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[0][8] == 2 && sides[1][0] == 1 && sides[2][2] == 5) ||
                        (sides[0][8] == 1 && sides[1][0] == 2 && sides[2][2] == 5)) {
                        U();
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[0][8] == 5) {
                    if ((sides[2][2] == 3 && sides[1][0] == 1) || (sides[2][2] == 1 && sides[1][0] == 3)) {
                        CU();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 3 && sides[1][0] == 0 && sides[0][8] == 5) ||
                        (sides[2][2] == 0 && sides[1][0] == 3 && sides[0][8] == 5)) {
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 0 && sides[1][0] == 2 && sides[0][8] == 5) ||
                        (sides[2][2] == 2 && sides[1][0] == 0 && sides[0][8] == 5)) {
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 2 && sides[1][0] == 1 && sides[0][8] == 5) ||
                        (sides[2][2] == 1 && sides[1][0] == 2 && sides[0][8] == 5)) {
                        U();
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if (sides[1][0] == 5) {
                    if ((sides[2][2] == 3 && sides[0][8] == 1 && sides[1][0] == 5) ||
                        (sides[2][2] == 1 && sides[0][8] == 3 && sides[1][0] == 5)) {
                        CU();
                        while (sides[5][8] != 5 || sides[1][8] != 3 || sides[4][2] != 1) {
                            B();
                            U();
                            CB();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 3 && sides[0][8] == 0 && sides[1][0] == 5) ||
                        (sides[2][2] == 0 && sides[0][8] == 3 && sides[1][0] == 5)) {
                        while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                            R();
                            U();
                            CR();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 0 && sides[0][8] == 2 && sides[1][0] == 5) ||
                        (sides[2][2] == 2 && sides[0][8] == 0 && sides[1][0] == 5)) {
                        U();
                        while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                            F();
                            U();
                            CF();
                            CU();
                        }
                    }
                    if ((sides[2][2] == 2 && sides[0][8] == 1 && sides[1][0] == 5) ||
                        (sides[2][2] == 1 && sides[0][8] == 2 && sides[1][0] == 5)) {
                        U();
                        U();
                        while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                            L();
                            U();
                            CL();
                            CU();
                        }
                    }
                }

                if ((sides[2][8] == 5 && sides[1][6] == 3 && sides[5][2] == 0) ||
                    (sides[2][8] == 5 && sides[1][6] == 0 && sides[5][2] == 3) ||
                    (sides[2][8] == 3 && sides[1][6] == 5 && sides[5][2] == 0) ||
                    (sides[2][8] == 0 && sides[1][6] == 5 && sides[5][2] == 3) ||
                    (sides[2][8] == 3 && sides[1][6] == 0 && sides[5][2] == 5)) {
                    while (sides[5][2] != 5 || sides[2][8] != 0 || sides[1][6] != 3) {
                        R();
                        U();
                        CR();
                        CU();
                    }
                }
                if ((sides[4][2] == 5 && sides[1][8] == 3 && sides[5][8] == 1) ||
                    (sides[4][2] == 5 && sides[1][8] == 1 && sides[5][8] == 3) ||
                    (sides[4][2] == 3 && sides[1][8] == 5 && sides[5][8] == 1) ||
                    (sides[4][2] == 1 && sides[1][8] == 5 && sides[5][8] == 3) ||
                    (sides[4][2] == 3 && sides[1][8] == 1 && sides[5][8] == 5)) {
                    while (sides[5][8] != 5 || sides[4][2] != 1 || sides[1][8] != 3) {
                        B();
                        U();
                        CB();
                        CU();
                    }
                }
                if ((sides[4][0] == 5 && sides[3][6] == 2 && sides[5][6] == 1) ||
                    (sides[4][0] == 5 && sides[3][6] == 1 && sides[5][6] == 2) ||
                    (sides[4][0] == 2 && sides[3][6] == 5 && sides[5][6] == 1) ||
                    (sides[4][0] == 1 && sides[3][6] == 5 && sides[5][6] == 2) ||
                    (sides[4][0] == 2 && sides[3][6] == 1 && sides[5][6] == 5)) {
                    while (sides[5][6] != 5 || sides[4][0] != 1 || sides[3][6] != 2) {
                        L();
                        U();
                        CL();
                        CU();
                    }
                }
                if ((sides[3][8] == 5 && sides[2][6] == 0 && sides[5][0] == 2) ||
                    (sides[3][8] == 5 && sides[2][6] == 2 && sides[5][0] == 0) ||
                    (sides[3][8] == 0 && sides[2][6] == 5 && sides[5][0] == 2) ||
                    (sides[3][8] == 2 && sides[2][6] == 5 && sides[5][0] == 0) ||
                    (sides[3][8] == 0 && sides[2][6] == 2 && sides[5][0] == 5)) {
                    while (sides[5][0] != 5 || sides[3][8] != 2 || sides[2][6] != 0) {
                        F();
                        U();
                        CF();
                        CU();
                    }
                }

                if ((sides[5][2] == 5 && (sides[2][8] != 0 && sides[2][8] != 3)) ||
                    (sides[5][2] == 5 && (sides[1][6] != 0 && sides[1][6] != 3))) {
                    R();
                    U();
                    CR();
                    CU();
                }
                if ((sides[5][8] == 5 && (sides[1][8] != 1 && sides[1][8] != 3)) ||
                    (sides[5][8] == 5 && (sides[4][2] != 1 && sides[4][2] != 3))) {
                    B();
                    U();
                    CB();
                    CU();
                }
                if ((sides[5][6] == 5 && (sides[4][0] != 1 && sides[4][0] != 2)) ||
                    (sides[5][6] == 5 && (sides[3][6] != 1 && sides[3][6] != 2))) {
                    L();
                    U();
                    CL();
                    CU();
                }
                if ((sides[5][0] == 5 && (sides[2][6] != 0 && sides[2][6] != 2)) ||
                    (sides[5][0] == 5 && (sides[3][8] != 0 && sides[3][8] != 2))) {
                    F();
                    U();
                    CF();
                    CU();
                }
            }

            // Stage 6 (top and bottom assembled)
            int prev = -1;
            while (sides[2][3] != 0 || sides[2][5] != 0 || sides[1][3] != 3 || sides[1][5] != 3 ||
                   sides[4][5] != 1 || sides[4][3] != 1 || sides[3][3] != 2 || sides[3][5] != 2) {
                current = 0;
                prev = -1;
                while (current > prev) {
                    prev = current;
                    if (sides[2][1] == 0 || sides[1][1] == 0 || sides[4][7] == 0 || sides[3][1] == 0) {
                        while (sides[2][1] != 0) {
                            U();
                        }
                        if (sides[0][7] == 3) {
                            current++;
                            U();
                            R();
                            U();
                            CR();
                            CU();
                            CF();
                            CU();
                            F();
                            U();
                        } else {
                            if (sides[0][7] == 2) {
                                current++;
                                CU();
                                CL();
                                CU();
                                L();
                                U();
                                F();
                                U();
                                CF();
                                CU();
                            }
                        }
                    }
                    if (sides[2][1] == 3 || sides[1][1] == 3 || sides[4][7] == 3 || sides[3][1] == 3) {
                        while (sides[1][1] != 3) {
                            U();
                        }
                        if (sides[0][5] == 1) {
                            current++;
                            U();
                            B();
                            U();
                            CB();
                            CU();
                            CR();
                            CU();
                            R();
                            U();
                        } else {
                            if (sides[0][5] == 0) {
                                current++;
                                CU();
                                CF();
                                CU();
                                F();
                                U();
                                R();
                                U();
                                CR();
                                CU();
                            }
                        }
                    }
                    if (sides[2][1] == 1 || sides[1][1] == 1 || sides[4][7] == 1 || sides[3][1] == 1) {
                        while (sides[4][7] != 1) {
                            U();
                        }
                        if (sides[0][1] == 2) {
                            current++;
                            U();
                            L();
                            U();
                            CL();
                            CU();
                            CB();
                            CU();
                            B();
                            U();
                        } else {
                            if (sides[0][1] == 3) {
                                current++;
                                CU();
                                CR();
                                CU();
                                R();
                                U();
                                B();
                                U();
                                CB();
                                CU();
                            }
                        }
                    }
                    if (sides[2][1] == 2 || sides[1][1] == 2 || sides[4][7] == 2 || sides[3][1] == 2) {
                        while (sides[3][1] != 2) {
                            U();
                        }
                        if (sides[0][3] == 0) {
                            current++;
                            U();
                            F();
                            U();
                            CF();
                            CU();
                            CL();
                            CU();
                            L();
                            U();
                        } else {
                            if (sides[0][3] == 1) {
                                current++;
                                CU();
                                CB();
                                CU();
                                B();
                                U();
                                L();
                                U();
                                CL();
                                CU();
                            }
                        }
                    }
                }
                if (sides[2][5] != 0) {
                    R();
                    U();
                    CR();
                    CU();
                    CF();
                    CU();
                    F();
                    U();
                }
                if (sides[1][5] != 3) {
                    B();
                    U();
                    CB();
                    CU();
                    CR();
                    CU();
                    R();
                    U();
                }
                if (sides[4][3] != 1) {
                    L();
                    U();
                    CL();
                    CU();
                    CB();
                    CU();
                    B();
                    U();
                }
                if (sides[3][5] != 2) {
                    F();
                    U();
                    CF();
                    CU();
                    CL();
                    CU();
                    L();
                    U();
                }
            }

            // Stage 7 (yellow cross)
            while (sides[0][3] != 4 || sides[0][1] != 4 || sides[0][5] != 4 || sides[0][7] != 4) {
                if ((sides[0][5] == 4 && sides[0][1] == 4) || (sides[0][1] == 4 && sides[0][7] == 4)) {
                    L();
                    F();
                    U();
                    CF();
                    CU();
                    CL();
                } else {
                    if (sides[0][5] == 4 && sides[0][7] == 4) {
                        B();
                        L();
                        U();
                        CL();
                        CU();
                        CB();
                    } else {
                        if (sides[0][3] == 4 && sides[0][7] == 4) {
                            R();
                            B();
                            U();
                            CB();
                            CU();
                            CR();
                        } else {
                            F();
                            R();
                            U();
                            CR();
                            CU();
                            CF();
                        }
                    }
                }
            }

            // Stage 8 (check for corners)
            int flag = 0;
            if (sides[2][1] == 0 && sides[1][1] == 3 && sides[4][7] == 1 && sides[3][1] == 2) {
                flag = 1;
            } else {
                U();
                if (sides[2][1] == 0 && sides[1][1] == 3 && sides[4][7] == 1 && sides[3][1] == 2) {
                    flag = 1;
                } else {
                    U();
                    if (sides[2][1] == 0 && sides[1][1] == 3 && sides[4][7] == 1 && sides[3][1] == 2) {
                        flag = 1;
                    } else {
                        U();
                        if (sides[2][1] == 0 && sides[1][1] == 3 && sides[4][7] == 1 && sides[3][1] == 2) {
                            flag = 1;
                        }
                    }
                }
            }
            if (flag == 0) {
                while (sides[2][1] != 0 || sides[1][1] != 3 || sides[4][7] != 1 || sides[3][1] != 2) {
                    U();
                    if (sides[1][1] == 3 && sides[4][7] == 1) {
                        R();
                        U();
                        CR();
                        U();
                        R();
                        U();
                        U();
                        CR();
                        U();
                        break;
                    }
                    if (sides[1][1] == 3 && sides[2][1] == 0) {
                        F();
                        U();
                        CF();
                        U();
                        F();
                        U();
                        U();
                        CF();
                        U();
                        break;
                    }
                    if (sides[2][1] == 0 && sides[3][1] == 2) {
                        L();
                        U();
                        CL();
                        U();
                        L();
                        U();
                        U();
                        CL();
                        U();
                        break;
                    }
                    if (sides[3][1] == 2 && sides[4][7] == 1) {
                        B();
                        U();
                        CB();
                        U();
                        B();
                        U();
                        U();
                        CB();
                        U();
                        break;
                    }
                    if (sides[1][1] == 3 && sides[3][1] == 2) {
                        B();
                        U();
                        CB();
                        U();
                        B();
                        U();
                        U();
                        CB();
                    }
                    if (sides[2][1] == 0 && sides[4][7] == 1) {
                        R();
                        U();
                        CR();
                        U();
                        R();
                        U();
                        U();
                        CR();
                    }
                }
            }

            while (!CheckCorners()) {
                if ((sides[0][8] == 4 && sides[2][2] == 0 && sides[1][0] == 3) ||
                    (sides[0][8] == 4 && sides[2][2] == 3 && sides[1][0] == 0) ||
                    (sides[0][8] == 0 && sides[2][2] == 4 && sides[1][0] == 3) ||
                    (sides[0][8] == 0 && sides[2][2] == 3 && sides[1][0] == 4) ||
                    (sides[0][8] == 3 && sides[2][2] == 0 && sides[1][0] == 4) ||
                    (sides[0][8] == 3 && sides[2][2] == 4 && sides[1][0] == 0)) {
                    while (!CheckCorners()) {
                        U();
                        R();
                        CU();
                        CL();
                        U();
                        CR();
                        CU();
                        L();
                    }
                } else {
                    if ((sides[2][0] == 0 && sides[3][2] == 2 && sides[0][6] == 4) ||
                        (sides[2][0] == 0 && sides[3][2] == 4 && sides[0][6] == 2) ||
                        (sides[2][0] == 2 && sides[3][2] == 4 && sides[0][6] == 0) ||
                        (sides[2][0] == 2 && sides[3][2] == 0 && sides[0][6] == 4) ||
                        (sides[2][0] == 4 && sides[3][2] == 2 && sides[0][6] == 0) ||
                        (sides[2][0] == 4 && sides[3][2] == 0 && sides[0][6] == 2)) {
                        while (!CheckCorners()) {
                            U();
                            F();
                            CU();
                            CB();
                            U();
                            CF();
                            CU();
                            B();
                        }
                    } else {
                        if ((sides[0][2] == 4 && sides[1][2] == 3 && sides[4][8] == 1) ||
                            (sides[0][2] == 4 && sides[1][2] == 1 && sides[4][8] == 3) ||
                            (sides[0][2] == 3 && sides[1][2] == 4 && sides[4][8] == 1) ||
                            (sides[0][2] == 3 && sides[1][2] == 1 && sides[4][8] == 4) ||
                            (sides[0][2] == 1 && sides[1][2] == 3 && sides[4][8] == 4) ||
                            (sides[0][2] == 1 && sides[1][2] == 4 && sides[4][8] == 3)) {
                            while (!CheckCorners()) {
                                U();
                                B();
                                CU();
                                CF();
                                U();
                                CB();
                                CU();
                                F();
                            }
                        } else {
                            if ((sides[0][0] == 4 && sides[4][6] == 1 && sides[3][0] == 2) ||
                                (sides[0][0] == 4 && sides[4][6] == 2 && sides[3][0] == 1) ||
                                (sides[0][0] == 2 && sides[4][6] == 1 && sides[3][0] == 4) ||
                                (sides[0][0] == 2 && sides[4][6] == 4 && sides[3][0] == 1) ||
                                (sides[0][0] == 1 && sides[4][6] == 4 && sides[3][0] == 2) ||
                                (sides[0][0] == 1 && sides[4][6] == 2 && sides[3][0] == 4)) {
                                while (!CheckCorners()) {
                                    U();
                                    L();
                                    CU();
                                    CR();
                                    U();
                                    CL();
                                    CU();
                                    R();
                                }
                            } else {
                                while (!CheckCorner()) {
                                    U();
                                    R();
                                    CU();
                                    CL();
                                    U();
                                    CR();
                                    CU();
                                    L();
                                }
                            }
                        }
                    }
                }
            }

            // Stage 9 (yellow edge)
            if (sides[0][2] != 4) {
                while (sides[0][2] != 4) {
                    B();
                    CR();
                    CB();
                    R();
                }
            }
            U();
            if (sides[0][2] != 4) {
                while (sides[0][2] != 4) {
                    B();
                    CR();
                    CB();
                    R();
                }
            }
            U();
            if (sides[0][2] != 4) {
                while (sides[0][2] != 4) {
                    B();
                    CR();
                    CB();
                    R();
                }
            }
            U();
            if (sides[0][2] != 4) {
                while (sides[0][2] != 4) {
                    B();
                    CR();
                    CB();
                    R();
                }
            }
            while (!IsSolved()) {
                U();
            }
        }
    }
};