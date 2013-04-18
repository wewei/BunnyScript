#pragma once

#include "ShortCut.h"
#include "Statement.h"
#include "Expression.h"
#include "AssignExpression.h"

namespace Bunny {
    namespace AST {
        class ForStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(ForStatement)

            ForStatement(const SPLValueC &element,
                         const SPExpressionC &exprCollection,
                         const SPStatementC &loopBody)
                : m_element(element)
                , m_exprCollection(exprCollection)
                , m_loopBody(loopBody)
                { }

            const SPLValueC &Element() const
                { return m_element; }

            const SPExpressionC &ColletionExpression() const
                { return m_exprCollection; }

            const SPStatementC &LoopBody() const
                { return m_loopBody; }

        private:
            SPLValueC m_element;
            SPExpressionC m_exprCollection;
            SPStatementC m_loopBody;
        };

        DEFINE_PTRS(ForStatement)
    }
}


