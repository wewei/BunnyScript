#pragma once

#include "ShortCut.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        typedef enum {
            AO_ASSIGN,
            AO_ADD_ASSIGN,
            AO_MINUS_ASSIGN,
            AO_MULTIPLY_ASSIGN,
            AO_DIVIDE_ASSIGN,
        } AssignOperator;

        class LValue : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(LValue)

            LValue(const SPExpressionC &exprChild) : m_exprChild(exprChild) { }

            const SPExpressionC &ChildExpression() const { return m_exprChild; }
        private:
            SPExpressionC m_exprChild;
        };

        DEFINE_PTRS(LValue)

        class AssignExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(AssignExpression)

            AssignExpression(const SPLValueC &lvalue,
                             const SPExpressionC &exprValue,
                             AssignOperator oper)
                : m_lvalue(lvalue)
                , m_exprValue(exprValue)
                , m_oper(oper)
                { }

            const AssignOperator Operator() const { return m_oper; }
            const SPLValueC &LValue() const { return m_lvalue; }
            const SPExpressionC &ValueExpression() const { return m_exprValue; }

        private:
            SPLValueC m_lvalue;
            SPExpressionC m_exprValue;
            AssignOperator m_oper;
        };

        DEFINE_PTRS(AssignExpression)
    }
}

