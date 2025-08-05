#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    if(head==nullptr){
        head = new Element(entry);
        
    }else{
        Element *newelment = new Element(entry);
        newelment->next=head;
        head=newelment;
    }
    current_size++;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(head!=nullptr){
        Element *t=head;
    int res = head->data;

        head =head->next;
        delete t;
    current_size--;


        return res;
    }
    return 0;
}

void List::reverse() {
    if(head!=nullptr){
        //recres(head);
        if(head->next==nullptr){
            return;
        }else if(head->next->next==nullptr){
           Element *tmp=head;
            head=head->next;
            head->next=tmp;
            tmp->next=nullptr;
            
        }else{
            Element *T1=head->next;
            Element *T2=head->next->next;
            T1->next=head;
            head->next=nullptr;
            head=T1;
            T1=T2;
            T2=T2->next;
            while(T2){
         
            T1->next=head;
            head=T1;
            T1=T2;
                if(T2->next){
                    T2=T2->next;
                }else{
                    T2->next=head;
                    head=T1;
                    T2=nullptr;
                }
                }
        }

       
           
    }
}

List::~List() {
    if(head!=nullptr){
        
    while(head){
            Element *t=head;
            head=head->next;
            delete t;
        }
    }
}

    void List::recres(Element* current,Element* prev){
        if(current->next){
                recres(current->next,current);
        }else{
            head=current;
        }
            
        current->next=prev;
        
    }

}  // namespace simple_linked_list
