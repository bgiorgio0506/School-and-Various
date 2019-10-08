#ifndef MATRICI_H
#define MATRICI_H
#define R 10
#define C 10
/*
Author Giorgio Bella 
Version 0.0.1 
Description : Class decleration for bidimensional Array and prototype decleration
*/
class matrici
{
private:
    typedef int matrice; // type deifinision for matrice (bidimesional array)
    matrice m1[R][C], res[R][C];
    int dim;

public:
//Prototypes Declerations
    matrici(matrice m1[][C]); // Constructor
    void LoadBidimensionalArray(matrice m1[][C]);
    void DisplayBiDimensionalArray();
    int SumBidimensionalArray(matrice m1[][C], matrice m2[][C]);
    int DifBidimensionalArray(matrice m1[][C], matrice m2[][C]);
    int getBidimesionDimension(){ return dim;}
};
#endif