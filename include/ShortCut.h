#pragma once

#include <string>
#include <tr1/memory>

#define SharedPtr std::tr1::shared_ptr
#define WeakPtr std::tr1::weak_ptr
#define UniquePtr std::auto_ptr

#define DEFINE_PTRS(type)                       \
    typedef SharedPtr<type> SP##type;           \
    typedef SharedPtr<const type> SP##type##C;  \
    typedef WeakPtr<type> WP##type;             \
    typedef WeakPtr<const type> WP##type##C;    \
    typedef UniquePtr<type> UP##type;           \
    typedef UniquePtr<const type> UP##type##C;  \


typedef std::string String;
DEFINE_PTRS(String)

