//
// Created by shawnunili on 2020-04-01.
//

#ifndef CPP_TOOLS_MULTIWAYSMERGETOPK_H
#define CPP_TOOLS_MULTIWAYSMERGETOPK_H

#include <vector>
#include <memory>

#include "max_heap.h"

class MultiWaysMergeTopK {
public:
    void test();

private:
    void mergeTopK(size_t k,
            const std::vector<std::shared_ptr<std::vector<MergeSortData>>>& multiWays,
            std::shared_ptr<std::vector<MergeSortData>> result);

    bool isEnded(std::vector<size_t> a, std::vector<size_t> b);

};


#endif //CPP_TOOLS_MULTIWAYSMERGETOPK_H
