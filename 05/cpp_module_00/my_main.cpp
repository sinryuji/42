#include "MyWarlock.hpp"

int main()
{
  MyWarlock bob;                            //Does not compile
  MyWarlock bob("Bob", "the magnificent");  //Compiles
  Warlock jim("Jim", "the nauseating");   //Compiles
  bob = jim;                              //Does not compile
  Warlock jack(jim);                      //Does not compile
}
