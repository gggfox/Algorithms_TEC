#include <iostream>
#include <fstream>
#include <limits>
#include <cstddef>
#include <utility>

using namespace std;

int binarySearch(int *iArr, int left, int right, int x,bool isMin, int &cont){
    if(right >= left){
        cont++;
        int middle = left +(right-left)/2;
        if(iArr[middle]==x || (isMin?(iArr[middle-1]<x && iArr[middle]>x):(iArr[middle]<x && iArr[middle+1]>x))){
            return middle;
        }else if(iArr[middle]>x){
            return binarySearch(iArr,left,middle - 1,x,isMin, cont);
        }else{
            return binarySearch(iArr,middle+1,right,x,isMin, cont);
        }  
    }
    return -1;
}

void pedirMatricula(int &min,int &max){
do{
  while ((cout<<"Dime la matricula menor"<<endl)
         && !(std::cin >> min)) {
    cout << "Entrada invalida "<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  while ((cout<<"Dime la matricula mayor"<<endl)
         && !(std::cin >> max)) {
    cout << "Entrada invalida "<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}while(min>max);
}

int getFileSize(){
    int iSize=0,num=0;
    ifstream file("matriculas.txt");
    while(!file.eof()){
        file>>num;
        iSize++;
    }
    file.close();
    return iSize;
}


int *InsertInArray(int &iPos){
    int *iArr,iCap=0, iNum=0;
    iCap=getFileSize();
    iArr=new int[iCap];
    ifstream file;
    file.open("matriculas.txt");
    while(!file.eof()){
        file>>iNum;
        iArr[iCap-1]=iNum;
        iPos++;
        iCap--;
    }
    
    file.close();
    return iArr;
}

void PrintArray(int *iArray,int iMinIndex,int iMaxIndex){
    for(int i = iMinIndex; i <= iMaxIndex; i++){
        cout<<"iArray["<<i<<"]:\t"<<iArray[i]<<endl;
    }
}

bool Continuamiento(){
    string continuar;
    cout<<"¿Deseas repetir el programa? [s/n]"<<endl;
    cin>>continuar;
    if(continuar == "N" || 
       continuar == "n" ||
       continuar == "No"||
       continuar == "no"){
           return false;
    }else{
           return true;
    }
}



void Display(int MaxIndex,int MinIndex,int cont1, int cont2){
    if((MaxIndex-MinIndex) < 0){
        cout<<" No hay mariculas en este rango"<<endl;
    }else if((MaxIndex==MinIndex)&&MinIndex>=0){
        cout<<"Cantidad de matriculas en el rango: "<<1<<endl;
    }else{
        cout<<"Cantidad de matriculas en el rango: "<<MaxIndex-MinIndex+1<<endl;
    }
    cout<<"Comparaciones para encontrar el menor: "<<cont1<<endl;
    cout<<"Comparaciones para encontrar el mayor: "<<cont2<<endl;
}

void ImprimirRango(int *iArr,int MinIndex, int MaxIndex){
    string continuar;
    cout<<"¿Quieres Imprimir el Rango? [s/n]"<<endl;
    cin>>continuar;
    if(continuar == "S"  || 
       continuar == "s"  ||
       continuar == "Si" ||
       continuar == "si" ||
       continuar == "Y"  ||
       continuar == "Yes"||
       continuar == "y"  ||
       continuar == "yes"){
            PrintArray(iArr,MinIndex,MaxIndex);
    }else{
           return;
    }
}

void problema1(){
 int min=0,max=0,iPos=0, *iArr,MinIndex=0,MaxIndex=0,cont1=0,cont2=0;
 iArr=InsertInArray(iPos);//O(n)
 do{
 pedirMatricula(min,max);
 if((!(min>iArr[iPos-1]))&&(!(max<iArr[0]))){
     if(max>iArr[iPos-1])max=iArr[iPos-1];
     if(min<iArr[0])min=iArr[0];
     MinIndex=binarySearch(iArr,0,iPos,min,true,cont1);//O(logN)
     MaxIndex=binarySearch(iArr,0,iPos,max,false,cont2);//O(logN)
 }
 Display(MaxIndex,MinIndex,cont1,cont2);
 ImprimirRango(iArr,MinIndex,MaxIndex);
}while(Continuamiento()&&(MaxIndex-MinIndex)>=0);//O(n)
}

int main(){
    problema1();
    return 0;
}