// Is only a simple welcome, trying to use getline because getline accept spaces, cin onlt take the first word of the text
// for example, from "Kibu tzuuji", cin only extrac the word "Kibu" and the code prints "Hola Kibu" in the output
// with getline, the code prints "Hola Kibu tzuuji" normally
#include <iostream>

int main(){   
    std::string nombre = "";
    std::cout<<"Ingrese su nombre"<<std::endl;
    std::getline (std::cin,nombre);
    std::cout<<"Hola " << nombre << std::endl; 
    return 0;
}
