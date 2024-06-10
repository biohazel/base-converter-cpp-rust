#include <iostream>
using namespace std;

/*American Standard Code for Information Interchange-ASCII eh uma 
codificacao de caracteres padraoque atribui valores numericos a letras, 
numeros, sinais de pontuacao e outros caracteres. Estes valores sao representados
por numeros inteiros de 0 a 127.

'0' = 48
'1' = 49
'2' = 50
'3' = 51
'4' = 52
'5' = 53
'6' = 54
'7' = 55
'8' = 56
'9' = 57
'A' = 65
'B' = 66
'C' = 67
'D' = 68
'E' = 69
'F' = 70

Função para converter um número de uma outra base para decimal. 
O char* eh um pointer para um array de caracteres que representa 
o numero na base dada.*/

long long toDecimal(const char* num, int base) {
    long long result = 0;
//Loop itera sobre cada caractere da string ate encontrar o terminador nulo. 
    for (int i = 0; num[i] != '\0'; i++) {
        result = result * base;
        if (num[i] >= '0' && num[i] <= '9')
            result += num[i] - '0'; //Converte para integer.
        else if (num[i] >= 'A' && num[i] <= 'F')
            result += num[i] - 'A' + 10; //Converte para integer. 
        else if (num[i] >= 'a' && num[i] <= 'f')
            result += num[i] - 'a' + 10;
    }
    return result;
}

/*Função para converter um número decimal para outra base. Um buffer de
caracteres eh uma area da memoria utilizada para armazenar temporariamente uma 
sequencia de caracteres, para manipular strings e dados de texto de maneira eficiente*/
void fromDecimal(long long num, int base, char* buffer) {
    const char* digits = "0123456789ABCDEF";
/*Buffer temporario de 64 bits + char nulo '\0'*/
    char temp[65]; 
    int i = 0;
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0'; //Marca final da string
        return;
    }
    while (num > 0) {
/*No temp[i++] o digito mapeado eh armazenado no buffer tmeporario temp
e o indice eh incrementado. O modulo num % base mapeia o valor do digito
para o caractere correspondente. Ex. 10 eh mapeado para 'A' se a base for 10*/
        temp[i++] = digits[num % base];
        num /= base; //Divisao inteira, truncando o floating point
    }
    int j = 0;
    while (i > 0) {
/*Reversao da ordem dos digitos. Copia os caracteres armazenados no buffer 
temporario'temp' para o buffer 'buffer' na ordem correta */
        buffer[j++] = temp[--i];
    }
    buffer[j] = '\0'; //Marca final da string valida
}

int main() {
    char num[65];
    char base_antes, base_depois;
    char resultado[65];

    cout << "Digite o número que será convertido, e em que base ele está." << endl;
    cout << "Opções de base: [D]ecimal, [H]exadecimal ou [B]inária." << endl;

    cin >> num >> base_antes;
    cout << "Agora digite para qual base deseja converter." << endl;
    cin >> base_depois;

    int base1 = (base_antes == 'D' || base_antes == 'd') ? 10 : (base_antes == 'H' || base_antes == 'h') ? 16 : 2;
    int base2 = (base_depois == 'D' || base_depois == 'd') ? 10 : (base_depois == 'H' || base_depois == 'h') ? 16 : 2;
    long long num_dec = toDecimal(num, base1);

    if (base2 == 10) {
        cout << "O resultado da conversão é: " << num_dec << endl;
    } else {
        fromDecimal(num_dec, base2, resultado);
        cout << "O resultado da conversão é: " << resultado << endl;
    }

    return 0;
}
