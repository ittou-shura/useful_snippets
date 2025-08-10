#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    Node* links[26];
    bool end;
    Node() : end(false){
        for(int i = 0; i<26; i++)
            links[i] = nullptr;
    }
    bool contains(char x){
        return links[x - 'a'];
    }
    Node* put(char x) {
        return links[x - 'a'] = new Node();
    }
    Node* get(char x) {
        return links[x - 'a'];
    }
    bool get_end() {
        return end;
    }
    void set_end() {
        end = 1;
    }
} node;

struct Trie{
    node* root;
    Trie(){
        root = new node();
    }
    void insert(string s) {
        node* temp = root;
        for(auto &x : s)
            temp = temp->contains(x) ? temp->get(x) : temp->put(x);
        temp->set_end();
    }
    bool search(string s) {
        node* temp = root;
        for(auto &x : s){
            if(temp->contains(x))  
                temp = temp->get(x);
            else    
                return false;
        }
        return temp->get_end();
    }
    bool starts_with(string s) {
        node* temp = root;
        for(auto &x : s){
            if(temp->contains(x))
                temp = temp->get(x);
            else 
                return false;
        }
        return true;
    }
};
