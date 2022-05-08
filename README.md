*Scope*

    * Function Scope is always global
    * Variable scope is always local to a function 

*Declarations*

    Errors will be thrown on the following 

    * Functions used before declaration
    * Variables used before declaration
    * Variables redeclared within the same scope

*Parameters*

    While my parser handles multiple parameters and parameter mismatches, the AST does not. For this reason, I am considering this as an additional aspect which I am adding to my project. This is to say, a function with multiple parameters will always expect this number of parameters in the proper order of type. 

**Implementation**

    Scope is handled by the use of a hashtable I designed in my CS50 class. All hashtable code is written by me but from a prior class. Variables are hashed by name and store a variable type meaning that no two variables within the same scope can have the same name (even if they have different type).