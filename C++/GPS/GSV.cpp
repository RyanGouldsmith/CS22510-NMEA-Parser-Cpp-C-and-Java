#include <vector>
#include <iostream>
#include "GSV.h"
#include <vector>
#include "string.h"
#include <stdlib.h>
/*!
 * \file GSV.cpp
 *
 * \author Ryan Gouldsmih
 * \date 28th March
 *
 * This implements the methods in the GSV class.Mainly this gets the SNR values from a given sentence, adds them to a vector and check
 * to see if they're a good result.
 */
using namespace std;
/**
* The constructor for the GSV senetence, where it get calls another function which gets the SNR numbers
* @param sentences is a vector of GSV sentences read in.
*/
GSV::GSV(std::vector<char*> sentences)
{
    for (unsigned int i =0; i < sentences.size(); i++)
    {
        getSNRNumber(sentences.at(i));
    }
}
/**
* This gets all the SNR Numbers from a GSV sentence and puts them into a vector of SNR values, which will be loopable to check the values
* @param line is a pointer to a chair, which represents a single GSV sentence out of a group of them
*/
void GSV::getSNRNumber(char* line)
{
    unsigned int i;
    std::vector<char*> temp = addValuesToVector(line);
    //checks to see if its not null
    if(temp.at(3) != NULL)
    {
        //loops to the last of the four items of a satellite information, getting the SNR value
        //REFERENCE : http://nmeaparser.googlecode.com/svn-history/r24/trunk/NMEAParser/SentenceHandlers/GPGSV.cs
        for (i = 4; i+3 < temp.size(); i +=4)
        {
            if (strcmp(temp.at(i+3), "*") == 0)
            {
                //Get the value at i+3
                string temp_str(temp.at(i+3));
                //removes the last 3 digits
                temp_str = temp_str.substr(0, temp_str.size() -3);
                //copy the c style strint to the temp vector
                strcpy(temp.at(i+3), temp_str.c_str());
            }
            //if there isn't an empty space
            if (strcmp(temp.at(i+3), "") == 1)
            {
                //add the values to the SNR vector
                this->snrValues.push_back(atoi(temp[i+3]));
            }
        }
    }
}
/**
* this checks whether the values for the SNR are a good fix by if 3 or more satellites are > 35.
* @returns true or false depending on whether it's a good fix
*/
bool GSV::isFixGood()
{
    unsigned int accepted =0 ;
    //loops over the SNR vector.
    for (unsigned int i =0 ; i < snrValues.size(); i++)
    {
        //checks to see if the number is 35
        if (snrValues.at(i)> 35)
        {
            //increment accepted
            accepted++;
        }
    }
    if (accepted >= 3)
    {
        return true;
    }
    return false;
}
/**
* This adds all lines to a vector by splitting them into tokens and adding them to the vector
* @para *line is the sentence line which is being split and added to the vecor
* @returns a vector of char* which has been split into tokens.
*/
vector<char*> GSV::addValuesToVector(char* line)
{
    char *tokens;
    //split with a ,
    char *delimeter = ",";
    char *line_char = line;
    //copy the line overto the array
    strcpy(line_char, line);
    //split on the delimter into tokens
    tokens = strtok(line_char, delimeter);
    vector<char*> sentence;
    //check there are still tokens
    while (tokens != NULL)
    {
        //add the tokens to the vector
        sentence.push_back(tokens);
        tokens = strtok(NULL, delimeter);
    }
    return sentence;
}
