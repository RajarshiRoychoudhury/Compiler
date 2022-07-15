 

Consider a simple C-like language with

 

    Data Type : character (char), and string (string)

Declaration statements can appear anywhere in the program and scope rules are   to be maintained accordingly.

    Assignments to the variables can be performed at the time of declaration at the beginning of the program. There is no separate Input, output statements.

    Loop Constructs: only while loops are supported. There can be nested loops.

    Relational operators supported in the loop construct are {>, <, >=, <=}

    Arithmetic operators supported are {+, –, ++ and - -}, i.e. addition, subtraction, increment and decrement. Operations can be done on character       variables. Assignment operator `=’ is supported.

    Only function is main(), there is no other function. The main() function may     contain arguments, but no return statements.

 

Part I – Construct a CFG for this language.

Part II – Write a lexical analyser to scan the stream of characters from a program written in the above language and generate stream of tokens.

Part III – Maintain a symbol table with appropriate data structures. The symbol table should also maintain the scope of each variable declared within the program.

Part IV – Write a top-down parser for this language (modules include left recursion removal, FIRST, FOLLOW, parsing table construction and parsing)
