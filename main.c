#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int num_elements(int na);  // скільки елементів в трикутнику матриці включно з діагоналлю
void max_min(int **A, int na);
void Transpon(int **B, int nb , int mb);
void dobutok(int **A ,int **B ,int na ,int nb ,int mb);
void sort(int **A , int x , int na);

int ** memoryAllocation(int rows, int cols)
{
    int i = 0;
    int **matrix = (int **)malloc(rows*sizeof(int *));
    for( i = 0; i < rows; i++)
    {
      matrix[i] = (int *)malloc(cols*sizeof(int));
    }
    return matrix;
}

int main()
{
    int **A;
    int **B;
    int na , nb , mb;
    int select;

        printf("Enter array size for square matrix A \n");
        scanf("%d", &na);
        A = memoryAllocation(na,na);

        printf("Enter width and height for matrix b \n");
        scanf("%d %d", &nb ,&mb);
        B = memoryAllocation(nb, mb);

        for (int x = 0 ; x < na ; x++)          //задаємо значення елементів матриці А
        {
            int temp;
            printf("Enter %d line  ", x+1);
            for (int y = 0 ; y < na ; y++)
            {
                scanf("%d", &temp);
                A[x][y] = temp;
                //A[x][y] = rand()%101;
            }
        }

        for (int x = 0 ; x < nb ; x++)          //задаємо значення елементів матриці В
        {
            int temp;
            printf("Enter %d line  ", x+1);
            for (int y = 0 ; y < mb ; y++)
            {
                scanf("%d", &temp);
                B[x][y] = temp;
                //B[x][y] = rand()%101;
            }
        }

        for (int x = 0 ; x < na ; x++)          //вивід матриці А
        {
            for(int y = 0; y < na; y++)
            {
                printf("%d \t", A[x][y]);
            }
            printf("\n");
        }
        printf("\n \n");

        for (int x = 0 ; x < nb ; x++)          //вивід матриці B
        {
            for(int y = 0; y < mb; y++)
            {
                printf("%d \t", B[x][y]);
            }
            printf("\n");
        }
        printf("\n \n");

        max_min(A, na);
        Transpon(B ,nb ,mb);
        dobutok(A , B , na , nb , mb);
        sort(A, 2, na);

    return 0;
}

int num_elements(int na)
{
    int y = 0;
    int sum = 0;

    for(int i = 1;i <= na;i++)
    {
        sum++;
        if(i == na)
        {
            y++;
            i=y;
        }
    }
    return sum;
}

void max_min(int **A, int na)   // перший пункт завдання
{
    int max ,min_tr , x , y;
    max = A[0][0];

    for (y = 0; y < na ; y++)
    {
        for(x = 0; x < na ; x++)
        {
            if (A[x][y] > max)
            {
                max = A[x][y];
            }
        }
    }
    x = 0;
    y = 0;
    int in = 0;
    min_tr = A[0][0];
    for(int i = 0;i < num_elements(na);i++)
    {
        if (min_tr > A[y][in])  //================================================================
        {                       // поміняти y з in мімцями для того ,щоб знайти мінімум нижнього трикутника
            min_tr = A[y][in];  //================================================================
        }
        if(in == na-1)
        {
            y++;
            in = y-1;
        }
        in++;
    }
    printf("\nMaximum is %d", max);
    printf("\nMinimum of triangle is %d", min_tr);
}

void Transpon(int **B, int nb , int mb)   //транспонування матриці
{                                         //в разі чого можна зробити ретурн BT(транспонованої матриці)
    int **BT;
    int temp;

    BT = memoryAllocation(mb , nb);

    for (int x = 0 ; x < nb ; x++)
    {
        for (int y = 0 ; y < mb ; y++)
        {
            temp = B[x][y];
            BT[y][x] = temp;
        }
    }

    for (int x = 0 ; x < mb ; x++)
        {
            for(int y = 0; y < nb; y++)
            {
                printf("%d \t", BT[x][y]);
            }
            printf("\n\n");
        }
}

void dobutok(int **A ,int **B ,int na ,int nb ,int mb)  // добуток матриць А та В
{                                                       // також можна зробити ретурн матриці AB
    int **AB;
    int temp_element = 0, temp_sum = 0;

    AB = memoryAllocation(na,mb);


    for(int z = 0 ; z < na ;z++)
    {
        for (int x = 0 ; x < mb ; x++)
        {
            for (int y = 0 ; y < nb ; y++)
            {
                temp_element = A[z][y] * B[y][x] ;
                temp_sum = temp_sum + temp_element;
            }
            AB[z][x] = temp_sum;
            temp_sum = 0;
        }
    }

    for (int x = 0 ; x < na ; x++)
    {
        for(int y = 0; y < mb; y++)
        {
            printf("%d \t", AB[x][y]);
        }
        printf("\n");
    }
}

void sort(int **A , int x , int na)
{
    int *sort_array = (int *)malloc(na * sizeof(int));
    int tempMIN;
    int tempE;
    int i = 0 , j = 0;

    for(int i = 0;i < na;i++)
    {
        sort_array[i] = A[x][i];
        printf("%d \t", sort_array[i]);
    }
    for(j = 0;j < na;j++)
    {
        tempMIN = sort_array[j];
        for(i = j;i < na;i++)
        {
            if(sort_array[i] < tempMIN)
            {
                tempMIN = sort_array[i];
                tempE = sort_array[j];
                sort_array[j] = tempMIN;
                sort_array[i] = tempE;
            }
        }
    }
        printf("\n");
    for(int i = 0;i < na;i++)
    {
        printf("%d \t", sort_array[i]);
    }
}
