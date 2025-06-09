#pragma once

#include "skiplist/skiplist.h"

// Insert a value into the skiplist
// return true if successfully inserted, false otherwise
template <typename T, typename Compare>
bool SkipList<T, Compare>::insert(T value) {}

// Remove a value from the skiplist
// return true if successfully removed, false otherwise
template <typename T, typename Compare>
bool SkipList<T, Compare>::remove(const T &value) {}

// Search the skiplist for a value
// return the node if the value exists, else return a nullpointer
template <typename T, typename Compare>
T *SkipList<T, Compare>::search(const T &value) const {}

// go all the way to the lowest layer of skiplist,
// then run through until you reach a node that has no pointers out
// return value of last node
template <typename T, typename Compare> T *SkipList<T, Compare>::max() const {}

// return the element after the dummy header
template <typename T, typename Compare> T *SkipList<T, Compare>::min() const {}

// Look if a value exists in the skiplist
// return true if it exists, else return false
template <typename T, typename Compare>
bool SkipList<T, Compare>::contains(const T &value) const {}

// Clear the whole skiplist of its nodes and reset the headers' pointers
template <typename T, typename Compare> void SkipList<T, Compare>::clear() {}

// check if there are elements in the skiplist (besides header)
template <typename T, typename Compare>
bool SkipList<T, Compare>::empty() const {}

// return the number of elements in the skiplist
template <typename T, typename Compare>
size_t SkipList<T, Compare>::size() const {}

// flip a coin, if heads, increment by one and flip again
// if tails, stop and return
template <typename T, typename Compare>
int SkipList<T, Compare>::randomLevel() {}
