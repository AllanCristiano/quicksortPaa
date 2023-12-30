#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[2];
    int total;
} Resultado;

// hoare mediana
int ha = 0;

void trocarhm(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    ha++;
}

int encontrarPivohm(int arr[], int inicio, int fim)
{
    int n = fim - inicio + 1;
    int v1 = (inicio + n) / 4;
    int v2 = (inicio + n) / 2;
    int v3 = 3 * (inicio + n) / 4;

    if (arr[v1] > arr[v2])
        trocarhm(&arr[v1], &arr[v2]);
    if (arr[v1] > arr[v3])
        trocarhm(&arr[v1], &arr[v3]);
    if (arr[v2] > arr[v3])
        trocarhm(&arr[v2], &arr[v3]);

    trocarhm(&arr[v2], &arr[v3]);

    return v3;
}

// Função de partição de Hoare
int particionarhm(int arr[], int inicio, int fim)
{
    int pivIndex = encontrarPivohm(arr, inicio, fim);
    int piv = arr[pivIndex];

    trocarhm(&arr[pivIndex], &arr[fim]);

    int i = inicio - 1;
    for (int j = inicio; j < fim; j++)
    {
        if (arr[j] <= piv)
        {
            i++;
            trocarhm(&arr[i], &arr[j]);
        }
    }

    trocarhm(&arr[i + 1], &arr[fim]);

    return i + 1;
}

void quicksorthm(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Encontrar o índice do pivô após a partição
        int pivIndex = particionarhm(arr, inicio, fim);

        ha += 2;
        quicksorthm(arr, inicio, pivIndex - 1);
        quicksorthm(arr, pivIndex + 1, fim);
    }
}
//end hoare mediana

// hoare padrao
int hp = 1;

void trocarhp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    hp++;
}

int particionarhp(int arr[], int baixo, int alto)
{
    int pivo = arr[baixo];
    int i = baixo - 1;
    int j = alto + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivo);

        do
        {
            j--;
        } while (arr[j] > pivo);

        if (i >= j)
        {
            return j;
        }

        trocarhp(&arr[i], &arr[j]);
    }
}

void quicksorthp(int arr[], int inicio, int final)
{
    if (inicio < final)
    {
        int p = particionarhp(arr, inicio, final);
        hp += 2;
        quicksorthp(arr, inicio, p);
        quicksorthp(arr, p + 1, final);
    }
}
// end hoare padrao

// lomuto aleatorio
int la = 1;

void trocarla(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    la++;
}

int escolherPivola(int arr[], int inicio, int tamanho)
{
    // Fórmula para escolha do pivô
    int indicePivo = inicio + abs(arr[inicio]) % tamanho;
    return indicePivo;
}

int particionarla(int arr[], int inicio, int fim)
{
    int indicePivo = escolherPivola(arr, inicio, fim - inicio + 1);
    trocarla(&arr[indicePivo], &arr[fim]);

    int pivot = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            trocarla(&arr[i], &arr[j]);
        }
    }

    trocarla(&arr[i + 1], &arr[fim]);
    return i + 1;
}

void quickSortla(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = particionarla(arr, inicio, fim);

        quickSortla(arr, inicio, pi - 1);
        quickSortla(arr, pi + 1, fim);
        la += 2;
    }
}
// end lomuto aleatorio
// lomuto mediana
int lm = 0;

void trocarlm(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    lm++;
}

int encontrarMedianalm(int arr[], int inicio, int fim)
{
    int n = fim - inicio + 1;
    int v1 = inicio + n / 4;
    int v2 = inicio + n / 2;
    int v3 = inicio + 3 * n / 4;

    if (arr[v1] > arr[v2])
        trocarlm(&arr[v1], &arr[v2]);

    if (arr[v1] > arr[v3])
        trocarlm(&arr[v1], &arr[v3]);

    if (arr[v2] > arr[v3])
        trocarlm(&arr[v2], &arr[v3]);

    return v2;
}

int particionarlm(int arr[], int inicio, int fim)
{
    int medianaIndex = encontrarMedianalm(arr, inicio, fim);
    trocarlm(&arr[medianaIndex], &arr[fim]); // Coloca a mediana no final
    int pivot = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            trocarlm(&arr[i], &arr[j]);
        }
    }

    trocarlm(&arr[i + 1], &arr[fim]);
    return i + 1;
}

void quickSortlm(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {

        int pi = particionarlm(arr, inicio, fim);
        quickSortlm(arr, inicio, pi - 1);
        quickSortlm(arr, pi + 1, fim);
        lm += 2;
    }
}

// end lomuto mediada

// lomuto padrao
int lp = 1;

void trocalp(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    lp++;
}

int particaolp(int arr[], int low, int high)
{
    int pivo = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivo)
        {
            i++;
            trocalp(&arr[i], &arr[j]);
        }
    }
    trocalp(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortlp(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = particaolp(arr, low, high);
        lp += 2;
        quickSortlp(arr, low, pi - 1);
        quickSortlp(arr, pi + 1, high);
    }
}
// end lomuto padrao
// montar array
void montarArray(int tamanho, int *array[], int array_tamanhos[], FILE *arquivo)
{
    for (int i = 0; i < tamanho; i++)
    {
        fscanf(arquivo, "%d", &array_tamanhos[i]);
        array[i] = malloc(array_tamanhos[i] * sizeof(int));
        for (int j = 0; j < array_tamanhos[i]; j++)
        {
            fscanf(arquivo, "%d", &array[i][j]);
        }
    }
}

// Função para copiar um array
int *copiarArray(const int *original, int tamanho)
{
    int *copia = malloc(tamanho * sizeof(int));

    if (copia == NULL)
    {
        // falha na alocação de memória
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++)
    {
        copia[i] = original[i];
    }

    return copia;
}

int main(int argc, char *argv[])
{
    (void)argc;
    FILE *arquivo = fopen(argv[1], "r");
    int total_array;
    fscanf(arquivo, "%d", &total_array);

    int *array_p[total_array];
    int array_tamanhos[total_array];

    montarArray(total_array, array_p, array_tamanhos, arquivo);

    Resultado resultados[total_array][6];

    for (int i = 0; i < total_array; i++)
    {
        // lomuto padrao
        lp = 1;
        int *copia01 = copiarArray(array_p[i], array_tamanhos[i]);
        quickSortlp(copia01, 0, array_tamanhos[i] - 1);
        strcpy(resultados[i][0].nome, "LP");
        resultados[i][0].total = lp;

        // lomuto mediana
        lm = 0;
        int *copia02 = copiarArray(array_p[i], array_tamanhos[i]);
        quickSortlm(copia02, 0, array_tamanhos[i] - 1);
        strcpy(resultados[i][1].nome, "LM");
        resultados[i][1].total = lm;

        // lomuto aleatorio
        la = 1;
        int *copia03 = copiarArray(array_p[i], array_tamanhos[i]);
        quickSortla(copia03, 0, array_tamanhos[i] - 1);
        strcpy(resultados[i][2].nome, "LA");
        resultados[i][2].total = la;

        // hoare padrao
        hp = 1;
        int *copia04 = copiarArray(array_p[i], array_tamanhos[i]);
        quicksorthp(copia04, 0, array_tamanhos[i] - 1);
        strcpy(resultados[i][3].nome, "HP");
        resultados[i][3].total = hp;

        // hoare mediana
        ha = 0;
        int *copia05 = copiarArray(array_p[i], array_tamanhos[i]);
        quicksorthm(copia05, 0, array_tamanhos[i] - 1);
        strcpy(resultados[i][4].nome, "HM");
        resultados[i][4].total = ha;

        free(array_p[i]);
    }

    for (int i = 0; i < total_array; i++)
    {
        printf("N(%d) %s(%d) ", array_tamanhos[i], resultados[i][0].nome, resultados[i][0].total);
        printf("%s(%d) %s(%d) ", resultados[i][1].nome, resultados[i][1].total, resultados[i][2].nome, resultados[i][2].total);
        printf("%s(%d) %s(%d) \n", resultados[i][3].nome, resultados[i][3].total, resultados[i][4].nome, resultados[i][4].total);
    }

    fclose(arquivo);
    return 0;
}
