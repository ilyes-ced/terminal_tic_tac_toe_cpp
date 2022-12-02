#include <iostream>

std::string data[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

int display(){
    std::cout << " "+data[0]+" | "+data[1]+" | "+data[2]+" \n";
    std::cout << "___________\n";
    std::cout << " "+data[3]+" | "+data[4]+" | "+data[5]+" \n";
    std::cout << "___________\n";
    std::cout << " "+data[6]+" | "+data[7]+" | "+data[8]+" \n";
}



int main(){
    std::string turn = "player1";
    int x;





    std::cout << "turn of player : "+turn+"\n please enter your box number";
    std::cin >> x;


    return 0;
}