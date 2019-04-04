/*
* Questo programma è stato creato a scopo scolastico. Andremo ad usare i seguemti concetti principali della OOP
* Incapsulamento: cioè il ragruppare le funzionalità di un oggetto in metodi
* L'Eredità : andremo a creare un sistema di eredità con una SuperClasse e SottoClasse
* da notare che possiamo avere pure un eredità multipla e virtuale su una classe
* L'overloading  : La possibilità di usare lo stesso nome per un metodo che ha parametri diversi e/o scopo diverso
* L'override : La possibilità di riscrivere un metodo di una superclasse per una sottoclasse
              ***Il Programma***
******************************************************************************
Questo programma contiene una famiglia di poligoni es Poligoni-> Quadrato, Rettangolo,
Paralelogramma, trinagolo. Clacoleremo Area e perimetro. Useremo l' overloading
di uno o più metodi per un solo poligono che ci permette di calcolare in modo divero l'area e il perimetro
******************************************************************************
* This program is under GNU 3.0 License Copyright 2019 Giorgio Bella
******************************************************************************
*/

/*Including base library for input and output data and math operation in case needed*/
#include "iostream"
#include "math.h"
// using standar namespace
using namespace std;

class poligono {
  protected:
    //we don't trust other classes so we use protected to gain access only to the friend classes
    typedef float lato;
    lato lato1;
  public:
    float perimetro(){
      return lato1 * 4;
    }
    float area(){
      return pow(lato1,2);
    }

};
  //Derivate class "Eredità"
  class quadrato:public poligono {
      private:
        float dataArea;
        float datoPerimetro;
      public:

        quadrato (lato a){
          lato1 = a;
          cout << "\nObject instancieted" << '\n';
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
          return lato1 * lato1;
        }

        //overloading method area
        float area(float datoPerimetro){
          lato lato;
          lato = datoPerimetro/4;
          return pow(lato,2);
        }
        //destroy
        ~quadrato (){
         cout << "Oggetto distrutto" << '\n';
       }
  };

  class rettangolo: public poligono{
    private:
      lato latoRet2;

    public:
      //construttore
      rettangolo(lato a , lato b){
        lato1 = a;
        latoRet2 = b;
      }
      float perimetro(){
        return (2*lato1)+(2*latoRet2);
      }
      float area(){
        return lato1*latoRet2;
      }
      //destroy
      ~rettangolo (){
       cout << "Oggetto distrutto" << '\n';
     }
  };

  class paralelogramma: public poligono{
    private:
     lato altezza;
     lato latoPar ;
    public:
    paralelogramma(lato a, lato b, lato h){
      lato1 = a;
      latoPar = b;
      altezza = h;
    }
    float perimetro(){
      return  (2*lato1)+(2*latoPar);
    }
    float area(){
      if (lato1 > latoPar) {
        return altezza * lato1;
      }else if (latoPar >= lato1){
        return altezza * latoPar;
      }else{
        cout << "Error" << '\n';
        return 0;
      }
    }
    //destroy
    ~paralelogramma (){
     cout << "Oggetto distrutto" << '\n';
   }
  };

  class trinagolo:public poligono{
    private:
      lato latoTri1;
      lato latoTri2;
      lato altTriangolo;

    public:
      trinagolo(lato a,lato b, lato c, lato h){
        lato1 = a;
        latoTri1 = b;
        latoTri2 = c;
        altTriangolo = h;
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
      //destroy
      ~trinagolo (){
       cout << "Oggetto distrutto" << '\n';
     }
  };

  //main
  int main() {
    float a , b, c, h, dper, dar;
    //Quadrato (Bare in mind I will implement a menu to choose what to do)
    cout << "\n/**** Quadrato Section *****/" << '\n';
    cout << "Inserisci lato quadrato" << '\n';
    cin >> a;
    quadrato q(a);
    // overiding methods
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
    q.~quadrato();
    cout <<'\n';
    cout << '\n';

    /*rettangolo*/
    /*reinitialization vars*/
    a = 0;
    cout << "\n/**** Rettangolo Section *****/" << '\n';
    cout << "Inserisci lato Rettangolo" << '\n';
    cin >> a;
    cout << "Inserisci lato Rettangolo" << '\n';
    cin >> b;
    rettangolo r(a,b);
    cout << "Perimetro= " << r.perimetro() << '\n';
    cout << "Area = " << r.area()<< '\n';
    r.~rettangolo();
    cout <<'\n';
    cout << '\n';

    /* Pentagono */
    cout << "\n/**** Paralelogramma Section *****/" << '\n';
    cout << "Inserisci lato Paralelogramma" << '\n';
    cin >> a;
    cout << "Inserisci lato Paralelogramma" << '\n';
    cin >> b;
    cout << "Inserisci altezza Paralelogramma" << '\n';
    cin >> h;
    paralelogramma p(a,b,h);
    cout << "Perimetro= " << p.perimetro() << '\n';
    cout << "Area = " << p.area()<< '\n';
    p.~paralelogramma();
    cout << '\n';
    cout <<'\n';


    /* Triangolo */
    cout << "\n/**** Triangolo Section *****/" << '\n';
    cout << "Inserisci base Triangolo" << '\n';
    cin >> a;
    cout << "Inserisci lato Triangolo" << '\n';
    cin >> b;
    cout << "Inserisci lato Triangolo" << '\n';
    cin >> c;
    cout << "Inserisci altezza Triangolo" << '\n';
    cin >> h;
    trinagolo t(a,b,c,h);
    cout << "Perimetro= " << t.perimetro() << '\n';
    cout << "Area = " << t.area()<< '\n';
    t.~trinagolo();

    return 0;
  }
