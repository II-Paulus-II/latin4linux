/* BEST LATIN LINUX APP 2050 */

#include "headers/mainheader.h"

int main()
{
  //lets see first
  Verbs verb = Verbs("Laudo", "Laudare", "Laudavi");
  verb.PrintVerbs();
  Verbs verb1 = Verbs("Rego", "Regere", "Rexi");
  verb1.PrintVerbs();
  Verbs verb2 = Verbs("Moneo", "Monere", "Monui");
  verb2.PrintVerbs();
  Verbs verb3 = Verbs("Audio", "Audire", "Audivi");
  verb3.PrintVerbs();
  Verbs verb4 = Verbs("Amo", "Amare", "Amavi");
  verb4.PrintVerbs();

  //nouns print
  
  //Nouns noun1 = Nouns("Ars", "Artis", "Fem");
  //noun1.Printnouns();
  //Nouns noun2 = Nouns("Civis", "Civis", "m");
  //noun2.Printnouns();
  //Nouns noun3 = Nouns("Exemplar", "Exemplaris", "n");
  //noun3.Printnouns();
  //Nouns noun4 = Nouns("Regnum", "Regni", "fem");
  //noun4.Printnouns();
  //ncurses functions 
  std::cout << "Test fields" << std::endl;
  std::cin.get();
  ncursesWINDOW();
  std::cin.get();
  return 0;

}
