#pragma once

#include "ShortCut.h"
#include "Type.h"
#include "Name.h"

namespace Bunny {
    namespace AST {
        class SimpleType: public Type{
        public:
            AST_CONCRETE_NODE_HEADER(SimpleType)

            SimpleType(const SPTypeC &nmspace,
                       const SPNameC &name)
                : m_nmspace(nmspace)
                , m_name(name)
                { }

            const SPTypeC &Namespace() const { return m_nmspace; }
            const SPNameC &Name() const { return m_name; }

        private:
            SPTypeC m_nmspace;
            SPNameC m_name;
        };

        DEFINE_PTRS(SimpleType)
    }
}

