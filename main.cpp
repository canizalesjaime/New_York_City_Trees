/******************************************************************************************************************************************
Title  : main.cpp
Author : Jaime Canizales 
Created on : January 1st, 2018
Purpose : To open CSV file and check its correctness, then separate the data from the file into separate tree objects and store those 
          tree objects in a treecollection class. Also responsible for user interactive mode.

******************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "Tree.h"
#include <fstream>
#include <sstream>
#include "Tree_Collection.h"
#include <list>

using namespace std;

int main ( int argc, char * argv[])
{

    if(!argv[1])
    {
       cerr<<"A file was not provided on the command line"<<endl;
       return 0;
    }
 
    ifstream input(argv[1]);

    if ( input.fail() )
    {
      cerr<<"failed to open file"<<endl;
      return 0;
    }
//error checking of input file
//*********************************************************************************************************************************    
    string line;
    TreeCollection catalog;
    while( getline( input, line ))
    {
        stringstream strStream(line);
        string reader = "";
        string quote;
        string tempData[9];

        for ( int i = 0; i < 9 ; i++)
        {
            getline(strStream, reader, ',');
            tempData[i] = reader;
        }   
           
        string stat   = tempData[2];
        string heal   = tempData[3];
        string spccommon = tempData[4];
        string bor = tempData[6];
               
        int treeidNum, dbhNum, zipcoNum;
        stringstream treeidconverter(tempData[0]);
        stringstream dbhconverter(tempData[1]);
        stringstream zipcoconverter(tempData[5]);
        treeidconverter>> treeidNum;
        dbhconverter>> dbhNum;
        zipcoconverter>> zipcoNum;  
        double x_num, y_num;
        stringstream xConverter(tempData[7]);
        stringstream yConverter(tempData[8]);
        xConverter>> x_num;
        yConverter>> y_num;
        Tree temp ( treeidNum, dbhNum, stat, heal, spccommon, zipcoNum, bor, x_num, y_num);
        catalog.insert(temp);
              
    }

//Tree collection object created
//***************************************************************************************************************************************
          
        string look;
        while ( look != "quit" )
        {
            cout<<"Enter the tree species to learn more about it ('quit' to stop):";
            getline(cin,look);
            list<string> allmatches = catalog.get_matching_species(look);
            list<string>::const_iterator it;
            cout<<"All matching species:"<<endl;
            for ( it = allmatches.begin(); it != allmatches.end(); ++it)
                cout<<"     "<<*it<<endl;
        }
return 0;
}                            
            





