# CS57 Project 1

<h2>Jonah Weinbaum</h2>

<hr></hr>

*Compilation*

   To run the minic program, use `make` to compile and `make clean` to clean the output files use. 
   Some examples have been provided to illustrate functionality in the `examples` folder. 
   To run use `./minic [FILENAME]` to read from either a file or STDIN.

<hr></hr>


*Scope*

    * Function Scope is always global
    * Variable scope is always local to a function 
    
<hr></hr>

*Declarations*

    Errors will be thrown on the following 

    * Functions used before declaration
    * Variables used before declaration
    * Variables redeclared within the same scope
<hr></hr>

*Parameters*

    While my parser handles multiple parameters and parameter mismatches, the AST does not. 
    For this reason, I am considering this as an additional aspect which I am adding to my project. 
    This is to say, a function with multiple parameters will always expect this number of parameters in the proper order of type. 

<hr></hr>

*AST*

    While my code is written in C, the C AST implementation had many problems and so, as per Ben's suggestion
    in the slack, I am using the C++ AST. This meant many conversions of types were required and resulted in 
    less than ideal code in terms of cleanliness. However, the end result is a functional AST. 

<hr></hr>

**Implementation**

    Scope is handled by the use of a hashtable I designed in my CS50 class. 
    All hashtable code is written by me but from a prior class. 
    Variables are hashed by name and store a variable type meaning that no two 
    variables within the same scope can have the same name (even if they have different type).
