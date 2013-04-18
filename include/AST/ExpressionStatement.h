#pragma once

#include "ShortCut.h"
#include "Statement.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class ExpressionStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(ExpressionStatement)

            ExpressionStatement(const SPExpressionC &expr) : m_expr(expr) { }

            const SPExpressionC &Expression() const { return m_expr; }
        private:
            SPExpressionC m_expr;
        };

        DEFINE_PTRS(ExpressionStatement)
    }
}

