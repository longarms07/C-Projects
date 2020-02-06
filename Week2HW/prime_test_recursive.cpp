#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    bool CheckPrime(int number);
    int number;

    cout << "Enter a number:";
    cin >> number;
    if(number >= 2147483647){ 
        cout << "The number you entered was too big! \n Please enter something <= 2,147,483,647.\n";
        exit(1);
        }
    bool prime = CheckPrime(number);
    if(prime){ cout << number << " is prime." << '\n';}
    else{ cout << number << " is NOT prime." << '\n';}

}

bool CheckPrime(int number){

    bool CheckPrimeDivisors(float, float);

    //0, 1, and 2 are prime so no need to check. 
    //2 is included since the next check determines if it is divisible by 2 (or other even numbers as a result).
    if(number <= 2) return true;
    float numberF = static_cast<float>(number);
    //check if the number divides by 2. If the number is a whole number it is not prime.
    float divideBy2 = numberF/2.0;
    //cout << number << " is divisible by 2 to get "<< divideBy2;
    if(divideBy2 == floor(divideBy2)){
        cout << number << " is divisible by 2!\n";
        return false;
    }
    //Next, we will divide by each odd number between 2 and the square root of the number being tested.
    float root = floor(static_cast<float>(sqrt(number)));
    //If the root is even, subtract by 1 to get the first odd number to check. 
    if((static_cast<int>(root) % 2) ==0) root--;
    return CheckPrimeDivisors(number, root);
}

bool CheckPrimeDivisors(float number, float divisor){
    //cout << "Divisor is "<<divisor<<"\n";
    if(divisor <= 2) return true;
    float result = number/divisor;
    if(result == floor(result)){
            cout << number << " is divisible by " << divisor << "!\n";
            return false;
    }
    return (CheckPrimeDivisors(number, divisor-2.0));
}



