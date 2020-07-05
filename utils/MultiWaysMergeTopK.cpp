//
// Created by shawnunili on 2020-04-01.
//

#include <iostream>
#include <unordered_set>
#include "MultiWaysMergeTopK.h"

void MultiWaysMergeTopK::test() {
    std::vector<std::shared_ptr<std::vector<MergeSortData>>> multiWays;
    std::shared_ptr<std::vector<MergeSortData>> oneWay = std::make_shared<std::vector<MergeSortData>>();
    std::shared_ptr<std::vector<MergeSortData>> twoWay = std::make_shared<std::vector<MergeSortData>>();
    std::shared_ptr<std::vector<MergeSortData>> threeWay = std::make_shared<std::vector<MergeSortData>>();

    for(size_t i = 100; i > 96; --i) {
        if(i%2 == 0) {
            std::cout << "i:" << i << std::endl;
            MergeSortData mergeSortData;
            mergeSortData.cid = i;
            mergeSortData.score = static_cast<float>(i);
            oneWay->push_back(mergeSortData);
        }
    }
    for(size_t i = 100; i > 98; --i) {
        if(i%2 == 1) {
            std::cout << "i:" << i << std::endl;
            MergeSortData mergeSortData;
            mergeSortData.cid = i;
            mergeSortData.score = static_cast<float>(i);
            twoWay->push_back(mergeSortData);
        }
    }
    for(size_t i = 1000; i > 996; --i) {
        if(i%2 == 0) {
            std::cout << "i:" << i << std::endl;
            MergeSortData mergeSortData;
            mergeSortData.cid = i;
            mergeSortData.score = static_cast<float>(i);
            threeWay->push_back(mergeSortData);
        }
    }
    std::cout << "------------" << std::endl;
    multiWays.push_back(oneWay);
    multiWays.push_back(oneWay);
    // multiWays.push_back(threeWay);
    std::shared_ptr<std::vector<MergeSortData>> result = std::make_shared<std::vector<MergeSortData>>();
    try {
        mergeTopK(4, multiWays, result);
    } catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }
    for(const auto& news : *result) {
        std::cout << news.score << std::endl;
    }
}

bool MultiWaysMergeTopK::isEnded(std::vector <size_t> a, std::vector <size_t> b) {
    bool result = true;
    for (size_t i = 0; i< a.size(); ++i) {
        result = result && (a[i] >= b[i]);
    }
    return result;
}

void MultiWaysMergeTopK::mergeTopK(size_t k, const std::vector<std::shared_ptr<std::vector<MergeSortData>>>& multiWays,
        std::shared_ptr<std::vector<MergeSortData>> result) {
    size_t waySize = multiWays.size();
    if(waySize == 1) {
        result = multiWays[0];
        return;
    }
    std::vector<size_t> index(waySize, 0);  // 当前每路的current
    std::vector<size_t> maxIndex(waySize, 0); //每路的end
    size_t topIndex = 0;  // 哪一路是目前的最大值
    MaxHeap maxHeap(waySize);
    std::cout << "multiWays size:" << multiWays.size() << std::endl;
    for(size_t i = 0; i < waySize; ++i) {
        maxIndex[i] = multiWays[i]->size();
        MergeSortData mergeSortData = *(multiWays[i]->begin());
        mergeSortData.index = i;
        maxHeap.insert(mergeSortData);
    }
    std::unordered_set<int64_t> docSet;
    while (result->size() < k && !isEnded(index, maxIndex)) {
        MergeSortData mergeSortData;
        bool heapHasData = maxHeap.pop(mergeSortData);
        if (heapHasData) {
            topIndex = mergeSortData.index;
            std::cout << "topIndex:" << topIndex << std::endl;
            if(docSet.count(mergeSortData.cid) == 0) {
                result->emplace_back(mergeSortData);
                docSet.insert(mergeSortData.cid);
            }
            //result->push_back(mergeSortData);
            ++index[topIndex];
            if (index[topIndex] < maxIndex[topIndex]) {//这一路目前还有数据
                (*multiWays[topIndex])[index[topIndex]].index= topIndex;
                maxHeap.insert((*multiWays[topIndex])[index[topIndex]]);
            } else {
                // 该路已经完了，那么top的数据在最大堆和剩下的各路里面,此时堆的大小要小于k了
                continue;
            }
        } else {
            // 此处没有意义。只有一种情况最大堆会空，即各路都读完了
            break;
        }
    }
    while (result->size() < k && !maxHeap.empty()) {
        std::cout << "guard" << std::endl;
        MergeSortData mergeSortData;
        maxHeap.pop(mergeSortData);
        result->emplace_back(mergeSortData);
    }
}