#ifndef GLOBAL_H
#define GLOBAL_H

typedef enum {V_Type, I_Type, F_Type, S_Type, ID_Type, B_Type} Symbol_type;

typedef struct Value Value;
struct Value
{
    union 
    {
        int i;
        float f;
        char *s;
        struct {
            char * id_name;
            // struct Value *val_ptr;
        };
    };

    Symbol_type symbol_type;
    
};


struct Value * val;

#endif

