#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
    int altura;
} No;

No* criaNo(int chave);
No* inserirNo(No *no, int valor, int *rotacao);
int altura(No *raiz);
void busca(No *no, int valor, int *procura);
int alturaDoNo(No *no);
int fatorDeBalanceamento(No *no);
No* rotEsq(No* raiz);
No* rotDir(No* raiz);
No* rotDirEsq(No *raiz);
No* rotEsqDir(No *raiz);
No* balancear(No *raiz, int *rotacao);
void exibirEmOrdem(No* no);

void desenharABB(No* raiz, int espaco);

int main(){
    clock_t start, end;
    double cpu_time_used;
    
    // Enter your tree values ​​here
    int avl[] = {307,9661,933,2661,9011,9824,3102,4072,1394,9754,8635,7107,5140,3798,3394,9581,8903,7642,6205,5434,3452,617,8342,7091,9061,7635,3311,5022,1651,9037,5471,6263,6960,6396,2564,529,4958,3541,9295,4378,6155,9846,45,424,9287,8568,4592,9568,1810,6437,4938,978,9966,3024,7901,2791,6380,8604,9926,1811,3386,4446,9325,569,5771,1327,1957,4070,1721,4620,4903,6464,8021,4298,7607,7301,2380,2118,6548,1343,1269,2255,4217,1176,1114,535,941,5787,1530,2557,2015,2043,8740,753,6218,6755,3089,8577,5252,3172,1046,8868,9098,404,9059,2695,1405,8991,6134,8176,3544,2438,8158,6933,1484,1751,2292,3512,319,1364,925,48,4279,3584,1133,2428,150,958,3474,3790,1812,3593,6294,3669,9813,6797,3860,4520,9531,1493,251,8754,1019,5802,1311,4359,1392,4590,5512,5554,2765,3825,8123,5724,7876,9672,1778,2997,5028,8810,2686,5769,2296,6931,1404,3734,6877,6786,2368,6485,8023,2173,2801,4710,4744,6194,9162,5243,8245,4674,6075,5688,1262,6082,5258,2994,2985,5194,4257,9183,9554,4560,2598,2250,5852,8966,6432,6322,3444,9187,5847,2540,6157,6110,5578,1626,9605,325,9711,4235,1720,7143,8821,4284,3240,5472,6068,5797,1128,1110,6849,3454,7370,6949,5408,2382,2668,3430,6757,7117,5498,7512,3642,5718,3686,5528,7156,2500,427,6551,7931,2610,5527,8016,9669,1687,5510,4509,5721,6170,8830,589,6330,9636,4424,2048,9375,9585,3615,1565,9393,7239,8,9578,2131,8533,2389,5295,106,6211,988,2287,5024,8103,5824,2647,6927,8309,3405,2088,915,1281,2937,7306,3627,7100,622,1846,9841,2315,7689,667,4296,11,7438,6681,3973,5235,2982,2016,1890,1102,124,4021,13,1916,1467,7392,4451,9361,2621,9637,6127,5101,9423,9394,8181,6665,670,4725,8397,3610,9161,5350,7873,290,4074,9939,4930,6118,7147,1951,4307,449,7541,8689,4372,6659,4847,4665,6734,4863,2052,2650,9463,455,9640,6440,3762,9438,9368,5240,4881,6412,217,4628,1408,7618,4111,4134,8295,5906,7874,1401,2630,4934,9613,7433,5307,7509,5674,3305,8916,2789,2427,1929,2947,3296,6073,3027,7629,5108,7194,8082,3105,3523,757,5579,3676,1971,3994,6356,1033,4276,9678,3106,5389,1905,1505,2858,600,8199,5923,8466,5244,4679,5727,4574,737,9726,6589,6184,3277,7883,5735,3298,1582,6339,2690,4702,8630,47,9674,3069,8500,8584,4689,3895,4467,277,9296,1606,7754,7718,6584,8948,4304,7341,2672,6342,5587,4871,4409,3445,2959,7594,7075,5476,1896,1832,8104,7749,195,1998,9855,8184,5112,7738,3826,7397,2567,5026,648,1753,1072,2742,5232,1784,2081,1719,539,7466,8913,2033,1632,5532,8057,4415,2823,8772,3440,580,3117,1688,52,3417,2148,2547,1807,8321,8816,5402,7806,5817,5910,5181,7890,7330,6732,6887};

    No *raiz_avl = malloc(sizeof(No));
    raiz_avl->chave = avl[0];
    raiz_avl->dir = NULL;
    raiz_avl->esq = NULL;

    int i = 0;
    int *procura = malloc(sizeof(int));
    (*procura) = 0;
    int tam1 = (sizeof(avl))/(sizeof(int));

    int *rotacao = malloc(sizeof(int));
    (*rotacao) = 0;
    for(i = 1; i < tam1; i++){
        raiz_avl = inserirNo(raiz_avl, avl[i], rotacao);
    }

    start = clock();
    busca(raiz_avl, 6050, procura);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // If you want to know how the tree turned out:
    // exibirEmOrdem(raiz_avl);

    printf("\nAltura AVL: %d\n", altura(raiz_avl));
    printf("Quantidade de vezes que a chamada procurou 6050 na AVL: %d\n", *procura);
    printf("Tempo gasto na funcao de busca AVL: %lfs\n", cpu_time_used);
    printf("Numero de rotacoes: %d\n", *rotacao);

    // Mostra a AVL
    // desenharABB(raiz_avl, 0);

    free(raiz_avl);
    free(procura);
    free(rotacao);


}

No* inserirNo(No *no, int valor, int *rotacao){

    /*
        Inserts a node into the tree according to the idea of ​​a 
        "AVL" (binary tree in which the heights of the two 
        subtrees of every node never differ by more than 1)
    */

    if(no == NULL){
        return criaNo(valor);
    }else{
        if (valor < no->chave){
            no->esq = inserirNo(no->esq, valor, rotacao);
        }else if(valor > no->chave){
            no->dir = inserirNo(no->dir, valor, rotacao);
        }
    }

    no->altura = altura(no);

    no = balancear(no, rotacao);
    return no;
    
}

No* criaNo(int chave){
    /*
        It takes a key as a parameter,
        creates a leaf node with that key and returns it
    */

    No *aux = malloc(sizeof(No));
    aux->chave = chave;
    aux->dir = NULL;
    aux->esq = NULL;
    aux->altura = 0;
    return aux;
}

int altura(No *raiz){
    /*
        Receives an AVL as a parameter and returns its height
    */
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if(esq > dir){
            return esq + 1;
        }
        else{
            return dir + 1;
        }
    }
}

void busca(No *no, int valor, int *procura){
    /*
        This function looks for a value in a binary tree
    */
    int i = 0;

    // Looping para fazer a função demorar um pouco a fim de mostrar
    // algum tempo na busca! (não é necessária para o funcionamento da árvore)

    for(i = 0; i < 1000000; i++){
        i = i;
    }

    if(no == NULL){
        (*procura)++;
        return;
    }

    if(valor == no->chave){
        return;
    }
    if(valor < no->chave){
        (*procura)++;
        busca(no->esq, valor, procura);
    }

    if(valor > no->chave){
        (*procura)++;
        busca(no->dir, valor, procura);
    }
}
int alturaDoNo(No *no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
    }
}

int fatorDeBalanceamento(No *no){
    /*
        Returns the "balance factor" that will tell 
        where the rotation direction will be
    */

    if(no){
        return ((alturaDoNo(no->esq)) - (alturaDoNo(no->dir)));
    }else{
        return 0;
    }
}

No* rotEsq(No* raiz){
    /*
        Rotate to the left
    */
    No *y, *f;

    y = raiz->dir;
    f = y->esq;

    y->esq = raiz;
    raiz->dir = f;

    raiz->altura = altura(raiz);
    y->altura = altura(y);

    return y;
}

No* rotDir(No* raiz){
    /*
        Rotate to the right
    */

    No *y, *f;

    y = raiz->esq;
    f = y->dir;

    y->dir = raiz;
    raiz->esq = f;

    raiz->altura = altura(raiz);
    y->altura = altura(y);

    return y;
}

No* rotDirEsq(No *raiz){
    /*
        rotate first to the right and then to the left
    */
    raiz->dir = rotDir(raiz->dir);
    return rotEsq(raiz);
}

No* rotEsqDir(No *raiz){
    /*
        rotate first to the left and then to the right
    */
    raiz->esq = rotEsq(raiz->esq);
    return rotDir(raiz);
}

No* balancear(No *raiz, int *rotacao){
    /*
        Check which way the rotations have to be
    */
    int fatorBal = fatorDeBalanceamento(raiz);

    if((fatorBal < -1) && (fatorDeBalanceamento(raiz->dir) <= 0)){
        (*rotacao)++;
        raiz = rotEsq(raiz);
    }else if((fatorBal > 1) && (fatorDeBalanceamento(raiz->esq) >= 0)){
        (*rotacao)++;
        raiz = rotDir(raiz);
    }else if((fatorBal > 1) && (fatorDeBalanceamento(raiz->esq) < 0)){
        (*rotacao)++;
        (*rotacao)++;
        raiz = rotEsqDir(raiz);
    }else if((fatorBal < -1) && (fatorDeBalanceamento(raiz->dir) > 0)){
        (*rotacao)++;
        (*rotacao)++;
        raiz = rotDirEsq(raiz);
    }

    return raiz;
}

#define TAM_ARESTAS 6

void desenharABB(No* raiz, int espaco) {
    /*
        Try to show how the avl turned out after balancing
    */

    if (raiz == NULL)
        return;

    espaco += TAM_ARESTAS;
 
    desenharABB(raiz->dir, espaco);
 
    printf("\n");
    for (int i = TAM_ARESTAS; i < espaco; i++)
        printf(" ");

    printf("%d\n", raiz->chave);
 
    desenharABB(raiz->esq, espaco);
}

void exibirEmOrdem(No* no) {
    /*
        print the tree in order
    */
    
    if (no->esq != NULL)
        exibirEmOrdem(no->esq);
    
    printf("%d ", no->chave);

    if (no->dir != NULL)
        exibirEmOrdem(no->dir);
}