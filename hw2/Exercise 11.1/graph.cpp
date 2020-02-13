
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

const int X_SIZE = 40; //Size of array in x direction
const int Y_SIZE = 60; //Size of array in y direction

char graphics[X_SIZE/8][Y_SIZE]; //graphics data

/**********************************************
* set_bit -- set a bit in the graphics array. *
*                                             *
* Parameters:                                 *
*   x,y -- location of the bit.               * 
***********************************************/
void assert_bit(int, int);
inline void set_bit(const int x, const int y)
{
    
    assert_bit(x, y);
    graphics[(x)/8][y] |= static_cast<char>(0x80 >> ((x)%8));
}

void clear_bit(const int, const int);
int main(){
    int loc; //current location we are setting
    void print_graphics(); //print the data

    for(loc = 0; loc < X_SIZE; ++loc)
    {
        
        set_bit(loc, loc);
        if(loc%4 == 0)
            clear_bit(loc, loc);
    }

    print_graphics();
    return(0);
}

/**********************************************
* print_graphics -- print the graphics array. *
*       as a set of X's and .'s               * 
********f***************************************/

char test_bit(const int, const int, const int);
void print_graphics()
{


    int x; //current x Byte
    int y; //current y location
    int bit; //bit we are testing in current Byte

    for(y = 0; y < Y_SIZE; ++y){
        //loop for each byte in the array
        for(x = 0; x < X_SIZE/8; ++x){

            //handle each bit
            for(bit = 0x80; bit > 0; bit = (bit >> 1)){
                cout << test_bit(x, y, bit);
            }
        }
        cout << '\n';
    }
}

//My functions for exercise 11.1 begin here
/**********************************************
* set_bit -- set a bit in the graphics array. *
*                                             *
* Parameters:                                 *
*   x,y -- location of the bit.               * 
***********************************************/
void assert_bit(int, int);
inline void clear_bit(const int x, const int y){
    
    
    assert_bit(x, y);
    graphics[(x)/8][y] &= (0);
}


/**********************************************
* test_bit -- test if the bit is empty.       *
*                                             *
* Parameters:                                 *
*   x,y -- location of the bit.               *
* Returns:                                    *
*   'X' if the bit value != 0                 *
*   '.' otherwise                             *
***********************************************/
inline char test_bit(const int x, const int y, const int bit){
    
    assert((x >= 0) && (x < X_SIZE/8));
    assert((y >= 0) && (y < Y_SIZE));
    if((graphics[x][y] & bit) != 0)
                        return 'X';
                    else
                        return '.';
}

/***************************************************
* assert_bit -- assert that the x and y are valid. *
*                                                  *
* Parameters:                                      *
*   x,y -- location of the bit.                    * 
****************************************************/
inline void assert_bit(const int x, const int y){
    assert((x >= 0) && (x < X_SIZE));
    assert((y >= 0) && (y < Y_SIZE));
}
