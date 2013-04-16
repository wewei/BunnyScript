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
    typedef type * P##type;                     \
    typedef const type * P##type##C;            \
    typedef type & Ref##type;                   \
    typedef const type & Ref##type##C;          \


typedef std::string String;
DEFINE_PTRS(String)

inline SPString SPSTR(const char *str) { return SPString(new String(str)); }

typedef std::ostream OStream;
DEFINE_PTRS(OStream)


