#include "sort.hpp"

int deque_strugler = -1;

// step 1 : group the element into n/2 pairs of elements

std::deque<std::pair<int, int> > group_pairs(std::deque<int> seq) {
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < seq.size(); i += 2) {
        if (i + 1 < seq.size()) {
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        } else if (seq.size() == i + 1) {
            deque_strugler = seq[i];
        }
    }
    return pairs;
}

// step 2 : determinat the larger of the two elements

std::deque<std::pair<int, int> > larger_of_pairs(std::deque<std::pair<int, int> > pairs){
    for (size_t i = 0; i < pairs.size(); i++){
        if (pairs[i].first < pairs[i].second){
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    return (pairs);
}

// step 3 : larger elemnt from rach pair

std::deque<std::pair<int, int> > compare_and_swap_pairs(std::deque<std::pair<int, int> > pairs){
    for (size_t i = 0; i < pairs.size() - 1; i++){
        for (size_t j = i + 1; j < pairs.size(); j++){
            if (pairs[i].first > pairs[j].first){
                swap_pair(pairs[i], pairs[j]);
            }
        }
    }
    return pairs;
}

// step 4 : Create the Main chain and  pending chain

std::deque<int> create_main_chain(std::deque<std::pair<int, int> > pairs){
    std::deque<int> main_chain;
    for (size_t i = 0; i < pairs.size(); i++){
        main_chain.push_back(pairs[i].first);
    }
    return main_chain;
}

std::deque<int> create_pending_chain(std::deque<std::pair<int, int> > pairs){
    std::deque<int> pending_chain;
    for (size_t i = 0; i < pairs.size(); i++){
        pending_chain.push_back(pairs[i].second);
    }
    return pending_chain;
}

// step 5 : generate the order of insertion using jacobsthal sequence

int computeJacobstal(size_t n, std::deque<int> &jacobstalNumbers) {
    if (n < jacobstalNumbers.size()) {
        return jacobstalNumbers[n];
    }
    int result = computeJacobstal(n - 1, jacobstalNumbers) + 2 * computeJacobstal(n - 2, jacobstalNumbers);
    jacobstalNumbers.push_back(result);
    return result;
}

// {0, 1, 1} are the first 3 numbers of the jacobstal serie
std::deque<int> JacobstalInsertionOrderDeque(size_t size) {
    std::deque<int> series;
    std::deque<int> jacobstalNumbers;
    jacobstalNumbers.push_back(0);
    jacobstalNumbers.push_back(1);
    jacobstalNumbers.push_back(1);

    int i = 3;
    int lastInserted = 1;

    while (series.size() < size - 1) {
        int jacobstalNumber = computeJacobstal(i, jacobstalNumbers);
        for (int j = jacobstalNumber; j > lastInserted; j--) {
            if (j > (int) size)
                continue;
            if (series.size() < size - 1)
                series.push_back(j);
            else
                break;
        }
        i++;
        lastInserted = jacobstalNumber;
    }
    return series;
}

// step 6 : whith a specially chosen insertion ordering, insert the elements of the pending chain into the main chain using binary search by inserting the small element from the pend chain into the main chain

std::deque<int> insert_pending_chain(std::deque<int> main_chain, std::deque<int> pending_chain){
    std::deque<int> jacobsthal_seq = JacobstalInsertionOrderDeque(pending_chain.size() + 1);
    
    for (std::deque<int>::iterator it = jacobsthal_seq.begin(); it != jacobsthal_seq.end(); it++) {
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[*it - 2]);
        main_chain.insert(pos, pending_chain[*it - 2]);
    }
    if (deque_strugler != -1) {
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), deque_strugler);
        main_chain.insert(pos, deque_strugler);
    }
    return main_chain;
}

std::deque<int> sort_deque(std::deque<int> seq) {
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> main_chain;
    std::deque<int> pending_chain;
    std::deque<int> jacobsthal_seq;

    pairs = group_pairs(seq);
    pairs = larger_of_pairs(pairs);
    pairs = compare_and_swap_pairs(pairs);
    main_chain = create_main_chain(pairs);
    pending_chain = create_pending_chain(pairs);
    main_chain = insert_pending_chain(main_chain, pending_chain);
    return main_chain;
}
