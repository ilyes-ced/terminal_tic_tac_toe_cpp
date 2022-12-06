#include <iostream>
#include <string>
#include "functions.h"
use namespace std

string data[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
string winner;
bool game_status = true;


int main(){
    string turn = "player 1";
    int input;

    display();



    while(game_status){
        cout << "turn of player : "+turn+"\n please enter your box number\n";
        cin >> input;

        while(input > 9 || input < 0){
            cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            cin >> input;
            //cout << input;
        }

        while(!(data[input-1] == to_string(input))){
            cout << "!!!!!!!!!!!!!!!       already taken       !!!!!!!!!!!!!!!\n";
            cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            cin >> input;
        }

        

        if(turn == "player 1"){
            data[input-1] = "X";
            turn = "player 2";
        }else{
            data[input-1] = "O";
            turn = "player 1";
        }
        cout << "\033[1;31mbold red text\033[0m\n";
        cout << "______________________________________________________________\n";
        display();
        cout << "______________________________________________________________\n";

        //win or draw conditions
        if(
            (data[0] == data[1] && data[1] == data[2]) || (data[3] == data[4] && data[4] == data[5])
            ||
            (data[6] == data[7] && data[7] == data[8]) || (data[0] == data[3] && data[3] == data[6])
            ||
            (data[1] == data[4] && data[4] == data[7]) || (data[2] == data[5] && data[5] == data[8])
            ||
            (data[0] == data[4] && data[4] == data[8]) || (data[2] == data[4] && data[4] == data[6])
        ){
            if(data[0] == data[1] && data[1] == data[2]){
                winner = decide_winner(data[0])
            }else if (data[3] == data[4] && data[4] == data[5]){
                winner = decide_winner(data[0])
            }else if (data[6] == data[7] && data[7] == data[8]){
                winner = decide_winner(data[0])
            }else if (data[0] == data[3] && data[3] == data[6]){
                winner = decide_winner(data[0])
            }else if (data[1] == data[4] && data[4] == data[7]){
                winner = decide_winner(data[0])
            }else if (data[2] == data[5] && data[5] == data[8]){
                winner = decide_winner(data[0])
            }else if (data[0] == data[4] && data[4] == data[8]){
                winner = decide_winner(data[0])
            }else if (data[2] == data[4] && data[4] == data[6]){
                winner = decide_winner(data[0])
            }
            
            if(winner == "player 1"){
                print_color(0, 97, "________________________________we have a winner: "+winner+" ______________________________", 41, 0);
            }else{
                print_color(0, 97, "________________________________we have a winner: "+winner+" ______________________________", 44, 0);
            }
            cout << "";
            game_status = false;
        }
    }


    return 0;
}