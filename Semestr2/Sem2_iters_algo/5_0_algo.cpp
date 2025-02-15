// clang-format off

//// #include <algorithm>

// Most used

// copy
// copy_backward
// copy_if (UnaryPredicate)
// fill
// unique (requires sorted range)

// Simple

// find
// find_if
// count
// count_if
// all_of
// any_of
// for_each

// More complex

// remove
// remove_if
// replace
// replace_if

// Even more complex

// sort (see libstdc++ impl)
// stable_sort (see libstdc++ impl and stl_tempbuf.h https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_tempbuf.h to explain log^2)
// partition: https://en.cppreference.com/w/cpp/algorithm/partition

// Complex (what iterator types are required ???)

// is_permutation (Forward)
// next_permutation (Bidirectional, with impl)
// is_heap (Random Access)
// make_heap (Random Access)
// rotate (Forward, but RA has better performance; example + examine impl: https://en.cppreference.com/w/cpp/algorithm/rotate#Possible_implementation). next_read = next_mid (2 cases depending on mid, always cut off the start)
// reverse (Bidirectional)

// clang-format on
