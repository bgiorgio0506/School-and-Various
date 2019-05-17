/*
This program was made for school purposes and contain some exercices that I have made from my exchange year
--- Coded by Giorgio Bella 17/05/19 License GNU 3.0 ---

 The program is coded based on the oop rules
*/
//including libs
#include "iostream"
#include "math.h"

using namespace std;

class bank{
   private:
     long investiment;
     int percent;
     int compaunding;

  public:
    //cunstructor
     bank( long TotInvestiment, int RatePercent,int AnnualCompounding){
       investiment = TotInvestiment;
       percent = RatePercent;
       compaunding = AnnualCompounding;
     }
     //methods
     float CalculateInvestiment(){
       double decimalP;
       long TotInvSum;
       decimalP = percent/100;
       //cout << decimalP << '\n';
       TotInvSum =1+decimalP/compaunding;
       //cout << TotInvSum << '\n';
       TotInvSum =investiment * TotInvSum;
       //cout << TotInvSum << '\n';
       //TotInvSum = pow(5,TotInvSum);
       //cout << TotInvSum << '\n';
       return TotInvSum;
     }

     ~bank (){
       cout << "object destroy" << '\n';
     }
};

int main() {
  long TotInvestiment;
  int RatePercent, AnnualCompounding;

  cout << "Insert the total of your investment" << '\n';
  cin >> TotInvestiment;
  cout << "Insert the rate in percent" << '\n';
  cin >> RatePercent;
  cout << "Insert Annual Compound" << '\n';
  cin >> AnnualCompounding;
  bank Inv(TotInvestiment,RatePercent,AnnualCompounding);
  TotInvestiment = Inv.CalculateInvestiment();
  //cout << "Final investment is: " << Inv.CalculateInvestiment() << '\n';
  Inv.~bank();
  return 0;
}
