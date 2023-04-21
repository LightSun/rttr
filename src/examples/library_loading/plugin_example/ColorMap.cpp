#include "ColorMap.h"

#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <iostream>

#include <rttr/registration>

using ColorMap = rttr_med::ColorMap;
using Color = rttr_med::Color;

RTTR_PLUGIN_REGISTRATION
{
    rttr::registration::class_<ColorMap>("ColorMap")
         .constructor<>()
         .method("get", (&ColorMap::get),rttr::registration::public_access)
         .method("put", (&ColorMap::put),rttr::registration::public_access)
         ;
    //rttr::select_const
    //rttr::select_overload
}
