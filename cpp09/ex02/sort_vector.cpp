#include "sort.hpp"

int vector_strugler = -1;

// step 1 : group the element into n/2 pairs of elements

std::vector<std::pair<int, int> > group_pairs(std::vector<int> seq) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < seq.size(); i += 2) {
        if (i + 1 < seq.size()) {
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        } else if (seq.size() == i + 1)
            vector_strugler = seq[i];
    }
    return pairs;
}

// step 2 : determinat the larger of the two elements

std::vector<std::pair<int, int> > larger_of_pairs(std::vector<std::pair<int, int> > pairs){
    for (size_t i = 0; i < pairs.size(); i++){
        if (pairs[i].first < pairs[i].second){
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    return (pairs);
}

// step 3 : larger elemnt from each pair

std::vector<std::pair<int, int> > compare_and_swap_pairs(std::vector<std::pair<int, int> > pairs){
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

std::vector<int> create_main_chain(std::vector<std::pair<int, int> > pairs){
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); i++){
        main_chain.push_back(pairs[i].first);
    }   
    return main_chain;
}

std::vector<int> create_pending_chain(std::vector<std::pair<int, int> > pairs){
    std::vector<int> pending_chain;
    for (size_t i = 0; i < pairs.size(); i++){
        pending_chain.push_back(pairs[i].second);
    }
    return pending_chain;
}

// step 5 : generate the order of insertion using jacobsthal sequence

int computeJacobstal(size_t n, std::vector<int> &jacobstalNumbers) {
    if (n < jacobstalNumbers.size()) {
        return jacobstalNumbers[n];
    }
    int result = computeJacobstal(n - 1, jacobstalNumbers) + 2 * computeJacobstal(n - 2, jacobstalNumbers);
    jacobstalNumbers.push_back(result);
    return result;
}

std::vector<int> JacobstalInsertionOrderVector(size_t size) {
    std::vector<int> series;
    std::vector<int> jacobstalNumbers;
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

// step 6 : Now we want to insert the pending chain in the main chain with jacobsthal sequence indexing

std::vector<int> insert_pending_chain(std::vector<int>& main_chain, std::vector<int>& pending_chain) {
    std::vector<int> jacobsthal_seq = JacobstalInsertionOrderVector(pending_chain.size() + 1);
    
    for (std::vector<int>::iterator it = jacobsthal_seq.begin(); it != jacobsthal_seq.end(); it++) {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[*it - 2]);
        main_chain.insert(pos, pending_chain[*it - 2]);
    }
    if (vector_strugler != -1) {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), vector_strugler);
        main_chain.insert(pos, vector_strugler);
    }
    return main_chain;
}

std::vector<int> sort_vector(std::vector<int> seq) {
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> main_chain;
    std::vector<int> pending_chain;
    std::vector<int> jacobsthal_seq;

    pairs = group_pairs(seq);
    pairs = larger_of_pairs(pairs);
    pairs = compare_and_swap_pairs(pairs);
    main_chain = create_main_chain(pairs);
    pending_chain = create_pending_chain(pairs);
    main_chain = insert_pending_chain(main_chain, pending_chain);
    return main_chain;
}
