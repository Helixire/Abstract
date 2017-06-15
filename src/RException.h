#ifndef __REXCEPTION_H__
#define __REXCEPTION_H__

#include <exception>
#include <string>

namespace RPTR
{
    class Exception : public std::exception
    {
    public:
        Exception(const std::string& error = "An exception occurred");
        virtual const char *what() const noexcept;
    protected:
        virtual void    set_what(const std::string &msg);
    private:
        std::string m_what;
    };
    
    class ThreadException : public RPTR::Exception
    {
    public:
        ThreadException(const std::string& func, int error);
    };
    
    class MutexException : public RPTR::Exception
    {
    public:
        MutexException(const std::string& func, int error);
    };
}
#endif /* __REXCEPTION_H__ */
