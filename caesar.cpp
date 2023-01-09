#include<iostream>
#include<string>
#include<map>
#include<vector>


namespace caesar{


#define RUSSIAN 1
#define ENGLISH 2


std::string rus = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
std::string eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
std::string punctuation_symbols = " !'.,?(){}[];:~`+=-|*&^%$#№@";
std::string digits = "0123456789";



std::string get_language(std::string language){

    std::map<std::string, int> language_mapping;
    language_mapping["rus"] = RUSSIAN;
    language_mapping["eng"] = ENGLISH;


    switch (language_mapping[language])
    {
    case RUSSIAN:
        return rus + punctuation_symbols + digits;
    case ENGLISH:
        return eng + punctuation_symbols + digits;
    default:
        throw std::invalid_argument("incorrect language");
    }
}


std::string encryption(int key, std::string text, std::string language){

    std::string result;

    for(int i = 0 ; i < text.length(); i++)
        result.push_back(language[(language.find(text[i]) + key) % language.length()]);

    return result;
} 


std::string decryption(int key, std::string text, std::string language){

    std::string result;

    for(int i = 0 ; i < text.length(); i++)
        result.push_back(language[(language.find(text[i]) - key) % language.length()]);

    return result;
} 


// int main(int argc, char* argv[]){
//     std::string text = "Hello world!";
//     std::string encrypted_text = encryption(5, text, get_language(argv[1]));
//     std::string decrypted_text = decryption(5, encrypted_text, get_language(argv[1]));
//     std::cout << text << std::endl;
//     std::cout << encrypted_text << std::endl;
//     std::cout << decrypted_text << std::endl;
    

//     return 0;
// }


}