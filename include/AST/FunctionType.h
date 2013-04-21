#pragma once

#include "ShortCut.h"
#include "Type.h"
#include "TypeList.h"

namespace Bunny {
    namespace AST {
        class FunctionType: public Type {
        public:
            AST_CONCRETE_NODE_HEADER(FunctionType)

            FunctionType(const SPTypeC &returnType,
                         const SPTypeListC &paramTypeList)
                : m_returnType(returnType)
                , m_paramTypeList(paramTypeList)
                { }

            const SPTypeC &ReturnType() const { return m_returnType; }

            const SPTypeListC &ParameterTypeList() const { return m_paramTypeList; }

        private:
            SPTypeC m_returnType;
            SPTypeListC m_paramTypeList;
        };

        DEFINE_PTRS(FunctionType)
    }
}

