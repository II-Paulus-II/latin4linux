#include "headers/verbs.h"

//NULL Constructor probably unnecessary but just in case I make one with no arguments somewhere
Verbs::Verbs()
{
  conjugation = 0;
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
  int secPPlength = secondPP.length();
  stem = secondPP.substr(0, secPPlength-3);
  
  //2.Get ends of Princple Parts
  int stemLength = stem.length();
  int firPPlength = firstPP.length();
  std::string firPPend = firstPP.substr(stemLength, firPPlength);
  //Test print cos im in basic development go away with your angry stares
  std::cout << "First Principle Part End is: " << firPPend << std::endl;
  std::string secPPend = secondPP.substr(stemLength, secPPlength);
  //test print
  std::cout << "Second Principle Part End is: " << secPPend << std::endl;

  //3. Choose conjugation, regulars only gonna make this better for irregular and -io verbs later
  if (firPPend == "o" && secPPend == "are")
  {
    conjugation = 1;
  }
  else if (firPPend == "eo" && secPPend == "ere")
  {
    conjugation = 2;
  }
  else if (firPPend == "o" && secPPend == "ere")
  {
    conjugation = 3;
  }
  else if (firPPend == "o" && secPPend == "ire")
  {
    conjugation = 4;
  }

}

void Verbs::PrintVerbs()
{
  std::cout << stem << std::endl;
  std::cout << conjugation << std::endl;

}
