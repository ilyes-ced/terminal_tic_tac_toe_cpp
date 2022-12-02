#include <iostream>
#include <string>


std::string data[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool game_status = true;


int display(){
    std::cout << " "+data[0]+" | "+data[1]+" | "+data[2]+" \n";
    std::cout << "---+---+---\n";
    std::cout << " "+data[3]+" | "+data[4]+" | "+data[5]+" \n";
    std::cout << "---+---+---\n";
    std::cout << " "+data[6]+" | "+data[7]+" | "+data[8]+" \n";
    return 0;
}

int print_color(int style, int forground, int background, int text_format){
    std::cout << "\033["+std::to_string(style)+";"+std::to_string(forground)+";"+std::to_string(background)+"m"+text+"\033["+std::to_string(text_format)+"m";
}

int main(){
    std::string turn = "player 1";
    int input;

    display();



    while(game_status){
        std::cout << "turn of player : "+turn+"\n please enter your box number\n";
        std::cin >> input;

        while(input > 9 || input < 0){
            std::cout << "!!!!!!!!!!!!!!! please enter valid number !!!!!!!!!!!!!!!\n";
            std::cin >> input;
            //std::cout << input;
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
    }


    return 0;
}