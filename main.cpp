#include <iostream>

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

int check_in_array(int pos){
    for(int i = 0; i < sizeof(game_status); i++){
        if(game_status[i] == pos){
            return game_status[i];
            break;
        }
    }
}

int main(){
    std::string turn = "player 1";
    int input;

    display();



    while(game_status){
        std::cout << "turn of player : "+turn+"\n please enter your box number\n";
        std::cin >> input;
        while(input > 9 || input < 0){
            check_in_array(input)
            std::cout << "please enter valid number \n";
            std::cin >> input;
            std::cout << input;
        }

        if(turn == "player 1"){
            turn = "player 2";
        }else{
            turn = "player 1";
        }
    }


    return 0;
}