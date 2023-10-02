#include "headers/verbs.h"

//NULL Constructor probably unnecessary but just in case I make one with no arguments somewhere
Verbs::Verbs()
{
  conjugation = "0";
  firstPP = "0";
  secondPP = "0";
  thirdPP = "0";
  fourthPP = "0";
  presentTense.push_back("0");
}

Verbs::Verbs(std::string onePP, std::string twoPP)
{
  //Set principle parts
  firstPP = onePP;
  secondPP = twoPP;
  thirdPP = "0";
  fourthPP = "0";

  //Identify the conjugation
  //1. get stem
  int PPlength = secondPP.length();
  stem = secondPP.substr(0, PPlength-3);
}

void Verbs::PrintVerbs()
{
  std::cout << stem << std::endl;

}
