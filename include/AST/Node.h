#pragma once

#include <cassert>

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include "ShortCut.h"
#include "CodeGen/TargetBuilder.h"

#ifdef DEBUG
#include "TreePrinter.h"
#endif // DEBUG

// #define SW_AST_DESTRUCTOR_LOG defined(DEBUG)
#define SW_AST_DESTRUCTOR_LOG 0

namespace Bunny {
    namespace AST {

        class Node {
        public:
            virtual ~Node() = 0;
            virtual void GenerateCode(TargetBuilder &targetBuilder) const = 0;
#ifdef DEBUG
            virtual void Print(TreePrinter &printer) const = 0;
#endif // DEBUG
        };

        DEFINE_PTRS(Node)

        inline Node::~Node() { }

    };
};



#define _AST_CONCRETE_NODE_HEADER_GENERAL(type)                      \
    virtual ~type();                                                \
    virtual void GenerateCode(TargetBuilder &targetBuilder) const;  \

#define _AST_CONCRETE_NODE_HEADER_DEBUG(type)                        \
    virtual void Print(TreePrinter &printer) const;                  \

#ifdef DEBUG

#define AST_CONCRETE_NODE_HEADER(type)          \
        _AST_CONCRETE_NODE_HEADER_GENERAL(type)  \
        _AST_CONCRETE_NODE_HEADER_DEBUG(type)    \

#else // DEBUG

#define AST_CONCRETE_NODE_HEADER(type)          \
        _AST_CONCRETE_NODE_HEADER_GENERAL(type)  \

#endif // DEBUG




#define AST_NODE_DEFINE_DUMMY_GenerateCode(type) \
void type::GenerateCode(TargetBuilder &targetBuilder) const { assert(false); }


#ifdef DEBUG

#define AST_NODE_DEFINE_DUMMY_Print(type) \
void type::Print(TreePrinter &printer) const { assert(false); }

#else // DEBUG

#define AST_NODE_DEFINE_DUMMY_Print(type)

#endif // DEBUG


#if SW_AST_DESTRUCTOR_LOG

#define AST_NODE_DESTRUCTOR_LOG(type) \
std::cout << "Destructor of class " #type " is called." << std::endl;

#else // SW_AST_DESTRUCTOR_LOG

#define  AST_NODE_DESTRUCTOR_LOG(type)

#endif // SW_AST_DESTRUCTOR_LOG

#define AST_NODE_DEFAULT_DESTRUCTOR(type)           \
type::~type() { AST_NODE_DESTRUCTOR_LOG(type) }     \


#define AST_NODE_DUMMY_IMPLEMENTATION(type)         \
AST_NODE_DEFAULT_DESTRUCTOR(type)                   \
AST_NODE_DEFINE_DUMMY_GenerateCode(type)            \
AST_NODE_DEFINE_DUMMY_Print(type)                   \


