#ifndef __RSEMAPHORE_H__
#define __RSEMAPHORE_H__

#include <memory>


namespace RPTR
{
    class Semaphore
    {
    public:
        Semaphore(unsigned int base = 0);
        ~Semaphore();
        
        void    wait();
        
        // return true if the Semaphore could be locked
        bool    trywait();
        
        void    post();
        
        int     get();
        
        void    add(unsigned int);
        
    private:
        
        struct RSemaphore_data;
        
        std::unique_ptr<RSemaphore_data>   m_data;
    };
}

#endif /* __RSEMAPHORE_H__ */

