#include <iostream>
//Nombre: Joaquin Flores Alarcon

const int N = 8; //el numero se ve de 0 a 8 si pongo N = 8, por ende, lo hago hasta el 7 para que esté la matriz inicializada en 8
const int aristas = 12; //contadas a través del dibujo, era más fácil que programar algo que cuente aristas sinceramente

int gradovertice (int vertice, int matriz[N][N]){
    int contador = 0;

    for (int i = 0; i < N; i++){
        if (vertice == i && matriz[vertice][i] == 1){
            contador += 2;
        }else if (matriz [vertice][i] == 1){
            contador += 1;
        }
    }

    return contador; //terminada, es un contador basicamente que ve solo la linea
}

void desplegarAdyacencia(int matriz[N][N]){

    std::cout << "    "; //para darle espacio y dejarlo más parecido al formato dado por la tarea solamente
    for (int j = 0; j < N; j++){
        std::cout << "V" << j+1 << " "; // para puro agregar el v1, v2 arriba
    }
    std::cout << std::endl<< "    -----------------------" << std::endl;
    for (int i = 0; i < N; i++){
        std::cout << "V" << i+1 << " | "; //i + 1 porque va a empezar de 0 y no me sirve eso
        for (int j = 0; j < N; j++){
            std::cout << matriz[i][j] << "  ";
        }
        std::cout << std::endl;
    } //este for es básicamente lo mismo que se vió de ppt, está agregado lo de v1, v2, etc y el |
}

void desplegarIncidencia (int matriz[N][aristas]){
    std::cout << "    ";
    for (int j = 0; j < aristas; j++){
        std::cout << "a" << j+1 << " ";
    }
    std::cout << std::endl;
    std::cout << "    "<< "----------------------------------------"<<std::endl;
    for (int i = 0; i < N; i++){
        std::cout << "V" << i+1 << " | ";

        for (int j = 0; j < aristas; j++){
            if (matriz[i][j]==-1){
                std::cout << matriz[i][j] << " ";
            }else{
                std::cout << matriz[i][j] << "  ";   
            }
        }

        std::cout << std::endl;
    }
}

int main(){

    //matriz adyacente NO dirigida - vertice / vertice

    int matriz[N][N] = {0};

    // unión de vertices por arista

    matriz [0][1] = 1;
    matriz [1][0] = 1;

    matriz [0][2] = 1;
    matriz [2][0] = 1;

    matriz [1][3] = 1;
    matriz [3][1] = 1;

    matriz [2][3] = 1;
    matriz [3][2] = 1;

    matriz [2][4] = 1;
    matriz [4][2] = 1;

    matriz [3][5] = 1;
    matriz [5][3] = 1;

    matriz [4][6] = 1;
    matriz [6][4] = 1;

    matriz [6][7] = 1;
    matriz [7][6] = 1;

    matriz [4][4] = 1;

    matriz [1][2] = 1;
    matriz [2][1] = 1;

    matriz [5][7] = 1;
    matriz [7][5] = 1;

    matriz [2][5] = 1;
    matriz [5][2] = 1;
    //fin matriz adyacente NO dirigida

    int matrizinci [N][aristas] = {0}; //matriz incidencia pero NO dirigida (porque quiero hacerlo en orden xd)

    //inicio de incidencias de aristas
    // matriz [vertice] [arista], empezando del 0 pero el 0 en verdad es 1 y asi con los siguientes (1 = 2, 2 = 3, etc)
    matrizinci[0][0] = 1; //vertice 1 conectado con arista 1 (a1)
    matrizinci[0][1] = 1; //vertice 1 conectado con arista 2 (a2)

    matrizinci[1][0] = 1; //conexiones de vertice 2 con aristas
    matrizinci[1][2] = 1;
    matrizinci[1][9] = 1;

    matrizinci[2][1] = 1; //conexiones de vertice 3 con aristas
    matrizinci[2][3] = 1;
    matrizinci[2][9] = 1;
    matrizinci[2][11] = 1;
    matrizinci[2][4] = 1;

    matrizinci[3][2] = 1; //conexiones de vertice 4 con aristas
    matrizinci[3][3] = 1;
    matrizinci[3][5] = 1;

    matrizinci[4][4] = 1; //conexiones de vertice 5 con aristas
    matrizinci[4][6] = 1;
    matrizinci[4][8] = 2; //incision a si mismo / bucle

    matrizinci[5][5] = 1; //conexiones de vertice 6 con aristas
    matrizinci[5][11] = 1;
    matrizinci[5][10] = 1;

    matrizinci[6][6] = 1; //conexiones de vertice 7 con aristas
    matrizinci[6][7] = 1;

    matrizinci[7][10] = 1; //conexiones de vertice 8 con aristas
    matrizinci[7][7] = 1;
    //fin matriz de incidencia NO dirigida

    //matriz adyacente dirigida - vertice / vertice

    int matrizdiri[N][N] = {0};

    // unión de vertices por arista

    matrizdiri [0][1] = 1; //vertice 1 dirigido a vertice 2 pero no en viceversa (a1 dirigido a v2)

    matrizdiri [2][0] = 1; //vertice 3 dirigido a vertice 1

    matrizdiri [1][3] = 1;
    matrizdiri [3][1] = 1;

    matrizdiri [2][3] = 1; //vertice 3 dirigido a vertice 4

    matrizdiri [2][4] = 1;
    matrizdiri [4][2] = 1;

    matrizdiri [3][5] = 1;
    matrizdiri [5][3] = 1;

    matrizdiri [4][6] = 1;
    matrizdiri [6][4] = 1;

    matrizdiri [6][7] = 1;
    matrizdiri [7][6] = 1;

    matrizdiri [4][4] = 1;

    matrizdiri [1][2] = 1;
    matrizdiri [2][1] = 1;

    matrizdiri [5][7] = 1; // vertice 6 dirigido a vertice 8

    matrizdiri [2][5] = 1;
    matrizdiri [5][2] = 1;
    //fin matriz adyacente dirigida


    int matrizincidiri [N][aristas] = {0}; //matriz incidencia pero NO dirigida (porque quiero hacerlo en orden xd)

    //inicio de incidencias de aristas
    // matriz [vertice] [arista], empezando del 0 pero el 0 en verdad es 1 y asi con los siguientes (1 = 2, 2 = 3, etc)
    matrizincidiri[0][0] = -1; //vertice 1 para saber la arista suma +1 a la sección de arista.
    matrizincidiri[0][1] = 1; //-1 significa que está apuntando a otro vertice

    matrizincidiri[1][0] = 1; //conexiones de vertice 2 con aristas
    matrizincidiri[1][2] = -1;
    matrizincidiri[1][9] = 1;

    matrizincidiri[2][1] = 1; //conexiones de vertice 3 con aristas
    matrizincidiri[2][3] = 1;
    matrizincidiri[2][9] = 1;
    matrizincidiri[2][11] = 1;
    matrizincidiri[2][4] = 1;

    matrizincidiri[3][2] = 1; //conexiones de vertice 4 con aristas
    matrizincidiri[3][3] = 1;
    matrizincidiri[3][5] = -1;

    matrizincidiri[4][4] = -1; //conexiones de vertice 5 con aristas
    matrizincidiri[4][6] = 1;
    matrizincidiri[4][8] = 2; //incision a si mismo / bucle

    matrizincidiri[5][5] = 1; //conexiones de vertice 6 con aristas
    matrizincidiri[5][11] = 1;
    matrizincidiri[5][10] = 1;

    matrizincidiri[6][6] = -1; //conexiones de vertice 7 con aristas
    matrizincidiri[6][7] = 1;

    matrizincidiri[7][10] = 1; //conexiones de vertice 8 con aristas
    matrizincidiri[7][7] = 1;
    //fin matriz de incidencia dirigida


    int num = 0;
    //menu
    do{
        std::cout<<"1. Mostrar matriz de adyacencia NO dirigida"<<std::endl;
        std::cout<<"2. Mostrar matriz de incidencia NO dirigida"<<std::endl;
        std::cout<<"3. Mostrar matriz de adyacencia dirigida"<<std::endl;
        std::cout<<"4. Mostrar matriz de incidencia dirigida"<<std::endl;
        std::cout<<"5. Obtener grado de un vertice (matriz NO dirigida)"<<std::endl;
        std::cout<<"6. Salir"<<std::endl;
        std::cout<<"Ingrese su opcion: ";
        std::cin>>num;
        std::cout<<std::endl;
        if(num == 1){
            desplegarAdyacencia(matriz);
        }else if (num == 2){
            desplegarIncidencia(matrizinci);
        }else if (num == 3){
            desplegarAdyacencia(matrizdiri);
        }else if (num == 4){
            desplegarIncidencia(matrizincidiri);
        }else if (num == 5){
            int vertice = 0;
            std::cout<<"Ingrese el vertice a evaluar: ";
            std::cin>>vertice;

            vertice = vertice - 1; //-1 porque las matrices se ven desde 0 en adelante, no de 1 en adelante
            std::cout<<"-----> El vertice es de grado "<<gradovertice(vertice, matriz)<<"<-----"<<std::endl;
        }
    }while(num != 6);

    return 0;
}