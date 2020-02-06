#include <iostream>

int result;
char open_char;
int value;

int main()
{
    result=0;
    while(true){
        std::cout << "Result: " << result << '\n';

        std::cout << "Enter operator and number: ";
        std::cin >> open_char >> value;
        if(open_char == '+'){
            result+=value;
        }
        else if(open_char == '-'){
            result-=value;
        }else if(open_char == '*'){
            result *= value;
        }else if (open_char == '/'){
            if(value == 0){
                std::cout << "Error! Divide by zero! \n Operation Ignored.";
            }
            else
                result /= value;
        }
        else{
            std::cout << "Unknown operator " << open_char << '\n';
        }
    }
    return 0;
}