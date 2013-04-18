#pragma once

#include "ShortCut.h"
#include "Statement.h"
#include "Expression.h"

namespace Bunny {
    namespace AST {
        class WhileStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(WhileStatement)

            WhileStatement(const SPExpressionC &exprCondition,
                        const SPStatementC &thenClause)
                : m_exprCondition(exprCondition)
                , m_loopBody(thenClause)
                { }

            const SPStatementC &LoopBody() const
                { return m_loopBody; }

            const SPExpressionC &ConditionExpression() const
                { return m_exprCondition; }
        private:
            SPExpressionC m_exprCondition;
            SPStatementC m_loopBody;
        };

        DEFINE_PTRS(WhileStatement)
    }
}


