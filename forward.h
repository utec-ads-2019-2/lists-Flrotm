#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include <iostream>

using namespace std;
template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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

            Node<T>* node = new Node<T>;
            node->data = value;
            if (this->nodes == 0){
                this->head = node;
                this->tail = this->head;
                this->nodes++;
            } else {
                this->tail->next = node;
                this->tail = node;
                this->nodes++;
            }
        }

        void pop_front() {
            if(this->nodes!=0){
            this->head=this->head->next;
            delete this->head->prev;
            this->nodes--;}
        }

        void pop_back() {
            auto temp = this->tail;
            auto node = this->head;
            while(node->next!=this->tail){
                node = node->next;
            }
            delete temp;
            this->tail = node;
            this->nodes--;
        }

        T operator[](int index) {

            if(index>=this->nodes){
                throw length_error("error");
            }else {
                auto *temp = this->head;
                for (int i=0; i < index; i++) {
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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
        return ForwardIterator<T>(this->head);
         }

        ForwardIterator<T> end() {
        return ForwardIterator<T>(this->tail->next);
         }

        void merge(ForwardList<T> list) {
            for(int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }
        }
};

#endif
