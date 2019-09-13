#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"
#include <iostream>
using namespace std;
template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            return this->current != other.current;
        }

        BidirectionalIterator<T> operator++() {
            if (this->current->next==nullptr) {
                throw length_error("error");
            }
            this->current = this->current->next;
            return *this;
        }

        BidirectionalIterator<T> operator--() {
            if (this->current->prev==nullptr) {
                throw length_error("error");
            }
            this->current = this->current->prev;
            return *this;
        }

        T operator*() {
            if (this->current==nullptr)
                throw length_error("error");
            return this->current->data;
        }
};

#endif
