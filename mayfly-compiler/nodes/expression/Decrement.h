#ifndef __MF_NODE_EXPRESSION_DECREMENT_H__
#define __MF_NODE_EXPRESSION_DECREMENT_H__

#include <cdk/nodes/expressions/UnaryExpression.h>
#include "SemanticProcessor.h"

namespace mayfly {
  namespace node {
    namespace expression {

      /**
       * Class for describing the negation operator
       */
      class Decrement: public cdk::node::expression::UnaryExpression {
		protected:
		  bool _is_prefix;

      public:
        inline Decrement(int lineno, Expression *arg, bool is_prefix=false) :
          UnaryExpression(lineno, arg), _is_prefix(is_prefix) {
        }

		  const bool is_prefix() {
		    return _is_prefix;
		  }

        /**
         * @return the name of the node's class
         */
        const char *name() const {
          return "Decrement";
        }

        /**
         * @param sp semantic processor visitor
         * @param level syntactic tree level
         */
        virtual void accept(SemanticProcessor *sp, int level) {
          sp->processDecrement(this, level);
        }

      };

    } // expression
  } // node
} // mayfly

#endif
