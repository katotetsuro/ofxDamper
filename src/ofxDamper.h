//
//  ofxDamper.h
//
//  Created by 加藤 哲朗 on 2014/01/23.
//
//

#ifndef ofxDamper_h
#define ofxDamper_h

#include <vector>
#include <string>

template <class T>
class ofxDamper {
    
public:
    void setup(int size) {
        if (size == 0) {
            // 警告
        }
        this->size = size;
//        values.reserve(size);
    }
    
    void add(T value) {
        if (values.size() == size) {
            values.erase(values.begin());
        }
        values.push_back(value);
    }
    void removeOldest() {
        if (values.size() > 0) {
            values.erase(values.begin());
        }
    }
    void clear() {
        values.clear();
    }
    
    T get() {
        T ret;
        for (auto &v : values) {
            ret += v;
        }
        return ret/values.size();
    }
    
private:
    int size;
    T last;
    std::vector<T> values;
};

#endif
