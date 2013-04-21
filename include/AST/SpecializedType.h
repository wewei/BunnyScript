#pragma once

#include "ShortCut.h"
#include "Type.h"
#include "TypeList.h"

namespace Bunny {
    namespace AST {
        class SpecializedType: public Type {
        public:
            AST_CONCRETE_NODE_HEADER(SpecializedType)

            SpecializedType(const SPTypeC &genericType,
                            const SPTypeListC &typeList)
                : m_genericType(genericType)
                , m_typeList(typeList)
                { }

            const SPTypeC &GenericType() const { return m_genericType; }

            const SPTypeListC &TypeList() const { return m_typeList; }

        private:
            SPTypeC m_genericType;
            SPTypeListC m_typeList;
        };

        DEFINE_PTRS(SpecializedType)
    }
}

