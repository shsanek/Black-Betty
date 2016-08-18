//
//  DTRLexemParser.hpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef DTRLexemParser_hpp
#define DTRLexemParser_hpp

#include <stdio.h>
#include "DTRSyntacticAnalyzer.hpp"
#include "DTRTokensAnalyzer.hpp"
#include "DTRAllLexems.h"
#include <list>
#include "DTRAllSyntacticObjectsForLexemParse.hpp"

using namespace std;
using namespace DTR;

/// <summary>
/// DTR lexem parser.
/// </summary>
class DTRLexemParser
{
    
    DTRTokensAnalyzer lexAnalyzer;
    DTRSyntacticAnalyzer syntacticAnalyzer;
    
    vector<LexemString> preprocessor(list<LexemString> lexems){
        vector<LexemString> resultString = vector<LexemString>();
        for (list<LexemString>::iterator i = lexems.begin();
             i != lexems.end();
             ++i) {
            if ((*i).lexemName == "const_string"){
                (*i).value = (*i).value.substr(1,(*i).value.length() - 2);
            }
            if ((*i).lexemName != "spasing") {
                resultString.push_back(*i);
            }
            
            
        }
        return resultString;
    }
    
public:
    shared_ptr<DTRTokensAnalyzer> tokensAnalyzerFromStrin(string str) {
        list<LexemString> lexems = this->lexAnalyzer.lexemsFromSting (str);
        vector<LexemString> preprocessorLexems = preprocessor (lexems);
        list<shared_ptr<SyntacticResultObject>> objects = this->syntacticAnalyzer.objectsFromLexems (preprocessorLexems);
        shared_ptr<DTRTokensAnalyzer> analyzer = shared_ptr<DTRTokensAnalyzer>(new DTRTokensAnalyzer ());
        
        string debugeText = "";
        for (list<shared_ptr<SyntacticResultObject>>::iterator obj = objects.begin();
             obj != objects.end();
             ++obj){
            debugeText += "\n\n";
            debugeText += (*obj)->debugingString();
        }
        printf("%s",debugeText.c_str());
        TokenAnalyzerCreater* creater = new TokenAnalyzerCreater(analyzer);
        for (list<shared_ptr<SyntacticResultObject>>::iterator obj = objects.begin();
             obj != objects.end();
             ++obj){
            (*obj)->getData(creater);
            //RowSyntacticObject::RowSyntacticResultObject* row = (RowSyntacticObject::RowSyntacticResultObject*)((*obj).get());
            //row->addedLexemInTokenAnalyzer (analyzer.get());
        }
        return analyzer;
    }
    
    DTRLexemParser () {
        shared_ptr<Lexem> quoteLexem = shared_ptr<Lexem>((Lexem*) new SymbosLexem ("\'"));
        list<shared_ptr<Lexem>> stringLexemTmp1 = list<shared_ptr<Lexem>>();
        stringLexemTmp1.push_back(shared_ptr<Lexem>((Lexem*)new NotLexem(quoteLexem)));
        stringLexemTmp1.push_back(shared_ptr<Lexem>((Lexem*)new SymbosLexem ("\\\'")));
        
        list<shared_ptr<Lexem>> stringLexemTmp2 = list<shared_ptr<Lexem>>();
        stringLexemTmp2.push_back(quoteLexem);
        stringLexemTmp2.push_back(shared_ptr<Lexem>((Lexem*)new SequenceLexem(shared_ptr<Lexem>((Lexem*)new ListLexem(stringLexemTmp1)),0)));
        stringLexemTmp2.push_back(quoteLexem);
        
        shared_ptr<Lexem> stringLexem = shared_ptr<Lexem>((Lexem*)new ConcatenationLexem(stringLexemTmp2));
        DTRTokensAnalyzer analyzer = DTRTokensAnalyzer ();
        analyzer.addLexemWithKey (stringLexem, "const_string");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("[")), "open_square_bracket");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("]")), "close_square_bracket");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("(")), "open_bracket");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem (")")), "close_bracket");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("+")), "plus");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem (",")), "comma");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("*")), "clinical");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("?")), "question");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SequenceLexem(shared_ptr<Lexem>((Lexem*)new SymbosLexem (" ")),1)), "spasing");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem (";")), "end_row");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("\n")), "new_row");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem (":")), "delimiter");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("|")), "concatenation");
        analyzer.addLexemWithKey (shared_ptr<Lexem>(new SymbosLexem ("!")), "not");
        lexAnalyzer = analyzer;
        
        this->syntacticAnalyzer = DTRSyntacticAnalyzer ();
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new DelimiterSyntacticObject(1)), "delimiter");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new SyntacticObject("end_row","end_row",0)), "row");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new LexemSyntacticObject(7)), "lexem");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new RangeSyntacticObject(7)), "range");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new NotLexemSyntacticObject(7)), "not");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new ClinicalSyntacticObject(6)), "clinical");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new PlusSyntacticObject(6)), "plus");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new SyntacticObject("comma","comma",3,true)), "comma");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new ConcatenationSyntacticObject(4)), "concatenation");
        syntacticAnalyzer.addSyntaxObject (shared_ptr<SyntacticObject>(new QuestionSyntacticObject(5)), "question");
    }
};

#endif /* DTRLexemParser_hpp */
