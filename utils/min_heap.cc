//
// Created by shawnunili on 2019-11-04.
//

#include "min_heap.h"

xct::MinHeap::MinHeap(size_t heapSize) : m_heapSize(heapSize), m_queue(minHeapCmp) {
    if (m_heapSize == 0) {
        abort();
    }
}

void xct::MinHeap::insert(const std::pair<int64_t, float>& data) {
    if (m_queue.size() < m_heapSize) {
        m_queue.push(data);
    } else {
        const auto& top = m_queue.top();
        if (data.second > top.second) {
            m_queue.pop();
            m_queue.push(data);
        }
    }
}

bool xct::MinHeap::pop(std::pair<int64_t, float>& minData) {
    if (m_queue.empty()) {
        return false;
    } else {
        minData = m_queue.top();
        m_queue.pop();
        return true;
    }
}