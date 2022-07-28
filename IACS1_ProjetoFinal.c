#include <stdio.h>
#include <stdlib.h>

#define MAX 50

//Chamadas das funcoes
int menu();
void typeNum();
void binario();
void octal();
void alternarSistema();
void endLoop();

//Variaveis globais
int num, choice;
char alternar, encerrar;

int main(){
    do{
        choice = menu();
        if((choice < 1) || (choice > 2)){
            printf("\nESCOLHA INVALIDA.\n\n");
            system("PAUSE");
        }
        switch(choice){
            case 1:
                typeNum();
                binario();
                alternarSistema();
                if((alternar == 's') || (alternar == 'S')){
                    octal();
                }
                endLoop();
                break;
            case 2:
                typeNum();
                octal();
                alternarSistema();
                if((alternar == 's') || (alternar == 'S')){
                    binario();
                }
                endLoop();
                break;
        }
    }while((encerrar != 's') && (encerrar != 'S'));

    printf("\nEncerrando o programa . . .\n");
    system("PAUSE");
    return 0;
}

//Menu de opcoes
int menu(){
    system("CLS");
    printf("MENU DE OPCOES\n");
    printf("1 - Binario\n");
    printf("2 - Octal\n");
    printf("Informe para qual deseja converter: ");
    scanf("%d", &choice);
    return choice;
}

//Insercao do valor decimal
void typeNum(){
    if(choice == 1){
        printf("\nCONVERSAO PARA BINARIO\n\n");
    }
    else{
        printf("\nCONVERSAO PARA OCTAL\n\n");
    }

    printf("Insira um valor inteiro em decimal: ");
    scanf("%d", &num);
    return num;
}

//Conversao de decimal para binario
void binario(){
    //Variaveis locais
    int i, j, copy = num, vetorBinario[MAX];

    //Conversao
    for(i = 0; copy > 0; i++){
        vetorBinario[i] = copy % 2;
        copy /= 2;
    }

    //Saida
    printf("\n%d EM BINARIO: ", num);
    for(j = i - 1; j >= 0; j--){
        printf("%d", vetorBinario[j]);
    }

    printf("\n\n");
}

//Conversao de decimal para octal
void octal(){
    //Variaveis locais
    int i, j, copy = num, vetorOctal[MAX];

    //Conversao
    for(i = 0; copy > 0; i++){
        vetorOctal[i] = copy % 8;
        copy /= 8;
    }

    //Saida
    printf("\n%d EM OCTAL: ", num);
    for(j = i - 1; j >= 0; j--){
        printf("%d", vetorOctal[j]);
    }

    printf("\n\n");
}

//Opcao de alternar entre sistemas para converter o valor decimal ja inserido
void alternarSistema(){
    getchar();
    if(choice == 1){
        printf("Converter o mesmo valor para octal (S/N)? ");
    }
    else{
        printf("Converter o mesmo valor para binario (S/N)? ");
    }
    scanf("%c", &alternar);
    while((alternar != 's') && (alternar != 'S') && (alternar != 'n') && (alternar != 'N')){
        getchar();
        if(choice == 1){
            printf("\nERRO: Informe uma escolha valida. Converter para octal (S/N)? ");
        }
        else{
            printf("\nERRO: Informe uma escolha valida. Converter para binario (S/N)? ");
        }
        scanf("%c", &alternar);
    }
    return alternar;
}

//Opcao de encerrar o programa
void endLoop(){
    getchar();
    printf("Deseja encerrar o programa (S/N)? ");
    scanf("%c", &encerrar);
    while((encerrar != 's') && (encerrar != 'S') && (encerrar != 'n') && (encerrar != 'N')){
        getchar();
        printf("\nERRO: Informe uma escolha valida. Encerrar programa (S/N)? ");
        scanf("%c", &encerrar);
    }
    return encerrar;
}
