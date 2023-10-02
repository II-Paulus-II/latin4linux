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
  std::cout << "Press a key to enter ncurses window" << std::endl;
  std::cin.get();
  ncursesWINDOW();
  return 0;

}
