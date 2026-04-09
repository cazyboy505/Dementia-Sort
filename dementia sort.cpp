#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <chrono>

std::vector<int> dementia_sort(std::vector<int>& sorted) {
    int highest = std::numeric_limits<int>::min();
    int num = 0;
    
    // set up for random number
    std::random_device dev;
    std::mt19937 engine(dev());

    auto start_time = std::chrono::steady_clock::now();
    
    
    while (num < static_cast<int>(sorted.size())) {
        if (sorted.empty()) return sorted;

        auto current_time = std::chrono::steady_clock::now();
        auto elasped_time = std::chrono::duration<double>(current_time - start_time).count();

        std::uniform_int_distribution<int> chance_num(0, 100);
        int chance = chance_num(engine);
        
        if (chance*elasped_time <= 40 && sorted.size() > 2){
            std::uniform_int_distribution<int> delete_index_num(0, sorted.size()-2);
            int delete_index = delete_index_num(engine);
            sorted.erase(sorted.begin() + delete_index);
            
            num = 0;
            highest = std::numeric_limits<int>::min();
        }
        
        if (sorted[num] < highest){
            sorted.erase(sorted.begin(), sorted.begin()+num);
            num = 0;
            if (sorted.empty()) return sorted;
            highest = sorted[0];
        }

        else {
            highest = sorted[num];
            num++;
        }
        
    }
    return sorted;
}

int main() {
    std::vector<int> list = {3, 8, 3, 1, 5, 4, 8, 10, 34, 2, 8, 23, 5, 2}; // change this line only please!!!!!!!!!!!1
    
    std::vector<int> sorted_list = dementia_sort(list);

    for (int i : sorted_list){
        std::cout << i << " ";
    }
    
    
}