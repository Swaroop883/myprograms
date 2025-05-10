#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(float *arr, int index1, int index2) { 
    float temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
} 


int main(){
    char file_name[100];
    scanf("%s",file_name);
    
    FILE *file = fopen(file_name,"r");
    char ch;
    char fs[10000];
    int a=0;
    int dot=0;
    int c=32;
    float num=0;
    float arr[100];
    int len=0;
    int nd=0;
    int minus = 0;
    while((ch = fgetc(file)) != EOF){
        if(ch=='-'){
            minus=1;
            continue;
        }
        if((48<=ch &&  ch <= 57) || (ch==46 && dot==0 && num != 0)){
            if(ch!='.'){
                num += (ch-48)*pow(10,c--);
                if(dot==1){
                    nd++;
                }
            }else{
                dot++;
            }
        }else if(num != 0 && minus==0){
            num = num/pow(10,c+1+nd);
            arr[len++]=num;
            c=32;
            num=0;
            dot=0;
            nd=0;
        }else{
            minus=0;
            num=0;
        }
        fs[a++] = ch;
    }
    fs[a] = '\0';
    
    float arr1[100];
    int al=0;
    int check=0;
    for(int i=0; i<len; i++){
        check=0;
        for(int j=0; j<al; j++){
            if(arr[i]==arr1[j])check++;
        }
        if(check==0){
            arr1[al++]=arr[i];
        }
    }
    for(int i=0; i<al; i++){
        for(int j=0; j<al-1; j++){
            if(arr1[j]>arr1[j+1]){
                swap(arr1,j,j+1);
            }
        }
    }
    
    for(int i=0; i<al; i++){
        printf("%g\n",arr1[i]);
    }
    
}