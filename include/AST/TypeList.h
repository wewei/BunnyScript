#pragma once

#include "ShortCut.h"
#include "Node.h"
#include "Type.h"

namespace Bunny {
    namespace AST {
        class TypeList;

        DEFINE_PTRS(TypeList)

        class TypeList : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(TypeList)

            TypeList(const SPTypeC &firstType,
                     const SPTypeListC &otherTypes)
                : m_firstType(firstType)
                , m_otherTypes(otherTypes)
                { }

            const SPTypeC &FirstType() const { return m_firstType; }

            const SPTypeListC &OtherTypes() const { return m_otherTypes; }

        private:
            SPTypeC m_firstType;
            SPTypeListC m_otherTypes;
        };
    }
}

