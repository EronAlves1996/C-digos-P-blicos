/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calcInvA(float inv, float m){
    return inv * m * 0.02;
}
float calcInvB(float inv, float m){
    return inv * m * 0.008;
}

int main()
{
    float investimento = 0;
    float meses = 0, juros = 0;
    char plano;
    printf("Bem vindo ao programa de cálculo de Juros!! \n Primeiro insira o valor a ser investido:\n");
    scanf("%f", &investimento);
    printf("Insira o tempo de aplicação:\n");
    do{
        scanf("%f", &meses);
        if(meses<12){
            printf("Valor inválido, digite um tempo válido, mínimo é 12 meses: \n");
        }
    }
    while(meses < 12);
    
    printf("Escolha o seu plano: A ou B");
    do{
        scanf(" %c", &plano);
        if(plano == 'A'){
            if(meses < 24)
            {
                printf("Opção inválida! Para opção A mínimo é de 24 meses!!");
                plano = 'c';
            }
            else
            {
                juros = calcInvA(investimento, meses);
            }
        }
        else
        {
            if(plano == 'B')
            {
                juros = calcInvB(investimento, meses);
            }
            else
            {
                printf("Opção Inválida, escolha entre A ou B!");
            }
        }
    }
    while(!(plano == 'A' || plano == 'B'));
    printf("O valor do juros é %.2f", juros);
    return 0;
}
