#include <iostream>
//Joaquin Flores Alarcon - P702
const int N = 7; 
const int aris = 8; //aristas, contadas por el dibujo del grafo

void desplegarmatrizadya(int matriz[N][N]){
    std::cout<<"Matriz de adyacencia:"<<std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<N; j++){
            std::cout<<matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void desplegarmatrizinci(int matriz[N][aris]){
    std::cout<<"Matriz de incidencia:"<<std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<aris; j++){
            std::cout<<matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

bool vecinos(int matriz[][N], int v){
    int contador = 0;
    for(int j = 0; j<N; j++){
            if(v == j && matriz[v][j] == 1){
                contador += 2;
            }else if (matriz[v][j] == 1){
                contador += 1;
            }
        }
    if (contador >= 1){
        return true;
    } else{
        return false;
    }
}

int main() {
    int matrizadya[N][N] = {0};
    
    matrizadya[0][1] = 1;
    matrizadya[1][0] = 1;
    
    matrizadya[1][2] = 1;
    matrizadya[2][1] = 1;
    
    matrizadya[2][3] = 1;
    matrizadya[3][2] = 1;
    
    matrizadya[3][4] = 1;
    matrizadya[4][3] = 1;
    
    matrizadya[4][5] = 1;
    matrizadya[5][4] = 1;
    
    matrizadya[4][4] = 1;
    
    matrizadya[5][6] = 1;
    matrizadya[6][5] = 1;
    
    matrizadya[1][3] = 1;
    matrizadya[3][1] = 1;
    
    //fin matriz adyacencia
    
    int matrizinci[N][aris] = {0};
    // matrizinci [vertice][arista]
    matrizinci[0][0] = 1; // todo esto es a1
    matrizinci[1][0] = 1;
    
    matrizinci[1][1] = 1; //a2
    matrizinci[2][1] = 1; 
    
    matrizinci[2][2] = 1; //a3
    matrizinci[3][2] = 1;
    
    matrizinci[3][3] = 1; //a4
    matrizinci[4][3] = 1;
    
    matrizinci[4][5] = 1; //a5
    matrizinci[5][4] = 1;
    
    matrizinci[5][5] = 2; //a6
    
    matrizinci[5][6] = 1; //a7
    matrizinci[6][6] = 1;
    
    matrizinci[1][7] = 1; //a8
    matrizinci[3][7] = 1;
    
    
    desplegarmatrizadya(matrizadya);
    desplegarmatrizinci(matrizinci);
    
    int vertice = 0;
    
    std::cout<<"Ingrese el vértice donde busca vecinos: ";
    std::cin>>vertice;
    
    vertice = vertice - 1; //esto porque no se cuenta como 1 2 3 4... etc en la matriz, empieza desde el 0 1 2 3... etc
    
    if(vecinos(matrizadya, vertice)){
        std::cout<<std::endl<<"Si hay vecinos en ese vértice!"<<std::endl;
    }else{
        std::cout<<std::endl<<"No hay vecinos en ese vértice :C"<<std::endl;
    }
    return 0;
}