#include <iostream>
#include <string>

class Nouns
{
  public:
    Nouns();
    Nouns(std::string nomC, std::string genC, std::string gend);
    void Printnouns();
  private:
    int declension;
    std::string gender;
    std::string nomCase;
    std::string vocCase;
    std::string accCase;
    std::string genCase;
    std::string datCase;
    std::string ablCase;
};
