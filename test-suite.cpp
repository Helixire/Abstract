#include <iostream>
#include "RThread.h"

void func(void *t)
{
    std::cout << *(int *)t << std::endl;
}

int main(int ac, char **av)
{
    int nb;
    
    nb = 4;
    RPTR::Thread test(func, (void *)&nb);
    
    std::cout << "This is Sparta" << std::endl;
    test.join();
    return (0);
}
