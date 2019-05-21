/*
* Menu module. This part of code contain all the methods for the class menu contained in menu.h
*/
#include "iostream"
#include "menu.h"
#define MAX 100
// including the menu namespaces
using namespace std;
using namespace menu;


//MENU methods
menu:: void ShowMenu(){
  cout << "Welcome!!" << '\n';
  cout << "** Choose an option by typeing the number **" << '\n';
  cout << "1. Quadrato" << '\n';
  cout << "2. Rettangolo" << '\n';
  cout << "3. Paralelogramma" << '\n';
  cout << "4. Triangolo" << '\n';
  cin >> choosen;
}

mene:: float TriangoloAltSubMenu(){
  lato3 = 0 ;
  cout << "Inserisci altezza" << '\n';
  cin >> lato3;
  return lato3;
}

menu:: float ShowSubsMenu(){
if (choosen != ""){
    switch (choosen) {

      case (choosen == "1" || "1."):
        cout << "\n/**** Quadrato Section *****/" << '\n';
        cout << "Inserisci lato quadrato" << '\n';
        cin >> lato1;
        return lato1;
      break;

      case (choosen = "2" || "2."):
        float values = [MAX];
        cout << "\n/**** Rettangolo Section *****/" << '\n';
        for (i = 0; i < 1; i++) {
          cout << "Inserisci lato Rettangolo" << '\n';
          cin >> values[i];
          i++;
        }
        return value;
      break;

      case(choosen == "3" || "3." ) :
      float values = [MAX];
      cout << "\n/**** Paralelogramma Section *****/" << '\n';
      for (i = 0; i < 2; i++) {
        cout << "Inserisci lato Paralelogramma" << '\n';
        cin >> values[i];
        i++;
      }
      return value;
      break;

      case(choosen == "4" || "4." ) :
      float values = [MAX];
      cout << "\n/**** Triangolo Section *****/" << '\n';
      for (i = 0; i < 2; i++) {
        cout << "Inserisci lato Triangolo" << '\n';
        cin >> values[i];
        i++;
      }
      return value;
      break;

      default:
       cout << "Invalid choice" << '\n';
      break;
    }
  }else{
    cout << "Error Accured" << '\n';
  }
}

menu:: float DisplayChoices(){
  switch (choosen) {
    // Writing also the point in case someone want to write 1.
    case (choosen == "1" || "1." ):
      ShowSubsMenu()
    break;

    case (choosen == "2" || "2." ):
      ShowSubsMenu()
    break;

    case (choosen == "3" || "3." ):
      ShowSubsMenu()
    break;

    case (choosen == "4" || "4." ):
      ShowSubsMenu()
    break;
  }

}

menu:: void ShowResults(){

}
