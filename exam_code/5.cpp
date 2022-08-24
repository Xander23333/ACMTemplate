#include<unordered_map>
#include<list>
#include<iostream>
using namespace std;

class LRUCache{
    int m_cap;
    int m_size;
    unordered_map<int,list<pair<int,int>>::iterator> ma;
    list<pair<int,int>> li;

    LRUCache(int capacity){
        m_cap = capacity;
    }
    int get(int key){
        if (ma.find(key) != ma.end()){
            put(key,ma[key]->second);
            return ma[key]->second;
        }
        else return -1;
    }
    void put(int key, int value){
        if (ma.find(key) != ma.end()){
            li.erase(ma[key]);
            --m_size;
        } 
        while (m_size > m_cap){
            li.erase(li.back());
            --m_size;
        }
        li.push_front(make_pair(key,value));
        ma[key] = li.front();
        m_size++;
    }
};