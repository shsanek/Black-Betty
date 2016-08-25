//
//  BBFile.cpp
//  BlackBetty
//
//  Created by Alexander Shipin on 24/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "BBFile.hpp"

using namespace BB;


string BB::getStingFromFileWithName(string fileName,ErrorPool_ptr errorPool){
    char buffer [100];
    FILE * pFile = fopen (fileName.c_str() , "r");
    if (pFile == NULL) {
        errorPool->addErrors(shared_ptr<Error>(new Error("file error",1,"file not found")));
    }
    else{
        string result = "";
        while ( ! feof (pFile) ){
            if ( fgets (buffer , 100 , pFile) == NULL ) break;
            //fputs (buffer , stdout);
            result += buffer;
        }
        fclose (pFile);
        return result;
    }
    return "";
}