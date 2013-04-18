#pragma once

#include "ShortCut.h"
#include "Expression.h"

namespace Bunny {

    namespace AST {

        class ArgumentList;
        DEFINE_PTRS(ArgumentList);

        class ArgumentList : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(ArgumentList)

            ArgumentList(const SPExpressionC &firstArgument,
                         const SPArgumentListC &otherArguments)
                : m_firstArgument(firstArgument)
                , m_otherArguments(otherArguments)
                { }

            const SPExpressionC &FirstArgument() const
                { return m_firstArgument; }

            const SPArgumentListC &OtherArguments() const
                { return m_otherArguments; }

        private:
            SPExpressionC m_firstArgument;
            SPArgumentListC m_otherArguments;
        };

        class CallExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(CallExpression)

            CallExpression(const SPExpressionC procedure,
                              const SPArgumentListC argumentList)
                : m_procedure(procedure)
                , m_argumentList(argumentList)
                { }

            const SPExpressionC &Procedure() const
                { return m_procedure; }

            const SPArgumentListC &ArgumentList() const
                { return m_argumentList; }

        private:
            SPExpressionC m_procedure;
            SPArgumentListC m_argumentList;
        };

        DEFINE_PTRS(CallExpression)
    }
}

