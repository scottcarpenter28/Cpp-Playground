#include<iostream>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int var = 10;
    int &ref = var;
    std::cout << "Variable value " << var << std::endl;
    std::cout << "Reference value " << ref << std::endl;

    int x = 5, y = 10;
    std::cout << "Before X:" << x << ", Y:" << y << std::endl;
    swap(x, y);
    std::cout << "After X:" << x << ", Y:" << y << std::endl;

    return 0;
}