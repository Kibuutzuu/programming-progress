#include <iostream>
using namespace std;

int main(){
    double i, factorial = 1;

    cout<<"Ingrese un número para sacar su factorial: ";
    cin>>i;

    for (int o = 1; o<=i; o++){
        factorial = factorial * o;
    }
    cout <<factorial;

    return 0;
}
