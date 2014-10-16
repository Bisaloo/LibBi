/**
 * @file
 *
 * @author Lawrence Murray <lawrence.murray@csiro.au>
 * $Rev$
 * $Date$
 */
#ifndef BI_STATE_FILTERSTATE_HPP
#define BI_STATE_FILTERSTATE_HPP

#include "State.hpp"

namespace bi {
/**
 * State for filter.
 *
 * @ingroup state
 */
template<class B, Location L>
class FilterState: public State<B,L> {
public:
  /**
   * Constructor.
   *
   * @param P Number of \f$x\f$-particles.
   * @param Y Number of observation times.
   * @param T Number of output times.
   */
  FilterState(const int P = 0, const int Y = 0, const int T = 0);

  /**
   * Shallow copy constructor.
   */
  FilterState(const FilterState<B,L>& o);

  /**
   * Assignment operator.
   */
  FilterState& operator=(const FilterState<B,L>& o);

  /**
   * Clear.
   */
  void clear();

  /**
   * Swap.
   */
  void swap(FilterState<B,L>& o);

  /**
   * Path sample.
   */
  typename State<B,L>::matrix_type path;

  /**
   * Times associated with path sample.
   */
  typename State<B,L>::vector_type times;

  /**
   * Log-prior density of parameters.
   */
  double logPrior;

  /**
   * Log-proposal density of parameters.
   */
  double logProposal;

  /**
   * Marginal log-likelihood of parameters.
   */
  double logLikelihood;

private:
  /**
   * Serialize.
   */
  template<class Archive>
  void save(Archive& ar, const unsigned version) const;

  /**
   * Restore from serialization.
   */
  template<class Archive>
  void load(Archive& ar, const unsigned version);

  /*
   * Boost.Serialization requirements.
   */
  BOOST_SERIALIZATION_SPLIT_MEMBER()
  friend class boost::serialization::access;
};
}

template<class B, bi::Location L>
bi::FilterState<B,L>::FilterState(const int P, const int Y, const int T) :
    State<B,L>(P, Y, T), path(B::NR + B::ND, T), times(T), logPrior(-BI_INF), logProposal(
        -BI_INF), logLikelihood(0.0) {
  //
}

template<class B, bi::Location L>
bi::FilterState<B,L>::FilterState(const FilterState<B,L>& o) :
    State<B,L>(o), path(o.path), times(o.times), logPrior(o.logPrior), logProposal(
        o.logProposal), logLikelihood(o.logLikelihood) {
  //
}

template<class B, bi::Location L>
bi::FilterState<B,L>& bi::FilterState<B,L>::operator=(
    const FilterState<B,L>& o) {
  State<B,L>::operator=(o);
  path = o.path;
  times = o.times;
  logLikelihood = o.logLikelihood;
  logPrior = o.logPrior;
  logProposal = o.logProposal;

  return *this;
}

template<class B, bi::Location L>
void bi::FilterState<B,L>::clear() {
  State<B,L>::clear();
  logPrior = -BI_INF;
  logProposal = -BI_INF;
  logLikelihood = 0.0;
}

template<class B, bi::Location L>
void bi::FilterState<B,L>::swap(FilterState<B,L>& o) {
  State<B,L>::swap(o);
  std::swap(logPrior, o.logPrior);
  std::swap(logProposal, o.logProposal);
  std::swap(logLikelihood, o.logLikelihood);
}

template<class B, bi::Location L>
template<class Archive>
void bi::FilterState<B,L>::save(Archive& ar, const unsigned version) const {
  ar & boost::serialization::base_object < State<B,L> > (*this);
  save_resizable_matrix(ar, version, path);
  save_resizable_vector(ar, version, times);
  ar & logPrior;
  ar & logProposal;
  ar & logLikelihood;
}

template<class B, bi::Location L>
template<class Archive>
void bi::FilterState<B,L>::load(Archive& ar, const unsigned version) {
  ar & boost::serialization::base_object < State<B,L> > (*this);
  load_resizable_matrix(ar, version, path);
  load_resizable_vector(ar, version, times);
  ar & logPrior;
  ar & logProposal;
  ar & logLikelihood;
}

#endif
