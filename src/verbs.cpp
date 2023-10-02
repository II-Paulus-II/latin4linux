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
  futureTense.push_back("0");
  imperfectTense.push_back("0");
  perfectTense.push_back("0");
}

Verbs::Verbs(std::string onePP, std::string twoPP, std::string threePP)
{
  //Set principle parts
  firstPP = onePP;
  secondPP = twoPP;
  thirdPP = threePP;
  fourthPP = "0";

  //Identify the conjugation
  //1. get stem
  int secPPlength = secondPP.length();
  stem = secondPP.substr(0, secPPlength-3);
  int thirdPPlength = thirdPP.length();
  stem3PP = thirdPP.substr(0, thirdPPlength-1); //Dropping the i
  
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

  //4. Populate Tenses Vectors
  PresentTense();
  FutureTense();
  ImperfectTense();
  PerfectTense();
  PluperfectTense();
  FutureperfectTense();
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

void Verbs::FutureTense()
{

  std::string endings1[6] = { "abo", "abis", "abit", "abimus", "abitis", "abunt"};
  std::string endings2[6] = { "ebo", "ebis", "ebit", "ebimus", "ebitis", "ebunt"};
  std::string endings3[6] = { "am", "es", "et", "emus", "etis", "ent"};
  std::string endings4[6] = { "iam", "ies", "iet", "iemus", "ietis", "ient"};
  //push back 
  switch (conjugation)
  {
    case 1:
      {
        futureTense.push_back(stem + endings1[0]);
        futureTense.push_back(stem + endings1[1]);
        futureTense.push_back(stem + endings1[2]);
        futureTense.push_back(stem + endings1[3]);
        futureTense.push_back(stem + endings1[4]);
        futureTense.push_back(stem + endings1[5]);
      }
      break;
    case 2:
      {
        futureTense.push_back(stem + endings2[0]);
        futureTense.push_back(stem + endings2[1]);
        futureTense.push_back(stem + endings2[2]);
        futureTense.push_back(stem + endings2[3]);
        futureTense.push_back(stem + endings2[4]);
        futureTense.push_back(stem + endings2[5]);
      }
      break;
    case 3:
      {
        futureTense.push_back(stem + endings3[0]);
        futureTense.push_back(stem + endings3[1]);
        futureTense.push_back(stem + endings3[2]);
        futureTense.push_back(stem + endings3[3]);
        futureTense.push_back(stem + endings3[4]);
        futureTense.push_back(stem + endings3[5]);
      }
      break;
    case 4:
      {
        futureTense.push_back(stem + endings4[0]);
        futureTense.push_back(stem + endings4[1]);
        futureTense.push_back(stem + endings4[2]);
        futureTense.push_back(stem + endings4[3]);
        futureTense.push_back(stem + endings4[4]);
        futureTense.push_back(stem + endings4[5]);
      }
      break;
    default:
      futureTense.push_back("0");
      break;
  }
}

void Verbs::ImperfectTense()
{

  std::string endings1[6] = { "abam", "abas", "abat", "abamus", "abatis", "abant"};
  std::string endings2[6] = { "ebam", "ebas", "ebat", "ebamus", "ebatis", "ebant"};
  std::string endings3[6] = { "ebam", "ebas", "ebat", "ebamus", "ebatis", "abant"};
  std::string endings4[6] = { "iebam", "iebas", "iebat", "iebamus", "iebatis", "iebant"};
  //push back 
  switch (conjugation)
  {
    case 1:
      {
        imperfectTense.push_back(stem + endings1[0]);
        imperfectTense.push_back(stem + endings1[1]);
        imperfectTense.push_back(stem + endings1[2]);
        imperfectTense.push_back(stem + endings1[3]);
        imperfectTense.push_back(stem + endings1[4]);
        imperfectTense.push_back(stem + endings1[5]);
      }
      break;
    case 2:
      {
        imperfectTense.push_back(stem + endings2[0]);
        imperfectTense.push_back(stem + endings2[1]);
        imperfectTense.push_back(stem + endings2[2]);
        imperfectTense.push_back(stem + endings2[3]);
        imperfectTense.push_back(stem + endings2[4]);
        imperfectTense.push_back(stem + endings2[5]);
      }
      break;
    case 3:
      {
        imperfectTense.push_back(stem + endings3[0]);
        imperfectTense.push_back(stem + endings3[1]);
        imperfectTense.push_back(stem + endings3[2]);
        imperfectTense.push_back(stem + endings3[3]);
        imperfectTense.push_back(stem + endings3[4]);
        imperfectTense.push_back(stem + endings3[5]);
      }
      break;
    case 4:
      {
        imperfectTense.push_back(stem + endings4[0]);
        imperfectTense.push_back(stem + endings4[1]);
        imperfectTense.push_back(stem + endings4[2]);
        imperfectTense.push_back(stem + endings4[3]);
        imperfectTense.push_back(stem + endings4[4]);
        imperfectTense.push_back(stem + endings4[5]);
      }
      break;
    default:
      imperfectTense.push_back("0");
      break;
  }
}

void Verbs::PerfectTense()
{

  std::string endings1[6] = { "i", "isti", "it", "imus", "istis", "erunt"};
  std::string endings2[6] = { "i", "isti", "it", "imus", "istis", "erunt"};
  std::string endings3[6] = { "i", "isti", "it", "imus", "istis", "erunt"};
  std::string endings4[6] = { "i", "isti", "it", "imus", "istis", "erunt"};

  //push back 
  switch (conjugation)
  {
    case 1:
      {
        perfectTense.push_back(stem3PP + endings1[0]);
        perfectTense.push_back(stem3PP + endings1[1]);
        perfectTense.push_back(stem3PP + endings1[2]);
        perfectTense.push_back(stem3PP + endings1[3]);
        perfectTense.push_back(stem3PP + endings1[4]);
        perfectTense.push_back(stem3PP + endings1[5]);
      }
      break;
    case 2:
      {
        perfectTense.push_back(stem3PP + endings2[0]);
        perfectTense.push_back(stem3PP + endings2[1]);
        perfectTense.push_back(stem3PP + endings2[2]);
        perfectTense.push_back(stem3PP + endings2[3]);
        perfectTense.push_back(stem3PP + endings2[4]);
        perfectTense.push_back(stem3PP + endings2[5]);
      }
      break;

    case 3:
      {
        perfectTense.push_back(stem3PP + endings3[0]);
        perfectTense.push_back(stem3PP + endings3[1]);
        perfectTense.push_back(stem3PP + endings3[2]);
        perfectTense.push_back(stem3PP + endings3[3]);
        perfectTense.push_back(stem3PP + endings3[4]);
        perfectTense.push_back(stem3PP + endings3[5]);
      }
      break;
    case 4:
      {
        perfectTense.push_back(stem3PP + endings4[0]);
        perfectTense.push_back(stem3PP + endings4[1]);
        perfectTense.push_back(stem3PP + endings4[2]);
        perfectTense.push_back(stem3PP + endings4[3]);
        perfectTense.push_back(stem3PP + endings4[4]);
        perfectTense.push_back(stem3PP + endings4[5]);
      }
      break;
      perfectTense.push_back("0");
      break;
  }
}


void Verbs::PluperfectTense()
{

  std::string endings1[6] = { "eram", "eras", "erat", "eramus", "eratis", "erant"};
  std::string endings2[6] = { "eram", "eras", "erat", "eramus", "eratis", "erant"};
  std::string endings3[6] = { "eram", "eras", "erat", "eramus", "eratis", "erant"};
  std::string endings4[6] = { "eram", "eras", "erat", "eramus", "eratis", "erant"};
  //push back 
  switch (conjugation)
  {
    case 1:
      {
        pluperfectTense.push_back(stem3PP + endings1[0]);
        pluperfectTense.push_back(stem3PP + endings1[1]);
        pluperfectTense.push_back(stem3PP + endings1[2]);
        pluperfectTense.push_back(stem3PP + endings1[3]);
        pluperfectTense.push_back(stem3PP + endings1[4]);
        pluperfectTense.push_back(stem3PP + endings1[5]);
      }
      break;
    case 2:
      {
        pluperfectTense.push_back(stem3PP + endings2[0]);
        pluperfectTense.push_back(stem3PP + endings2[1]);
        pluperfectTense.push_back(stem3PP + endings2[2]);
        pluperfectTense.push_back(stem3PP + endings2[3]);
        pluperfectTense.push_back(stem3PP + endings2[4]);
        pluperfectTense.push_back(stem3PP + endings2[5]);
      }
      break;

    case 3:
      {
        pluperfectTense.push_back(stem3PP + endings3[0]);
        pluperfectTense.push_back(stem3PP + endings3[1]);
        pluperfectTense.push_back(stem3PP + endings3[2]);
        pluperfectTense.push_back(stem3PP + endings3[3]);
        pluperfectTense.push_back(stem3PP + endings3[4]);
        pluperfectTense.push_back(stem3PP + endings3[5]);
      }
      break;
    case 4:
      {
        pluperfectTense.push_back(stem3PP + endings4[0]);
        pluperfectTense.push_back(stem3PP + endings4[1]);
        pluperfectTense.push_back(stem3PP + endings4[2]);
        pluperfectTense.push_back(stem3PP + endings4[3]);
        pluperfectTense.push_back(stem3PP + endings4[4]);
        pluperfectTense.push_back(stem3PP + endings4[5]);
      }
      break;
      pluperfectTense.push_back("0");
      break;
  }
}

void Verbs::FutureperfectTense()
{

  std::string endings1[6] = { "ero", "eris", "erit", "erimus", "eritis", "erint"};
  std::string endings2[6] = { "ero", "eris", "erit", "erimus", "eritis", "erint"};
  std::string endings3[6] = { "ero", "eris", "erit", "erimus", "eritis", "erint"};
  std::string endings4[6] = { "ero", "eris", "erit", "erimus", "eritis", "erint"};
  //push back 
  switch (conjugation)
  {
    case 1:
      {
        futureperfectTense.push_back(stem3PP + endings1[0]);
        futureperfectTense.push_back(stem3PP + endings1[1]);
        futureperfectTense.push_back(stem3PP + endings1[2]);
        futureperfectTense.push_back(stem3PP + endings1[3]);
        futureperfectTense.push_back(stem3PP + endings1[4]);
        futureperfectTense.push_back(stem3PP + endings1[5]);
      }
      break;
    case 2:
      {
        futureperfectTense.push_back(stem3PP + endings2[0]);
        futureperfectTense.push_back(stem3PP + endings2[1]);
        futureperfectTense.push_back(stem3PP + endings2[2]);
        futureperfectTense.push_back(stem3PP + endings2[3]);
        futureperfectTense.push_back(stem3PP + endings2[4]);
        futureperfectTense.push_back(stem3PP + endings2[5]);
      }
      break;

    case 3:
      {
        futureperfectTense.push_back(stem3PP + endings3[0]);
        futureperfectTense.push_back(stem3PP + endings3[1]);
        futureperfectTense.push_back(stem3PP + endings3[2]);
        futureperfectTense.push_back(stem3PP + endings3[3]);
        futureperfectTense.push_back(stem3PP + endings3[4]);
        futureperfectTense.push_back(stem3PP + endings3[5]);
      }
      break;
    case 4:
      {
        futureperfectTense.push_back(stem3PP + endings4[0]);
        futureperfectTense.push_back(stem3PP + endings4[1]);
        futureperfectTense.push_back(stem3PP + endings4[2]);
        futureperfectTense.push_back(stem3PP + endings4[3]);
        futureperfectTense.push_back(stem3PP + endings4[4]);
        futureperfectTense.push_back(stem3PP + endings4[5]);
      }
      break;
      futureperfectTense.push_back("0");
      break;
  }
}

void Verbs::PrintVerbs()
{
  std::cout << "Principle Parts 1: " << firstPP << " 2: " << secondPP << " 3: " << thirdPP << "\n";
  std::cout << "Endings of Principle Parts are 1: " << firPPend << " 2: " << secPPend << "\n";
  std::cout << "stem is " << stem << "\n";
  std::cout << "conjugation is " <<conjugation << "\n";
  std::cout << "Present Tense is \n";
  for (const auto& element : presentTense) {
    std::cout << element << " ";
  }
  std::cout << "\nFuture Tense is \n";
  for (const auto& element : futureTense) {
    std::cout << element << " ";
  }
  std::cout << "\nImperfect Tense is \n";
  for (const auto& element : imperfectTense) {
    std::cout << element << " ";
  }
  std::cout << "\nPerfect Tense is \n";
  for (const auto& element : perfectTense) {
    std::cout << element << " ";
  }  
  std::cout << "\nPluperfect Tense is \n";
  for (const auto& element : pluperfectTense) {
    std::cout << element << " ";
  }
  std::cout << "\nFuture-Perfect Tense is \n";
  for (const auto& element : futureperfectTense) {
    std::cout << element << " ";
  }
  std::cout << "\n" << std::endl;
}
