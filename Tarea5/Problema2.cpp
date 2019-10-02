#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string PreguntarArchivo(){
    string archivo;
    cout<<"Dime el nombre del archivo"<<endl;
    cin>>archivo;
    return archivo;
}

vector<string> Cities(string archivo){
    string city ="";
    ifstream cities;
    vector<string> cityVector;
    cities.open(archivo);
    while(!cities.eof()){
        cities>>city;
        if(city=="#")break;
        cityVector.push_back(city);
    }
    return cityVector;
}

int getIndex(vector<string> cities,string city){
    for(int i = 0;i<cities.size();i++){
        if(cities[i]==city)return i;
    }
    return 0;
}

//Algoritmo de FLOYD
vector<vector<int>> AirRoutes(string file, vector<string> cities){
    string pointA,pointB;
    int tam=cities.size(), distance=0,i=0,j=0,infinito=9999;
    //creamos una matriz con valores de 9999 despues igualamos la diagonal a zero
    vector<vector<int>> matrix(tam);
    for(i;i<tam;i++)matrix[i].resize(tam,infinito);
    for(i=0;i<tam;i++)matrix[i][i]=0;

    //leemos un archivo hasta donde hay un hashtag y nos detenemos
    ifstream routes;
    routes.open(file);
    while(!routes.eof()){
        routes>>pointA;
        if(pointA=="#")break;
    }
    //ponemos los valores del archivo en las columnas y renglones que pertenecen
    while(!routes.eof()){
        routes>>pointA>>pointB>>distance;
        i=getIndex(cities,pointA);
        j=getIndex(cities,pointB);
        matrix[i][j]=distance;
        matrix[j][i]=distance;
    }
    return matrix;
}

void PrintMatrix(vector<vector<int>> matrix,vector<string> cities){
    int tam=cities.size();
    cout<<"\t";
    for(int i=0;i<tam;i++){
        cout<<cities[i][0]<<cities[i][1]<<cities[i][2]<<cities[i][3]<<"\t";
    }
    cout<<endl;
    for(int i = 0;i<tam;i++){
        cout<<cities[i][0]<<cities[i][1]<<cities[i][2]<<cities[i][3]<<"\t";
        for(int j=0;j<tam;j++){
            if(matrix[i][j]==9999){
                cout<<"···\t";
            }else{
               cout<<matrix[i][j]<<"\t"; 
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

vector<vector <int>> Floyd(vector<vector <int>> matrix){
    int n=matrix.size();
    for( int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=
                (matrix[i][j]<matrix[i][k]+matrix[k][j]?matrix[i][j]:matrix[i][k]+matrix[k][j]);
                matrix[j][i]=matrix[i][j];
            }
        }
    }
    return matrix;
}

vector<vector<int>> ShortestPath(vector<vector<int>> floyd,int tam){
    int infinito=9999;
    vector<vector<int>> lastNode(tam);
    for(int i=0;i<tam;i++)lastNode[i].resize(tam,infinito);
    for(int i=0;i<tam;i++)lastNode[i][i]=0;
    for(int k=0;k<tam;k++){
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                if(floyd[i][k]+floyd[k][j]<floyd[i][j]){
                    lastNode[i][j]=k;
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                }
            }
        }
    }
    return lastNode;
}

void Camino(vector<vector<int>> escalas, int inicio, int fin, vector<string> cities){
    int infinito=9999;
    if(escalas[inicio][fin]>=0&&escalas[inicio][fin]<infinito){
        Camino(escalas,inicio,escalas[inicio][fin],cities);
        cout<<"\t"<<cities[escalas[inicio][fin]]<<endl;
        Camino(escalas,escalas[inicio][fin],fin,cities);
    }
}

void Escalas(vector<string> cities,vector<vector<int>> escalas,vector<vector<int>> floyd){
    string puntoA,puntoB;
    cout<<"Dime la ciudad de partida."<<endl;
    cin>>puntoA;
    cout<<"Dime la ciudad destino."<<endl;
    cin>>puntoB;
    int start=getIndex(cities,puntoA);
    int end = getIndex(cities,puntoB);
    cout<<endl;
    cout<<"Costo: "<<floyd[start][end]<<endl;
    cout<<"Ruta: \t"<<cities[start]<<endl;
    Camino(escalas,start,end,cities);
    cout<<"\t"<<cities[end]<<endl;
    return;
}

void Opciones(){
    int num=0;
    cout<<"ESCRIBE EL NUMERO DE LA OPCION"<<endl;
    cout<<"1. Ruta mas economica"<<endl;
    cout<<"2. Todos los destinos de una ciudad"<<endl;
    cout<<"3. rutas optimas con cierto num3ero de escalas"<<endl;
    cin>>num;
    switch(num){
        case 1:
        cout<<"Costo: "<<endl;
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void Algorithm(){
  string archivo="pruebaTar5 AD19.txt";
  //string archivo=PreguntarArchivo();
  vector<string> ciudades=Cities(archivo);
  vector<vector<int>> matriz=AirRoutes(archivo,ciudades);
  vector<vector<int>> floyd=Floyd(matriz);
  vector<vector<int>> escalas=ShortestPath(matriz,ciudades.size());
  
  PrintMatrix(matriz,ciudades);
  PrintMatrix(floyd,ciudades);
  PrintMatrix(escalas,ciudades);
  Escalas(ciudades,escalas,floyd);
}

int main(){
    Algorithm();
    return 0;
}