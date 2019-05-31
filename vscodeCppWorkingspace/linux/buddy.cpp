#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <random>
#include <algorithm>

typedef unsigned long block_size;

const unsigned int MEMORY_SPACE_SIZE = 10;  //可利用空间大小的2的幂次

struct block_node{
    bool is_alloc;                  //块标志,fasle:未分配,true:已分配
    block_size size;                //块大小
    unsigned int start_addr;
    block_node(bool _is_alloc,block_size _size,unsigned int _start_addr){
        this->is_alloc = _is_alloc;
        this->size = _size;
        this->start_addr = _start_addr;
    }
    bool operator==(block_node & obj){
        return (this->is_alloc == obj.is_alloc &&
                this->size == obj.size &&
                this->start_addr == obj.start_addr);
    }
};


struct block{
    block_size size;                //块大小
    std::list<block_node> list;
};



const std::size_t length = MEMORY_SPACE_SIZE;

//将空间大小转化为相应的空闲链表序号
unsigned int get_number(unsigned int space_size){
    return ((space_size & space_size - 1) == space_size) ? log2(space_size) : (log2(space_size) + 1);
}


void init_space(std::vector<block> & free_space,std::vector<block> & alloc_space){
    for (int i = 0; i < free_space.size(); i++){
        free_space[i].size = i;
        if (i== free_space.size() -1){
            free_space[i].list.push_back(block_node(false, i,0));
        }
    }

    for (int i = 0; i < alloc_space.size(); i++){
        alloc_space[i].size = i;
    }
}

void buddy_alloc(std::vector<block> & free_space,std::vector<block> & alloc_space,block_size n){
    auto k = 0;
    for (; (k <= length) && (free_space[k].size < n || free_space[k].list.empty()); ++k);

    block_node node = *free_space[k].list.begin();
    free_space[k].list.pop_front();

    int i = 1;
    for (; free_space[k - i].size >= n; ++i){
        block_node tmp(false,k-i,node.start_addr + exp2(k - i));
        free_space[k - i].list.push_front(tmp);
    }
    node.is_alloc = true;
    block_size size = k - --i;
    node.size = size;
    alloc_space[size].list.push_front(node);
}

bool is_exist(std::vector<block> & free_space,block_node node){
    auto iter = free_space[node.size].list.begin();
    for (; iter != free_space[node.size].list.end(); iter++){
        if (*iter == node){
            return true;
        }
    }
    return false;
}

void buddy_free(std::vector<block> & free_space,std::vector<block> & alloc_space,block_node free){
    auto iter = alloc_space[free.size].list.begin();
    for (; iter != alloc_space[free.size].list.cend(); iter++){
        if (*iter == free){
            alloc_space[free.size].list.erase(iter);
            break;
        }
    }
    
    

    block_node node(false,free.size,free.start_addr);

    block_size k = free.size;
    bool can_merge = true;
    
    while (k != length && can_merge) {
        block_size buddy_addr = 0;
        block_size num1 = (block_size)std::exp2(node.size + 1);
        block_size num2 = (block_size)std::exp2(node.size);


        if (free.start_addr % num1 == 0) {
            buddy_addr = node.start_addr + num2;
        } else if (node.start_addr % num1 == num2) {
            buddy_addr = node.start_addr - num2;
        }
        std::cout << buddy_addr << std::endl;

        block_node butty(node.is_alloc, node.size, buddy_addr);
      
        if (is_exist(free_space,butty) == false){
            can_merge = false;
        } else {
            //从空闲表擦除伙伴
            iter = free_space[butty.size].list.begin();
            for (; iter != free_space[butty.size].list.end(); iter++){
                if (*iter == butty){
                    free_space[node.size].list.erase(iter);
                    break;
                }
            }
            

            node.is_alloc = false;
            node.size = node.size + 1;
            node.start_addr = std::min(node.start_addr, butty.start_addr);
        }
        
    }
    free_space[node.size].list.push_front(node);
}


int main(){
    std::vector<block> free_space(length+1);
    std::vector<block> alloc_space(length+1);
    std::default_random_engine e;
    init_space(free_space, alloc_space);
    buddy_alloc(free_space,alloc_space,6);

    buddy_free(free_space, alloc_space, block_node(true,6,0));
   
   

    std::cout << "free space:" << std::endl;
    for (int i = 0; i < free_space.size(); i++){
        std::cout << (unsigned long)std::exp2(free_space[i].size) << "\t";
        for (auto iter = free_space[i].list.begin(); iter != free_space[i].list.end();iter++){
            std::cout << iter->is_alloc << "\t" << iter->size << "\t" << iter->start_addr << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "alloc space:" << std::endl;
    for (int i = 0; i < alloc_space.size(); i++){
        std::cout << (unsigned long)std::exp2(alloc_space[i].size) << "\t";
        for (auto iter = alloc_space[i].list.begin(); iter != alloc_space[i].list.end();iter++){
            std::cout << iter->is_alloc << "\t" << iter->size << "\t" << iter->start_addr << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}