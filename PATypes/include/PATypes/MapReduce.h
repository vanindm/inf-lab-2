#pragma once

#include "Sequence.h"

namespace PATypes {

    template<class T>
    Sequence<T>* map(T (*f)(T), Sequence<T>* list) {
        list->map(f);
        return list;
    }
}