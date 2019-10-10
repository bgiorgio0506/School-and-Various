#include <cstdlib>
#include <iostream>
#define R 10
#define C 10


using namespace std;

class matrici{
	private:
		int m1[R][C];
		int dim;
	public:
		
		matrici(){
			cout<<"Matrice inizialied waiting function to run"<<endl;
		}
		
		void LoadBidimensionalArray(){
    		int i, j;
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
		
		void DisplayBidimensional(){
    		int i, j;
    		for (i = 0; i < dim; i++)
    		{
        		for (j = 0; j < dim; j++)
        		{
            		cout<< "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"<< ": " << m1[i][j] << endl;
        		}
   			}
   			cout<<"*********End Matrice Print**********"<<endl;
		}
		
		int getBidimesionDimension()
		{ 
			return dim;
		}
};

int main()
{
    int m1[R][C];
    matrici m;
    matrici m2;
    m.LoadBidimensionalArray();
    m2.LoadBidimensionalArray();
    cout<<"Dimensione: "<<m.getBidimesionDimension()<<"X"<<m.getBidimesionDimension()<<endl;
    m.DisplayBidimensional();
    m2.DisplayBidimensional();
    system("PAUSE");
}
