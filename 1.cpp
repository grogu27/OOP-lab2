#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
#define N 4

void del(int** mas, int* D);
int** mass_creat();
void print(int** arr);
void print_D(int* D);
void first(int** mass, int* D);
void second(int** matrix, int* D);
void third(int** matrix, int* D);
void fourth(int** matrix, int* D);

int main()
{
    int** arr = mass_creat();
    int* D = new int[N*N]; 
    
    print(arr);
    first(arr, D);
    cout << "a)" << " ";
    print_D(D);

    second(arr, D);
    cout << "b)" << " ";
    print_D(D);

    third(arr, D);
    cout << "c)" << " ";
    print_D(D);

    fourth(arr, D);
    cout << "d)" << " ";
    print_D(D);
    
    del(arr, D);
    return 0;
}

void del(int** mass, int* D)
{
    for (int i = 0; i < N; i++)
        delete [] mass[i];
    
    delete [] mass;
    delete [] D;
}

int** mass_creat()
{
    srand(time(NULL));
    int **mass = new int*[N];
    for (int i = 0; i < N; i++){
        mass[i] = new int[N];
        for (int j = 0; j < N; j++)
            mass[i][j] = rand() % 10;
    }
    return mass;
}

void print(int** arr)
{
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void print_D(int* D)
{
    for (int i = 0; i < N*N; i ++)
        cout << D[i] << " ";
    cout << endl;
}
// a) по правым диагоналям, начиная с правого верхнего элемента
void first(int** matrix, int* D)
{
    /* Количество диагоналей = 2*N-1 */
    int index = 0;
    for (int d = 0; d < 2 * N - 1; d++) {
        int i = (d < N) ? 0 : d - N + 1;        //Если d < N, то мы находимся на верхней половине матрицы
        int j = (d < N) ? N - d - 1 : 0;

        while (i < N && j < N) {
            D[index] = matrix[i][j];
            index++;
            i++;
            j++;
        }
    }
}

// b) по левым диагоналям, начиная с левого верхнего элемента
void second(int** matrix, int* D)
{
    /* Количество диагоналей = 2*N-1 */
    int index = 0;
    for (int d = 0; d < 2 * N - 1; d++)
    {
        int i = (d < N) ? 0: d - N + 1;         //Если d < N, то мы находимся на верхней половине матрицы
        int j = (d < N) ? 1 + d - 1: N - 1; 

        while (i < N  && j >= 0) {
            D[index] = matrix[i][j];
            index++;
            i++;
            j--;
        }
    }
}

// c) по спирали, начиная с центрального элемента
void third(int** matrix, int* D)
{
    int k = 0;
    int center = N / 2;
    if(center % 2 == 0 && center > 0 && N < 5)
	    center -= 1;
    int step = 0;
    int left = 0, right = 0, bottom = 0, top = 0;
    D[k++] = matrix[center][center];
    while (k < N * N) {
        step++;
        for (int i = 1; i <= step && k < N * N; i++) { //right
            D[k++] = matrix[center - top][center - left + i];
        }
        right++;
        for (int i = 1; i <= step && k < N * N; i++) { //bottom
            D[k++] = matrix[center - top + i][center + right];
        }
        bottom++;
        step++;
        for (int i = 1; i <= step && k < N * N; i++) { //left
            D[k++] = matrix[center + bottom][center + right - i];
        }
        left++;
        for (int i = 1; i <= step && k < N * N; i++) { //top
            D[k++] = matrix[center + bottom - i][center - left];
        }
        top++;
 
    }
}

// d) по спирали, начиная с левого верхнего элемента
void fourth(int** matrix, int* D)
{
    int k = 0;
    int center = N / 2;
    int left = 0, right = 0, bottom = 0, top = 0;
    int size = N;
    while(k < N * N)
    {
        for(int i = 0; i < size && k < N * N; i++ )
            D[k++] = matrix[top][left + i];
        top++;
        size--;  
        
        for(int i = 0; i < size && k < N * N; i++ )
            D[k++] = matrix[top + i][N - 1 - right];
        right++;
        

        for(int i = 0; i < size && k < N * N; i++ )
            D[k++] = matrix[N - 1 - bottom][N - 1 - right - i];
        bottom++;
        size--;

        for(int i = 0; i < size && k < N * N; i++ )
            D[k++] = matrix[N - 1 - bottom - i][left];
        left++;
    }
}