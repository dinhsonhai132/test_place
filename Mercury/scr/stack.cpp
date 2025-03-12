#include "stack.h"

stack *MerCompiler_Stack_new(void) {
    stack *s = new stack;
    s->mode = "";
    s->cc = "";
    s->cval = 0;
    s->err = "";
    s->s_table = MerCompiler_Table_new();
    s->s_symtable = MerCompiler_SymbolTable_new();
    return s;
}
table *MerCompiler_Table_new(void) {
    table *t = new table;
    t->cval = 0;
    t->cstr = "";
    t->err = "";
    t->table[0] = nullptr;
    return t;
}
symtable *MerCompiler_SymbolTable_new(void) {
    symtable *s = new symtable;
    s->name = "";
    s->value = 0;
    s->type = "";
    s->err = "";
    s->stack[0] = nullptr;
    return s;
}

int MerCompiler_free_stack(stack *s) {
    if (!s) return __FAILURE__;
    delete[] s;
    return __SUCCESS__;
}
int MerCompiler_free_table(table *t) {
    if (!t) return __FAILURE__;
    delete[] t;
    return __SUCCESS__;
}
int MerCompiler_free_symboltable(symtable *s) {
    if (!s) return __FAILURE__;
    delete[] s;
    return __SUCCESS__;
}

stack *MerCompiler_stack_setup(stack *s, table *t, symtable *sy) {
    if (!s || !t || !sy) return nullptr;
    s = MerCompiler_Stack_new();
    s->s_table = t;
    s->s_symtable = sy;
    return s;
}

table *MerCompiler_table_setup(float cval, int cidx = 0)
{
    table *t = MerCompiler_Table_new();
    t->cval = cval;
    return t;
}

symtable *MerCompiler_symboltable_setup(string name, int value, string type) {
    symtable *s = MerCompiler_SymbolTable_new();
    s->name = name;
    s->value = value;
    s->type = type;
    return s;
}
