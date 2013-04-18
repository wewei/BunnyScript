#pragma once

#include "ShortCut.h"
#include "Statement.h"

namespace Bunny {
    namespace AST {
        class StatementList;
        DEFINE_PTRS(StatementList)

        class StatementList : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(StatementList)

            StatementList(const SPStatementC &firstStatement,
                          const SPStatementListC &otherStatements)
                : m_firstStatement(firstStatement)
                , m_otherStatements(otherStatements)
                { }

            const SPStatementC &FirstStatement() const
                { return m_firstStatement; }

            const SPStatementListC &OtherStatements() const
                { return m_otherStatements; }

        private:
            SPStatementC m_firstStatement;
            SPStatementListC m_otherStatements;
        };

        class BlockStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(BlockStatement)

            BlockStatement(const SPStatementListC &statements)
                : m_statements(statements)
                { }

            const SPStatementListC &Statements() const
                { return m_statements; }

        private:
            SPStatementListC m_statements;
        };

        DEFINE_PTRS(BlockStatement)
    }
}

