#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include <iostream>
#include "iterators/bidirectional_iterator.h"
#include <algorithm>
using namespace std;

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

    T front() {
        if(this->head!= nullptr)
            return this->head->data;
        else throw invalid_argument("error");
    }

    T back() {
        if(this->head!= nullptr)
            return this->tail->data;
        else throw invalid_argument("error");
    }

        void push_front(T value) {
            // Falta manejo de punteros
            auto current=this->head;
            auto temp=new Node<T>;

            temp->data=value;
            // Cuando la lista esté vacía dará error
            while (current->next!=this->head)
                current=current->next;
            temp->next=temp;
            if(this->head==nullptr){
                this->head=temp;
            }else {
                temp->next=this->head;
                current->next=temp;
                this->head=temp;
            }
        }

        void push_back(T value) {
            // Falta manejo de punteros
            auto current=this->head;
            auto temp=new Node<T>;
            temp->data=value;
            while (current->next!=this->head)
                current=current->next;
            temp->next=temp;
            if(this->head==nullptr){
                this->head=temp;
            }else {
                temp->next=this->head;
                current->next=temp;
            }
        }

        void pop_front() {
            // Deberías mejor fijarte en los punteros
            if(this->nodes!=0){
            auto current=this->head;
            // Aquí no deberías crear un nodo, eso reserva memoria
            auto temp=new Node<T>;
            while (current->next!=this->head){
                temp=current;
                current=current->next;}
                temp->next=current->next;
            delete current;
        }}

        void pop_back() {
            if(this->nodes!=0){
                auto current=this->head;
                // Aquí no deberías crear un nodo, eso reserva memoria
                auto temp=new Node<T>;
                while (current->next!=this->head)
                    current=current->next;
                current->next=this->head->next;
                this->head=this->head->next;
                delete temp; }}

        T operator[](int index) {
            auto temp=new Node<T>;
            if(index>this->nodes)
                throw length_error("Error");
            else{
                for(int i=0;i<index;i++){
                    temp=temp->next;
                }
                return temp->data;
            }
        }

    bool empty() {
        return this->nodes==0;
    }

    int size() {
        return this->nodes;
    }

    void clear() {
        this->head->killSelf();
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes = 0;
    }

        void sort() {
            T arr[this->nodes];
            auto tempo=this->head;
            for(int i=0; i<this->nodes; ++i){
                arr[i]=tempo->data;
                tempo=tempo->next;
            }
            for (int i = this->nodes/2; i >0 ; i /=2) {
                for (int j = i; j <this->nodes; j++) {
                    int temp=arr[j];
                    int k;
                    for ( k = j; k >=i and arr[k-i]>temp; k -=i) {
                        arr[k] = arr[k-i];
                    }
                    arr[k]=temp;
                }
            }
            tempo=this->head;
            for(int i=0; i<this->nodes; ++i){
                tempo->data=arr[i];
                tempo=tempo->next;
            }
        }
    
        void reverse() {
            T arr[this->nodes];
            auto temp=this->head;
            for(int i=0; i<this->nodes; ++i){
                arr[i]=temp->data;
                temp=temp->next;

            }
            for(int i=0; i<this->nodes; ++i){
                this->push_back(arr[i]);

            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail);
        }

        void merge(CircularLinkedList<T> list) {
            for(int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }

        }
};

#endif
