#include <iostream>
#include <string>
#include <vector>

class Verbs
{
  public:
  Verbs();
  Verbs(std::string onePP, std::string twoPP, std::string threePP); //for now
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

    //Private Methods
    void PresentTense();
    void FutureTense();
    void ImperfectTense();
    void PerfectTense();
    void PluperfectTense();
    void FutureperfectTense();

};


