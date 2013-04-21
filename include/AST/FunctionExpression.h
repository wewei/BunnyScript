#pragma once

#include "ShortCut.h"
#include "Expression.h"
#include "Type.h"
#include "Name.h"
#include "Statement.h"

namespace Bunny {
    namespace AST {
        class ParameterList;

        DEFINE_PTRS(ParameterList)

        class ParameterList : public Node {
        public:
            AST_CONCRETE_NODE_HEADER(ParameterList)

            ParameterList(const SPTypeC &firstParamType,
                          const SPNameC &firstParamName,
                          const SPParameterListC &otherParameters)
                : m_firstParamType(firstParamType)
                , m_firstParamName(firstParamName)
                , m_otherParameters(otherParameters)
                { }

            const SPTypeC &FirstParameterType() const
                { return m_firstParamType; }

            const SPNameC &FirstParameterName() const
                { return m_firstParamName; }

            const SPParameterListC &OtherParameters() const
                { return m_otherParameters; }

        private:
            SPTypeC m_firstParamType;
            SPNameC m_firstParamName;
            SPParameterListC m_otherParameters;
        };

        class FunctionExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(FunctionExpression)

            FunctionExpression(const SPTypeC &returnType,
                               const SPParameterListC &paramList,
                               const SPStatementC &statement)
                : m_returnType(returnType)
                , m_paramList(paramList)
                , m_statement(statement)
                { }

            const SPTypeC &ReturnType() const { return m_returnType; }
            const SPParameterListC &ParameterList() const { return m_paramList; }
            const SPStatementC &Statement() const { return m_statement; }
        private:
            SPTypeC m_returnType;
            SPParameterListC m_paramList;
            SPStatementC m_statement;
        };

        DEFINE_PTRS(FunctionExpression)
    }
}

