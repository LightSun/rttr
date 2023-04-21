
#include "ColorMap.h"

#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <iostream>

#include <rttr/type>

using namespace rttr;
using Color = rttr_med::Color;
using ColorMap = rttr_med::ColorMap;

//more: https://www.rttr.org/doc/master/register_classes_page.html
void test_colorMap(){
    std::vector<type> put_types = {type::get<unsigned char>(),
                                   type::get<const Color&>()};
    std::vector<type> get_types = {type::get<unsigned char>(),
                                   type::get<Color&>()};

    ColorMap cm;
    auto t = type::get(cm);
//    for (auto meth : t.get_methods())
//    {
//        std::cout << meth.get_signature() << std::endl;
//    }

    //auto t = type::get_by_name("ColorMap");
    //if no overload func. no need pass types.fff
    Color c = {1, 2, 3, 4};
    t.get_method("put", put_types).invoke(cm, (unsigned char)1, c);
    Color c2 = {0, 0, 0, 0};
    t.get_method("get", get_types).invoke(cm, (unsigned char)1, c2);
    printf("c2 = %.1f, %.1f, %.1f, %.1f\n", c2.r, c2.g, c2.b, c2.a);

    //create obj from empty constructor.
    auto cm2 = t.create();
    t.get_method("put", put_types).invoke(cm2, (unsigned char)1, c);
    c2 = {0, 0, 0, 0};
    t.get_method("get", get_types).invoke(cm2, (unsigned char)1, c2);
    printf("c2_2 = %.1f, %.1f, %.1f, %.1f\n", c2.r, c2.g, c2.b, c2.a);
}
