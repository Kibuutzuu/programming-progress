#include <iostream>
//the code calculates the square powers of a number "n" based on the sum of the first "n" odd numbers
//in this case, "cuadradito" is a silly form to say square, like little square, just a fun name
int cuadradito(int n){
    if (n==1){ //this is my conditional base, this condition tells when the code should stop recursion and start working with the results
        return 1;
    }else{
        return cuadradito(n-1) + (2*n-1); //this is my recursion, "cuadradito(n-1) + (2*n-1)" is a form to view the same result but evaluating the square power from the previous number
      // (2*n-1) represents the odd number in the "n" position, this would be the last odd number of all the sums
    }
}

int main(){
    int numerito;
    std::cout<<"Ingrese un número: "; //it says "Enter a number"
    std::cin>>numerito;
    std::cout<<cuadradito(numerito);
    return 0;
}
