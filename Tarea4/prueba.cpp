#include <iostream>

using namespace std;





void merge(int *a, int *b, int low, int pivot, int high){
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;

    while((h<=pivot)&&(j<=high)){
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }else{
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot){
        for(k=j; k<=high; k++){
            b[i]=a[k];
            i++;
        }
    }else{
        for(k=h; k<=pivot; k++){
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++){
        a[k]=b[k];
    } 
}
void mergesort(int *a, int*b, int low, int high, int &comp){
    int pivot;
    if(low<high){
        comp++;
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot,comp);
        mergesort(a,b,pivot+1,high,comp);
        merge(a,b,low,pivot,high);
    }
}

void copyArr(int arr[], int *arrb, int cap){
    for(int i=0;i<cap;i++){
        arr[i]=arrb[i];
    }
    return;
}


int main(){
    int datos [] = {6,7,5,8,4,9,2,1,3};
    int datos2 [] = {81,42,93,24,15,36,76,57,99};
    int num = sizeof(datos)/sizeof(*datos);
    int arr[num];
    copyArr(arr,datos,num);
    // for(int i = 0; i<num;i++){
    //     arr[i]=datos[i];
    //     cout<<arr[i]<<endl;
    // }
    // datos[0]=9;
    // datos[num-1]=0;
    for(int i = 0; i<num;i++){
        cout<<arr[i]<<endl;
    }
    copyArr(arr,datos2,num);
    cout<<endl;
    for(int i = 0; i<num;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}