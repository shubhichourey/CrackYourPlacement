/*Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
push1 : pushes element into first stack.
push2 : pushes element into second stack.
pop1 : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
pop2 : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.
*/

class twoStacks {
     int *arr;
    int size;
    int t1, t2;
  public:

    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        t1 = -1; 
        t2 = size;
    
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(t2-t1 >1)
          arr[++t1]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
         if(t2-t1 >1)
          arr[--t2]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
         if(t1>=0)
        {
            int x = arr[t1--];
            return x;
        }
        return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
         if(t2<size)
        {
            int x = arr[t2++];
            return x;
        }
        return -1;
    }
};