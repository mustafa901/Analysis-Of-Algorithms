#include <iostream>

int Computer_Factorial(int n){
    int i = 1;
    int result = 1;


    while (i <= n){
        result = result * i;
        i++;
    }
    return result;
}

int main(){
    int n = 5;
}



