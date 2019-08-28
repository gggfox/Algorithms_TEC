//Gerardo Galan Garzafox (ITC)
//A00821196
//Algoritmos
//Tarea 2.2

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <algorithm>

//problema 1 de la tarea 2, solucion con arreglo
void problema1(std::string archivo){
    std::cout<<std::endl<<std::endl<<"\t########PROBLEMA 1########"<<std::endl<<std::endl;
    //Inicio de cronometro
    auto start = std::chrono::high_resolution_clock::now();
///////////////////////////////////////////////////////////////////
    int grade=0,arr[100] = {0},mode=0, common_grade=0,total_grades=0;;
    std::ifstream grades;
    grades.open(archivo);
//ciclo para leer datos de archivo
    while(! grades.eof()){
        grades>>grade;
        total_grades++;
        (grade == 100 ? arr[0]++ : arr[grade]++);
    }
//ciclo para encontrar dato con mas repeticiones
    for (int i = 1;i<100;i++){
        if(arr[i]>mode){
            mode=arr[i];
            common_grade=i;
        }
       // std::cout<<i<<(i<10 ? ": \t\t" : ": \t")<<arr[i]<<"\n";
    }
  //  std::cout<<"100: \t"<<arr[0]<<"\n";
    if(arr[0]>mode){
        mode=arr[0];
        common_grade=100;
    }
    
 
std::cout<<"Calificacion: "<<common_grade<<"\n";
std::cout<<"#Repeticiones: "<<mode<<"\n";
std::cout<<"Datos de Archivo: "<<total_grades<<"\n";
//////////////////////////////////////////////////////////////////
    //Final de cronometro
    auto stop = std::chrono::high_resolution_clock::now();

    //calculo de timepo de solucion en microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<"ms: "<<duration.count()<<std::endl;
}

void problema2(std::string archivo){
    std::cout<<std::endl<<std::endl<<"\t########PROBLEMA 2########"<<std::endl<<std::endl;
        //Inicio de cronometro
    auto start = std::chrono::high_resolution_clock::now();
///////////////////////////////////////////////////////////////////
int grade = 0,same=0,mode=0, cont=0,i=0,common_grade=0,total_grades=0;
std::vector<int> vec;
std::ifstream grades;
grades.open(archivo);
//Insertar datos en el vector
while(! grades.eof()){
grades>>grade;
vec.push_back(grade);
total_grades++;
// std::cout<<i<<": "<<vec[i]<<"\n";
// i++;
}

std::cout<<std::endl;
cont=1;
same=vec[0];
std::sort(vec.begin(),vec.end());
for(int i = 1;i<vec.size();i++){
    if(same==vec[i]){
        ++cont;
        if(cont>mode){
            common_grade=vec[i];
            mode=cont;
        }
    }else{
        same=vec[i];
        cont=1;
    }
    
    // std::cout<<i<<": "<<vec[i]<<"\n";
}

std::cout<<"Calificacion: "<<common_grade<<"\n";
std::cout<<"#Repeticiones: "<<mode<<"\n";
std::cout<<"Datos de Archivo: "<<total_grades<<"\n";
//////////////////////////////////////////////////////////////////
    //Final de cronometro
    auto stop = std::chrono::high_resolution_clock::now();

    //calculo de timepo de solucion en microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<"ms: "<<duration.count()<<std::endl;
}

int main(){
    int num_archivo=0;
    std::string archivo, opciones[3]={"calif1.txt","calif2.txt","calif3.txt"};
    do{
    std::cout<<"Que archivo quieres?\n1)calif1.txt\n2)calif2.txt\n3)calif3.txt\n\n";
    std::cin>>num_archivo;

    }while(! num_archivo>3||num_archivo<1);
    archivo=opciones[num_archivo-1];
    problema1(archivo);
    problema2(archivo);

}