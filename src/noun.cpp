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

  std::string nomcaseEnd = nomCase.substr(nomcaseLen-1, nomcaseLen-1);
  std::string gencaseEnd = genCase.substr(gencaseLen -1, gencaseLen-1);

  std::string nomcase2End = nomCase.substr(nomcaseLen-2, nomcaseLen-1);
  std::string gencase2End = genCase.substr(gencaseLen-2, gencaseLen-1);

  if ((nomcaseLen - gencaseLen) == -1) //ill make a switch in a bit
  {
    if ((gencase2End == "ae") && (nomcaseEnd == "a"))
    {
      declension = 1; // 1 for first declension rosa/rosae
    }
    else if ((gencaseEnd == "i") && (nomcase2End == "er"))
    {
      declension = 22; //2 for 2nd declension 2 for type puer,pueri
    }
    else if ((gencase2End == "us") && (nomcaseEnd == "u"))
    {
      declension = 42; //4th declension type genu/genus
    }
  }
  else if (nomcaseLen == gencaseLen)
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
  }
  else if ((nomcaseLen - gencaseLen) == 1)
  {
    if ((gencaseEnd == "i") && (nomcase2End == "us"))
    {
      declension = 21; //2 for 2nd decl 1 for type oculus/oculi
    }
    else if ((gencaseEnd == "i") && (nomcase2End == "um"))
    {
      declension = 24; //2 for 2nd decl 4 for type regnum/regni
    }

  }


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
}
