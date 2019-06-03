#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
class menu {
  private:
    typedef  float lato;
    typedef std::string choices;
    lato lato1,lato2 ,lato3 ;
    choices choosen;
  public :

    menu(){
      //using std:: to indicate std namespace
      std::cout << "Inizializing Menu..." << '\n';
      choosen = "";
    }
    // destroy
    ~menu();
  };
#endif
