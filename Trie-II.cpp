#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int endCount, prefixCount;
    Node() : endCount(0), prefixCount(0) {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }
    bool contains(char x) { return links[x - 'a']; }
    Node* get(char x) { return links[x - 'a']; }
    Node* put(char x) { return links[x - 'a'] = new Node(); }
    void inc_end() { endCount++; }
    void inc_pref() { prefixCount++; }
    void dec_end() { endCount--; }
    void dec_pref() { prefixCount--; }
    int get_pref() { return prefixCount; }
    int get_end() { return endCount; }
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }

    void insert(const string &s) {
        Node* temp = root;
        temp->inc_pref();
        for (char x : s) {
            if (!temp->contains(x))
                temp->put(x);
            temp = temp->get(x);
            temp->inc_pref();
        }
        temp->inc_end();
    }

    int count_prefix(const string &s) {
        Node* temp = root;
        for (char x : s) {
            if (!temp->contains(x))
                return 0;
            temp = temp->get(x);
        }
        return temp->get_pref();
    }

    int count_equals(const string &s) {
        Node* temp = root;
        for (char x : s) {
            if (!temp->contains(x))
                return 0;
            temp = temp->get(x);
        }
        return temp->get_end();
    }

    void erase(const string &s) {
        if (count_equals(s) == 0) return; 
        Node* temp = root;
        temp->dec_pref();
        for (char x : s) {
            temp = temp->get(x);
            temp->dec_pref();
        }
        temp->dec_end();
    }
};

