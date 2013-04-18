#pragma once

#include "ShortCut.h"
#include "Statement.h"

namespace Bunny {
    namespace AST {
        class BreakStatement : public Statement {
        public:
            AST_CONCRETE_NODE_HEADER(BreakStatement)
        private:
        };

        DEFINE_PTRS(BreakStatement)
    }
}

