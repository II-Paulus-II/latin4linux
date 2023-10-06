#include "headers/noun.h"

Nouns::Nouns()
{
  declension = 0;
  gender = "0";
  nomCase = "0";
  vocCase = "0";
  accCase = "0";
  genCase = "0";
  datCase = "0";
  ablCase = "0";
}

Nouns::Nouns(std::string nomC, std::string genC, std::string gend) 
{
  nomCase = nomC;
  genCase = genC;
  gender = gend;

  //select Declension
  
  int nomcaseLen = nomCase.length();
  int gencaseLen = genCase.length();
  signed int difference = nomcaseLen - gencaseLen;

  std::string nomcaseEnd = nomCase.substr(nomcaseLen-1, 1);
  std::string gencaseEnd = genCase.substr(gencaseLen -1,1);

  std::string nomcase2End = nomCase.substr(nomcaseLen-2, 2);
  std::string gencase2End = genCase.substr(gencaseLen-2, 2);

  switch (difference)
  {
    case -1:
    {
      if ((gencase2End == "ae") && (nomcaseEnd == "a"))
      {
        declension = 1; // 1 for first declension rosa/rosae
        Declinefirst();
      }
      else if ((gencaseEnd == "i") && (nomcase2End == "er"))
      {
       declension = 22; //2 for 2nd declension 2 for type puer,pueri
      }
      else if ((gencase2End == "us") && (nomcaseEnd == "u"))
      {
       declension = 42; //4th declension type genu/genus
      }
      else if ((gencase2End == "us") && (nomcaseEnd == "o"))
      {
        declension = 43; //4th declension type hero/herus
      }
      break;
    }
    case 0:
    {
      if ((gencase2End == "ri") && (nomcase2End == "er"))
      {
        declension = 23; //2 for 2nd declension 3 for type ager/agri
      }
      else if ((gencase2End == "us") && (nomcase2End == "us"))
      {
        declension = 41; //type gradus/gradus
      }
      else if ((gencase2End == "ei") && nomcase2End == "es")
      {
        declension = 5; // type dies/diei 
      }
      break;
    }
    case 1:
    {
      if ((gencaseEnd == "i") && (nomcase2End == "us"))
      {
        declension = 21; //2 for 2nd decl 1 for type oculus/oculi
      }
      else if ((gencaseEnd == "i") && (nomcase2End == "um"))
      {
        declension = 24; //2 for 2decl and 4 for type regnum/regni
      }
      break;
    }
    default:
    {
      Declinethird();
      break;
    }
  }

}

void Nouns::Declinefirst()
{
  std::string EndingsSg[6] = { "a", "a", "am", "ae", "ae", "a"};
  std::string EndingsPl[6] = { "ae", "ae", "as", "arum", "is", "is"};
  int stemLen = nomCase.length() -1;
  std::string stem = nomCase.substr(0, stemLen);
  vocCase = stem + EndingsSg[1];
  accCase = stem + EndingsSg[2];
  datCase = stem + EndingsSg[4];
  ablCase = stem + EndingsSg[5];
  nompluCase = stem + EndingsPl[0];
  vocpluCase = stem + EndingsPl[1];
  accpluCase = stem + EndingsPl[2];
  genpluCase = stem + EndingsPl[3];
  datpluCase = stem + EndingsPl[4];
  ablpluCase = stem + EndingsPl[5];
}

void Nouns::Declinesecond()
{

}

void Nouns::Declinethird()
{
  std::cout << "third declension is complex" << std::endl;
  declension = 3; //for nows
}

void Nouns::Declinefourth()
{

}

void Nouns::Declinefifth()
{

}

void Nouns::Printnouns()
{
  std::cout << "Declension: " << declension << " Gender: " << gender << "\n";
  std::cout << "Nominative Case: " << nomCase << "\n";
  std::cout << "Vocative Case: " << vocCase << "\n";
  std::cout << "Accusative Case: " << accCase << "\n";
  std::cout << "Genitive Case: " << genCase << "\n";
  std::cout << "Dative Case: " << datCase << "\n";
  std::cout << "Ablative Case: " << ablCase << std::endl;

  std::cout << "Nominative Plural Case: " << nompluCase << "\n";
  std::cout << "Vocative Plural Case: " << vocpluCase << "\n";
  std::cout << "Accusative Plural Case: " << accpluCase << "\n";
  std::cout << "Genitive Plural Case: " << genpluCase << "\n";
  std::cout << "Dative Plural Case: " << datpluCase << "\n";
  std::cout << "Ablative Plural Case: " << ablpluCase << std::endl;
}
