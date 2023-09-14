#ifndef __NexCore_Core_Singleton_H__
#define __NexCore_Core_Singleton_H__

#include <NexCore/Core/Core.h>

template <typename Ty>
class Singleton {
public:
    Singleton() {
        NEX_ASSERT(s_instance == nullptr, "Singleton already initialized (" __FILE__ ")!");
        s_instance = static_cast<Ty*>(this);
    }

    virtual ~Singleton() {
        s_instance = nullptr;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static Ty& Get() {
        NEX_ASSERT(s_instance == nullptr, "Singleton is not initialized!");
        return *s_instance;
    }

    static Ty* GetPtr() {
        return s_instance;
    }

protected:
    static Ty* s_instance;
};

#endif // __NexCore_Core_Singleton_H__