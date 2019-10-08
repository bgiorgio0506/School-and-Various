#include "matrici.h"
#include "iostream"
using namespace std;

matrici::matrici(matrice m1[][C])
{
    LoadBidimensionalArray(m1);
}

void matrici::LoadBidimensionalArray(matrice m1[][C])
{
    int i, j, dim;
    cout << "Inserisci dimesione della matrice";
    cin >> dim;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            cout << "Inserire numero da caricare nella matrice nella posizione [" << i + 1 << ";" << j + 1 << "]" << endl;
            cin >> m1[i][j];
        }
    }
}

void matrici::DisplayBiDimensionalArray()
{
    int dim = getBidimesionDimension();
    int i, j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            cout << "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"
                 << ": " << m1[i][j] << endl;
        }
    }
}