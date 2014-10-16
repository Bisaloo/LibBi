/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csiro.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_FILTER_FILTER_HPP
#define BI_FILTER_FILTER_HPP

#include "../random/Random.hpp"
#include "../state/Schedule.hpp"
#include "../misc/macro.hpp"

namespace bi {
/**
 * Filter wrapper, buckles a common interface onto any filter.
 *
 * @ingroup method_filter
 *
 * @tparam F Base filter type.
 */
template<class F>
class Filter: public F {
public:
  BI_PASSTHROUGH_CONSTRUCTORS(Filter, F)

  /**
   * %Filter after initialisation or proposal.
   *
   * @tparam S1 State type.
   * @tparam IO1 Output type.
   *
   * @param[in,out] rng Random number generator.
   * @param first Start of time schedule.
   * @param last End of time schedule.
   * @param[in,out] s State.
   * @param[out] out Output buffer.
   *
   * For this to work correctly, either init() or propose() should be called
   * directory before the call to filter().
   */
  template<class S1, class IO1>
  void filter(Random& rng, const ScheduleIterator first,
      const ScheduleIterator last, S1& s, IO1& out);
};
}

template<class F>
template<class S1, class IO1>
void bi::Filter<F>::filter(Random& rng, const ScheduleIterator first,
    const ScheduleIterator last, S1& s, IO1& out) {
  ScheduleIterator iter = first;
  this->output0(s, out);
  this->correct(rng, *iter, s);
  this->output(*iter, s, out);
  while (iter + 1 != last) {
    this->step(rng, iter, last, s, out);
  }
  this->term(s);
  this->outputT(s, out);
}

#endif
