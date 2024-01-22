#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main() {
    int three_row[8][3] = {{1, 2, 3}, {1, 4, 7}, {7, 8, 9}, {3, 6, 9}, {2, 5, 8}, {4, 5, 6}, {1, 5, 9}, {3, 5, 7}};
    char board[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
    char disp_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int c_choice;
    int p_choice;
    string def = "Draw";
    int taken_spots[2][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    for (int i = 0; i < 5; i++) {
        cout << "\t      T I C   T A C   T O E" << endl << endl;
        cout << "\t Player 1 is X     Computer is O" << endl << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << disp_board[0][0] << "  |  " << disp_board[0][1] << "  |  " << disp_board[0][2] << endl;
        cout << "\t\t_____|_____|_____" << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << disp_board[1][0] << "  |  " << disp_board[1][1] << "  |  " << disp_board[1][2] << endl; 
        cout << "\t\t_____|_____|_____" << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << disp_board[2][0] << "  |  " << disp_board[2][1] << "  |  " << disp_board[2][2] << endl; 
        cout << "\t\t     |     |     " << endl;

        cout << "\t      T I C   T A C   T O E" << endl << endl;
        cout << "\t Player 1 is X     Computer is O" << endl << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
        cout << "\t\t_____|_____|_____" << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl; 
        cout << "\t\t_____|_____|_____" << endl;
        cout << "\t\t     |     |     " << endl;
        cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl; 
        cout << "\t\t     |     |     " << endl;

        if (def != "Draw"){
            cout << def << endl;
            return 0;
        }

        cin >> p_choice;
        taken_spots[0][i] = p_choice;
        switch (p_choice){
            case 1:
                board[0][0] = 'X';
                break;
            case 2:
                board[0][1] = 'X';
                break;
            case 3:
                board[0][2] = 'X';
                break;
            case 4:
                board[1][0] = 'X';
                break;
            case 5:
                board[1][1] = 'X';
                break;
            case 6:
                board[1][2] = 'X';
                break;
            case 7:
                board[2][0] = 'X';
                break;
            case 8:
                board[2][1] = 'X';
                break;
            case 9:
                board[2][2] = 'X';
                break;
        }

        //PLAYER WIN CONDITIONS CHECK
        int flag = 0;
        int count = 0;
        int row = 0;
        int c = 0;
        int ai = -5;

        while (flag == 0){
            for (int a = 0; a < 5; ++a) {
                
                if (three_row[row][c] == taken_spots[0][a]){
                    ++count;
                }
            }
            
            ++c;

            if (count == 2 && ai == -5){
                int ele = 0;
                int in = 0;
                int aic = 0;
                for (int ele = 0; ele < 3; ++ele){
                    for (int in = 0; in < 5; ++in){
                        if (taken_spots[1][in] != three_row[row][ele]){
                            ++aic;
                        }
                    }
                }
                   
                if (aic == 15){
                    ai = row;
                }
                
                
            }

            if (c == 3){
                if (count == 3) {
                    def = "Player Wins!";
                    flag = 1;
                }
                c = 0;
                count = 0;
                ++row;
            }
            if (row == 8) {
                flag = 1;
            }
        }
        int path = 0;
        int opt[3];
        int ind;
        int d = 0;

        if (ai != -5 && def == "Draw"){
            for (int d = 0; d < 3; ++d){
                opt[d] = three_row[ai][d];
            }
            ind = rand() %3;
            c_choice = opt[ind];
            path = 1;
        }
        else {
            c_choice = 1 + rand() %9;
        }
        

        int e = 0;

        if (i < 4){
            while (e != 5){

                if (c_choice == taken_spots[0][e] || c_choice == taken_spots[1][e]) {
                    if (path == 0){
                        c_choice = 1 + rand() %9;
                    }
                    else {
                        ind = rand() %3;
                        c_choice = opt[ind];
                        
                    }
                    
                    e = 0;
                }
                else {
                    ++e;
                }
            }
            taken_spots[1][i] = c_choice;

            switch (c_choice){
            case 1:
                board[0][0] = 'O';
                break;
            case 2:
                board[0][1] = 'O';
                break;
            case 3:
                board[0][2] = 'O';
                break;
            case 4:
                board[1][0] = 'O';
                break;
            case 5:
                board[1][1] = 'O';
                break;
            case 6:
                board[1][2] = 'O';
                break;
            case 7:
                board[2][0] = 'O';
                break;
            case 8:
                board[2][1] = 'O';
                break;
            case 9:
                board[2][2] = 'O';
                break;
            }

        }  
        //COMPUTER WIN CONDITIONS CHECK
        int f = 0;
        int cnt = 0;
        int r = 0;
        int cc = 0;

        while (f == 0){
            for (int b = 0; b < 5; ++b) {
                
                if (three_row[r][cc] == taken_spots[1][b]){
                    ++cnt;
                }
            }
            
            ++cc;
            
            if (cc == 3){
                if (cnt == 3) {
                    def = "Computer Wins!";
                    f = 1;
                }
                cc = 0;
                cnt = 0;
                ++r;
            }
            if (r == 8) {
                f = 1;
            }
        }

    }
    cout << "\t      T I C   T A C   T O E" << endl << endl;
    cout << "\t Player 1 is X     Computer is O" << endl << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << disp_board[0][0] << "  |  " << disp_board[0][1] << "  |  " << disp_board[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << disp_board[1][0] << "  |  " << disp_board[1][1] << "  |  " << disp_board[1][2] << endl; 
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << disp_board[2][0] << "  |  " << disp_board[2][1] << "  |  " << disp_board[2][2] << endl; 
    cout << "\t\t     |     |     " << endl;

    cout << "\t      T I C   T A C   T O E" << endl << endl;
    cout << "\t Player 1 is X     Computer is O" << endl << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl; 
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl; 
    cout << "\t\t     |     |     " << endl;

    cout << def << endl;
    return 0;
}
