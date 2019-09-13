#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include<iostream>
#include <algorithm>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

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
            auto temp= new Node<T>;
            temp->data=value;
            temp->next=this->head;
            this->head=temp;
        }

        void push_back(T value) {
            auto temp= new Node<T>;
            temp->data=value;
            temp->next=this->tail;
            this->tail=temp;
        }

        void pop_front() {
           if(this->nodes!=0){
            this->head=this->head->next;
            this->head->prev=this->tail;
            this->nodes--;}
        }

        void pop_back() {
            if(this->nodes!=0){

                auto temp = new Node<T>;
                for(int i=0;i<this->nodes-1;i++){
                    temp=temp->next;
                }
                delete this->tail;
                this->tail=temp;}
        }

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
            return "Linked List";
        }
         BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
    }

         BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->tail);
    }


        void merge(LinkedList<T> list) {
            for(int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }
        }
};

#endif
