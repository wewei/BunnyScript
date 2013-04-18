#pragma once

#include "ShortCut.h"
#include "Statement.h"

namespace Bunny {
    namespace AST {
        class ContinueStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(ContinueStatement)
        private:
        };

        DEFINE_PTRS(ContinueStatement)
    }
}

