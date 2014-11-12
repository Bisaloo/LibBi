/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csiro.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_PROGRAM_CONDITIONAL_HPP
#define BI_PROGRAM_CONDITIONAL_HPP

#include "Conditioned.hpp"
#include "Braced.hpp"
#include "Scoped.hpp"

namespace biprog {
/**
 * Conditional.
 *
 * @ingroup program
 */
class Conditional: public virtual Conditioned,
    public virtual Braced,
    public virtual Scoped,
    public boost::enable_shared_from_this<Conditional> {
public:
  /**
   * Constructor.
   */
  Conditional(boost::shared_ptr<Expression> cond,
      boost::shared_ptr<Expression> braces, boost::shared_ptr<Scope> scope);

  /**
   * Destructor.
   */
  virtual ~Conditional();

  /*
   * Operators.
   */
  virtual bool operator<(const Expression& o) const;
  virtual bool operator<=(const Expression& o) const;
  virtual bool operator>(const Expression& o) const;
  virtual bool operator>=(const Expression& o) const;
  virtual bool operator==(const Expression& o) const;
  virtual bool operator!=(const Expression& o) const;

protected:
  /**
   * Output.
   */
  virtual void output(std::ostream& out) const;
};
}

inline biprog::Conditional::Conditional(boost::shared_ptr<Expression> cond,
    boost::shared_ptr<Expression> braces, boost::shared_ptr<Scope> scope) :
    Conditioned(cond), Braced(braces), Scoped(scope) {
  //
}

inline biprog::Conditional::~Conditional() {
  //
}

#endif
