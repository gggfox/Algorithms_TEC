//¿Cuántos árboles binarios distintos se pueden formar con ‘n’ nodos?

#include<iostream>
#include<vector>

using namespace std;

void ABDistintos(){
    int n=0,accum=0,start=2;
    vector<int> c={1,1};
    cout<<"cuantos nodos tiene un arbol (maximo 19)"<<endl;
    cin>>n;
    if(n>=2){
        for(int e = 2;e<=n;e++){
            for(int i=0;i<=start;i++){
                accum+=c[i]*c[start-i-1];
            }
            c.push_back(accum);
            accum=0;
            start++;
        }
        cout<<"Sepueden hacer "<<c[n]<<" arboles distintos."<<endl;
        c.clear();
    }else{
        cout<<1<<endl;
    }
}

int main(){
string repetir;
do{
    ABDistintos();
    cout<<"¿Quieres repetir el programa?[s/n]"<<endl;
    cin>>repetir;
}while(repetir!="n");
return 0;
}