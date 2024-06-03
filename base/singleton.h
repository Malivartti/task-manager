#ifndef SINGLETON_H
#define SINGLETON_H

/**
 * @brief The Singleton.
*/
template <class T>
class Singleton {
private:
    /**
     * @brief The Instance of Class T.
    */
    static inline T* instance = nullptr;

protected:
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton() {};

public:
    /**
     * @brief The Method for obtaining an instance of a Class T.
    */
    static T* getInstance()
    {
        if (!instance) {
            instance = new T();
        }
        return instance;
    }
};

#endif // SINGLETON_H
