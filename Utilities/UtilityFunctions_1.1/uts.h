/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   uts.h
 * Author: scott_r_parker
 *
 * Created on May 10, 2017, 10:55 PM
 * 
 * Enables the following functions:
 * //Generate a random word 
 *      string rWord (int length=0)
 *      //Call this function without an argument to generate an all lowercase 
 *      //string of 2-8 letters in length (rand()%6+2)  if passed an integer 
 *      //argument it will generate a string of the length of the passed integer
 * //Generate a random first name
        string rNameF ()
 *      //Generates a string with a capital first letter of length rand()4+4
 * //generate a random first and last name
        string rName ()
 *      //Generates two random words separated by a space with the first letter
 *      //of each word capitalized (First and Last name)
 * //Generate a random sentences
        void lorem (int snt=0)
 *      //Generate sentences. If passed no argument will generate one sentence 
 *      //of 12-20 words. If passed an integer argument will integer number of
 *      //sentences. 
 * //Function to pause until enter is pressed
 *      //!!!*!!! Must input cin.ignore() in main based on input buffer status when 
 *      //!!!!!!! calling this function!
        void pauser()
 * 
 */

#ifndef UTS_H
#define UTS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

namespace uts {
    
    //Function to pause until enter is pressed
    void pauser() {
        string pauser;
        cout<<"Press <ENTER> to continue"<<endl;
        getline(cin, pauser);
    }
    
    //Generate a random word
    string rWord (int length=0) {
        string word="";
        if (length==0) length=rand()%6+2;
        char temp='\0';
        int count=0;
        for (int i=0;i<length;i++) {
            if (temp!='a' || temp!='e' || temp!='i' || temp!='o' || temp!='u' || temp!='y') {
                count++;
            } else {
                count=0;
            }
            if (count<3) {
                temp=rand()%26+97;
            } else {
                count=0;
                int vowel=rand()%6;
                switch (vowel) {
                    case 5:{temp='y';break;}
                    case 4:{temp='u';break;}
                    case 3:{temp='o';break;}
                    case 2:{temp='i';break;}
                    case 1:{temp='e';break;}
                    default:temp='a';
                }
            }
            word+=temp;
        }
        return word;
    }
    
    //Generate a random first name
    string rNameF () {
        string word="";
        int length=rand()%6+3;
        int count=0;
        char temp='\0';
        for (int i=0;i<length;i++) {
            if (temp!='a' || temp!='e' || temp!='i' || temp!='o' || temp!='u' || temp!='y') {
                count++;
            } else {
                count=0;
            }
            if (count<3) {
                temp=rand()%26+97;
            } else {
                count=0;
                int vowel=rand()%6;
                switch (vowel) {
                    case 5:{temp='y';break;}
                    case 4:{temp='u';break;}
                    case 3:{temp='o';break;}
                    case 2:{temp='i';break;}
                    case 1:{temp='e';break;}
                    default:temp='a';
                }
            }
            if (i==0) {
                temp=toupper(temp);
            }
            word+=temp;
        }
        return word;
    }
    
    //generate a random first and last name
    string rName () {
        string word="";
        word+= rNameF ();
        word+=" ";
        word+=rNameF ();
        return word;
    }
    
    //Generate a random sentences
    void lorem (int snt=0) {
        int sents=0, words=0;
        string phrase="";
        if (snt==0) {
            sents=1;
        } else { 
            sents=snt;
        }
        for (int i=0;i<sents;i++) {
            char temp='\0';
            temp=rand()%26+65; //first letter of sentence capital
            phrase+=temp;
            words=rand()%8+12;
            for (int j=0;j<words;j++) {
                phrase+=rWord(); //call function to generate lowercase word
                if (j==words-1) {
                    phrase+=". ";
                } else {
                    phrase+=" ";
                }
                if (phrase.length()>=67){ //check for width to see output
                    cout<<phrase<<endl;
                    phrase.clear();
                }
            }
        }
        cout<<phrase<<endl;
    }



}

#endif /* UTS_H */

