#include <iostream>
#include <random>
#include <unistd.h>

int main() {
    std::string guess,guess2,guess3;
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<> round1(1, 30);
    std::uniform_int_distribution<> round2(-0.4, 176);
    std::uniform_real_distribution<> round3(-200, 300);
    auto r1 = round1(gen);
    auto r2 = round2(gen);
    auto r3 = round3(gen);
    std::cout << "Welcome to the random number guessing game,Please Guess the Correct Number!..........\n";
    sleep(2);
    std::cout << "Notes:\n";
    std::cout << "1-The Difficulty increases with each round (there are 3 rounds)\n";
    std::cout << "2-The Amount of the prize also increases each round by 500 coins!\n";
    std::cout << "3-Negative Numbers ARE included!\n";
    std::cout << "Enjoy!\n";
    sleep(2);
    std::cout << "Enter guess for first number: ";
    std::cin >> guess;
    if ( std::stoi(guess) == r1 ) {
        std::cout << "Correct Guess for round 1! you now have 100 coins in your balance\n";
        std::cout << "Enter guess for second number: ";
        std::cin >> guess2;
        if ( std::stoi(guess2) == r2 ) {
            std::cout << "Correct Guess for round 2! you now have 600 coins in your balance\n";
            std::cout << "Enter guess for third number: ";
            std::cin >> guess3;
            if ( std::stof(guess3) == r3 ) {
                std::cout << "Correct Guess for round 3! you now have 1100 coins in your balance\n";
                std::cout << "Thanks for playing!";
                exit(0);
            } else {
                std::cout << "Sorry,Wrong guess!";
                exit(0);
            }
        } else {
            std::cout << "Sorry,Wrong guess!";
            exit(0);
        }
            
        } else {
            std::cout << "Sorry,Wrong guess!";
            exit(0);
        }
    return 0;
} 

    


