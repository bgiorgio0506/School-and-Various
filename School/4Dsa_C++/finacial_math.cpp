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
     double percent;
     int compaunding;

  public:
    //cunstructor
     bank( double TotInvestiment, double RatePercent,int AnnualCompounding){
       investiment = TotInvestiment;
       percent = RatePercent;
       compaunding = AnnualCompounding;
     }
     //methods
     long CalculateInvestiment(){
       //Decleration of loacl vars
       double decimalP;
       double TotInvSum;
       long   TotInv;
       float  exp;

       //Calculate TotInv
       decimalP = percent/100;
       TotInvSum = decimalP/compaunding;
       TotInvSum = TotInvSum + 1;
       exp =  compaunding * percent+1; //Add one to the exponet
       TotInvSum =pow(TotInvSum,exp);
       TotInv = investiment * TotInvSum;

       return TotInv;
     }

     ~bank (){
       cout << "Ended" << '\n';
     }
};


int main() {
  double TotInvestiment, RatePercent;
  int  AnnualCompounding;
  bool continue;


  cout << "Insert the total of your investment" << '\n';
  cin >> TotInvestiment;
  cout << "Insert the rate in percent" << '\n';
  cin >> RatePercent;
  cout << "Insert Annual Compound" << '\n';
  cin >> AnnualCompounding;
  bank Inve1(TotInvestiment,RatePercent,AnnualCompounding);
  inv1 = Inve1.CalculateInvestiment()
  cout << "Final investment is: " << inv1 << '\n';
  Inv.~bank();
  return 0;
}
