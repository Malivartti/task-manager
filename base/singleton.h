#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton {
private:
    static inline T* instance = nullptr;

protected:
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton() {};

public:
    static T* getInstance()
    {
        if (!instance) {
            instance = new T();
        }
        return instance;
    }
};

#endif // SINGLETON_H
