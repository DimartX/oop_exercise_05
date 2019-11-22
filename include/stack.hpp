#pragma once

#include <memory>
#include <iterator>

namespace bad {
    
    template<class T>
    class stack{
    private:
        struct node;
        
    public:
        stack() :
            head(nullptr),
            size_(0)
        {};

        struct forward_iterator {

            using value_type = T;
            using reference = T &;
            using pointer = T *;
            using difference_type = ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;

            forward_iterator(node* ptr) : ptr(ptr) {}; 

            T& operator* (); 
            forward_iterator& operator++ (); 
            forward_iterator operator++ (int);

            forward_iterator operator+ (int id) {
                if (id < 0) {
                    throw 9;
                }
                for (int i = 0; i < id; i++) {
                    if (*this == nullptr) {
                        throw 9;
                    }
                    (*this)++;
                }
                return *this;
            }
            
            
            bool operator== (const forward_iterator& o) const;
            bool operator!= (const forward_iterator& o) const;
            
        private:

            node *ptr;
            friend class stack;
        };
        
        forward_iterator begin(); 
        forward_iterator end();
        size_t size();
        
        void insert(const forward_iterator& it, const T& value); ///
        void erase(const forward_iterator& it); ///
        
        void push(const T& value); 
        void pop(); 
        T& top() const;
    
    private:
        
        struct node{
            T value;
            std::unique_ptr<node> nextNode;

            forward_iterator next();
            friend class stack;
        };
        

        std::unique_ptr<node> head;
        size_t size_;
    };


    template<class T>
    T& stack<T>::forward_iterator::operator* () {
        return ptr->value;
    }

    template<class T>
    typename stack<T>::forward_iterator& stack<T>::forward_iterator::operator++ () {
        *this = ptr->next();
        return *this;
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::forward_iterator::operator++ (int) {
        forward_iterator prev = *this;
        ++(*this);
        return prev;
    }
    


    template<class T>
    bool stack<T>::forward_iterator::operator!= (const forward_iterator &o) const {
        return ptr != o.ptr;
    }

    template<class T>
    bool stack<T>::forward_iterator::operator== (const forward_iterator &o) const {
        return ptr == o.ptr;
    }
    
    template<class T>
    typename stack<T>::forward_iterator stack<T>::begin() {
        return head.get();
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::end() {
        return nullptr;
    }

    template<class T>
    size_t stack<T>::size() {
        return size_;
    }
    
    template<class T>
    typename stack<T>::forward_iterator stack<T>::node::next() {
        return {nextNode.get()};
    }

    template<class T>
    void stack<T>::insert(const forward_iterator& it, const T& value) {
        if (it == this->begin()) {
            this->push(value);
            return;
        }
        
        forward_iterator tmp = this->begin();
        while (tmp.ptr->next() != it) {
            tmp++;
        }
        
        std::unique_ptr<node> newNode(new node{value, nullptr});
        newNode->nextNode = std::move(tmp.ptr->nextNode);
        tmp.ptr->nextNode = std::move(newNode);
        
        ++size_;
    }

    template<class T> 
    void stack<T>::erase(const forward_iterator& it) {
        if (it == nullptr) {
            throw 11;
        }
        if (it == this->begin()) {
            head = std::move(head->nextNode);
            return;
        }

        forward_iterator tmp = this->begin();
        while (tmp.ptr->next() != it) {
            tmp++;
        }

        tmp.ptr->nextNode = std::move(it.ptr->nextNode);
    }

    template<class T>
    void stack<T>::push(const T& value) {
        std::unique_ptr<node> newNode(new node{value, nullptr});
        if (size_ == 0) {
            head = std::move(newNode);
        }
        else {
            newNode->nextNode = std::move(head);
            head = std::move(newNode);
        }
        ++size_;
    }

    template<class T>
    void stack<T>::pop() {
        if (size_ == 0) {
            throw 4;
        }
        head = std::move(head->nextNode);
        --size_;
    }

    template<class T>
    T& stack<T>::top() const{
        if (size_ == 0) {
            throw 5;
        }
        return head->value;
    }
}



