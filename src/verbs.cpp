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
  firPPend = firstPP.substr(stemLength, firPPlength);
  secPPend = secondPP.substr(stemLength, secPPlength);

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
  else if (firPPend == "io" && secPPend == "ire")
  {
    conjugation = 4;
  }

  //4. Populate Present Tense Vector
  PresentTense();
}

void::Verbs::PresentTense()
{
  std::string endings1[6] = { "o", "as", "at", "amus", "atis", "ant"};
  std::string endings2[6] = { "eo", "es", "et", "emus", "etis", "ent"};
  std::string endings3[6] = { "o", "is", "it", "imus", "itis", "unt"};
  std::string endings4[6] = { "io", "is", "it", "imus", "itis", "iunt"};
  //push back 
  switch (conjugation)
  {
    case 1:
      {
        presentTense.push_back(stem + endings1[0]);
        presentTense.push_back(stem + endings1[1]);
        presentTense.push_back(stem + endings1[2]);
        presentTense.push_back(stem + endings1[3]);
        presentTense.push_back(stem + endings1[4]);
        presentTense.push_back(stem + endings1[5]);
      }
      break;
    case 2:
      {
        presentTense.push_back(stem + endings2[0]);
        presentTense.push_back(stem + endings2[1]);
        presentTense.push_back(stem + endings2[2]);
        presentTense.push_back(stem + endings2[3]);
        presentTense.push_back(stem + endings2[4]);
        presentTense.push_back(stem + endings2[5]);
      }
      break;
    case 3:
      {
        presentTense.push_back(stem + endings3[0]);
        presentTense.push_back(stem + endings3[1]);
        presentTense.push_back(stem + endings3[2]);
        presentTense.push_back(stem + endings3[3]);
        presentTense.push_back(stem + endings3[4]);
        presentTense.push_back(stem + endings3[5]);
      }
      break;
    case 4:
      {
        presentTense.push_back(stem + endings4[0]);
        presentTense.push_back(stem + endings4[1]);
        presentTense.push_back(stem + endings4[2]);
        presentTense.push_back(stem + endings4[3]);
        presentTense.push_back(stem + endings4[4]);
        presentTense.push_back(stem + endings4[5]);
      }
      break;
    default:
      presentTense.push_back("0");
      break;
  }
}

void Verbs::PrintVerbs()
{
  std::cout << "Principle Parts 1: " << firstPP << " & 2: " << secondPP << "\n";
  std::cout << "Endings of Principle Parts are 1: " << firPPend << " & 2: " << secPPend << "\n";
  std::cout << "stem is " << stem << "\n";
  std::cout << "conjugation is " <<conjugation << "\n";
  for (const auto& element : presentTense) {
    std::cout << element << " ";
  }
  std::cout << "\n" << std::endl;
}
