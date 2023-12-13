/* Some verbs only have three principle parts despite being regular verbs
 * So need constructors for verbs with 3 and 4 principle parts */

#include "precompiled.h"

class Verbs
{
  public:
  Verbs();
  Verbs(std::string onePP, std::string twoPP, std::string threePP); 
  Verbs(std::string onePP, std::string twoPP, std::string threePP, std::string fourPP);
  void PrintVerbs();
  
  private:
    int conjugation;
    std::string firstPP;
    std::string firPPend;
    std::string secondPP;
    std::string secPPend;
    std::string thirdPP;
    std::string fourthPP;
    std::string stem;
    std::string stem3PP;
    std::vector<std::string> presentTense;
    std::vector<std::string> futureTense;
    std::vector<std::string> imperfectTense;
    std::vector<std::string> perfectTense;
    std::vector<std::string> pluperfectTense;
    std::vector<std::string> futureperfectTense;
    std::vector<std::string> presentpassiveTense;

    //Private Methods
    void SelectConjugation();
    void PresentTense();
    void FutureTense();
    void ImperfectTense();
    void PerfectTense();
    void PluperfectTense();
    void FutureperfectTense();
    void PresentpassiveTense();

};
