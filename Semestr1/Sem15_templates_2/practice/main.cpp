#include "pair.hpp"
#include "comparison.hpp"
#include "hash.hpp"


// "integral constant"
#include "lect/is_same.hpp"
// "type_identity"
#include "lect/conditional.hpp"
#include "lect/remove_const.hpp"
#include "lect/remove_reference.hpp"

#include "fib.hpp"
#include "is_prime.hpp"
#include "rank.hpp"
#include "is_member_pointer.hpp"
#include "decay.hpp"

// variadic templates
#include "lect/print.hpp"
#include "is_homogeneous.hpp"

// template template parameters

int main() {
  TestPair();
  TestComparison();
  TestHash();

  TestIsSame();
  TestConditional();
  TestRemoveConst();
  TestRemoveReference();

  TestFib();
  TestIsPrime();
  // TestRank();
  // TestIsMemberPointer();
  // TestDecay();

  TestPrint();
  TestIsHomogeneous();
}
