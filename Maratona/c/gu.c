#include <stdio.h>
 
int main() {
    
    int cem=0, cinq=0, vinte=0, dez=0, cinco=0, dois=0, um=0, m50=0, m25=0, m10=0, m05=0, m01=0;
    double x;
    scanf("%lf",&x);
    
    cem = x/100;
    x = x - 100 * cem;
    cinq = x/50;
    x = x - 50 * cinq;
    vinte = x/20;
    x = x - 20 * vinte;
    dez = x/10;
    x = x - 10 * dez;
    cinco = x/5;
    x = x - 5 * cinco;
    dois = x/2;
    x = x - 2 * dois;
    um = x;
    x = x - 1 * um;
    m50 = x/0.5;
    x = x - 0.5 * m50;
    m25 = x/0.25;
    x = x - 0.25 * m25;
    m10 = x/0.1;
    x = x - 0.1 * m10;
    m05 = x/0.05;
    x = x - 0.05 * m05;
    m01 = x/0.01;
    x = x - 0.01 * m01;
    
    printf("NOTAS:\n");
    printf("%d nota(s) de R$100.00\n",cem);
    printf("%d nota(s) de R$50.00\n",cinq);
    printf("%d nota(s) de R$20.00\n",vinte);
    printf("%d nota(s) de R$10.00\n",dez);
    printf("%d nota(s) de R$5.00\n",cinco);
    printf("%d nota(s) de R$2.00\n",dois);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$1.00\n",um);
    printf("%d moeda(s) de R$0.50\n",m50);
    printf("%d moeda(s) de R$0.25\n",m25);
    printf("%d moeda(s) de R$0.10\n",m10);
    printf("%d moeda(s) de R$0.05\n",m05);
    printf("%d moeda(s) de R$0.01\n",m01);
    
    return 0;
}