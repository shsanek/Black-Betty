//
//  DTRLexemParser.cpp
//  DTR
//
//  Created by Alexander Shipin on 12/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#include "DTRLexemParser.hpp"

vector<LexemString> DTRLexemParser::preprocessor(list<LexemString> lexems){
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


DTRTokensAnalyzer_ptr DTRLexemParser::tokensAnalyzerFromStrin(string str) {
    list<LexemString> lexems = this->lexAnalyzer.lexemsFromSting (str);
    vector<LexemString> preprocessorLexems = preprocessor (lexems);
    list<SyntacticResultObject_ptr> objects = this->syntacticAnalyzer.objectsFromLexems (preprocessorLexems);
    DTRTokensAnalyzer_ptr analyzer = DTRTokensAnalyzer_ptr(new DTRTokensAnalyzer ());
    
    if (debugeMod) {
        string debugeText = "";
        for (list<SyntacticResultObject_ptr>::iterator obj = objects.begin();
             obj != objects.end();
             ++obj){
            debugeText += "\n\n";
            debugeText += (*obj)->debugingString();
        }
        printf("%s",debugeText.c_str());
    }
    TokenAnalyzerCreater* creater = new TokenAnalyzerCreater(analyzer);
    for (list<SyntacticResultObject_ptr>::iterator obj = objects.begin();
         obj != objects.end();
         ++obj){
        (*obj)->getData(creater);
    }
    return analyzer;
}

DTRLexemParser::DTRLexemParser () {
    debugeMod = false;
    Lexem_ptr quoteLexem = Lexem_ptr((Lexem*) new SymbosLexem ("\'"));
    list<Lexem_ptr> stringLexemTmp1 = list<Lexem_ptr>();
    stringLexemTmp1.push_back(Lexem_ptr((Lexem*)new NotLexem(quoteLexem)));
    stringLexemTmp1.push_back(Lexem_ptr((Lexem*)new SymbosLexem ("\\\'")));
    
    list<Lexem_ptr> stringLexemTmp2 = list<Lexem_ptr>();
    stringLexemTmp2.push_back(quoteLexem);
    stringLexemTmp2.push_back(Lexem_ptr((Lexem*)new SequenceLexem(Lexem_ptr((Lexem*)new ListLexem(stringLexemTmp1)),0)));
    stringLexemTmp2.push_back(quoteLexem);
    
    Lexem_ptr stringLexem = Lexem_ptr((Lexem*)new ConcatenationLexem(stringLexemTmp2));
    DTRTokensAnalyzer analyzer = DTRTokensAnalyzer ();
    analyzer.addLexemWithKey (stringLexem, "const_string");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("[")), "open_square_bracket");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("]")), "close_square_bracket");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("(")), "open_bracket");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem (")")), "close_bracket");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("+")), "plus");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem (",")), "comma");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("*")), "clinical");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("?")), "question");
    analyzer.addLexemWithKey (Lexem_ptr(new SequenceLexem(Lexem_ptr((Lexem*)new SymbosLexem (" ")),1)), "spasing");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem (";")), "end_row");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("\n")), "new_row");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem (":")), "delimiter");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("|")), "concatenation");
    analyzer.addLexemWithKey (Lexem_ptr(new SymbosLexem ("!")), "not");
    lexAnalyzer = analyzer;
    
    this->syntacticAnalyzer = DTRSyntacticAnalyzer ();
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new DelimiterSyntacticObject(1)), "delimiter");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new SyntacticObject("end_row","end_row",0)), "row");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new LexemSyntacticObject(7)), "lexem");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new RangeSyntacticObject(7)), "range");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new NotLexemSyntacticObject(7)), "not");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new ClinicalSyntacticObject(6)), "clinical");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new PlusSyntacticObject(6)), "plus");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new SyntacticObject("comma","comma",3,true)), "comma");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new ConcatenationSyntacticObject(4)), "concatenation");
    syntacticAnalyzer.addSyntaxObject (SyntacticObject_ptr(new QuestionSyntacticObject(5)), "question");
}