#include <iostream>
#include <cassert>
#include <string>
#include <bitset>

using namespace std;

const int NUM_BITS = 16;
const int BIT_TEST = 0x8000;

int count_bits(const int toCount){
    int count = 0;
    for(int bit = BIT_TEST; bit > 0; bit = (bit >> 1)){
        //cout << std::bitset<NUM_BITS>(bit) << " , " << std::bitset<NUM_BITS>(toCount & bit) << '\n';
        if((toCount & bit) != 0){
            count++;
        }
    }
    return count;
}

int count_bits(int);
int main(){
    int input;
    cout << "Enter a integer to find out how many bits are set in it." << '\n';
    cin >> input;
    cout << "Number of bits in " << input << " (" << std::bitset<NUM_BITS>(input) << "): " << count_bits(input) << '\n'; 
}