# StacksandQueues

This project focuses on building two critical data structures: an array-based stack (ABS) and an array-based queue (ABQ). Both are template classes that can handle any data type and use dynamic memory to manage elements efficiently. Using these data structures, the project demonstrates essential ideas in data storage, manipulation, and dynamic memory management.

Array-Based Stack (ABS)

The ABS follows the last-in, first-out (LIFO) concept. The class has constructors that set its state, with the default constructor initializing it with a maximum capacity of one and a current size of zero. The copy constructor generates a deep copy, whereas the destructor handles dynamic memory.

Key methods are Push, which adds an element and resizes the array if it is full, and Pop, which removes and returns the top element while throwing a runtime_error exception if there is an underflow. The Peek method retrieves the top element without removing it, whereas the Get Size and Get Capacity methods offer the stack's current information.

Array-Based Queue (ABQ)

The First-In, First-Out (FIFO) principle is adhered to by the ABQ. It uses constructors and a destructor to control its state, just like the ABS. When using the Enqueue method, the array is resized as needed and an element is added to the end of the queue. By removing the front element and checking to see if the queue is empty, the Dequeue function throws a runtime error. Size and capacity methods give the most recent information, and the Peek method returns the front element without deleting it.

Implementation Strategy

Using the copy constructor, copy assignment operator, and destructor—the "Big Three"—the implementation places a strong emphasis on dynamic memory management. The array's capacity grows by a scale factor (by default set to 2.0) when it is full and decreases when utilization drops below a threshold in order to effectively handle dynamic resizing. This method ensures strong error handling while striking a balance between performance and memory utilization.

Conclusion

This project effectively showcases the use of templates, exception handling, dynamic memory management, and the creation of two basic data structures. The classes ABS and ABQ offer a strong basis for delving deeper into C++ data structures, showcasing their working principles and effectiveness in managing dynamic data sets.
