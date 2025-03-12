#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;

#define MAX_STACK_SIZE 1000

class MercuryEngine_ {
private:
    int stack[MAX_STACK_SIZE];
    pair<string, int> global_stack[MAX_STACK_SIZE];
    int stack_pointer = 0;
    int global_pointer = 0;
public:
    void push_float(float value);
    void store_global(const char* name);
    void load_global(const char* name);
    void binary_plus();
    void binary_sub();
    void binary_time();
    void binary_div();
    void call_function();
};

MercuryEngine_ createMercuryEngine() {
    MercuryEngine_ _engine = MercuryEngine_();
    return _engine;
}

void MercuryEngine_::push_float(float value) {
    stack[stack_pointer] = value;
    stack_pointer++;
}

void MercuryEngine_::store_global(const char *name) {
    global_stack[global_pointer] = make_pair(name, stack[stack_pointer - 1]);
    global_pointer++;
}

void MercuryEngine_::load_global(const char *name) {
    for (int i = 0; i < global_pointer; i++) {
        if (global_stack[i].first == name) {
            stack[stack_pointer] = global_stack[i].second;
            stack_pointer++;
            return;
        }
    }
    cerr << "Error: Variable " << name << " not found" << endl;
    exit(1);
}

void MercuryEngine_::binary_plus() {
    stack_pointer--;
    stack[stack_pointer - 1] += stack[stack_pointer];
}

void MercuryEngine_::binary_sub() {
    stack_pointer--;
    stack[stack_pointer - 1] -= stack[stack_pointer];
}

void MercuryEngine_::binary_time() {
    stack_pointer--;
    stack[stack_pointer - 1] *= stack[stack_pointer];
}

void MercuryEngine_::binary_div() {
    stack_pointer--;
    stack[stack_pointer - 1] /= stack[stack_pointer];
}

void MercuryEngine_::call_function()
{
}
