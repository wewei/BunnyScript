#pragma once

#include "ShortCut.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class AsyncExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(AsyncExpression)

            AsyncExpression(const SPExpressionC &exprChild)
                : m_exprChild(exprChild)
                { }

            const SPExpressionC &ChildExpression() const { return m_exprChild; }

        private:
            SPExpressionC m_exprChild;
        };

        DEFINE_PTRS(AsyncExpression)
    }
}

