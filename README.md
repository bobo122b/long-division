# long-division
A project to perform long division on binomials

the main algorithm of long division is implemented by me from scratch, it depends on subtraction of powers and coefficients and modulating the input array of constants that the user inputs, it also depends on memory reallocation so that can take a dynamic memory to deal with inputs and outputs, so the user can put any number of constants that he needs and the algorithm will keep on dealing with it.

you can get the code running by opening terminal in the directory of the code and then write the following two lines

  
    gcc -o division division.c division.h main.c printOut.c input.c
    
    ./division
    
or on windows
    
    .\division.exe

The print function takes a lot of lines cause it deals with many situations and if-else statements
