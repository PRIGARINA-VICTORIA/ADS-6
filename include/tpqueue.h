// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int first;
    int last;

 public:
    TPQueue() : first(0), last(0) { }
    void push(T x) {
        if ((last - first) >= size) {
            throw "Full!";
        } else {
            int j = first;
            while (j < last) {
                if (x.prior > arr[j % size].prior) {
                    for (int i = last - 1; i >= j; i--) {
                        arr[(i + 1) % size] = arr[i % size];
                    }
                    arr[j % size] = x;
                    last++;
                    return;
                }
                j++;
            }
            arr[last++ % size] = x;
        }
    }
    T& pop() {
        return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
