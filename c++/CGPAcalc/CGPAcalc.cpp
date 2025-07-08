#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<double> credits;
    int n = 0;
    double credit,grade,sum1 = 0;
    std::cout << "Enter number of courses: ";
    std::cin >> n;
    for ( int i = 0; i < n; i++) {
        std::cout << "Please Enter Credit and Grade per course (Credit 1st then Grade and add a space between each number): ";
        std::cin >> credit;
        credits.push_back(credit);
        std::cin >> grade;
        sum1 += grade*credit;
    }
    double sum2 = accumulate(credits.begin(),credits.end(),0.0);
    double cgpa = sum1/sum2;
    std::cout << "CGPA is: " << cgpa;
    return 0;
}

