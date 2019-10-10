#include <cstdlib>
#include <iostream>
#define R 10
#define C 10
//Ricorda riscrivere il programma ;) 

using namespace std;

class matrici{
	private:
		int m1[R][C], m2[R][C], res[R][C];
		int dim;
	public:
		
		matrici(){
			cout<<"Matrice inizialied waiting function to run"<<endl;
		}
		
		void LoadBidimensionalArray(){
    		int i, j;
    		cout << "Inserisci dimesione della matrice";
    		cin >> dim;
			if(dim > C){
				cout<<"Error unexpected input";
			}
    		for (i = 0; i < dim; i++)
    		{
        		for (j = 0; j < dim; j++)
        		{
            		cout << "Inserire numero da caricare nella matrice nella posizione [" << i + 1 << ";" << j + 1 << "]" << endl;
            		cin >> m1[i][j];
        		}
    		}
		}

		void LoadBidimensionalArray(int m1[R][C]){
			int i, j;
    		for (i = 0; i < dim; i++)
    		{
        		for (j = 0; j < dim; j++)
        		{
            		cout<< "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"<< ": " << m2[i][j] << endl;
        		}
   			}
   			cout<<"*********End Matrice Print**********"<<endl;
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

		void DisplayRes(){
			int i, j;
    		for (i = 0; i < dim; i++)
    		{
        		for (j = 0; j < dim; j++)
        		{
            		cout<< "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"<< ": " << res[i][j] << endl;
        		}
   			}
   			cout<<"*********End Matrice Print**********"<<endl;
		}
		
		int getBidimesionDimension(){ 
			return dim;
		}

		int SumArray()
		{
			for (int i = 0; i < dim; i++)
			{
				for (int j = 0; j < dim; j++)
				{
					res[i][j] = m1[i][j] + m2[j][i];
				}
			}
			DisplayRes();
		}

		int DifArray()
		{
			for (int i = 0; i < dim; i++)
			{
				for (int j = 0; j < dim; j++)
				{
					res[i][j] = m1[i][j] - m2[j][i];
				}
			}
			DisplayRes();
		}
};

int main()
{
    int m1[R][C];
    matrici m;
    m.LoadBidimensionalArray();
    cout<<"Dimensione: "<<m.getBidimesionDimension()<<"X"<<m.getBidimesionDimension()<<endl;
    m.DisplayBidimensional();
    system("PAUSE");
}
