#pragma once

#include "ShortCut.h"
#include "Statement.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class ReturnStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(ReturnStatement)

            ReturnStatement(const SPExpressionC &exprReturn)
                : m_exprReturn(exprReturn)
                { }

            const SPExpressionC &ReturnExpression() const
                { return m_exprReturn; }
        private:
            SPExpressionC m_exprReturn;
        };

        DEFINE_PTRS(ReturnStatement)
    }
}

