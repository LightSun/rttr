#pragma once

#include <map>

namespace rttr_med{

struct Color{
    float r, g, b, a;
};

class ColorMap
{
public:
    using K = unsigned char;
    ColorMap(){};

    void put(K k, const Color& c){
        m_map[k] = c;
    }
    void get(K k, Color& c){
        c = m_map[k];
    }
private:
    std::map<K, Color> m_map;
};
}
