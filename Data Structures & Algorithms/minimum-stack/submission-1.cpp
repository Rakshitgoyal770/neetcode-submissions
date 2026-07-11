class MinStack {
public:
    vector<int> vac;
    vector<int> minS = {INT_MAX};

    MinStack() {
        // Constructor
    }

    void push(int val) {
        vac.push_back(val);
        minS.push_back(min(minS.back(), val));
    }

    void pop() {
        if (vac.empty()) {
            return ;
        }
            vac.pop_back();
            minS.pop_back();
        
    }

    int top() {
        return vac.back();
    }

    int getMin() {
        if (minS.empty()) {
            return -1;
        }


        return minS.back();
    }
};
