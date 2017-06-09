#include "RException.h"

RPTR::Thread_exception::Thread_exception(std::string func, int error)
{
    
}

const char * RPTR::Thread_exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return m_err.c_str();
}
