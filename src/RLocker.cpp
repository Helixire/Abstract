#include "RLocker.h"
#include <iostream>

RPTR::Locker::Locker(Mutex &mut) : m_mut(mut) { m_mut.lock(); }

RPTR::Locker::~Locker() { m_mut.unlock(); }
