#include <iostream>

typedef  unsigned short uint16_t;
typedef   short int16_t;
uint16_t unsigned_a = 6u;
int16_t signed_b = -9;

typedef struct
{
    uint16_t count;
    uint16_t max_count;
    uint16_t _unused;
    uint16_t control;
} timer_reg_t;//use from _t in end of name 

int main() {
    
    if (unsigned_a + signed_b < 4)
    {
    std::cout << "Ok";
    }
    // Write C++ code here
    std::cout << "Hello word";

    return 0;
}