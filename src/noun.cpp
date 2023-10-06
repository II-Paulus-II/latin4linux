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
          Declinesecond();
        }
      else if ((gencase2End == "us") && (nomcaseEnd == "u"))
        {
          declension = 42; //4th declension type genu/genus
          Declinefourth();
        }
      else if ((gencase2End == "us") && (nomcaseEnd == "o"))
        {
          declension = 43; //4th declension type hero/herus
        }
      }
      break;
    case 0:
      {
      if ((gencase2End == "ri") && (nomcase2End == "er"))
        {
          declension = 23; //2 for 2nd declension 3 for type ager/agri
          Declinesecond();
        }
      else if ((gencase2End == "us") && (nomcase2End == "us"))
        {
          declension = 41; //type gradus/gradus
          Declinefourth();
        }
      else if ((gencase2End == "ei") && nomcase2End == "es")
        {
          declension = 5; // type dies/diei 
          Declinefifth();
        }
      }
      break;
    case 1:
      {
        if ((gencaseEnd == "i") && (nomcase2End == "us"))
        {
          declension = 21; //2 for 2nd decl 1 for type oculus/oculi
          Declinesecond();
        }
        else if ((gencaseEnd == "i") && (nomcase2End == "um"))
        {
          declension = 24; //2 for 2decl and 4 for type regnum/regni
          Declinesecond();
        }
      }
      break;
    default:
      {
        Declinethird();
      }
      break;
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
  switch (declension)
  {
    case 21: //oculus,oculi
      {
        std::string EndingsSg[6] = { "us", "e", "um", "i", "o", "o"};
        std::string EndingsPl[6] = { "i", "i", "os", "orum", "is", "is"};
        int stemLen = nomCase.length() -2;
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
      break;
    case 22: //puer,pueri
      {
        std::string EndingsSg[6] = { "", "", "um", "i", "o", "o"};
        std::string EndingsPl[6] = { "i", "i", "os", "orum", "is", "is"};
        int stemLen = nomCase.length();
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
      break;
    case 23: //ager,agri
      {
        std::string EndingsSg[6] = { "er", "er", "rum", "ri", "ro", "ro"};
        std::string EndingsPl[6] = { "ri", "ri", "ros", "rorum", "ris", "ris"};
        int stemLen = nomCase.length() -2;
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
      break;
    case 24: //regnum,regni
      {
        std::string EndingsSg[6] = { "um", "um", "um", "i", "o", "o"};
        std::string EndingsPl[6] = { "a", "a", "a", "orum", "is", "is"};
        int stemLen = nomCase.length() -2;
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
      break;
  }
}

void Nouns::Declinethird()
{
  std::cout << "third declension is complex AAA" << std::endl;
  declension = 3; //for nows
}

void Nouns::Declinefourth()
{
  switch(declension)
  {
    case 41: // type gradus/gradus
      {
        std::string EndingsSg[6] = { "us", "us", "um", "us", "ui", "u"};
        std::string EndingsPl[6] = { "us", "us", "us", "uum", "ibus", "ibus"};
        int stemLen = nomCase.length() -2;
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
      break;
    case 42: //case genu/genus
      {
        std::string EndingsSg[6] = { "u", "u", "u", "us", "u", "u"};
        std::string EndingsPl[6] = { "ua", "ua", "ua", "uum", "ibis", "ibis"};
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
      break;
  }
}

void Nouns::Declinefifth()
{
  std::string EndingsSg[6] = { "es", "es", "em", "ei", "ei", "e"};
  std::string EndingsPl[6] = { "es", "es", "es", "erum", "ebus", "ebus"};
  int stemLen = nomCase.length() -2;
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
