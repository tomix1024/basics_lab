//
// Created by alex on 23.11.20.
//

#ifndef BCG_GRAPHICS_BCG_MESH_VERTEX_AREA_BARYCENTRIC_H
#define BCG_GRAPHICS_BCG_MESH_VERTEX_AREA_BARYCENTRIC_H

#include "bcg_mesh.h"

namespace bcg{

bcg_scalar_t vertex_barycentric_area(const halfedge_mesh &mesh, vertex_handle v);

void vertex_barycentric_areas(halfedge_mesh &mesh, size_t parallel_grain_size = 1024);

}

#endif //BCG_GRAPHICS_BCG_MESH_VERTEX_AREA_BARYCENTRIC_H
