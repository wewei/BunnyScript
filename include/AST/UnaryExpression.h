#pragma once

#include "ShortCut.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        typedef enum {
            // Arithmetic
            UO_NEG,

            // Logic
            UO_NOT,
        } UnaryOperator;

        class UnaryExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(UnaryExpression)

            UnaryExpression(const SPExpressionC &exprChild, UnaryOperator oper)
                : m_exprChild(exprChild)
                , m_oper(oper)
            { }

            UnaryOperator Operator() { return m_oper; }
            const SPExpressionC &ChildExpression() const { return m_exprChild; }

        private:
            UnaryOperator m_oper;
            SPExpressionC m_exprChild;
        };

        DEFINE_PTRS(UnaryExpression)
    }
}

