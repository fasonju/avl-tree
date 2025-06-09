#pragma once

#include "container.h"
#include <memory>
#include <random>
#include <vector>

constexpr int DEFAULT_MAX_LEVEL = 20;
constexpr float LEVEL_UP_CHANCE = 0.5;

template <typename T, typename Compare = std::less<T>,
          typename Allocator = std::allocator<T>>
class SkipList {
  public:
    // this one (or the maxLevel) even necessary?
    explicit SkipList(int maxLevel = DEFAULT_MAX_LEVEL) : maxLevel(maxLevel) {};

    SkipList(const SkipList &) = delete;
    SkipList(SkipList &&) = delete;
    SkipList &operator=(const SkipList &) = delete;
    SkipList &operator=(SkipList &&) = delete;
    ~SkipList() = default;

    bool insert(T value);
    bool remove(const T &value);
    T *search(const T &value) const;
    T *max() const;
    T *min() const;
    bool contains(const T &value) const;
    [[nodiscard]] size_t size() const;
    void clear();
    [[nodiscard]] bool empty() const;

  private:
    struct Node {
        T value;
        std::vector<Node *> forward;

        Node(const T &&val, int level)
            : value(std::move(val)), forward(level, nullptr) {}
    };
    using NodeAllocator =
        typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;

    int randomLevel();
    Node *createNode(const T &value, int level);

    const int maxLevel;
    int currentLevel = 0;
    size_t _size = 0;
    Node *header;
    mutable std::mt19937 gen;
    mutable std::uniform_real_distribution<> dist;
    Compare comp;
};

#include "skiplist/skiplist.hpp"

static_assert(Container<SkipList<int>, int>);
