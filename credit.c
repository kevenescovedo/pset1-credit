#include <stdio.h>
#include <cs50.h>

int lenght (long numero) {
    int tamanho  = 0;
    do
    {
        tamanho++;
        numero = numero / 10;
    } while(numero > 0);
    return tamanho;
}


int get_first_digits(int tamanho, long numero, int qtd) {
    long potencia = 0;

    if(tamanho > 0 && tamanho <= qtd){
        return numero;
    }

    int x = 0;
    while(x < (tamanho - qtd))
    {
        x++;
        if(potencia == 0){
           potencia = 10;
        }
        else {
            potencia = potencia * 10;
        }

    }


    int result = numero / potencia;
    return result;
}

bool number_card_isvalid(long numero_cartao, int tamanho) {
    long n = numero_cartao;
    int resultado_soma_multipla_2 = 0;
    int soma_digitos = 0;
    bool skip = false;

    while(n > 0) {

    if(skip) {
      int ultimo_numero  = n % 10;

      int multiplica_digito_Por_2 = ultimo_numero * 2;

      if(multiplica_digito_Por_2  >= 10) {
        int ultimo_digito = multiplica_digito_Por_2 % 10;
        int primeiro_digito = multiplica_digito_Por_2 / 10;
       multiplica_digito_Por_2 = primeiro_digito + ultimo_digito;
      }

     resultado_soma_multipla_2 = resultado_soma_multipla_2 +  multiplica_digito_Por_2;
     skip = false;


    } else {
        soma_digitos = soma_digitos + (n % 10);
        skip = true;
    }

    n = n / 10;

    }

     int resultado = resultado_soma_multipla_2  + soma_digitos;

     if(resultado % 10 == 0) {
        return true;
     } else {
        return false;

     }



}


int main (void) {
long numero_cartao = get_long("Digite o número do Cartão: ");
int tamanho = lenght(numero_cartao);
int dois_digitos = get_first_digits(tamanho, numero_cartao, 2);
int um_digito = get_first_digits(tamanho, numero_cartao, 1);



if(tamanho == 15 && (dois_digitos == 34 || dois_digitos == 37) && number_card_isvalid(numero_cartao, tamanho) ) {
   printf("AMERICAN EXPRESS\n");
} else if(tamanho == 16 && ( dois_digitos >= 51 && dois_digitos <= 55) && number_card_isvalid(numero_cartao, tamanho)) {
    printf("MASTERCARD\n");
}else if((tamanho == 13 || tamanho == 16) && um_digito == 4 && number_card_isvalid(numero_cartao, tamanho)) {
 printf("VISA\n");
} else {
    printf("INVALID\n");
}




}

