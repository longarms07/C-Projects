#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){

    bool CheckPalindrome(string);

    string input;

    cout << "Enter a number or string: ";
    cin >> input;
    if(CheckPalindrome(input)){
        cout << input << " is a palindrome! :D\n";
    }else{
        cout << input << " is not a palindrome. :'(\n";
    }

}


bool CheckPalindrome(string toCheck){
    int frontN = 0;
    int backN = toCheck.length()-1;
    while(frontN<=backN){
        if(toCheck.at(frontN)!=toCheck.at(backN)) return false;
        frontN++;
        backN--;
    }    
    return true;
}