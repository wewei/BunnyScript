#pragma once

#include "Expression.h"

namespace Bunny {
    namespace AST {
        typedef enum {
            // Arithmetic
            BO_ADD,
            BO_MINUS,
            BO_MULTIPLY,
            BO_DIVIDE,
            BO_POWER,

            // Comparator
            BO_LT,
            BO_GT,
            BO_LE,
            BO_GE,
            BO_EQ,
            BO_NE,

            // Logic
            BO_AND,
            BO_OR,
            BO_XOR,

        } BinaryOperator;

        class BinaryExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(BinaryExpression)

            BinaryExpression(const SPExpressionC &exprLeft, const SPExpressionC &exprRight, BinaryOperator oper)
                : m_exprLeft(exprLeft)
                , m_exprRight(exprRight)
                , m_oper(oper)
            { }

            BinaryOperator Operator() { return m_oper; }
            const SPExpressionC &LeftExpression() const { return m_exprLeft; }
            const SPExpressionC &RightExpression() const { return m_exprRight; }

        private:
            BinaryOperator m_oper;
            SPExpressionC m_exprLeft;
            SPExpressionC m_exprRight;
        };

        DEFINE_PTRS(BinaryExpression)

    }
}

