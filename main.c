#include <stdio.h>
#include <time.h>



int tabuleiro[3][3];
int arr[9] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
int finalizado = 0;



void embaralharValores()
{

    srand(time(NULL));

    for (int i = 8; i >= 1; i--)
    {
        int j = rand() % 9;
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }

    for (int k = 0; k < 3; k++)
    {
        for (int x = 0; x < 3; x++)
        {
            tabuleiro[k][x] = arr[k * 3 + x];
        }
    }
}

void verificaVitoria(int arr[9])
{
    int objetivo[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int acertos = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == objetivo[i])
        {
            acertos += 1;
        }
    }
    if (acertos == 9)
    {
        printf("\nParabens! Voce ganhou.\n");
        finalizado = 1;
        return;
    }
    else
    {
        return;
    }
}

void atualizarTabuleiro(char move)
{

    if (move == 'w')
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == 0)
            {
                if (i < 3)
                {
                    printf("movimento invalido!\n");
                    return;
                }
                int aux = arr[i];
                int xua = arr[i - 3];
                arr[i - 3] = aux;
                arr[i] = xua;
                i = 9;
            }
        }
    }
    else if (move == 's')
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == 0)
            {
                if (i > 5)
                {
                    printf("movimento invalido!\n");
                    return;
                }
                int aux = arr[i];
                int xua = arr[i + 3];
                arr[i + 3] = aux;
                arr[i] = xua;
                i = 9;
            }
        }
    }
    else if (move == 'a')
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == 0)
            {
                if (i % 3 == 0)
                {
                    printf("movimento invalido!\n");
                    return;
                }
                int aux = arr[i];
                int xua = arr[i - 1];
                arr[i - 1] = aux;
                arr[i] = xua;
                i = 9;
            }
        }
    }
    else if (move == 'd')
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == 0)
            {
                if (i % 3 == 2)
                {
                    printf("movimento invalido!\n");
                    return;
                }
                int aux = arr[i];
                int xua = arr[i + 1];
                arr[i + 1] = aux;
                arr[i] = xua;
                i = 9;
            }
        }
    }

    for (int k = 0; k < 3; k++)
    {
        for (int x = 0; x < 3; x++)
        {
            tabuleiro[k][x] = arr[k * 3 + x];
        }
    }

    verificaVitoria(arr);
}

void mostrarTabuleiro()
{

    for (int k = 0; k < 3; k++)
    {
        for (int x = 0; x < 3; x++)
        {
            tabuleiro[k][x] = arr[k * 3 + x];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}




int main()
{

    mostrarTabuleiro();
    verificaVitoria(arr);

    char move;

    while (finalizado == 0)
    {
        scanf(" %c", &move);
        atualizarTabuleiro(move);
        mostrarTabuleiro();
    };

    return 0;
}
