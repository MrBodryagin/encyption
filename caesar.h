#include<string>
#include<vector>
#include "tools/language.h"

#pragma once


namespace caesar
{


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


}