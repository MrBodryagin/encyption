#include "tools/language.h"



int main(){

    language::Language russian_lang = language::Language("rus", language::rus_capital_letter, language::rus_lowercase_letter);
    std::cout << russian_lang.lower("Всем привет!") << std::endl;

    return 0;
}