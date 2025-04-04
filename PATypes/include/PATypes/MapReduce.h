#pragma once

#include "Sequence.h"

namespace PATypes {

    template<class T>
    Sequence<T>* map(T (*f)(T), Sequence<T>* list) {
        return list->map(f);
    }

    template<class T>
    T reduce(T (*f)(T, T), Sequence<T>* list, T c) {
        if (list->getLength() == 1) {
            return (*f)(list->getFirst(), c);
        } else {
            auto subSequence = list->getSubsequence(0, list->getLength() - 2);
            T result = (*f)(list->getLast(), reduce(f, subSequence, c));
            delete subSequence;
            return result;
        }
    }
};// namespace PATypes