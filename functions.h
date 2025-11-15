#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "LinkedList.h"
#include <iostream>

struct stats { 
    size_t comparison_count = 0; 
    size_t copy_count = 0; 
};

std::ostream& operator<<(std::ostream& os, stats stat) {
    os << "(Сравнения: " << stat.comparison_count << ", Копирования: " << stat.copy_count << ")";
    return os;
}

template<typename T>
stats insertion_sort(LinkedList<T>& list) {
    stats stats;

    auto main = list.head_->next;
    auto key = list.head_;
    stats.copy_count += 2;
    while (main) {
        key = main; stats.copy_count++;
        main = main->next; stats.copy_count++;
        auto it = list.head_; stats.copy_count++;

        while(key->value > it->value && it != key) { it = it->next; stats.comparison_count++;  stats.copy_count++;}
        stats.comparison_count++;

        if (it != key) { // Перевязывание элементов списка
            auto it_prev = it->prev;
            if (it->prev) { it->prev->next = key; stats.copy_count++;}
            if (it == list.head_) { list.head_ = key; stats.copy_count++;}
            it->prev = key; // [it_prev]->|key|<-[it]

            key->prev->next = key->next;
            if (key->next) { key->next->prev = key->prev; stats.copy_count++;} // [key->prev]<->[key->next]
            if (key == list.tail_) { list.tail_ = key->prev; stats.copy_count++;}
            
            key->next = it; 
            key->prev = it_prev; // [it_prev]<->[key]<->[it]

            stats.copy_count += 5;
        }
    }

    return stats; 
}

template<typename T>
stats shaker_sort(std::vector<T>& vec) { 
    return stats(); 
}

template<typename T>
stats quick_sort(std::vector<T>& vec) { 
    return stats(); 
}

#endif /* FUNCTIONS_H */