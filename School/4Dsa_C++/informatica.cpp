/*
* Questo programma è stato creato a scopo scolastico. Andremo ad usare i concetti principali della OOP
* Incapsulamento: cioè il ragruppare le funzionalità di un oggetto in metodi
* L'Eredità : andremo a creare un sistema di eredità con una SuperClasse e SottoClasse
* L'overloading  : La possibilità di usare lo stesso nome per un metodo che ha parametri diversi e/o scopo diverso
* L'override : La possibilità di riscrivere un metodo di una superclasse per una sottoclasse
              ***Il Progromma***
******************************************************************************
Questo programma conterra una famiglia di poligoni es Poligoni-> Quadrato, Rettangolo,
Paralelogramma, trinagolo. Clacoleremo Area e perimetro. Crereomo un overloading
di un metodo per un solo poligono che ci permette di calcolare in modo divero l'area e il perimetro
******************************************************************************
* This program is under GNU License Copyright 2019 Giorgio Bella
******************************************************************************
*/

/*Including base library for input and output data and math operation in case needed*/
#include "iostream"
#include "math.h"
// using standar namespace
using namespace std;
// define a type float with name lato


class poligono {
  protected:
    typedef float lato;
    lato lato1;
  public:
    float perimetro(){
      return lato1 * 4;
    }
    float area(){
      return pow(lato1,2);
    }
  // Destroy
  //virtual ~poligono (){}
};
  //Derivate class "Eredita"
  class quadrato:public poligono {
      private:
        float dataArea;
        float datoPerimetro;
        //Quadrato nothing to add in the decleration scope we can access to the lato1 var in the superclass
      public:
        quadrato (float lato1){
          lato1 = lato1;
          cout << "Object instancieted" << '\n';
          cout <<lato1<<'\n';
        }
        float perimetro(){
          return  lato1 * 4;
        }
        //Overloading method perimetro
        float perimetro(float dataArea){
          lato lato;
          lato = sqrt(dataArea);
          return lato * 4;
        }
        float area(){
            lato1 = lato1;
          return lato1 * lato1;
        }
        float area(float datoPerimetro){
          lato lato;
          lato = datoPerimetro/4;
          return pow(lato,2);
        }
  };

  class rettangolo: public poligono{
    protected:
      lato latoRet2;

    public:
      //construttore
      rettangolo(lato lato1 , lato latoRet2){
        lato1 = lato1;
        latoRet2 = latoRet2;
      }
      float perimetro(){
        return (2*lato1)+(2*latoRet2);
      }
      float area(){
        return lato1*latoRet2;
      }
  };
 /*Class paralelogramma is a derivated of rettangolo for the compcet is-a we can see
 * our paralelogramma as a rectangular so we have a sencond layer of eredity
 */
  class paralelogramma: public poligono{
    private:
     lato altezza;
     lato latoRet2;
    public:
    paralelogramma(lato lato1, lato latoRet2, lato altezza){
      lato1 = lato1;
      latoRet2 = latoRet2;
      altezza = altezza;
    }
    float perimetro(){
      return  (2*lato1)+(2*latoRet2);
    }
    float area(){
      if (lato1 > latoRet2) {
        return altezza * lato1;
      }else if (latoRet2>lato1){
        return altezza * latoRet2;
      }else{
        cout << "Error" << '\n';
        return 0;
      }
    }
  };

  class trinagolo:public poligono{
    private:
      lato latoTri1;
      lato latoTri2;
      lato altTriangolo;

    public:
      trinagolo(lato lato1,lato latoTri1, lato latoTri2, lato altTriangolo){
        lato1 = lato1;
        latoTri1 = latoTri1;
        latoTri2 = latoTri2;
        altTriangolo = altTriangolo;
      }
      float perimetro(){
        return lato1 + latoTri1 + latoTri2;
      }
      float area(){
        if(lato1 > latoTri1 && lato1 > latoTri2){
          return lato1 * altTriangolo/2;
        }else if(latoTri1 > latoTri2 && latoTri1 > lato1){
          return latoTri1 * altTriangolo/2;
        }else if (latoTri2 >= latoTri1 && latoTri2 >= lato1){
          return latoTri2 * altTriangolo/2;
        }else {
          cout << "Error" << '\n';
          return 0;
        }

      }
  };

  //main
  int main() {
    float a , b, per, ar, dper, dar;
    cout << "Inserisci lato quadrato" << '\n';
    cin >> a;
    quadrato q(a);
    cout << "Perimetro= " << q.perimetro() << '\n';
    cout << "Area = " << q.area()<< '\n';
    cout << "Inserisici un area" << '\n';
    cin >> dar;
    //overloading method
    cout << "Area = " <<q.perimetro(dar)<< '\n';
    cout << "Inserisici un perimetro" << '\n';
    cin >> dper;
    //overloading method
    cout << "Perimetro = " <<q.area(dper)<< '\n';

    return 0;
  }
