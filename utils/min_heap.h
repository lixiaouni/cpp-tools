//
// Created by shawnunili on 2019-11-04.
//

#ifndef CPP_TOOLS_MINHEAP_H
#define CPP_TOOLS_MINHEAP_H

#include <vector>
#include <queue>

namespace xct {
    // lhs left hand side
    auto minHeapCmp = [](const std::pair<int64_t, float> lhs, const std::pair<int64_t, float> rhs) {
        return lhs.second > rhs.second;
    };

    class MinHeap {
        typedef std::priority_queue<std::pair<int64_t, float>, std::vector<std::pair<int64_t, float>>, decltype(minHeapCmp)> MinHeapType;
    public:
        MinHeap(size_t heapSize);

        bool pop(std::pair<int64_t, float>& minData);

        void insert(const std::pair<int64_t, float>& data);

    private:
        size_t m_heapSize;
        MinHeapType m_queue;
    };
}
#endif //CPP_TOOLS_MINHEAP_H
