"""Aula 03 - Construa e diga o custo.

NAO mude o nome deste arquivo nem a assinatura das funcoes.
Escreva sua solucao no lugar do 'pass'.

ATENCAO: quase todas as funcoes desta aula devolvem DUAS coisas,
o resultado e a contagem de operacoes:

    return soma, operacoes

Quem devolve so o resultado nao passa nos testes.
"""


def soma_contando(lista):
    """Devolve (soma, operacoes).
    Conte 1 operacao para cada numero que voce somar.
    soma_contando([1, 2, 3]) -> (6, 3)"""
    soma = 0
    operacoes = 0
    for n in lista:
        soma += n
        operacoes += 1
    return soma, operacoes


def busca_linear_contando(lista, alvo):
    """Devolve (posicao, comparacoes), ou (-1, comparacoes) se nao achar.
    Conte 1 comparacao cada vez que comparar um elemento com o alvo.
    Pare assim que encontrar."""
    comparacoes = 0
    for i, elemento in enumerate(lista):
        comparacoes += 1
        if elemento == alvo:
            return i, comparacoes
    return -1, comparacoes


def busca_binaria_contando(lista, alvo):
    """Recebe uma lista JA ORDENADA.
    Devolve (posicao, comparacoes), ou (-1, comparacoes) se nao achar.
    Conte 1 comparacao cada vez que olhar o elemento do meio."""
    esquerda = 0
    direita = len(lista) - 1
    comparacoes = 0

    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        comparacoes += 1

        if lista[meio] == alvo:
            return meio, comparacoes
        elif lista[meio] < alvo:
            esquerda = meio + 1
        else:
            direita = meio - 1

    return -1, comparacoes


def tem_repetido_contando(lista):
    """Devolve (True, comparacoes) ou (False, comparacoes).
    Conte 1 comparacao cada vez que comparar um par de elementos.
    Pare assim que encontrar o primeiro repetido."""
    comparacoes = 0
    for i in range(len(lista)):
        for j in range(i + 1, len(lista)):
            comparacoes += 1
            if lista[i] == lista[j]:
                return True, comparacoes
    return False, comparacoes


def quantas_divisoes(n):
    """Quantas vezes da para dividir n por 2 ate sobrar 1.
    Use divisao inteira. Devolve so o numero, sem contagem.
    quantas_divisoes(8) -> 3"""
    count = 0
    while n > 1:
        n //= 2
        count += 1
    return count


def mais_frequente_contando(lista):
    """(Desafio) Devolve (valor, comparacoes).
    O valor que mais aparece na lista. Em caso de empate, o que aparece
    primeiro. Conte 1 comparacao cada vez que comparar dois elementos."""
    comparacoes = 0
    frequencias = {}
    for elemento in lista:
        if elemento in frequencias:
            frequencias[elemento] += 1
        else:
            frequencias[elemento] = 1

    max_frequencia = 0
    valor_mais_frequente = None
    for elemento in lista:
        comparacoes += 1
        if frequencias[elemento] > max_frequencia:
            max_frequencia = frequencias[elemento]
            valor_mais_frequente = elemento

    return valor_mais_frequente, comparacoes

