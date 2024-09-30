#include <iostream>
#include <bits/c++config.h>

template<typename T, std::size_t size>
class List{
    private:

        T data[size];
        std::size_t size_;

    public:

    List() : size_(0) {}

    void push_back(const T& value){
        if(size_ < size){
            for(std::size_t i = size_; i != 0; --i){
                data[i] = data[i - 1];
            }
            data[0] = value;
            ++size_;
        }else{
            std::cerr << "List overflow" << std::endl;
        }
    }

    void pop_back(){
        if(size_ > 0){
            for(std::size_t i = 0; i != size_ - 1; ++i){
                data[i] = data[i + 1];
            }
            --size_;
        }else{
            std::cerr << "List is empty" << std::endl;
        }
    }

    void insert_at(T value, std::size_t index){
        if(index <= size_ && size_ < size){
            for(std::size_t i = size_; i != index; --i){
                data[i] = data[i - 1];
            }
            data[index] = value;
            ++size_;
        }else{
            std::cerr << "Invalid index or list is full" << std::endl;
        }
    }

    void remove_at(std::size_t index){
        if(index < size_){
            for(std::size_t i = index; i != size_ - 1; ++i){
                data[i] = data[i + 1];
            }
            --size_;
        }else{
            std::cerr << "Invalid index" << std::endl;
        }
    }

    int find(T value) const{
        for(std::size_t i = 0; i != size_; ++i){
            if(data[i] == value){
                return i;
            }
        }
        return -1;
    }

    void print() const{
        for(std::size_t i = 0; i!= size_; ++i){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    List<int, 5> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.print();

    list.insert_at(6, 2);
    list.print();

    list.remove_at(2);
    list.print();

    list.insert_at(6, 2);
    list.print();

    std::cout << "Index of 3: " << list.find(3) << std::endl;

    std::cout << "Index of 4: " << list.find(4) << std::endl;

    return 0;
}