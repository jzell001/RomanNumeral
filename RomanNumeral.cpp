#include <iostream>

using namespace std;


/*
    
    Jason Zellmer
    
    Description:
        This is a Roman Numeral number converter. It takes numbers
        from 1-1000 in Arabic Number format and converts them to
        Roman Numeral format.
    
    Implementation:
        Compile:  g++ -Werror -Wall Procore4.cpp
        Run:      ./a.out
        
    Symbol   I   V   X   L   C    D    M
    Value    1   5   10  50  100  500  1,000
   
   
    1-10 (by 1):
    I, II, III, IV, V, VI, VII, VIII, IX, X
   
    10-100 (by 10):
    X, XX, XXX, XL, L, LX, LXX, LXXX, XC, C
   
    100-1000 (by 100):
    C, CC, CCC, CD, D, DC, DCC, DCCC, CM, M
   
*/
   
   
   int main() {
    
    int arabic_number = 0;
    int current       = 0;
    string temp   = "";
    string single = "";
    string five   = "";
    string ten    = "";
    
    
    
    ////////////////////////////////////////////////////////////
    // Request a number
    cout << "Enter a number between 1 and 1000 (0 to quit): ";
    cin >> arabic_number;
    
    cout << "arabic_number: " << arabic_number << endl;
    
    if( (arabic_number < 1) || (arabic_number > 1000) ) {
        cout << "Error: number outside range 1-100" << endl;
        return 0;
    }
    else if(arabic_number == 0) {
        cout << "Quiting..." << endl;
        return 0;
    }
    ////////////////////////////////////////////////////////////
    
    
    ////////////////////////////////////////////////////////////
    // Keep repeating until they enter 0 to quit
    while(arabic_number != 0) {
        
        current = arabic_number;
        temp   = "";
        
        // do this 3 times, onece for each possible multiple of 10
        for(int i = 1; i <= 3; i++) {
           
            if(i == 1) {
                single = "I";
                five   = "V";
                ten    = "X";
            }
            else if(i == 2) {
                single = "X";
                five   = "L";
                ten    = "C";
            }
            else if(i == 3) {
                single = "C";
                five   = "D";
                ten    = "M";
            }
           
           
            if(current % 10 == 1) {
                temp = single + temp;
                current = current - 1;
            }
            else if(current % 10 == 2) {
                temp = single + single + temp;
                current = current - 2;
            }
            else if(current % 10 == 3) {
                temp = single + single + single + temp;
                current = current - 3;
            }
            else if(current % 10 == 4) {
                temp = single + five + temp;
                current = current - 4;
            }
            else if(current % 10 == 5) {
                temp = five + temp;
                current = current - 5;
            }
            else if(current % 10 == 6) {
                temp = five + single + temp;
                current = current - 6;
            }
            else if(current % 10 == 7) {
                temp = five + single + single + temp;
                current = current - 7;
            }
            else if(current % 10 == 8) {
                temp = five + single + single + single + temp;
                current = current - 8;
            }
            else if(current % 10 == 9) {
                temp = single + ten + temp;
                current = current - 9;
            }
           
           
            current = current / 10;
            //cout << "current: " << current << endl;
            
            
           
        }
        
        
        //////////////////////////////////////////////////
        // last case is when 1000 is entered, which is M
        if(current > 0) {
            temp = ten;
        }
        //////////////////////////////////////////////////
            
        
        ////////////////////////////////////////////////////////////
        // output result and ask if they want to continue
        cout << "Roman Numeral: " << temp << endl << endl;
        
        
        
        cout << "Enter a number between 1 and 1000 (0 to quit): ";
        cin >> arabic_number;
        
        cout << "arabic_number: " << arabic_number << endl;
        
        if( (arabic_number < 1) || (arabic_number > 1000) ) {
            cout << "Error: number outside range 1-100" << endl;
            return 0;
        }
        else if(arabic_number == 0) {
            cout << "Quiting..." << endl;
        }
        ////////////////////////////////////////////////////////////
        
        
        
        
        
    }
    ////////////////////////////////////////////////////////////
    
        
    
    return 0;
}
    
    
    
    
