#include<map>
#include<string>
#include<iostream>


#pragma once


namespace language
{
    #define RUSSIAN 1
    #define ENGLISH 2

    std::string rus_capital_letter = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::string rus_lowercase_letter = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::string eng_capital_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string eng_lowercase_letter = "abcdefghijklmnopqrstuvwxyz";
    std::string punctuation_symbols = " !'.,?(){}[];:~`+=-|*&^%$#№@";
    std::string digits = "0123456789";


    class Language{
        public:
            std::string name;
            std::string capital_letters;
            std::string lowercase_letters;
            std::string all_symbols;

            Language(std::string, std::string, std::string);
            ~Language();

            std::string lower(std::string);
            bool symbols_in_string(std::string, char);
    };


    Language::Language(std::string name, std::string capital_letters, std::string lowercase_letters){
        this->name = name;
        this->capital_letters = capital_letters;
        this->lowercase_letters = lowercase_letters;
        this->all_symbols = capital_letters + lowercase_letters + digits + punctuation_symbols;
    }


    Language::~Language(){
        std::cout << "Delete Language" << std::endl;
    }


    std::string Language::lower(std::string text){
        std::cout << text << std::endl; 
        for (int i = 0; i < text.length(); i++)
            if (symbols_in_string(this->capital_letters, text[i]))
        {
            std::cout << text.length() << std::endl;
            text[i] = this->lowercase_letters[this->capital_letters.find(text[i])];
        }
        return text;        
    }


    bool Language::symbols_in_string(std::string text, char c){
        for (int i = 0; i < text.length(); i++)
            if (text[i] == c)
                return true;
        return false;
    }



    
    // std::string get_language(std::string language){

    //     std::map<std::string, int> language_mapping;
    //     language_mapping["rus"] = RUSSIAN;
    //     language_mapping["eng"] = ENGLISH;


    //     switch (language_mapping[language])
    //     {
    //     case RUSSIAN:
    //         return rus_capital_letter + rus_lowercase_letter + punctuation_symbols + digits;
    //     case ENGLISH:
    //         return eng_capital_letter + eng_lowercase_letter + punctuation_symbols + digits;
    //     default:
    //         throw std::invalid_argument("incorrect language");
    //     }
    // }




}