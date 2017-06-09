
#include <exception>
#include <string>

namespace RPTR
{
    
    class Thread_exception : public std::exception
    {
    public:
        Thread_exception(std::string func, int error);
        virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
    private:
        std::string m_err;
    };
    
}
