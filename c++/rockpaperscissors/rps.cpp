#include <iostream>

int main() {
    std::string p1,p2;
    std::cout << "Please Enter your choices players! (Player 1 and 2):\n";
    std::cout << "Player 1: ";
    std::cin >> p1;
    std::cout << "Player 2: ";
    std::cin >> p2;
    if ( p1 == "Rock" && p2 == "Rock" ) {
        std::cout << "Draw!";
    } else if ( p1 == "Rock" && p2 == "Paper" ) {
        std::cout << "Player 2 Wins!";
    } else if ( p1 == "Rock" && p2 == "Scissors" ) {
        std::cout << "Player 1 Wins!";
    }
     else if ( p1 == "Paper" && p2 == "Paper" ) {
        std::cout << "Draw!";
    } else if ( p1 == "Paper" && p2 == "Scissors" ) {
        std::cout << "Player 2 Wins!";
    } else if ( p1 == "Paper" && p2 == "Rock" ) {
        std::cout << "Player 1 Wins!";
    }
     else if ( p1 == "Scissors" && p2 == "Scissors" ) {
        std::cout << "Draw!";
    } else if ( p1 == "Scissors" && p2 == "Rock" ) {
        std::cout << "Player 2 Wins!";
    } else if ( p1 == "Scissors" && p2 == "Paper" ) {
        std::cout << "Player 1 Wins!";
    }
    else {
        std::cout << "Out of Possibiltes,please try again!";
    }
    return 0;
}
