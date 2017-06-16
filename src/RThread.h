#ifndef __RTHREAD_H__
#define __RTHREAD_H__

#include <memory>

namespace RPTR
{
    class Thread
    {
    public:
        Thread();
        Thread(void (* funct)(void *), void* param);
        void start(void (*funct)(void *), void *param);
        void join();
        void detach();
        
        ~Thread();
    private:
        bool    m_joinable;
        struct RThread_data;
        
        std::unique_ptr<RThread_data>   m_data;
    };
}

#endif /* __RTHREAD_H__ */
