
//stackqueue/stack_queue_utils.hpp
#pragma once
#include "array/vector.hpp"
#include "list/doubly_linked.hpp"
#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"
#include <string>
#include <stdexcept>
std::string remove_duplicates(std::string input)
{
    dsac::stackqueue::stack<char> container;
    std::string edited = "";
    char prev = input[0];

    for(int i = 0; i < int(input.length()); i++){
        container.push(input[i]);

        if(input[i] == prev && i != 0 && container.size() >= 2){
            container.pop();
            container.pop();
            if(container.size() >= 1)
                prev = input[container.size()-1];
        }
        else{prev = container.top();}
    }

    while(!container.empty()){
        edited = container.top() + edited;
        container.pop();
    }

    return edited;  
}

std::string clean_backspace_string(std::string input){
    dsac::stackqueue::stack<char> container;
    std::string edited = "";

        for(int i = 0; i < int(input.length()); i++){
        container.push(input[i]);

        if(input[i] == '<'){
            container.pop();
            if(!container.empty()){container.pop();}
        }
        }

        while(!container.empty()){
            edited = container.top() + edited;
            container.pop();
        }

        return edited;
}
template <
typename T,
typename StackContainer=dsac::array::Vector<T>,
typename QueueContainer=dsac::array::Vector<T>
>
bool stack_contains(
dsac::stackqueue::stack<T, StackContainer>& st,
dsac::stackqueue::queue<T, QueueContainer>& qu,
const T& elt){

    bool found = false;
    int length = st.size();

    if(!qu.empty())
        throw std::invalid_argument("Q must be initially empty.");

    for(int i = 0; i < length; i++){
        if(st.top() == elt){
            found = true;
        }
        qu.push(st.top());
        st.pop();
    }

    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    return found;
}
