#include <iostream>
#include <string>
//#include "functions.h"

std::string data[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
std::string winner;
bool game_status = true;
std::string turn = "player 1";
int input;
int game_type;

int print_color(int style, int forground, std::string text, int background, int text_format){
    std::cout << "\033["+std::to_string(style)+";"+std::to_string(forground)+";"+std::to_string(background)+"m"+text+"\033["+std::to_string(text_format)+"m";
    return 0;
}

int color_select(std::string ind){
    if(ind == "O"){
        print_color(0, 97, "  "+ind+"  ", 44, 0);
    }else if (ind == "X"){
        print_color(0, 97, "  "+ind+"  ", 41, 0);
    }else{
        print_color(0, 30, "  "+ind+"  ", 107, 0);
    }
    return 0;
}





std::string decide_winner(std::string letter){
    if(letter == "X"){
        return "player 1";
    }else if(letter == "O"){
        return "player 2";
    }else{
        return "draw";
    }
}



void decide_game_stop(){
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
                winner = decide_winner(data[0]);
            }else if (data[3] == data[4] && data[4] == data[5]){
                winner = decide_winner(data[1]);
            }else if (data[6] == data[7] && data[7] == data[8]){
                winner = decide_winner(data[2]);
            }else if (data[0] == data[3] && data[3] == data[6]){
                winner = decide_winner(data[3]);
            }else if (data[1] == data[4] && data[4] == data[7]){
                winner = decide_winner(data[4]);
            }else if (data[2] == data[5] && data[5] == data[8]){
                winner = decide_winner(data[5]);
            }else if (data[0] == data[4] && data[4] == data[8]){
                winner = decide_winner(data[6]);
            }else if (data[2] == data[4] && data[4] == data[6]){
                winner = decide_winner(data[7]);
            }
            
            if(winner == "player 1"){
                print_color(0, 97, "________________________________we have a winner: "+winner+" ______________________________", 41, 0);
            }else{
                print_color(0, 97, "________________________________we have a winner: "+winner+" ______________________________", 44, 0);
            }
            std::cout << "";
            game_status = false;
        }
}




int display(){
    print_color(0, 107, "                 ", 30, 0);
    std::cout << "\n";

    color_select(data[0]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[1]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[2]);
    std::cout << "\n";
    print_color(0, 107, "   ---+---+---   ", 30, 0);
    std::cout << "\n";

    color_select(data[3]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[4]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[5]);
    std::cout << "\n";
    print_color(0, 107, "   ---+---+---   ", 30, 0);
    std::cout << "\n";

    color_select(data[6]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[7]);
    print_color(0, 107, "|", 30, 0);
    color_select(data[8]);
    std::cout << "\n";    

    print_color(0, 107, "                 ", 30, 0);
    std::cout << "\n";



    return 0;
}











void player_vs_player(){
        while(game_status){
        std::cout << "turn of player : "+turn+"\n please enter your box number\n";

        if(turn == "player 1"){
            print_color(0, 97, "________________________________turn of player : "+turn+"\n please enter your box number\n______________________________", 41, 0);
        }else{
            print_color(0, 97, "_____________________ of player : "+turn+"\n please enter your box number\n_____________________", 44, 0);
        }

        std::cin >> input;

        while(input > 9 || input < 0){
            std::cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            std::cin >> input;
            //cout << input;
        }

        while(!(data[input-1] == std::to_string(input))){
            std::cout << "!!!!!!!!!!!!!!!       already taken       !!!!!!!!!!!!!!!\n";
            std::cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            std::cin >> input;
        }

        

        if(turn == "player 1"){
            data[input-1] = "X";
            turn = "player 2";
        }else{
            data[input-1] = "O";
            turn = "player 1";
        }
        std::cout << "\033[1;31mbold red text\033[0m\n";
        std::cout << "______________________________________________________________\n";
        display();
        std::cout << "______________________________________________________________\n";

        //win or draw conditions
        decide_game_stop();


    }
}







void player_vs_AI(){
        int co = 0;
        while(game_status){
        std::cout << "your turn\n";
        std::cin >> input;

        while(input > 9 || input < 0){
            std::cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            std::cin >> input;
            //cout << input;
        }

        while(!(data[input-1] == std::to_string(input))){
            std::cout << "!!!!!!!!!!!!!!!       already taken       !!!!!!!!!!!!!!!\n";
            std::cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            std::cin >> input;
        }

        data[input-1] = "X";
        

        if(data[0] == data[1] && data[0] == "X" && data[2] != "X" && data[2] != "O" ){
            data[2] = "O";
            std::cout << "this is index 0";
        }else if(data[1] == data[2] && data[1] == "X" && data[0] != "X" && data[0] != "O" ){
            data[0] = "O";
            std::cout << "this is index 1";
        }else if(data[3] == data[4] && data[3] == "X" && data[5] != "X" && data[5] != "O" ){
            data[5] = "O";
            std::cout << "this is index 2";
        }else if(data[4] == data[5] && data[4] == "X" && data[3] != "X" && data[3] != "O" ){
            data[3] = "O";
            std::cout << "this is index 3";
        }else if(data[6] == data[7] && data[6] == "X" && data[8] != "X" && data[8] != "O" ){
            data[8] = "O";
            std::cout << "this is index 4";
        }else if(data[7] == data[8] && data[7] == "X" && data[6] != "X" && data[6] != "O" ){
            data[6] = "O";
            std::cout << "this is index 5";
        }else if(data[0] == data[3] && data[0] == "X" && data[6] != "X" && data[6] != "O" ){
            data[6] = "O";
            std::cout << "this is index 6";
        }else if(data[3] == data[6] && data[3] == "X" && data[0] != "X" && data[0] != "O" ){
            data[0] = "O";
            std::cout << "this is index 7";
        }else if(data[1] == data[4] && data[1] == "X" && data[8] != "X" && data[8] != "O" ){
            data[8] = "O";
            std::cout << "this is index 8";
        }else if(data[4] == data[7] && data[4] == "X" && data[1] != "X" && data[1] != "O" ){
            data[1] = "O";
            std::cout << "this is index 9";
        }else if(data[2] == data[5] && data[2] == "X" && data[8] != "X" && data[8] != "O" ){
            data[8] = "O";
            std::cout << "this is index 10";
        }else if(data[5] == data[8] && data[5] == "X" && data[2] != "X" && data[2] != "O" ){
            data[2] = "O";
            std::cout << "this is index 11";
        }else if(data[0] == data[4] && data[0] == "X" && data[8] != "X" && data[8] != "O" ){
            data[8] = "O";
            std::cout << "this is index 12";
        }else if(data[4] == data[8] && data[4] == "X" && data[0] != "X" && data[0] != "O" ){
            data[0] = "O";
            std::cout << "this is index 13";
        }else if(data[2] == data[4] && data[2] == "X" && data[6] != "X" && data[6] != "O" ){
            data[6] = "O";
            std::cout << "this is index 14";
        }else if(data[4] == data[6] && data[4] == "X" && data[2] != "X" && data[2] != "O" ){
            data[2] = "O";
            std::cout << "this is index 15";
        }else if(data[0] == data[8] && data[0] == "X" && data[4] != "X" && data[4] != "O" ){
            data[4] = "O";
            std::cout << "this is index 16";
        }else if(data[0] == data[2] && data[0] == "X" && data[1] != "X" && data[1] != "O" ){
            data[1] = "O";
            std::cout << "this is index 17";
        }else if(data[2] == data[8] && data[2] == "X" && data[5] != "X" && data[5] != "O" ){
            data[5] = "O";
            std::cout << "this is index 18";
        }else if(data[6] == data[8] && data[6] == "X" && data[7] != "X" && data[7] != "O" ){
            data[7] = "O";
            std::cout << "this is index 19";
        }else if(data[0] == data[6] && data[0] == "X" && data[3] != "X" && data[3] != "O" ){
            data[3] = "O";
            std::cout << "this is index 20";
        }else{
            std::cout << 'error';
            while(data[co] == "X" || data[co] == "O"){
                co++;
            }
            data[co] = "O";
            std::cout << "this is index 21";
        }

        std::cout << "______________________________________________________________\n";
        display();
        std::cout << "______________________________________________________________\n";

        //win or draw conditions
        decide_game_stop();
    }
}







int main(){


    display();

    std::cout << "!!!!!!!!!!!!!!!select game mode!!!!!!!!!!!!!!!\n 1 ) player vs player \n 2) player vs AI\n";
    std::cin >> game_type;
    if(game_type == 1){
        player_vs_player();
    }else if(game_type == 2){
        player_vs_AI();
    }




    return 0;
}