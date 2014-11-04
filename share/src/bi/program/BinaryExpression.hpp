/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csirexpr.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_PROGRAM_BINARYEXPRESSION_HPP
#define BI_PROGRAM_BINARYEXPRESSION_HPP

#include "Expression.hpp"
#include "Operator.hpp"

namespace biprog {
/**
 * Binary expression.
 *
 * @ingroup program
 */
class BinaryExpression: public virtual Expression,
    public boost::enable_shared_from_this<BinaryExpression> {
public:
  /**
   * Constructor.
   */
  BinaryExpression(boost::shared_ptr<Expression> left, Operator op,
      boost::shared_ptr<Expression> right);

  /**
   * Destructor.
   */
  virtual ~BinaryExpression();

  /*
   * Operators.
   */
  virtual bool operator<(const Expression& o) const;
  virtual bool operator<=(const Expression& o) const;
  virtual bool operator>(const Expression& o) const;
  virtual bool operator>=(const Expression& o) const;
  virtual bool operator==(const Expression& o) const;
  virtual bool operator!=(const Expression& o) const;

  /**
   * Left operand.
   */
  boost::shared_ptr<Expression> left;

  /**
   * Operator.
   */
  Operator op;

  /**
   * Right operand.
   */
  boost::shared_ptr<Expression> right;
};
}

inline biprog::BinaryExpression::BinaryExpression(
    boost::shared_ptr<Expression> left, Operator op,
    boost::shared_ptr<Expression> right) :
    left(left), op(op), right(right) {
  //
}

inline biprog::BinaryExpression::~BinaryExpression() {
  //
}

inline bool biprog::BinaryExpression::operator<(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op == expr.op && *left < *expr.left && *right < *expr.right;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::BinaryExpression::operator<=(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op == expr.op && *left <= *expr.left && *right <= *expr.right;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::BinaryExpression::operator>(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op == expr.op && *left > *expr.left && *right > *expr.right;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::BinaryExpression::operator>=(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op == expr.op && *left >= *expr.left && *right >= *expr.right;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::BinaryExpression::operator==(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op == expr.op && *left == *expr.left && *right == *expr.right;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::BinaryExpression::operator!=(const Expression& o) const {
  try {
    const BinaryExpression& expr = dynamic_cast<const BinaryExpression&>(o);
    return op != expr.op || *left != *expr.left || *right != *expr.right;
  } catch (std::bad_cast e) {
    return true;
  }
}

#endif
