class MyCircularDeque {
    private:
        int m_capacity;
        int m_size;
        vector<int> m_arry;
        int m_front;
        int m_last;
    public:
        /** Initialize your data structure here. Set the size of the deque to be k. */
        MyCircularDeque(int k) {
            m_capacity = k + 1;
            m_arry.assign(m_capacity, 0);
            m_front = 0;
            m_last = 0;
        }

        bool isFull() {
            return (m_last + 1) % m_capacity == m_front;
        }

        bool isEmpty() {
            return m_front == m_last;
        }

        /** Adds an item at the front of Deque. Return true if the operation is successful. */
        bool insertFront(int value) {
            if (isFull()) {
                return false;
            }
            m_front = (m_front - 1 + m_capacity) % m_capacity;
            m_arry[m_front] = value;
            return true;
        }

        /** Adds an item at the rear of Deque. Return true if the operation is successful. */
        bool insertLast(int value) {
            if (isFull()) {
                return false;
            }
            m_arry[m_last] = value;
            m_last = (m_last + 1) % m_capacity;
            return true;
        }

        /** Deletes an item from the front of Deque. Return true if the operation is successful. */
        bool deleteFront() {
            if (isEmpty()) {
                return false;
            }
            m_front = (m_front + 1) % m_capacity;
            return true;
        }

        /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
        bool deleteLast() {
            if (isEmpty()) {
                return false;
            }
            m_last = (m_last - 1 + m_capacity) % m_capacity;
            return true;
        }

        /** Get the front item from the deque. */
        int getFront() {
            if (isEmpty()) {
                return -1;
            }
            return m_arry[m_front];
        }

        /** Get the last item from the deque. */
        int getRear() {
            if (isEmpty()) {
                return -1;
            }
            return m_arry[(m_last - 1 + m_capacity) % m_capacity];
        }

};

