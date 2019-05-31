#include <iostream>
#include <list>
#include <algorithm>
#include <string>
typedef unsigned long size_type;

const int INIT_SIZE = 4096;
const int MEMORY_SIZE = 64*4096;

enum assign_algotithm{
    FIRST_FIT,
    BEST_FIT,
    WORST_FIT
};
//空闲块必然有序
//首次适应算法:空闲块按起始地址大小从小到大进行排序
//最佳适应算法:空闲块按空闲块大小从小到大进行排序
//最坏适应算法:空闲块按空闲块大小从大到小进行排序
struct free_block{
    bool is_allocated;
    size_type start_addr;
    size_type size;
    free_block(bool _is_allocated,int _start_addr,size_type _size){
        this->is_allocated = _is_allocated;
        this->start_addr = _start_addr;
        this->size = _size;
    }

    bool operator == (const free_block obj){
        return (this->is_allocated == obj.is_allocated &&
                this->size == obj.size &&
                this->start_addr == obj.start_addr);
    }
};


struct alloced_block{
    std::size_t pid;
    std::size_t size;
    std::size_t start_addr;
    std::string name;
    static std::size_t counter;
    alloced_block(){
        counter++;
        pid = alloced_block::counter;
    }
};

std::size_t alloced_block::counter = 0;


void rearrange_firstfit(std::list<free_block> *free_block_list){
    free_block_list->sort( [](free_block f1, free_block f2)->bool{ return f1.start_addr < f2.start_addr; });
}

void rearrange_bestfit(std::list<free_block> *free_block_list){
    free_block_list->sort( [](free_block f1, free_block f2)->bool{ return f1.size < f2.size; });
}
void rearrange_worstfit(std::list<free_block> *free_block_list){
    free_block_list->sort( [](free_block f1, free_block f2)->bool{ return f1.size > f2.size; });
}
int set_algorithm(){
    int algorithm = 0;
    std::cout << "\t1 - firstfit" << std::endl;
    std::cout << "\t2 - bestfit" << std::endl;
    std::cout << "\t3 - worstfit" << std::endl;
    std::cin >> algorithm;
}

void rearrange(std::list<free_block> *free_block_list,int algotirhm){
    switch (algotirhm){
        case 1:
            rearrange_firstfit(free_block_list);
            break;
        case 2:
            rearrange_bestfit(free_block_list);
            break;
        case 3:
            rearrange_worstfit(free_block_list);
            break;
    }
}


//分配空间
size_type memory_malloc(std::list<free_block> *free_block_list, size_type bytes_num);
//初始化空间
void memory_init(std::list<free_block> *free_block_list);
//释放空间
void memory_free(std::list<free_block> *free_block_list, free_block node);


unsigned long get_process_needs();

void display_menu(){
    std::cout << "1 - set memory size(default = " << INIT_SIZE << " )" << std::endl;
    std::cout << "2 - select memory allocation algorithm" << std::endl;
    std::cout << "3 - new process" << std::endl;
    std::cout << "4 - terminate a process" << std::endl;
    std::cout << "5 - display memory usage" << std::endl;
}

int main(){

    std::list<free_block> free_block_list;

    std::list<size_type> allocd_block_list;
    for (auto i = 0; i < 10; i++)
    {
        memory_malloc(&free_block_list, 100+100*i);
    }
    
    
    std::cout << "is_allocated" << "\t" << "start_addr" << "\t" << "size" << "\t" << std::endl;    
    for (auto iter = free_block_list.begin(); iter != free_block_list.end();iter++){
        std::cout << iter->is_allocated << "\t" <<
            iter->start_addr << "\t" << 
            iter->size << "\t" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "is_allocated" << "\t" << "start_addr" << "\t" << "size" << "\t" << std::endl;
    rearrange(&free_block_list, 1);
    for (auto iter = free_block_list.begin(); iter != free_block_list.end();iter++){
        std::cout << iter->is_allocated << "\t" <<
                iter->start_addr << "\t" << 
                iter->size << "\t" << std::endl;
    }
    for (auto i = 0; i < 10; i++)
    {
        //memory_free(&sys_free_block_list, free_block(true,100*i,100));
    }
       
    
    std::cout << std::endl;

    std::cout << "is_allocated" << "\t" << "start_addr" << "\t" << "size" << "\t" << std::endl;
    rearrange(&free_block_list, 2);
    for (auto iter = free_block_list.begin(); iter != free_block_list.end();iter++){
        std::cout << iter->is_allocated << "\t" <<
                iter->start_addr << "\t" << 
                iter->size << "\t" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "is_allocated" << "\t" << "start_addr" << "\t" << "size" << "\t" << std::endl;
    rearrange(&free_block_list, 3);
    for (auto iter = free_block_list.begin(); iter != free_block_list.end();iter++){
        std::cout << iter->is_allocated << "\t" <<
                iter->start_addr << "\t" << 
                iter->size << "\t" << std::endl;
    }

    return 0;
}


void memory_init(std::list<free_block> * free_block_list){
    free_block_list->push_back({false, 0, INIT_SIZE});
}

//分配内存 
size_type memory_malloc(std::list<free_block> * free_block_list,size_type bytes_num){
    if (free_block_list->empty()){
        memory_init(free_block_list);
    }
    free_block node{false,0,bytes_num};
    for (auto iter = free_block_list->begin(); iter != free_block_list->end(); iter++){
       
        //如果空闲块大于请求分配空间的大小
        if (iter->size >= node.size && 
                        iter->is_allocated == false){
            //正好相等
            if (node.size == iter->size){
                iter->is_allocated = true;
                node.start_addr = iter->start_addr;
                return node.start_addr;
            }
            else //分配末尾
            {
                
                node.is_allocated = true;
                node.start_addr = iter->start_addr;
                iter->size -= node.size;
                iter->start_addr += node.size;
                free_block_list->insert(iter,node);
                return node.start_addr;
            }
        }
    }
    //rearrange(free_block_list, set_algorithm());
    return 0;
}

//释放内存
void memory_free(std::list<free_block> * free_block_list,free_block node){

    for (auto iter = free_block_list->begin(); iter != free_block_list->end(); iter++){
        
        if (*iter == node){
            auto prev = iter;
            prev--;
            auto next = iter;
            next++;
            
            //如果该块的前一块或后一块是空闲区
            if (prev->is_allocated == false || next->is_allocated == false){
                //如果该块的前一块是空闲区
                if (prev->is_allocated == false){
                    iter->size += prev->size;
                    iter->start_addr = prev->start_addr;
                    iter->is_allocated = false;
                    free_block_list->remove(*prev);
                }
                //如果该块的后一块是空闲区
                if (next->is_allocated == false){
                    iter->size += next->size;
                    iter->is_allocated = false;
                    free_block_list->remove(*next);
                }

            }
           
            //如果该块的前一块和后一块都不是空闲区
            if (prev->is_allocated != false && next->is_allocated != false){
                iter->is_allocated = false;
            }
        }
    }
}

int alloced_mem(alloced_block * process){
    return -1;
}

void new_process(std::list<alloced_block> * alloced_block_list,std::size_t size){
    //新的进程,pid在构造时已完成初始化
    alloced_block new_pro;
    new_pro.name = "Process " + std::to_string(new_pro.pid);
    
    if (size > 0){
        new_pro.size = size;
    }
    //分配空间
    int ret = alloced_mem(&new_pro);
    //根据分配空间的结果选择
    if (ret == 1){
        alloced_block_list->push_back(new_pro);
    } else if (ret == -1){
        std::cout << "allocation fail" << std::endl;
    }
}