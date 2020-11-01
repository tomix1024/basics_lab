//
// Created by alex on 29.10.20.
//

#ifndef BCG_GRAPHICS_BCG_MATERIAL_POINTS_H
#define BCG_GRAPHICS_BCG_MATERIAL_POINTS_H

#include "bcg_library/color/bcg_colors.h"

namespace bcg{

struct material_points{
    bool use_uniform_point_size;
    bcg_scalar_t uniform_point_size;
    bool use_uniform_color;
    VectorS<4> uniform_color;
};


}

#endif //BCG_GRAPHICS_BCG_MATERIAL_POINTS_H
