/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csirexpr.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_PROGRAM_SEQUENCE_HPP
#define BI_PROGRAM_SEQUENCE_HPP

#include "Expression.hpp"

namespace biprog {
/**
 * Sequence of statements.
 *
 * @ingroup program
 */
class Sequence: public virtual Expression,
    public boost::enable_shared_from_this<Sequence> {
public:
  /**
   * Constructor.
   */
  Sequence(boost::shared_ptr<Expression> head,
      boost::shared_ptr<Expression> tail);

  /**
   * Destructor.
   */
  virtual ~Sequence();

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
   * First statement.
   */
  boost::shared_ptr<Expression> head;

  /**
   * Remaining statements.
   */
  boost::shared_ptr<Expression> tail;
};
}

inline biprog::Sequence::Sequence(boost::shared_ptr<Expression> head,
    boost::shared_ptr<Expression> tail) :
    head(head), tail(tail) {
  //
}

inline biprog::Sequence::~Sequence() {
  //
}

inline bool biprog::Sequence::operator<(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head < *expr.head && *tail < *expr.tail;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::Sequence::operator<=(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head <= *expr.head && *tail <= *expr.tail;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::Sequence::operator>(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head > *expr.head && *tail > *expr.tail;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::Sequence::operator>=(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head >= *expr.head && *tail >= *expr.tail;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::Sequence::operator==(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head == *expr.head && *tail == *expr.tail;
  } catch (std::bad_cast e) {
    return false;
  }
}

inline bool biprog::Sequence::operator!=(const Expression& o) const {
  try {
    const Sequence& expr = dynamic_cast<const Sequence&>(o);
    return *head != *expr.head || *tail != *expr.tail;
  } catch (std::bad_cast e) {
    return true;
  }
}

#endif
