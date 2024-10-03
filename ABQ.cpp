///////////////////////////////////////////////////////////////////////////////
///////////////////////ONLY WORK IN THIS FILE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;
template <typename T>
class ABQ{
private:
  T *data;
  float scale_factor;
  int size;
  int capacity;
  int front_stack;
  int back_stack;

public:
  ABQ(){
    size = 0;
    capacity = 1;
    front_stack = 0;
    back_stack = 0;
    scale_factor = 2.0f;
    data = new T[capacity];
  }

  ABQ (int initial_capacity){
    size = 0;
    front_stack = 0;
    back_stack = 0;
    scale_factor = 2.0f;


    if (initial_capacity < 1){
      throw runtime_error(" Stack is empty");
  }

    capacity = initial_capacity;
    data = new T[capacity];
  }

  ABQ (const ABQ& rhs){
    size = rhs.size;
    capacity = rhs.capacity;
    front_stack = rhs.front_stack;
    back_stack = rhs.back_stack;
    scale_factor = rhs.scale_factor;

    data = new T[capacity];
    for (int i = 0; i < size; i++){
      data[i] = rhs.data[front_stack + i];
    }
  }

  ABQ& operator=(const ABQ& rhs){
    if (this == &rhs){
      return *this;
    }

    delete[] data;

    size = rhs.size;
    capacity = rhs.capacity;
    front_stack = rhs.front_stack;
    back_stack = rhs.back_stack;
    scale_factor = rhs.scale_factor;

    data = new T[capacity];
    for (int i = 0; i < size; i++){
      data[i] = rhs.data[front_stack + i];
    }
    return *this;
  }

    ~ABQ (){
      delete[] data;
    }

    void enqueue(T value){

      if (size == capacity){
        int capacity_new = capacity * scale_factor;
        T* data_new = new T[capacity_new];


        for (int i = 0; i < size; i++){
          int j = front_stack + i;
          if (j >= capacity){
            j -= capacity;
          }
          data_new[i] = data[j];
      }

        delete[] data;
        data = data_new;
        capacity = capacity_new;
        front_stack = 0;
        back_stack = size;

      }
      data[back_stack] = value;
      back_stack++;
      size++;
      if(back_stack >= capacity){
        back_stack = 0;
        }

}


    T dequeue(){
      if(size == 0){
        throw runtime_error("Stack is empty");

      }
      T dequeue_value = data[front_stack];
      front_stack++;
      if (front_stack >= capacity){
        front_stack = 0;
      }
      size--;

      if (size < capacity / scale_factor && capacity > 1){
        int capacity_new = capacity / scale_factor;
        if (capacity_new < 1){
          capacity_new = 1;
        }

        T* data_new = new T[capacity_new];

        for (int i = 0; i < size; i++){
          int j = front_stack + i;
          if (j >= capacity) {
            j -= capacity;
            }
          data_new[i] = data[j];
        }

        delete[] data;
        data = data_new;
        capacity = capacity_new;
        front_stack = 0;
        back_stack = size;


    }
    return dequeue_value;


    }

    T peek(){
      if (size == 0){
        throw runtime_error("Stack is empty");
      }

      return data[front_stack];

    }
    int getSize(){
      return size;
    }

    int getMaxCapacity(){
      return capacity;
    }

    T* getData(){
      return data;
    }


};
