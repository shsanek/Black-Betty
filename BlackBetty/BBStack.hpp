//
//  BBStack.hpp
//  BlackBetty
//
//  Created by Alexander Shipin on 23/08/16.
//  Copyright © 2016 Alexander Shipin. All rights reserved.
//

#ifndef BBStack_hpp
#define BBStack_hpp

#include <stdlib.h>
#include <stdio.h>

namespace BB {
    class Stack{
        struct StackElement{
            bool waitingForRemoval;
            __uint8_t* data;
            size_t size;
            
            StackElement(__uint8_t* data,size_t size){
                this->data = new __uint8_t[size];
                this->size = size;
                memcpy(this->data,data,size);
                waitingForRemoval = false;
            }
            
            ~StackElement(){
                delete []data;
            }
        };
        struct StackListElement{
            StackElement* stackElement;
            StackListElement* next;
            StackListElement* back;
            
            StackListElement(__uint8_t* data,size_t size,StackListElement* back){
                this->stackElement = new StackElement(data,size);
                this->next = back?back->next:NULL;
                this->back = back;
                back->next = this;
            }
            
            ~StackListElement(){
                if (this->back) {
                    this->back->next = this->next;
                }
                if (this->next) {
                    this->next->back = this->back;
                }
                delete stackElement;
            }
        };
        
        StackListElement* stackHead;
        
    public:
        inline void pushStackWithSize(__uint8_t* data,size_t size){
            stackHead = new StackListElement(data,size,stackHead);
            while (stackHead && stackHead->next) {
                delete stackHead->next;
            }
        }
        
        inline __uint8_t* popStack(size_t* size){
            *size = stackHead->stackElement->size;
            __uint8_t* data = stackHead->stackElement->data;
            stackHead->stackElement->waitingForRemoval = true;
            stackHead = stackHead->back;
            return data;
        }
        
        inline __uint8_t* popStack(){
            __uint8_t* data = stackHead->stackElement->data;
            stackHead->stackElement->waitingForRemoval = true;
            stackHead = stackHead->back;
            return data;
        }
        
        inline void removeStackElements(){
            while (stackHead && stackHead->next) {
                delete stackHead->next;
            }
        }
    };
};


#endif /* BBStack_hpp */
