#include <iostream>
#include <limits>

double inputValidationNumber(double input){
    while(!input){
        std::cout << "Invalid input: Nan\nRe-enter:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    }
    return input;
}

double inputValidationNegative(double input){
    while(input<0){
        std::cout << "Invalid input: X must be positive\nRe-enter:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
        input = inputValidationNumber(input);
    }
    return input;
}

int main(){
    double a,x;
    std::cout << "A:";
    std::cin >> a;
    a = inputValidationNumber(a);
    
    std::cout << "X:";
    std::cin >> x;
    x = inputValidationNumber(x);
    x = inputValidationNegative(x);

    for(int i=1;i<4;++i){
        x=x*i;
        double sum = a;
        for(auto j=2;j<x+2;++j){
            std::cout << sum << ",";
            sum = a*j;
        }
        std::cout << "\n";
        ++a;
        x = x/i;
    }
}