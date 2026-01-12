#include <iostream>

struct cajero{
    std::string nombre;

    private:
    int cuentabancaria = 1000;


    public:
    cajero(std::string Nombre){
        nombre = Nombre;
        int num;
        std::cout<<"Hola "<<nombre<<std::endl;

        while (num != 3){
            std::cout<<"Tu saldo actual es de: $"<<cuentabancaria<<std::endl<<"Que quieres hacer?"<<std::endl;
            std::cout<<"1.- depositar"<<std::endl<<"2.- girar"<<std::endl<<"3.- salir"<<std::endl;
            std::cin>>num;

            if (num == 1){
                depositar();
            } else if(num == 2){
                girar();
            } else if (num == 3){
                std::cout<<"Gracias por ocupar nuestros servicios!";
            }
        }
    }

    void depositar(){
        int cant;
        std::cout<<"Ingrese la cantidad que quiere depositar: ";
        std::cin>>cant;

        cuentabancaria += cant;

        std::cout<<"Listo!"<<std::endl;
    }

    void girar(){
        int cant;
        std::cout<<"Ingrese la cantidad que quiere girar: ";
        std::cin>>cant;
        if (cant > cuentabancaria){
            std::cout<<"Excede monto"<<std::endl;
        }else{
            cuentabancaria -= cant;
            std::cout<<"Listo!"<<std::endl;
        }
        
    }
    


};

int main(){
    std::string nom;
    std::cout<<"Ingrese su nombre: ";
    std::cin>>nom;

    cajero Cliente(nom);


    return 0;
}