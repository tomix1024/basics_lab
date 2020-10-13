//
// Created by alex on 10.10.20.
//

#ifndef BCG_GRAPHICS_BCG_MESH_H
#define BCG_GRAPHICS_BCG_MESH_H

#include "bcg_graph.h"

namespace bcg {

struct halfedge_mesh : public halfedge_graph {
    using position_t = vec3f;
    property_container vertices, halfedges, edges, faces, object_properties;

    struct vertex_connectivity {
        halfedge_handle h;
    };

    struct halfedge_connectivity {
        vertex_handle v;
        halfedge_handle nh;
        halfedge_handle ph;
        face_handle f;
    };

    struct face_connectivity {
        halfedge_handle h;
    };

    property<position_t, 3> position;
    property<vertex_connectivity, 1> vconn;
    property<halfedge_connectivity, 1> hconn;

    halfedge_mesh();

    ~halfedge_mesh() override = default;

    void assign(const halfedge_mesh &other);

    halfedge_mesh &operator=(const halfedge_mesh &other);

    bool has_garbage() const override;

    void garbage_collection() override;

    bool is_boundary(vertex_handle v) const override;

    bool is_boundary(halfedge_handle h) const override;

    bool is_boundary(edge_handle e) const override;

    bool is_boundary(face_handle f) const;

    bool is_manifold(vertex_handle v) const;

    bool is_manifold() const;

    bool is_triangle_mesh() const;

    bool is_quad_mesh() const;

    bool is_removal_ok(edge_handle e) const;

    bool is_collapse_ok(halfedge_handle h) const;

    bool is_flip_ok(edge_handle e) const;

    face_handle get_face(edge_handle e) const;

    void set_face(edge_handle e, face_handle f);

    halfedge_handle get_halfedge(face_handle f) const;

    void set_halfedge(face_handle f, halfedge_handle h);

    size_t num_vertices(face_handle f) const;

    size_t num_edges(face_handle f) const;

    face_handle add_face(const std::vector<vertex_handle> &f_vertices);

    face_handle add_triangle(vertex_handle v0, vertex_handle v1, vertex_handle v2);

    face_handle add_quad(vertex_handle v0, vertex_handle v1, vertex_handle v2, vertex_handle v3);

    void adjust_outgoing_halfedge(vertex_handle v);

    void delete_face(face_handle f);

    void remove_edge(edge_handle e);

    void delete_edge(edge_handle e);

    void delete_vertex(vertex_handle v) override;

    struct face_around_vertex_circulator {
        const halfedge_mesh *ds;
        halfedge_handle halfedge;
        bool active;

        explicit face_around_vertex_circulator(const halfedge_mesh *ds = nullptr, vertex_handle v = vertex_handle());

        inline bool operator==(const face_around_vertex_circulator &rhs) const;

        inline bool operator!=(const face_around_vertex_circulator &rhs) const;

        inline face_around_vertex_circulator &operator++();

        inline face_around_vertex_circulator &operator--();

        inline face_handle operator*() const;

        inline operator bool() const;

        inline face_around_vertex_circulator &begin();

        inline face_around_vertex_circulator &end();
    };

    face_around_vertex_circulator get_faces(vertex_handle v) const;

    struct vertex_around_face_circulator {
        const halfedge_mesh *ds;
        halfedge_handle halfedge;
        bool active;

        explicit vertex_around_face_circulator(const halfedge_mesh *ds = nullptr, face_handle f = face_handle());

        inline bool operator==(const vertex_around_face_circulator &rhs) const;

        inline bool operator!=(const vertex_around_face_circulator &rhs) const;

        inline vertex_around_face_circulator &operator++();

        inline vertex_around_face_circulator &operator--();

        inline vertex_handle operator*() const;

        inline vertex_around_face_circulator &begin();

        inline vertex_around_face_circulator &end();
    };

    vertex_around_face_circulator get_vertices(face_handle f) const;


    struct halfedge_around_face_circulator {
        const halfedge_mesh *ds;
        halfedge_handle halfedge;
        bool active;

        explicit halfedge_around_face_circulator(const halfedge_mesh *ds = nullptr, face_handle f = face_handle());

        inline bool operator==(const halfedge_around_face_circulator &rhs) const;

        inline bool operator!=(const halfedge_around_face_circulator &rhs) const;

        inline halfedge_around_face_circulator &operator++();

        inline halfedge_around_face_circulator &operator--();

        inline halfedge_handle operator*() const;

        inline halfedge_around_face_circulator &begin();

        inline halfedge_around_face_circulator &end();
    };

    halfedge_around_face_circulator get_halfedges(face_handle f) const;

    void triangulate();

    void triangulate(face_handle f);

    void collapse(halfedge_handle h);

    void remove_edge_helper(halfedge_handle h);

    void remove_loop_helper(halfedge_handle h);

    vertex_handle split(face_handle f, const position_t &point);

    vertex_handle split(face_handle f, vertex_handle v);

    halfedge_handle split(edge_handle e, const position_t &point);

    halfedge_handle split(edge_handle e, vertex_handle v);

    halfedge_handle insert_vertex(edge_handle e, const position_t &point);

    halfedge_handle insert_vertex(edge_handle e, vertex_handle v);

    halfedge_handle insert_vertex(halfedge_handle h, vertex_handle v);

    halfedge_handle insert_edge(halfedge_handle h0, halfedge_handle h1);

    void flip(edge_handle e);

    std::vector<vec3i> get_triangles();

    std::vector<vec3i> get_triangles_adjacencies();



protected:


};

}

#endif //BCG_GRAPHICS_BCG_MESH_H