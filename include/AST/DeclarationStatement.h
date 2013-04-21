#pragma once

#include "ShortCut.h"
#include "Statement.h"

#include "Type.h"
#include "Name.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class DeclarationStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(DeclarationStatement)

            DeclarationStatement(const SPTypeC &type,
                                 const SPNameC &varName,
                                 const SPExpressionC &initValue)
                : m_type(type)
                , m_varName(varName)
                , m_initValue(initValue)
                { }

            const SPTypeC &Type() const
                { return m_type; }

            const SPNameC &VariableName() const
                { return m_varName; }

            const SPExpressionC &InitialValue() const
                { return m_initValue; }

        private:
            SPTypeC m_type;
            SPNameC m_varName;
            SPExpressionC m_initValue;
        };

        DEFINE_PTRS(DeclarationStatement)
    }
}

