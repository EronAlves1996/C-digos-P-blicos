/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

struct impostos 
{
    float faixasIR[5][3];
    float faixasINSS[4][3];
};

int main()
{
    // Calculo de impostos e tributos de um funcionário
    float SalarioBruto = 0, SA_IR = 0, INSS = 0, IR = 0, SalarioLiquido = 0, ValeTransporte = 0, BaseINSS = 0;
    int IndiceINSS = 0, IndiceIR = 0;
    char defVT;
    struct impostos impsal;
    
    impsal.faixasIR[0][0] = 1903.98;
    impsal.faixasIR[1][0] = 2826.25;
    impsal.faixasIR[2][0] = 3751.05;
    impsal.faixasIR[3][0] = 4664.68;
    impsal.faixasIR[4][0] = 4664.69;
    impsal.faixasIR[0][1] = 0;
    impsal.faixasIR[1][1] = 0.075;
    impsal.faixasIR[2][1] = 0.15;
    impsal.faixasIR[3][1] = 0.225;
    impsal.faixasIR[4][1] = 0.275;
    impsal.faixasIR[0][2] = 0;
    impsal.faixasIR[1][2] = 142.80;
    impsal.faixasIR[2][2] = 354.80;
    impsal.faixasIR[3][2] = 636.13;
    impsal.faixasIR[4][2] = 869.36;
    
    impsal.faixasINSS[0][0] = 1100.00;
    impsal.faixasINSS[1][0] = 2203.48;
    impsal.faixasINSS[2][0] = 3305.22;
    impsal.faixasINSS[3][0] = 6433.57;
    impsal.faixasINSS[0][1] = 0.075;
    impsal.faixasINSS[1][1] = 0.09;
    impsal.faixasINSS[2][1] = 0.12;
    impsal.faixasINSS[3][1] = 0.14;
    impsal.faixasINSS[0][2] = 0;
    impsal.faixasINSS[1][2] = 16.5;
    impsal.faixasINSS[2][2] = 82.6;
    impsal.faixasINSS[3][2] = 148.71;
    
    printf("Insira o valor do salário bruto: \n");
    scanf("%f", &SalarioBruto);
    
    while ((defVT != 'S') && (defVT != 'N'))
    {
        printf("Funcionário optou pelo Vale Tranporte? [S/N] \n");
        scanf(" %c", &defVT);
        if ((defVT != 'S') && (defVT != 'N'))
        {
            printf("Opção Inválida! \n");
        }
    }
    
    if (SalarioBruto <= impsal.faixasINSS[0][0])
    {
        IndiceINSS = 0;
    }
    else
    {
        if ((SalarioBruto > impsal.faixasINSS[0][0]) && (SalarioBruto <= impsal.faixasINSS[1][0]))
        {
            IndiceINSS = 1;
        }
        else
        {
            if ((SalarioBruto > impsal.faixasINSS[1][0]) && (SalarioBruto <= impsal.faixasINSS[2][0]))
            {
                IndiceINSS = 2;
            }
            else
            {
                IndiceINSS = 3;
            }
        }
    }
    
    if (IndiceINSS == 3)
    {
        BaseINSS = impsal.faixasINSS[3][0];
    }
    else
    {
        BaseINSS = SalarioBruto;
    }
    
    INSS = (BaseINSS * impsal.faixasINSS[IndiceINSS][1]) - impsal.faixasINSS[IndiceINSS][2];
    SA_IR = SalarioBruto - INSS;
    
    if(SA_IR <= impsal.faixasIR[0][0])
    {
        IndiceIR = 0;
    }
    else
    {
        if ((SA_IR > impsal.faixasIR[0][0]) && (SA_IR <= impsal.faixasIR[1][0]))
        {
            IndiceIR = 1;
        }
        else
        {
            if((SA_IR > impsal.faixasIR[1][0]) && (SA_IR <= impsal.faixasIR[2][0]))
            {
                IndiceIR = 2;
            }
            else
            {
                if((SA_IR > impsal.faixasIR[1][0]) && (SA_IR <= impsal.faixasIR[2][0]))
                {
                IndiceIR = 2;
                }
                else
                {
                    if((SA_IR > impsal.faixasIR[2][0]) && (SA_IR <= impsal.faixasIR[3][0]))
                    {
                        IndiceIR = 3;
                    }
                    else
                    {
                        IndiceIR = 4;
                    }
                }
            }
        }
    }
    IR = (SA_IR * impsal.faixasIR[IndiceIR][1]) - impsal.faixasIR[IndiceIR][2];
    if (defVT == 'S')
    {
        ValeTransporte = SalarioBruto * 0.06;
    }
    SalarioLiquido = SalarioBruto - INSS - IR - ValeTransporte;
    printf("\nSalario Bruto = %.2f", SalarioBruto);
    printf("\nDesconto INSS = %.2f", INSS);
    printf("\nDesconto IR = %.2f", IR);
    printf("\nDesconto Vale Transporte = %.2f", ValeTransporte);
    printf("\nSalario Liquido = %.2f", SalarioLiquido);
}


