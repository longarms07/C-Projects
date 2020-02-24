#include <iostream>
#include <cassert>
#include <string>
#include <list>


using namespace std;

class queue{
    private:
        list<int> backingList;

    public:
        queue(){
            backingList = {};
        }

        void put(int item){
            backingList.push_back(item);
        }

        int get(){
            int item = backingList.front();
            backingList.pop_front();
            return item;
        }

        void print(){
            cout << "Queue is [";
            for(int item :backingList){
                cout << item << ",";
            }
            cout << "]\n";
        }
};

void QTest();
int main(){
    QTest();
}

void QTest(){
    queue q = queue();
    for(int i=0;i<21;i++){
        q.put(i);
        q.print();
    }
    for(int i=0;i<21;i++){
        assert(q.get() == i);
        q.print();
    }
}