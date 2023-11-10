// p1.cpp : Defines the entry point for the application.
//

#include "p1.h"

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <map>
//using namespace std;

int fibonacci(int n) {
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n > 2) {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

class Coder {
public:
    std::string corpus;
    Coder(std::string p_corpus) {
        p_corpus = corpus;
    }

    std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }


    std::map<std::string, int> encode(std::string corpus, std::string s) {
        std::map<std::string, int> dict;
        std::map<std::string, int> input_dict;
        std::vector<std::string> strs = split(corpus, " ");
        std::vector<std::string> input_strs = split(s, " ");

        int N = strs.size();
        std::vector<int>* code = new std::vector<int>[N];
        for (int i = 0; i < strs.size(); i++) {
            dict[strs[i]] = fibonacci(i + 1);
            //std::cout << strs[i] << " " << dict[strs[i]] << std::endl;
        }

        for (int i = 0; i < input_strs.size(); i++) {
            std::map<std::string, int>::iterator it = dict.find(input_strs[i]);
            if (it != dict.end())
            {
                std::cout << it->second << " ";
                input_dict[input_strs[i]] = it->second;
                //it->second = false;
            }

        }
        return input_dict;
    }

    std::map<int, std::string> decode(std::string corpus, std::vector<int> vect) {
        std::map<int, std::string> dict;
        std::map<int, std::string> input_dict;
        std::vector<std::string> strs = split(corpus, " ");
        //std::vector<std::string> input_strs = split(s, " ");

        int N = strs.size();
        std::vector<int>* code = new std::vector<int>[N];
        for (int i = 0; i < strs.size(); i++) {
            dict[fibonacci(i + 1)] = strs[i];
            //std::cout << strs[i] << " " << dict[strs[i]] << std::endl;
        }

        for (int i = 0; i < vect.size(); i++) {
            std::cout << dict[vect[i]] << " ";
            input_dict[vect[i]] = dict[vect[i]];

        }
        return input_dict;
    }
};


int main()
{
    std::string corp = "This, is the string";
    Coder c(corp);
    /*std::vector<std::string> strs = c.split(corp, " ");
    for (int i = 0; i < strs.size(); i++) {
        std::cout << strs[i] << std::endl;
    }*/
    std::vector<int> vec = { 1, 3, 5, 2 };
    std::cout << "Encoding: " << std::endl;
    std::map<std::string, int> enc = c.encode(corp, "is the string This,");
    std::cout << "\nDecoding: " << std::endl;
    std::map<int, std::string> denc = c.decode(corp, vec);
    return 0;
}
