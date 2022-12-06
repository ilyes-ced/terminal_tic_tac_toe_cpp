

extern std::string data;



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
        print_color(0, 97, "  "+ind+"  ", 107, 0);
    }
    return 0;
}





std::string dicide_winner(std::string letter){
    if(letter == "X"){
        return "player 1";
    }else{
        return "player 2";
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