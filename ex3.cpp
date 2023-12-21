#include <iostream>
#include <queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> decreasing;
    priority_queue<int, std::vector<int>, std::greater<int>> increasing;
    bool evn = true;

    MedianFinder() {
    }

    void addNum(int num) {
        evn =!evn;
        if(!evn){
            decreasing.push(num);
            increasing.push(decreasing.top());
            decreasing.pop();
        }else{
            increasing.push(num);
            decreasing.push(increasing.top());
            increasing.pop();
        }
    }

    double findMedian() {
        if (!evn) return increasing.top();
        return (decreasing.top() + increasing.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << std::endl;
    mf.addNum(3);
    cout << mf.findMedian() << std::endl;
    return 0;
}
