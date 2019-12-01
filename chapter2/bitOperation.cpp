#include <iostream>

void subset(int x)
{
    int b = 0;
    std::cout << "{";
    do {
        std::cout << b << " "; 
    }while(b = (b-x)&x);
    std::cout << "}" << std::endl;
}

int main()
{
    int x = (1 << 2) | (1 << 4) | (1 << 6);
    subset(x);
}
