#include "headers/noun.h"

Nouns::Nouns()
{
  declension = "0";
  gender = "0";
  nomCase = "0";
  vocCase = "0";
  accCase = "0";
  genCase = "0";
  datCase = "0";
  ablCase = "0";
}

Nouns::Nouns(std::string nomC, std::string genC, std::string gender) 
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
}
