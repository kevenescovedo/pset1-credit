
# PSET 1 CRÉDITO CS50 HAVERD

Este repositório contém a solução do PSET1 CREDIT

Um cartão de crédito (ou débito), é um cartão de plástico com o qual você pode pagar por bens e serviços. Impresso nesse cartão está um número que também é armazenado em um banco de dados em algum lugar, de modo que, quando o cartão for usado para comprar algo, o credor saiba a quem cobrar. Há muitas pessoas com cartões de crédito no mundo, então esses números são bem longos: American Express usa números de 15 dígitos, MasterCard usa números de 16 dígitos e Visa usa números de 13 e 16 dígitos. E esses são números decimais (0 a 9), não binários, o que significa, por exemplo, que a American Express poderia imprimir até 10 ^ 15 = 1.000.000.000.000.000 de cartões exclusivos! (Isso é, hum, um quatrilhão)

Na verdade, isso é um pouco exagerado, porque os números de cartão de crédito têm alguma estrutura. Todos os números American Express começam com 34 ou 37; a maioria dos números do MasterCard começa com 51, 52, 53, 54 ou 55 (eles também têm alguns outros números iniciais potenciais com os quais não nos preocupamos neste problema) e todos os números Visa começam com 4. Mas os números de cartão de crédito também têm um “checksum” embutido, uma relação matemática entre pelo menos um número e outros. Essa soma de verificação permite que os computadores (ou humanos que gostam de matemática) detectem erros de digitação (por exemplo, transposições), se não números fraudulentos, sem ter que consultar um banco de dados, que pode ser lento. É claro que um matemático desonesto certamente poderia criar um número falso que, no entanto, respeite a restrição matemática, portanto, uma pesquisa no banco de dados ainda é necessária para verificações mais rigorosas.

# Algoritmo de Luhn

Então, qual é a fórmula secreta? Bem, a maioria dos cartões usa um algoritmo inventado por Hans Peter Luhn, da IBM. De acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da seguinte maneira:

Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses produtos.

Adicione essa soma à soma dos dígitos que não foram multiplicados por 2.

Se o último dígito do total for 0 (ou, mais formalmente, se o módulo total 10 for congruente com 0), o número é válido!

Isso é meio confuso, então vamos tentar um exemplo com o cartão Visa do David: 4003600000000014.

1- Para fins de discussão, vamos primeiro sublinhar todos os outros dígitos, começando com o penúltimo dígito do número:

4003600000000014

Ok, vamos multiplicar cada um dos dígitos sublinhados por 2:

1 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 0 • 2 + 6 • 2 + 0 • 2 + 4 • 2

Isso nos dá:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Agora vamos adicionar os dígitos desses produtos (ou seja, não os próprios produtos):

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

2- Agora vamos adicionar essa soma (13) à soma dos dígitos que não foram multiplicados por 2 (começando do final):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

3- Sim, o último dígito dessa soma (20) é 0, então o cartão de David é legítimo!

Portanto, validar números de cartão de crédito não é difícil, mas se torna um pouco tedioso manualmente. Vamos escrever um programa.
