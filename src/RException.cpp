#include "RException.h"
#include <sstream>

RPTR::Exception::Exception(const std::string &error) : m_what(error) {}

const char *RPTR::Exception::what() const noexcept { return m_what.c_str(); }

void RPTR::Exception::set_what(const std::string &msg) { m_what = msg; }

RPTR::ThreadException::ThreadException(const std::string &func, int error) {
  std::stringstream s;

  s << "Thread exception : " << func << " returned " << error;
  set_what(s.str());
}

RPTR::MutexException::MutexException(const std::string &func, int error) {
  std::stringstream s;

  s << "Mutex exception : " << func << " returned " << error;
  set_what(s.str());
}

RPTR::SemaphoreException::SemaphoreException(const std::string &func,
                                             int error) {
  std::stringstream s;

  s << "Semaphore exception : " << func << " errno : " << error;
  set_what(s.str());
}
