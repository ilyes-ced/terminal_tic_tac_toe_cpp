#include <iostream>
#include <string>


std::string data[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
bool game_status = true;

int print_color(int style, int forground, std::string text, int background, int text_format){
    std::cout << "\033["+std::to_string(style)+";"+std::to_string(forground)+";"+std::to_string(background)+"m"+text+"\033["+std::to_string(text_format)+"m";
    return 0;
}
int color_select(int ind){
    if(data[ind] == "O"){
        print_color(0, 97, "  "+data[0]+"  ", 44, 0);
    }else if (data[ind] == "X")
    {
        print_color(0, 97, "  "+data[ind]+"  ", 41, 0);
    }else{
        print_color(0, 97, "  "+data[ind]+"  ", 107, 0);
    }
    return 0;
}
int display(){
    print_color(0, 107, "                 ", 30, 0);
    std::cout << "\n";

    color_select(0);
    print_color(0, 107, "|", 30, 0);
    color_select(1);
    print_color(0, 107, "|", 30, 0);
    color_select(2);
    std::cout << "\n";
    print_color(0, 107, "   ---+---+---   ", 30, 0);
    std::cout << "\n";

    color_select(3);
    print_color(0, 107, "|", 30, 0);
    color_select(4);
    print_color(0, 107, "|", 30, 0);
    color_select(5);
    std::cout << "\n";
    print_color(0, 107, "   ---+---+---   ", 30, 0);
    std::cout << "\n";

    color_select(6);
    print_color(0, 107, "|", 30, 0);
    color_select(7);
    print_color(0, 107, "|", 30, 0);
    color_select(8);
    std::cout << "\n";    

    print_color(0, 107, "                 ", 30, 0);
    std::cout << "\n";



    return 0;
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

        //win or draw conditions
        if(
            ((data[0] == data[1] && data[1] == data[2]) ||
            (data[3] == data[4] && data[4] == data[5]) ||
            (data[6] == data[7] && data[8] == data[9]) ) ||
        )
    }


    return 0;
}