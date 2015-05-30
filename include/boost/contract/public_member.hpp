
#ifndef BOOST_CONTRACT_PUBLIC_MEMBER_HPP_
#define BOOST_CONTRACT_PUBLIC_MEMBER_HPP_

/** @file */

#include <boost/contract/core/set_precondition_postcondition.hpp>
#include <boost/contract/core/virtual.hpp>
#include <boost/contract/aux_/function/public_member.hpp>
#include <boost/contract/aux_/none.hpp>
/** @cond */
#include <boost/make_shared.hpp>
/** @endcond */

namespace boost { namespace contract {

// For non-virtual of class with no bases.
template<class C>
set_precondition_postcondition<void> public_member(C* obj) {
    return set_precondition_postcondition<void>(boost::make_shared<
        boost::contract::aux::public_member<
            boost::contract::aux::none,
            boost::contract::aux::none,
            boost::contract::aux::none,
            C,
            boost::contract::aux::none
        >
    >(0, obj, boost::contract::aux::none::value));
}

// For virtual members of class with no bases.
template<class C>
set_precondition_postcondition<void> public_member(virtual_* v, C* obj) {
    return set_precondition_postcondition<void>(boost::make_shared<
        boost::contract::aux::public_member<
            boost::contract::aux::none,
            boost::contract::aux::none,
            boost::contract::aux::none,
            C,
            boost::contract::aux::none
        >
    >(v, obj, boost::contract::aux::none::value));
}

// For virtual members of class with no bases.
template<typename R, class C>
set_precondition_postcondition<R> public_member(virtual_* v, R& r, C* obj) {
    return set_precondition_postcondition<R>(boost::make_shared<
        boost::contract::aux::public_member<
            boost::contract::aux::none,
            R,
            boost::contract::aux::none,
            C,
            boost::contract::aux::none
        >
    >(v, obj, r, boost::contract::aux::none::value));
}

// TODO: Support configurable function arity.
// arity = 0

// For non-virtual members of class with bases.
template<class O, typename F, class C>
set_precondition_postcondition<void> public_member(F, C* obj) {
    return set_precondition_postcondition<void>(boost::make_shared<
        boost::contract::aux::public_member<
            O,
            boost::contract::aux::none,
            F,
            C,
            boost::contract::aux::none
        >
    >(0, obj, boost::contract::aux::none::value));
}

// For virtual members of class with bases.
template<class O, typename F, class C>
set_precondition_postcondition<void> public_member(virtual_* v, F, C* obj) {
    return set_precondition_postcondition<void>(boost::make_shared<
        boost::contract::aux::public_member<
            O,
            boost::contract::aux::none,
            F,
            C,
            boost::contract::aux::none
        >
    >(v, obj, boost::contract::aux::none::value));
}

// arity = 1

template<class O, typename F, class C, typename A0>
set_precondition_postcondition<void> public_member(F, C* obj, A0& a0) {
    return set_precondition_postcondition<void>(boost::make_shared<
        boost::contract::aux::public_member<
            O,
            boost::contract::aux::none,
            F,
            C,
            A0
        >
    >(0, obj, a0));
}

template<class O, typename F, class C, typename A0>
set_precondition_postcondition<boost::contract::aux::none> public_member(
        virtual_* v, F, C* obj, A0& a0) {
    return set_precondition_postcondition<boost::contract::aux::none>(
            boost::make_shared<
        boost::contract::aux::public_member<
            O,
            boost::contract::aux::none,
            F,
            C,
            A0
        >
    >(v, obj, boost::contract::aux::none::value, a0));
}

template<class O, typename R, typename F, class C, typename A0>
set_precondition_postcondition<R> public_member(
        virtual_* v, R& r, F, C* obj, A0& a0) {
    return set_precondition_postcondition<R>(boost::make_shared<
        boost::contract::aux::public_member<
            O,
            R,
            F,
            C,
            A0
        >
    >(v, obj, r, a0));
}

// TODO: Support configurable arity.

} } // namespace

#endif // #include guard

