#pragma once

#include "ShortCut.h"
#include "Statement.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class IfStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(IfStatement)

            IfStatement(const SPExpressionC &exprCondition,
                        const SPStatementC &thenClause,
                        const SPStatementC &elseClause)
                : m_exprCondition(exprCondition)
                , m_thenClause(thenClause)
                , m_elseClause(elseClause)
                { }

            const SPStatementC &ThenClause() const
                { return m_thenClause; }

            const SPStatementC &ElseClause() const
                { return m_elseClause; }

            const SPExpressionC &ConditionExpression() const
                { return m_exprCondition; }
        private:
            SPExpressionC m_exprCondition;
            SPStatementC m_thenClause;
            SPStatementC m_elseClause;
        };

        DEFINE_PTRS(IfStatement)
    }
}


