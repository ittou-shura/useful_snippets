#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    Node* links[26];
    bool end;
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
        return;
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
            temp = temp->put(x);
        temp->set_end();
    }
    bool search(string s) {
        node* temp = root;
        for(auto &x : s){
            temp = temp->get(x);
            if(!temp) return false;
        }
        return temp->get_end();
    }
    bool starts_with(string s) {
        node* temp = root;
        for(auto &x : s){
            temp = temp->get(x);
            if(!temp) return false;
        }
        return true;
    }
};
