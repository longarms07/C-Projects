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
    if(number >= 2147483647){ cout << "Due to integer sizes, that number has been set to 2,147,483,647.\n";}
    bool prime = CheckPrime(number);
    if(prime){ cout << number << " is prime." << '\n';}
    else{ cout << number << " is NOT prime." << '\n';}

}

bool CheckPrime(int number){
    //0, 1, and 2 are prime so no need to check. 
    //2 is included since the next check determines if it is divisible by 2 (even).
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
    float root = static_cast<float>(sqrt(number));
    for(float i = 3.0; i<=root; i+=2.0){
        float result = numberF/i;
        if(result == floor(result)){
            cout << number << " is divisible by " << i << "!\n";
            return false;
        }
    }
    return true;
}



