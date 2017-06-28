#ifndef __RTHREAD_H__
#define __RTHREAD_H__

#include "RICommand.h"

namespace RPTR
{
class Thread
{
public:
    Thread();
    Thread(void (*funct)(void *), void* param);
    Thread(SCommand cmd);
    void    start(void (*funct)(void *), void *param);
    void    start(SCommand cmd);
    void    join();
    void    detach();

    ~Thread();
private:

    static void    launch_cmd(SCommand *cmd);

    bool    m_joinable;
    struct RThread_data;

    std::unique_ptr<RThread_data>   m_data;
};
}

#endif /* __RTHREAD_H__ */
