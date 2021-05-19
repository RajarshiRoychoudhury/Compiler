/**
 * * Assignment-3 of Compiler Design
 * * @written by Shubham Kumar, Rajarshi Roychoudhary, Arka Maji, Susanka Mazumdar
 * * Symbol Table header file
*/


#include"Token.h"

/**
 * ? SYMBOL TABLE CLASS
 * * symtabfile = a file where my symbol table is kept (.csv);
 * * tokenfile = tokens generated are kept (.tok) and this file is given as an input to the parser;
 * * map<string,vector<Token>>string_tokens = A hashmap of tokens, with key as lexeme and Tokens as a vector;
*/

class SymbolTable{

    public:

        map<string,vector<Token>>string_tokens;
        fstream  symtabfile;
        fstream tokenfile;
        
        /**
         * ? PARAMETERIZED CONSTRUCTOR SYMBOL TABLE
         * * It takes two parameters, an symbol table file name and token file name;
         * * Used to open both the files, error checks have been provided in case the file fails to open.
         * * symtabfile << : This is used to write in a file
        */

        SymbolTable(string symbol_table_file , string token_file ){ 
            symtabfile.open(symbol_table_file,ios::out);
            if(!symtabfile){
                cout<<"Error: Symbol table file"<<"\n";
                return;
            }
            tokenfile.open(token_file,ios::out);
            if(!tokenfile){
                cout<<"Error: Token table file"<<"\n";
                return;
            }
            symtabfile << "======================================SYMBOL TABLE==========================================\n";
            symtabfile << "\n--------------------------------------------------------------------------------------------\n";
            symtabfile << "|LEXEME|\t" << "|TOKEN|\t" <<"|DTYPE|\t"<< "|ROW|\t" <<"|COLUMN|\t" << "|SCOPE|\t" << "|ROW_DECLARED|\t" <<"|COLUMN_DECLARED|\t" << "|SCOPE_DECLARED|\t" <<"|IS_BEING_DECLARED\n";
            symtabfile << "--------------------------------------------------------------------------------------------\n";
        }

        void insert_error_token(Token * t){
            symtabfile << t->token << "\t" << t->token_id << "\t" <<t->dtype<<"\t"<< t->row << "\t" << t->column << "\t" << t->scope <<"\t"<< t->row_declared<<"\t"<<t->column_declared<<"\t"<<t->scope_declared<<"\t"<<t->is_being_declared<<"\n";
        }

        bool insert_token(Token * t){
            if(t->token_id=="eof"){
                tokenfile << t->token_id <<endl;
                symtabfile.close();
                tokenfile.close();
                //this->displaySym();
            }
            else{
                if(!checkInsertion(t)){
                    return false;
                }
                tokenfile << t->token_id<<" ";
                if(t->token_id=="id"){
                    symtabfile << t->token << "\t" << t->token_id <<"\t" <<t->dtype<< "\t" << t->row << "\t" << t->column << "\t" << t->scope <<"\t"<< t->row_declared<<"\t"<<t->column_declared<<"\t"<<t->scope_declared<<"\t"<<t->is_being_declared<<"\n";
                }
            }
            if(t->token_id!="id"){
                return true;
            }
            if(string_tokens.find(t->token) == string_tokens.end()){
                //cout<<"Creating vector for "<<t->token<<endl;
                vector<Token> newVec;
                newVec.push_back(*t);
                string_tokens.insert({t->token,newVec});
                // symtabfile >> t->token >> "\t" 
            }
            else{
                string_tokens[t->token].push_back(*t);
            }
            return true;
        }


        /**
         * ? displaySym()
         * * Used to display the symbol table. 
        */

        void displaySym(){
            cout << "================================SYMBOL TABLE=============================\n";
            cout << "\n----------------------------------------------------------------------------\n";
            cout << "|LEXEME|\t" << "|TOKEN|\t" << "  |ROW|\t" <<"|COLUMN|\t  " << "|SCOPE|\n";
            cout << "----------------------------------------------------------------------------\n";
            for(auto x : string_tokens){
                for(auto y : x.second){
                    y.displayToken();
                }
            }
        }

        void closeFile(){
            this->symtabfile.close();
            this->tokenfile.close();
        }

        bool checkInsertion(Token * t){
            map<int,int> scope_count_map = t->scope_count_map;
            if(t->token_id!="id"){
                return true;
            }
            if(string_tokens.find(t->token)==string_tokens.end()){
                if(t->is_being_declared){
                    t->row_declared=t->row;
                    t->column_declared=t->column;
                    t->scope_declared=t->scope;
                }
                else{
                    cout<<"Not declared "<<t->token<<" "<<t->row<<" "<<t->column<<endl;
                }
                return t->is_being_declared;
            }
            if(t->is_being_declared){
                for(int i=0;i<string_tokens[t->token].size();i++){
                    if(t->scope==string_tokens[t->token][i].scope && t->scope_count==string_tokens[t->token][i].scope_count){
                        if(string_tokens[t->token][i].is_being_declared){
                            cout<<"Same token "<<t->row<<" "<<t->column<<" declared in same scope("<<string_tokens[t->token][i].row<<" "<<string_tokens[t->token][i].column<<")";
                            return false;
                        }
                        // t->row_declared=string_tokens[t->token][i].row;
                        // t->column_declared = string_tokens[t->token][i].column;
                        // t->scope_declared = string_tokens[t->token][i].scope;
                    }
                }
                t->row_declared=t->row;
                t->column_declared = t->column;
                t->scope_declared = t->scope;
                return true;
            }
            else{
                t->row_declared=-1;
                t->column_declared=-1;
                t->scope_declared=-1;
                for(int i=0;i<string_tokens[t->token].size();i++){
                    if(string_tokens[t->token][i].scope>t->scope_declared 
                    && (string_tokens[t->token][i].scope<=t->scope 
                    && string_tokens[t->token][i].is_being_declared 
                    && string_tokens[t->token][i].scope_count==scope_count_map[string_tokens[t->token][i].scope]
                    )){
                        t->row_declared=string_tokens[t->token][i].row;
                        t->column_declared = string_tokens[t->token][i].column;
                        t->scope_declared = string_tokens[t->token][i].scope;
                        t->dtype = string_tokens[t->token][i].dtype;
                    }
                    
                }
                if(t->row_declared==-1){
                    cout<<"Token "<<t->token<<" "<<t->row<<" "<<t->column<<" not in the scope or redeclared"<<endl;
                }
                return t->row_declared!=-1;
            }
            return false;
        }


};






















