#include <iostream>
#include <cassert>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Dog{
    private:
        static int numDoggos;
        bool doDeconstruction = true;
    public:
        Dog(){
            ++numDoggos;
            speak();
        }
        Dog(bool deconstruct){
            doDeconstruction = false;
            ++numDoggos;
            speak(); 
        }
        Dog(const Dog& old_dog){
            doDeconstruction = true;
        }
        ~Dog(){
            if(doDeconstruction){
                numDoggos--;
                cout << "Bye bye Doggie!\n";
            }   
        }
        void speak(){
            cout << "Bork! Bork! \n";
        }
        static int getNumber(){
            return numDoggos;
        }
};
int Dog::numDoggos = 0;

class Pig{
    private:
        static int numPiggies;
        bool doDeconstruction = true;
    public:
        Pig(){
            ++numPiggies;
            speak();
        }
        Pig(bool deconstruct){
            doDeconstruction = false;
            ++numPiggies;
            speak(); 
        }
        Pig(const Pig& old_pig){
            doDeconstruction = true;
        }
        ~Pig(){
            if(doDeconstruction){
                numPiggies--;
                cout << "The pig flew away.\n";
            }
        }
        void speak(){
            cout << "Oink! Oink! \n";
        }
        static int getNumber(){
            return numPiggies;
        }
};
int Pig::numPiggies = 0;

class Horse{
    private:
        static int numHorsies;
        bool doDeconstruction = true;
    public:
        Horse(){
            ++numHorsies;
            speak(); 
        }
        Horse(bool deconstruct){
            doDeconstruction = false;
            ++numHorsies;
            speak(); 
        }
        Horse(const Horse& old_horse){
            doDeconstruction = true;
        }
        ~Horse(){
            if(doDeconstruction){
                numHorsies--;
                cout << "The horse galloped off.\n";
            }
        }
        void speak(){
            cout << "Neigh! Neigh! \n";
        }
        static int getNumber(){
            return numHorsies;
        }
};
int Horse::numHorsies = 0;

int main(){
int totalNumberAnimals();
    list<Pig> piggies = {};
    list<Dog> doggos = {};
    list<Horse> horses = {};
    cout << "Welcome to Dr. Able Smith's Veterinarian Office! \nYou're in charge of handling new arrivals and discharges.\n";
    while(true){
        cout << "Current number of animals: " << totalNumberAnimals() << "\n";
        cout << "Pigs: " << Pig::getNumber() << " Horses: " << Horse::getNumber() << " Dogs: " << Dog::getNumber() << "\n";
        cout << "To admit a new animal, type '1'. To discharge an animal, type '2'. To quit, type '0'\n";
        int code;
        cin >> code;
        if(!cin){
            cin.clear();
            cin.ignore();
            cout << "Error! You did not type in a number.\n";
            cin >> code;
            continue;
        }else{
            if(code == 0) exit(0);
            else if(code != 1 && code !=2){
                cout << "Error! Invalid entry. Please enter '1' or '2'.\n";
            }else{
                cout << "Which type of animal? Type 'P' for Pig, 'H' for Horse, or 'D' for Dog.\n";
                char input;
                cin >> input;
                input = toupper(input);
                switch(input){
                    case 'H':
                        if(code == 1){
                            cout << "Admitting a horse...\n";
                            horses.push_back(Horse(false));
                        }
                        else{
                            cout << "Discharging a horse...\n";
                            horses.pop_back();
                        }
                        break;
                    case 'P':
                        if(code == 1)
                            piggies.push_back(Pig(false));
                        else
                            piggies.pop_back();
                        break;
                    case 'D':
                        if(code == 1)
                            doggos.push_back(Dog(false));
                        else
                            doggos.pop_back();
                        break;
                    default:
                        "Invalid character! You must enter either a 'P', 'H', or 'D'!\n";
                        break;
                }
            }
        }
    }
}

int totalNumberAnimals(){
   return Pig::getNumber() + Horse::getNumber()+Dog::getNumber();
}
