///////////////////////////////////////////////////////////////////////////////
///////////////////////ONLY WORK IN THIS FILE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;
template <typename T>
class ABS{
private:
  T *data;
  float scale_factor;
  int size;
  int capacity;

  void resize(int intial_capacity){
    T* data_one = new T[intial_capacity];
    for (int i = 0; i < size; i++){
      data_one[i] = data[i];
    }
    delete[] data;
    data = data_one;
    capacity = intial_capacity;
  }
public:
  ABS(){
     size = 0;
     capacity = 1;
     scale_factor = 2.0f;
    data = new T[capacity];

  }
  ABS (int intial_capacity){
    size = 0;
    capacity = intial_capacity;
    scale_factor = 2.0f;
    data = new T[capacity];

  }
  ABS(ABS &rhs){
    size = rhs.size;
    capacity = rhs.capacity;
    scale_factor = rhs.scale_factor;
    data = new T[capacity];
    for (int i= 0; i < size; i++){
      data[i] = rhs.data[i];
    }
  }

  ABS& operator= (ABS &rhs){
    if(this ==&rhs){
      return *this;
    }
    delete[] data;

    size = rhs.size;
    capacity = rhs.capacity;
    scale_factor = rhs.scale_factor;
    data = new T[capacity];

    for (int i = 0; i < size; i++){
      data[i] = rhs.data[i];
    }
    return *this;


  }


~ABS (){
  delete[] data;

}

  void push(T value){
    if (size == capacity){
      resize(capacity * scale_factor);
    }
    data[size]= value;
    size++;
  }

  T pop(){
    if (size == 0){
      throw runtime_error("Stack is empty");
    }

    T top = data[--size];
    if (size < capacity / scale_factor && capacity > 1){
      resize(capacity / scale_factor );
    }

    return top;
  }

  T peek() {
    if(size == 0){
      throw runtime_error("Stack is empty");
    }
    return data[size -1];
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


