#include <iostream>
template <typename type>
class list_item{
public:
    list_item(const type & value,list_item * next)
    :item_value(value),item_next(next)
    {
    }
    type value()const noexcept{
        return this->item_value;
    }
    list_item * next()const noexcept{
        return this->item_next;
    }

    type item_value;
    list_item  * item_next;
};

template <typename type>
class simple_list{
public:

    simple_list(){
        this->list_front = new list_item<type>(0, nullptr);
        this->list_end = this->list_front;
    }
    list_item<type> * front(){
        return this->list_front;
    }
    list_item<type> * end(){
        return this->list_end;
    }
    void insert_front(const type & value){
        list_item<type> *new_item = new list_item<type>(value,this->list_front->next);
        this->list_front->next = new_item;
        this->list_end = new_item;
    }
    void insert_back(const type & value){
        list_item<type> *new_item = new list_item<type>(value,nullptr);
        this->list_end->item_next = new_item;
        this->list_end = new_item;
    }
    void display(std::ostream & out = std::cout) {
        list_item<type> *tmp_ptr = this->list_front->item_next;
        while(tmp_ptr != nullptr){
            std::cout << tmp_ptr->value() << " ";
            tmp_ptr = tmp_ptr->item_next;
        }
        std::cout << std::endl;
    }
    ~simple_list(){
        list_item<type> *tmp = this->list_front;
        while(tmp != nullptr){
            list_item<type> *ptr = tmp->item_next;
            delete tmp;
            tmp = ptr;
        }
    }

private:
    list_item<type> *list_end;
    list_item<type> *list_front;
    std::size_t size;
};

template<typename type>
class list_iter{
public:
    list_iter(type * p = nullptr)
    :ptr(p)
    {
    }

    type & operator*()const noexcept{
        return *(this->ptr);
    }
    type * operator->()const noexcept{
        return this->ptr;
    }
    list_iter & operator++(){
        this->ptr = this->ptr->next();
        return *this;
    }

    list_iter & operator++(int){
        list_iter<type> tmp = *this;
        this->ptr = this->ptr->next();
        return tmp;
    }
    bool operator == (const list_iter & iter){
        return this->ptr == iter.ptr;
    }
    bool operator != (const list_iter & iter){
        return this->ptr != iter.ptr;
    }
private:
    type *ptr;
};

template<typename type>
bool operator != (const list_item<type> & item,const type & value){
    return item.value() != value;
}

template<typename input_iterator,typename type>
input_iterator find(input_iterator first,input_iterator last,const type & value){
    while (first != last && *first != value){
        ++first;
    }
    return first;
}

int main(){
    simple_list<int> list;
    for (int i = 0; i < 5;i++){
        list.insert_back(i);
        list.insert_back(i + 2);
    }
    list_iter<list_item<int>> begin(list.front());
    list_iter<list_item<int>> end;
    list_iter<list_item<int>> iter;
    list.display();

    iter = find(begin, end, 3);
    std::cout << iter->value() << std::endl;
    return 0;
}
