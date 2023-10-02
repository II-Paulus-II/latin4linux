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
    std::string conjugation;
    std::string firstPP;
    std::string secondPP;
    std::string thirdPP;
    std::string fourthPP;
    std::string stem; 
    std::vector<std::string> presentTense;
};


