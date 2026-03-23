grammar Polynomial;

prog:   stat+ ;

stat:   ID '=' poly            # assign    
    |   poly                   # printExpr
    |   'exit'                 # exit      
    ;

poly:   term (('+' | '-') term)* ;

term:   coefficient? variables 
    |   coefficient
    ;

sign:   '+' | '-' ;

coefficient:   sign? NUM ;

variables:   var+ ;

var:    VAR ('^' NUM)? ;  

VAR:    [xyz] ;

NUM:    [0-9]+ ('.' [0-9]+)? ; 

ID:     [a-w] ;  

WS:     [ \t\r\n]+ -> skip ;