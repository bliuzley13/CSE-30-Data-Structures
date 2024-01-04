#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;


    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }

    std::vector<std::string>possibleSolutions(){
        // Your code here... 
        
        // Loops through the entire answers.txt
        // for (int i=0; i < answers.size(); i++){
        //     std::cout << answers[i] << std::endl;
        // }


        // For Green Constraint:
        //std::vector<std::string> green;    
        std::vector<std::string> greenResult;
        std::vector<std::string> yellowResult;
        std::vector<std::string> grayResult;
        //Iterates through whole answers.txt given
        for (int a = 0; a < answers.size(); a++){
            bool work = true;
            std::string word = answers[a];
            for (int b = 0; b < 5; b++){
                char greenchar = green[0][b];
                if (greenchar == '_') {
                    continue;
                }
                if (greenchar == word[b]){
                    continue;
                }
                work = false;
                break;
            }
            if (!work){
                continue;
            }
            greenResult.push_back(word);
        }

        for (int a2 = 0; a2 < greenResult.size(); a2++) {
            // For Yellow Constraint:
            bool work2 = true;
            std::string word2 = greenResult[a2];
            for (int c = 0; c < 5; c++){
                char yellowchar = yellow[0][c];
                if (yellowchar == '_') {
                    continue;
                }
                if (word2.find(yellowchar) != std::string::npos){
                    continue;
                }
                work2 = false;
                break;
            }
            if (!work2){
                continue;
            }
            yellowResult.push_back(word2);
        }
        
        // For Gray Constraint:
        for (int a3 = 0; a3 < yellowResult.size(); a3++) {
            bool work3 = true;
            std::string word3 = yellowResult[a3];
            for (int d = 0; d < word3.size(); d++){
                char graychar = gray[0][d];
                if (word3.find(graychar) == std::string::npos){
                    continue;
                }
                work3 = false;
                break;
            }
            if(!work3){
                continue;
            }
            grayResult.push_back(word3);
        }
        return grayResult;
        
    }

    std::vector<std::string> suggest(){
        // Optionally, your code here...
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }

    friend struct WordleTester;

};

#endif