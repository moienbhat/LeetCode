#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqListMap;

    void updateFreq(int key) {
        auto nodeIt = keyNode[key];
        Node node = *nodeIt;
        int freq = node.freq;
        freqListMap[freq].erase(nodeIt);
        if (freqListMap[freq].empty()) {
            freqListMap.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        node.freq++;
        freqListMap[node.freq].push_front(node);
        keyNode[key] = freqListMap[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end()) return -1;
        int val = keyNode[key]->value;
        updateFreq(key);
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            updateFreq(key);
            return;
        }
        if (keyNode.size() >= capacity) {
            auto &listRef = freqListMap[minFreq];
            Node lastNode = listRef.back();
            keyNode.erase(lastNode.key);
            listRef.pop_back();
            if (listRef.empty()) freqListMap.erase(minFreq);
        }
        minFreq = 1;
        freqListMap[1].push_front(Node(key, value));
        keyNode[key] = freqListMap[1].begin();
    }
};

