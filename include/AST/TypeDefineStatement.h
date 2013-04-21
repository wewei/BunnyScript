#pragma once

#include "ShortCut.h"
#include "Statement.h"

#include "Type.h"
#include "Name.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class TypeDefineStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(TypeDefineStatement)

            TypeDefineStatement(const SPTypeC &type,
                                const SPNameC &typeName)
                : m_type(type)
                , m_typeName(typeName)
                { }

            const SPTypeC &Type() const
                { return m_type; }

            const SPNameC &TypeName() const
                { return m_typeName; }

        private:
            SPTypeC m_type;
            SPNameC m_typeName;
        };

        DEFINE_PTRS(TypeDefineStatement)
    }
}

