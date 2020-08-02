//
// Created by shawnunili on 2019/3/25.
//

#ifndef CPP_TOOLS_SINGLETON_H
#define CPP_TOOLS_SINGLETON_H

namespace xct {
    template<typename T>
    class Singleton {
    public:
        static T* getInstance() {
            static T t;
            return &t;
        }
    private:
        Singleton();
        Singleton(const Singleton&);
        Singleton& operator = (const Singleton&);
    };
}

#endif //CPP_TOOLS_SINGLETON_H
