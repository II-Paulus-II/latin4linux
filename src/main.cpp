/* BEST LATIN LINUX APP 2050 */

#include "headers/mainheader.h"

int main()
{
  //lets see first
  Verbs verb = Verbs("Laudo", "Laudare");
  verb.PrintVerbs();
  Verbs verb1 = Verbs("Rego", "Regere");
  verb1.PrintVerbs();
  Verbs verb2 = Verbs("Moneo", "Monere");
  verb2.PrintVerbs();
  std::cin.get();
  return 0;

}
