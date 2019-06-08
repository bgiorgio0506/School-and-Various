//including libs
#include "iostream"
#include "string.h"
using namespace std;

//calss object
class aeromobile {
private:
  string Ac, engine, dep, dest;
  int fuel, altitude_set, heading_set, radio_altimeter, thrust_set;
  bool takeoff, autopilot;

  int refuel(int fuel) {
    cout << "Insert refuel amount" << '\n';
    cin >> fuel;
    return fuel;
  }


public:

 aeromobile (string acf, string eng, int fuelAv, string depAirport, string destAirport){
   Ac = acf;
   engine = eng;
   fuel = fuelAv;
   dep = depAirport;
   dest = destAirport;
   cout << "Aircraft is initializing" << '\n';
   system("clear");
 }

  void checkFuel() {
    //if you have no fuel
    if (fuel == 0){
      for (size_t i = 0; i < 101; i++) {
        fuel++;
      }
      cout << "You have been refueled" << '\n';
    }
    if (fuel<50) {
      int fuel1 = fuel;
      cout << "You are runnig out of fuel please refuel" << '\n';
      fuel = refuel(fuel);
      if (fuel1<=fuel) {
        cout << "Good job you refueled your aircraft "<< '\n';
      }else if(fuel1 > fuel){
        cout << "Attention captain you have added a small ammount of fuel" << '\n';
      }
    }
  }
  //make flightPlan
  string flightPlan() {
  if(dep.length() !=4 || dest.length() !=4){
    cout << "Only ICAO code permitted" << '\n';
  }
  else
  //controllo db
    if(dep==dest){
      cout << "non puoi mettere lo stesso aeroporto " << '\n';
    }
    else{
      string flightplan = dep +" - "+dest;
      return flightplan;
    }
  }
};

//display menu and build the object
void takeDataObject( string& ac, string& engineType, int& fuelLevel, string& depAirport, string& destAirport) {
  cout << "Insert ACF(Aircraft)" << '\n';
  cin >> ac;
  cout << "Insert Engine" << '\n';
  cin >> engineType;
  cout << "Insert fuel" << '\n';
  cin >> fuelLevel;
  cout << "Let's make your flightplan" << '\n';
  cout << "Enter Dep" << '\n';
  cin >> depAirport;
  cout << "Enter Dest" << '\n';
  cin >> destAirport;

}

int main(){
  string acf , engine, dep, dest;
  int fuel;
  takeDataObject(acf, engine, fuel, dep, dest);
  aeromobile aereo(acf, engine, fuel, dep, dest);
  aereo.checkFuel();
  cout << "Il Piano di volo è "<<aereo.flightPlan() << '\n';
}
