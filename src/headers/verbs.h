#include <iostream>
#include <string>
#include <vector>

class Verbs
{
  public:
  Verbs();
  Verbs(std::string onePP, std::string twoPP); //for now
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
    std::vector<std::string> presentTense;

    //Private Methods
    void PresentTense();

};


