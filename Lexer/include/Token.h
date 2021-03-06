/**
 * * Assignment-3 of Compiler Design
 * * @written by Shubham Kumar, Rajarshi Roychoudhary, Arka Maji, Susanka Mazumdar
 * * Token header file
*/


#include<bits/stdc++.h>
using namespace std;

/**
 * ? TOKEN CLASS
 * * token_id = lexeme;
 * * token = consists of assign_op, string,  char, parenthesis, relational_op and identifiers;
 * * row = current row number of that particular token;
 * * row_declared = originally row where it has been declared;
 * * column_declared = originally column where it has been declared;
 * * column = column number of that particular token;
 * * scope = scope number of that particular token, a counter kept which increases with  '{' and decreases with '}';
 * * getter & setter = get and set the value of their respective fields;
 * * displayToken = prints the field of the token class;
 * * is_being_declared = if it is declared or not;
 * * scope_declared = in which scope it is declared;
*/

class Token{
    public:
        string token;
        string token_id;
        int row;
        int column;
        int scope;
        bool is_being_declared;
        int row_declared;
        int column_declared;
        int scope_declared;
        int scope_count;
        map<int,int> scope_count_map;
        string dtype;
        Token(string token, string token_id,int row, int column,int scope,int scope_count,bool is_being_declared,map<int,int> scope_count_map){
            this->token = token;
            this->token_id = token_id;
            this->row = row;
            this->column = column;
            this->scope = scope;
            this->scope_count=scope_count;
            this->is_being_declared=is_being_declared;
            this->scope_count_map = scope_count_map;
        }
        Token(string token, string token_id,int row, int column,int scope, int scope_count, bool is_being_declared,string dtype, map<int,int> scope_count_map){
            this->token = token;
            this->token_id = token_id;
            this->row = row;
            this->column = column;
            this->scope = scope;
            this->scope_count=scope_count;
            this->is_being_declared = is_being_declared;
            this->dtype=dtype;
            this->scope_count_map = scope_count_map;
        }
        string getToken(){
            return this->token;
        }

        string getTokenId(){
            return this->token_id;
        } 

        int getRow(){
            return this->row;
        }

        int getColumn(){
            return this->column;
        }
        
        int getScope(){
            return this->scope;
        } 

        void displayToken(){
            if(this->token == "string"){
                cout<<"| "<<this->token<<"\t"<<this->token_id<<"\t\t\t"<<this->row<<"\t\t"<<this->column<<"\t\t"<<this->scope<<"|"<<endl;
            }
            else if(this->token_id == "stringToken" || this->token_id == "charToken" || this->token_id == "lessthan" || this->token_id == "greaterthan"){
                cout<<"| "<<this->token<<"\t\t"<<this->token_id<<"\t\t"<<this->row<<"\t\t"<<this->column<<"\t\t"<<this->scope<<"|"<<endl;
            }
            else {
                cout<<"| "<<this->token<<"\t\t"<<this->token_id<<"\t\t\t"<<this->row<<"\t\t"<<this->column<<"\t\t"<<this->scope<<"|"<<endl;
            }    
        }
};

