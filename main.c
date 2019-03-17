/*
@Name   Jonathan Silva
@Data   16/03/2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Prototypes:
int binaryToDecimal(int size, int vector_Binary[]);
long long int diggitAccount(long long int value);
void separeteInt(long long int value, int size, int*);



int main(){
    long long int value = 1001001000;
    int size = diggitAccount(value);
    printf("size ->%d\n",size);
    int * vector_Binary = malloc (sizeof(int)*size);
    separeteInt(value, size, vector_Binary);
    int decimal  = binaryToDecimal(size, vector_Binary);
    printf("decimal =>> %d\n", decimal);
}

/*@Brief    Converte o número binário para decimal
@param  *vector_Binary  Vetor de Binários
@param  size    numero de digitos no número binário
**/
int binaryToDecimal(int size, int vector_Binary[]){
    int nSize = size; // nSize = new size
    int decimal = 0;
    for(int i = 0; i < size; i++){
        nSize--;
        decimal = vector_Binary[i]*pow(2,nSize) + decimal;
        printf("decimal value =>%d\n",decimal);
    }

    return decimal;
}


/*
}
@Brief  conta a quantida de digitos do valor passado
@param value    Valor que vai ter os dígitos contados
**/
long long int diggitAccount(long long int value){
     int diggitAccount = 0;
    if (value == 0)
        diggitAccount = 1;
    else
        while(value > 0){
            diggitAccount++;
            value = value / 10;
        }
return diggitAccount;
}


/*
@brief  Sepera os digitos do valor inteiro e os aloca em um vetor.
@param  value   valor q vai ser alocado
@param  size    tamanho do valor(soma dos seus digitos)
@param  *vetor_Binary vetor de binários que vai receber os digitos de value
**/
void separeteInt(long long int value, int size, int *vector_Binary){
    int i = 0;
    while(value > 0){
        long long int nValue = value%10;
        value = value/10;
        vector_Binary[size-1] = nValue;
        size--;
    }
}