"""Lista A - Python, listas, busca e custo.

NAO mude o nome deste arquivo nem a assinatura das funcoes.
Escreva sua solucao no lugar do 'pass'.

Os exercicios do Bloco 3 devolvem DOIS valores: o resultado e a contagem.
"""

# ---------- Bloco 1: listas e percurso ----------

def conta_negativos(lista):
    """Quantos numeros da lista sao menores que zero."""
    contador = 0
    for numero in lista:
        if numero < 0:
            contador += 1
    return contador



def media(lista):
    """Media dos numeros. Lista vazia devolve 0."""
    if not lista:
        return 0
    return sum(lista) / len(lista)




def sem_o_maior(lista):
    """Lista NOVA sem o maior valor. Se o maior repete, tira so o primeiro."""
    if not lista:
        return []
    maior = max(lista)
    nova = list(lista)
    nova.remove(maior)
    return nova



def acumulada(lista):
    """Lista NOVA onde cada posicao e a soma de tudo ate ali.
    acumulada([1, 2, 3]) -> [1, 3, 6]"""
    if not lista:
        return []
    result = [lista[0]]
    for i in range(1, len(lista)):
        result.append(result[-1] + lista[i])
    return result


def achata(lista_de_listas):
    """(Desafio) Junta as sublistas numa lista so.
    achata([[1, 2], [3]]) -> [1, 2, 3]"""
    result = []
    for sublista in lista_de_listas:
        result.extend(sublista)
    return result


# ---------- Bloco 2: busca ----------

def busca_ultima(lista, alvo):
    """ULTIMA posicao do alvo, ou -1."""
    for i in range(len(lista) - 1, -1, -1):
        if lista[i] == alvo:
            return i
    return -1


def conta_ocorrencias(lista, alvo):
    """Quantas vezes o alvo aparece."""
    contador = 0
    for elemento in lista:
        if elemento == alvo:
            contador += 1
    return contador


def primeiro_maior_que(lista, limite):
    """Posicao do primeiro elemento maior que limite, ou -1."""
    for i, elemento in enumerate(lista):
        if elemento > limite:
            return i
    return -1


def busca_binaria_primeira(lista, alvo):
    """(Desafio) Lista JA ORDENADA, o alvo pode repetir.
    Devolve a PRIMEIRA posicao do alvo, ou -1. Sem percorrer tudo."""
    
def busca_binaria_primeira(lista, alvo):
    """(Desafio) Lista JA ORDENADA, o alvo pode repetir.
    Devolve a PRIMEIRA posicao do alvo, ou -1. Sem percorrer tudo."""
    inicio = 0
    fim = len(lista) - 1
    resultado = -1  

    while inicio <= fim:
        meio = (inicio + fim) // 2

        if lista[meio] == alvo:
            resultado = meio   
            fim = meio - 1     
        elif lista[meio] < alvo:
            inicio = meio + 1    
        else:
            fim = meio - 1       

    return resultado


# ---------- Bloco 3: custo ----------

def soma_pares_contando(lista):
    """(soma_dos_pares, operacoes). Conte 1 por elemento examinado."""
    pass


def maior_contando(lista):
    """(maior, comparacoes). Lista nao vazia.
    Conte 1 comparacao por elemento a partir do segundo."""
    maior = lista[0]
    comparacoes = 0
    for x in lista[1:]:
        comparacoes += 1
        if x > maior:
            maior = x
    return (maior, comparacoes)



def tem_soma_contando(lista, alvo):
    """(True/False, comparacoes). Existem dois elementos que somam alvo?
    Conte 1 por par comparado. Pare assim que achar."""
    comparacoes = 0
    n = len(lista)
    for i in range(n):
        for j in range(i + 1, n):
            comparacoes += 1
            if lista[i] + lista[j] == alvo:
                return (True, comparacoes)
    return (False, comparacoes)


def ordenada_contando(lista):
    """(Desafio) (True/False, comparacoes). A lista esta em ordem crescente?
    Conte 1 por par de vizinhos comparado. Pare no primeiro fora de ordem."""
    comparacoes = 0
    for i in range(len(lista) - 1):
        comparacoes += 1
        if lista[i] > lista[i + 1]:
            return (False, comparacoes)
    return (True, comparacoes)


# ---------- Bloco 4: padroes ----------

def inverte_no_lugar(lista):
    """Inverte a PROPRIA lista recebida. NAO cria lista nova e NAO devolve nada."""
    esquerda = 0
    direita = len(lista) - 1
    while esquerda < direita:
        lista[esquerda], lista[direita] = lista[direita], lista[esquerda]
        esquerda += 1
        direita -= 1


def eh_palindromo(lista):
    """True se a lista e igual lida de tras para frente."""
    esquerda = 0
    direita = len(lista) - 1
    while esquerda < direita:
        if lista[esquerda] != lista[direita]:
            return False
        esquerda += 1
        direita -= 1
    return True


def par_que_soma(lista, alvo):
    """Lista JA ORDENADA. Devolve (i, j) das posicoes cujos valores somam alvo,
    ou (-1, -1). Sem laco dentro de laco."""
    i = 0
    j = len(lista) - 1
    while i < j:
        soma = lista[i] + lista[j]
        if soma == alvo:
            return (i, j)
        elif soma < alvo:
            i += 1
        else:
            j -= 1
    return (-1, -1)


def soma_maxima_janela(lista, k):
    """Maior soma de k elementos seguidos.
    soma_maxima_janela([1, 2, 3, 4], 2) -> 7"""
    if k <= 0 or k > len(lista):
        return 0
    max_soma = sum(lista[:k])
    soma_atual = max_soma
    for i in range(k, len(lista)):
        soma_atual += lista[i] - lista[i - k]
        max_soma = max(max_soma, soma_atual)
    return max_soma


def parenteses_balanceados(texto):
    """(Desafio) True se os ( ) e [ ] do texto abrem e fecham na ordem certa."""
    pilha = []
    pares = {')': '(', ']': '['}
    for char in texto:
        if char in '([':
            pilha.append(char)
        elif char in ')]':
            if not pilha or pilha[-1] != pares[char]:
                return False
            pilha.pop()
    return len(pilha) == 0
