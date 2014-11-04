/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csirexpr.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_PROGRAM_BRACKETED_HPP
#define BI_PROGRAM_BRACKETED_HPP

#include "Expression.hpp"

namespace biprog {
/**
 * Bracketed expression.
 *
 * @ingroup program
 */
class Bracketed : public virtual Expression {
public:
  /**
   * Constructor.
   *
   * @param brackets Expression in square brackets.
   */
  Bracketed(boost::shared_ptr<Expression> brackets);

  /**
   * Destructor.
   */
  virtual ~Bracketed() = 0;

  /**
   * First statement in index brackets.
   */
  boost::shared_ptr<Expression> brackets;
};
}

inline biprog::Bracketed::Bracketed(boost::shared_ptr<Expression> brackets) :
    brackets(brackets) {
  //
}

inline biprog::Bracketed::~Bracketed() {
  //
}

#endif

