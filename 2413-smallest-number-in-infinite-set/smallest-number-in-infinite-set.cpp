class SmallestInfiniteSet {
public:
    int curr;
    set<int> added;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if(!added.empty()){
            int smallest = *added.begin();
            added.erase(added.begin());
            return smallest;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num<curr){
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */