#pragma once

#include "Sequence.h"

namespace PATypes {

    template<class T>
    Sequence<T>* map(T (*f)(T), Sequence<T>* list) {
        list->map(f);
        return list;
    }

    template<class T>
    Sequence<T>* reduce(T (*f)(T), Sequence<T> list, T c) {
        if (list.getLength() == 1) {
            return f(list.getLast(), c);
        } else {
            return f(list.getLast(), reduce(f, list.getSubsequence(0, list.getLength() - 2), c));
        }
    }
}