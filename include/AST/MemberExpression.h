#pragma once

#include "ShortCut.h"
#include "Expression.h"
#include "Name.h"

namespace Bunny {
    namespace AST {

        class MemberExpression : public Expression {
        public:
            AST_CONCRETE_NODE_HEADER(MemberExpression)

            MemberExpression(const SPExpressionC &exprMaster,
                             const SPNameC &memberName)
                : m_exprMaster(exprMaster)
                , m_memberName(memberName)
                { }

            const SPExpressionC &MasterExpression() const { return m_exprMaster; }
            const SPNameC &MemberName() const { return m_memberName; }

        private:
            SPExpressionC m_exprMaster;
            SPNameC m_memberName;
        };

        DEFINE_PTRS(MemberExpression)

    }
}

