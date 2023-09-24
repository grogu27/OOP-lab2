#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


void del(int** mas, int rows, int cols);
int** mass_creat(int rows, int cols);
void print(int** arr, int rows, int cols);

int main()
{
    srand(time(NULL));
    int rows = rand() % 15 + 1;
    int cols = rand() % 15; + 1;
    int** arr = mass_creat(rows, cols);

    print(arr, rows, cols);
    del(arr, rows, cols);
    return 0;
}

void del(int** mass, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        delete [] mass[i];
    
    delete [] mass;
}

int** mass_creat(int rows, int cols)
{
    srand(time(NULL));
    int **mass = new int*[rows];
    for (int i = 0; i < rows; i++){
        mass[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            mass[i][j] = rand() % 10;
    }
    return mass;
}

void print(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i ++)
    {
        for (int j = 0; j < cols; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
