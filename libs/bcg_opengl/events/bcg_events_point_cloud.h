//
// Created by alex on 04.11.20.
//

#ifndef BCG_GRAPHICS_BCG_EVENTS_POINT_CLOUD_H
#define BCG_GRAPHICS_BCG_EVENTS_POINT_CLOUD_H

#include "entt/entt.hpp"

namespace bcg{

}
namespace bcg::event::point_cloud{
struct setup{
    entt::entity id;
    std::string filename;
};
namespace build{
struct graph_knn{
    entt::entity id;
    int num_closest = 0;
};
struct graph_radius{
    entt::entity id;
    bcg_scalar_t radius = 0;
};
}

namespace vertex{
namespace pca{
struct svd{
    entt::entity id;
    bool compute_mean = true;
    int num_closest = 0;
    bcg_scalar_t radius = 0;
};
struct weighted_svd{
    entt::entity id;
    bool compute_mean = true;
    int num_closest = 0;
    bcg_scalar_t radius = 0;
};
struct eig{
    entt::entity id;
    bool compute_mean = true;
    int num_closest = 0;
    bcg_scalar_t radius = 0;
};
struct weighted_eig{
    entt::entity id;
    bool compute_mean = true;
    int num_closest = 0;
    bcg_scalar_t radius = 0;
};
}
}
}
#endif //BCG_GRAPHICS_BCG_EVENTS_POINT_CLOUD_H
