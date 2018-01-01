/******************************************************************************************************************************************
Title  : Treemain.cpp
Author : Jaime Canizales 
Created on : March 20, 2017
Purpose : To open CSV file and check its correctness, then separate the data from the file into separate tree objects and store those 
          tree objects in a treecollection class. Also responsible for user interactive mode.

******************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "Tree.h"
#include <fstream>
#include <sstream>
#include "tree_collection.h"
#include "avl_Tree.h"
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
        string treeid, dbh, zipco;                 //ints to be
        string stat, heal, spccommon, bor;
        string x_, y_ ;                            //doubles to be
        string reader = "";
        string quote;

        string tempData[42];

        for ( int i = 0; i < 42 ; i ++)
        {

            getline(strStream, reader, ',');

            if(reader[0] == '"')
            {
              getline(strStream, quote, '"');
              continue;
            }

            tempData[i] = reader;
        }   
      
        treeid = tempData[0];
        dbh    = tempData[3];
        stat   = tempData[6];
        heal   = tempData[7];
        spccommon = tempData[9];
        zipco  = tempData[25];
        bor    = tempData[29];
        x_     = tempData[39];
        y_     = tempData[40];

               
        int treeidNum, dbhNum, zipcoNum;
        stringstream treeidconverter(treeid);
        stringstream dbhconverter(dbh);
        stringstream zipcoconverter(zipco);
        treeidconverter>> treeidNum;
        dbhconverter>> dbhNum;
        zipcoconverter>> zipcoNum;  
        double x_num, y_num;
        stringstream xConverter(x_);
        stringstream yConverter(y_);
        xConverter>> x_num;
        yConverter>> y_num;
        Tree temp ( treeidNum, dbhNum, stat, heal, spccommon, zipcoNum, bor, x_num, y_num);
        catalog.insert(temp);
              
    }
          
        string look;
        while ( look != "quit" )
        {
            cout<<"Enter the tree species to learn more about it ('quit' to stop):"<<endl;
            getline(cin,look);
            list<string> allmatches = catalog.get_matching_species(look);
            list<string>::const_iterator it;

            for ( it = allmatches.begin(); it != allmatches.end(); ++it)
                cout<<*it<<endl;

        }
return 0;
}                            
            





