//Gerardo Galan Garzafox (ITC)
//A00821196
//Algoritmos
//Tarea 2.2

#include <iostream>
#include <chrono>       //std::chrono
#include <thread>
#include <fstream>      //std::ifstream
#include <vector>       //std::vector
#include <algorithm>    //std::sort
#include <list> 
#include <string>
#include <cstdlib>

/********************************
 * PROBLEMA #1
 * *****************************/
void problema1(std::string archivo){
    std::cout<<std::endl<<std::endl<<"\t########PROBLEMA 1########"<<std::endl<<std::endl;
    //Inicio de cronometro
    auto start = std::chrono::high_resolution_clock::now();
///////////////////////////////////////////////////////////////////
    int grade=0,arr[100] = {0},mode=0, common_grade=0,total_grades=0;;
    std::ifstream grades;
    grades.open(archivo);
//ciclo para leer datos de archivo
//O(n)
    while(! grades.eof()){
        grades>>grade;
        total_grades++;
        (grade == 100 ? arr[0]++ : arr[grade]++);
    }
//ciclo para encontrar dato con mas repeticiones
//O(1)
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
    std::cout<<"microseg: "<<duration.count()<<std::endl;
}

/********************************
 * PROBLEMA #2
 * *****************************/

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
//O(n)
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
//Ordenamos el vector con el algoritmo stl 
//O(nlogn)
std::sort(vec.begin(),vec.end());

for(int i = 1;i<vec.size();i++){
    //si el dato se sigue repitiendo
    if(same==vec[i]){
        ++cont;
        //condicional para obtener el dato que mas se repite
        if(cont>mode){
            common_grade=vec[i];
            mode=cont;
        }
    //si el dato para de repetirse
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
    std::cout<<"microseg: "<<duration.count()<<std::endl;
}




/********************************
 * HASH Data Structure Class
 * *****************************/
class Hash{
    private:        
        struct node{
                int number=0;
                int cont=0;
            };  
        std::array<std::list<node>,10>table;
    public:
        
//        void insertItem(int x);
//        void deleteItem(int key);
        int hashFunction(int x){
            return(x%10);
        }
        void insertGrade(int grade);
        void displayHash();
        void findMean();
};



// void Hash::insertItem(int key){
//     int index=hashFunction(key);
//     node n;
//     n.number=key;
//     table[index].push_back(n);
// }


void Hash::insertGrade(int grade){
    int index=hashFunction(grade);
    node n;//node has a grade and a repetirion counter
    n.number=grade;
    std::list<node>::iterator i;
    for(i = table[index].begin();i !=table[index].end();i++){
        //si encontramos la calificacion, hacemos un incremento al contador
        if(i->number == n.number){
            i->cont++;
            break;
        }
    }
    if(i == table[index].end()){
        n.cont=1;
        table[index].push_back(n);
    }

}

void Hash::findMean(){
    node mode;
    mode.number=table[0].begin()->number;
    mode.cont=table[0].begin()->cont;
    std::list<node>::iterator i;
    //O(10)
    for(int x=0;x<10;x++){
        //peor caso O(10)
        for(i = table[x].begin();i !=table[x].end();i++){
            if(i->cont>mode.cont){
                mode.number=i->number;
                mode.cont=i->cont;
            }
        }
    }
    std::cout<<"Calificacion: "<<mode.number<<"\n";
    std::cout<<"#Repeticiones: "<<mode.cont<<"\n";
}

// void Hash::deleteItem(int key){
//     int index=hashFunction(key);
//     std::list<node>::iterator i;
//     for (i=table[index].begin();i !=table[index].end();i++){
//         if(*i == key){
//             break;
//         }
//     }
//     if(i!=table[index].end()){
//         table[index].erase(i);
//     }
// }

void Hash::displayHash(){
    for(int i=0;i<10;i++){
        std::cout<<i;
        for (auto x:table[i]){
            std::cout<<"-->"<<x.number<<"("<<x.cont<<")";
        }
        std::cout<<std::endl;
    }
}
/********************************
 * PROBLEMA 3
 * *****************************/
void problema3(std::string archivo){
    std::cout<<std::endl<<std::endl<<"\t########PROBLEMA 3########"<<std::endl<<std::endl;
        //Inicio de cronometro
    auto start = std::chrono::high_resolution_clock::now();
///////////////////////////////////////////////////////////////////
int total_grades=0,grade=0;
std::ifstream grades;
Hash miHash;
grades.open(archivo);

//Insertar datos en el vector
//O(n)
while(! grades.eof()){
grades>>grade;
//peor caso O(10)
miHash.insertGrade(grade);
total_grades++;
}
     // miHash.displayHash();
      miHash.findMean();
std::cout<<"Datos de Archivo: "<<total_grades<<"\n";
//////////////////////////////////////////////////////////////////
    //Final de cronometro
    auto stop = std::chrono::high_resolution_clock::now();

    //calculo de timepo de solucion en microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<"microseg: "<<duration.count()<<std::endl;
}

/********************************
 * MAIN FUNCTION
 * *****************************/
int main(){
    std::cout<<std::endl<<std::endl<<"\t******CASO #1******";
    std::cout<<std::endl<<"\t******calif1.txt******"<<std::endl<<std::endl;
    problema1("calif1.txt");
    problema2("calif1.txt");
    problema3("calif1.txt");
    std::cout<<std::endl<<std::endl<<"\t******CASO #2******";
    std::cout<<std::endl<<"\t******calif2.txt******"<<std::endl<<std::endl;
    problema1("calif2.txt");
    problema2("calif2.txt");
    problema3("calif2.txt");
    std::cout<<std::endl<<std::endl<<"\t******CASO #3******";
    std::cout<<std::endl<<"\t******calif3.txt******"<<std::endl<<std::endl;
    problema1("calif3.txt");
    problema2("calif3.txt");
    problema3("calif3.txt");


    // int num_archivo=0;
    // std::string archivo, opciones[3]={"calif1.txt","calif2.txt","calif3.txt"};
    // do{
    // std::cout<<"Que archivo quieres?\n1)calif1.txt\n2)calif2.txt\n3)calif3.txt\n\n";
    // std::cin>>num_archivo;

    // }while(! num_archivo>3||num_archivo<1);
    // archivo=opciones[num_archivo-1];
    // problema1(archivo);
    // problema2(archivo);
    //problema3(archivo);

}