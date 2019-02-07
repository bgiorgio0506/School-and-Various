#include "stdlib.h"
#include "iostream"
#include "string.h"

namespace std::aeromobile{

class aeromobile {
private:
  string type, engine, dep, dest;
  int fuel, altitude_set, heading_set, radio_altimeter, thrust_set;
  bool takeoff, autopilot;

  private void refuel(int) {
    std::cout << "Insert refuel amount" << '\n';
    std::cin >> fuel;
  }


public:
 aeromobile(string, string, string, string, int);
void fuel(int fuel) {
  //if you have no fuel
  if (fuel == 0){
    for (size_t i = 0; i < 101; i++) {
      fuel++;
    }
    std::cout << "sei stato rifornito" << '\n';
  }
  if (fuel<50) {
    fuel1 = fuel
    std::cout << "You are runnig out of fuel please refuel" << '\n';
    fuel = refuel(fuel);
    if (fuel1<fuel) {
      std::cout << "Good job you refueled your aircraft" << fuel << '\n';
    }
  }
  return fuel;
}

int flightplan(string dep, string dest) {
if(strlen(dep)!=4 && strlen(dest)!=4){
  std::cout << "Only ICAO code permitted" << '\n';
}
else
//controllo db
  if(dep==dest){
    std::cout << "non puoi mettere lo stesso aeroporto " << '\n';
  }
  else{
    string flightplan = dep + dest;
    return flightplan
  }
}

};

aeromobile::aeromobile(string acf, string engine, string dep, string dest, int fuel){
  type = acf;
  engine = engine;
  dep = dep;
  dest = dest;
  fuel = fuel;
}
int take_data_object(string acf, string engine, string dep, string dest,int fuel) {
  std::cout << "Insert ACF(Aircraft)" << '\n';
  std::cin >> acf;
  std::cout << "Insert Engine" << '\n';
  std::cin >> engine;
  std::cout << "Insert fuel" << '\n';
  std::cin >> fuel;
  std::cout << "Let's make your flightplan" << '\n';
  std::cout << "Enter Dep" << '\n';
  std::cin >> dep;
  std::cout << "Enter Dest" << '\n';
  std::cin >> dest;

   aeromobile B737(acf, engine, dep, dest, fuel);
   return B737;
}
main(){
  string acf,engine,dep,dest;
  int fuel;
  B737= take_data_object(acf,engine,dep,dest,fuel);  std::cin >> dep;
std::cout << "Il fuel è"<<aeromobile.fuel(fuel) << '\n';
std::cout << "Il Piano di volo è "<<aeromobile.flightplan(dep,dest) << '\n';

}
