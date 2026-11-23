// FOB - Compiler Backend API
// Copyright (c) 2026 notjoshki
// https://github.com/notjoshki/fob.git

#include "fob_data_type.h"
#include "fob_error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_TYPE_CAPACITY 4

FOB_Data_Type_List create_fob_data_type_list() {
    return (FOB_Data_Type_List){ .types = malloc(DATA_TYPE_CAPACITY * sizeof(FOB_Data_Type)), .count = 0, .capacity = DATA_TYPE_CAPACITY };
}

void delete_fob_data_type_list(FOB_Data_Type_List *list) {
    free(list->types);
}

void fob_push_data_type(FOB_Data_Type_List *list, FOB_Data_Type data_type) {
    if (list->count + 1 > list->capacity) {
        list->capacity *= 2;
        list->types = realloc(list->types, list->capacity * sizeof(FOB_Data_Type));
    }

    list->types[list->count++] = data_type;
}

char *fob_data_type_to_string(const FOB_Data_Type *data_type) {
    char *str = malloc(data_type->pointers + 6);

    switch (data_type->primitive_type) {
        case FOB_PRIM_VOID:
            strcpy(str, "void");
            break;
        case FOB_PRIM_BOOL:
            strcpy(str, "bool");
            break;
        case FOB_PRIM_CHAR:
            strcpy(str, "char");
            break;
        case FOB_PRIM_I8:
            strcpy(str, "i8");
            break;
        case FOB_PRIM_I16:
            strcpy(str, "i16");
            break;
        case FOB_PRIM_I32:
            strcpy(str, "i32");
            break;
        case FOB_PRIM_I64:
            strcpy(str, "i64");
            break;
        case FOB_PRIM_ISIZE:
            strcpy(str, "isize");
            break;
        case FOB_PRIM_U8:
            strcpy(str, "u8");
            break;
        case FOB_PRIM_U16:
            strcpy(str, "u16");
            break;
        case FOB_PRIM_U32:
            strcpy(str, "u32");
            break;
        case FOB_PRIM_U64:
            strcpy(str, "u64");
            break;
        case FOB_PRIM_USIZE:
            strcpy(str, "usize");
            break;
        case FOB_PRIM_F32:
            strcpy(str, "f32");
            break;
        case FOB_PRIM_F64:
            strcpy(str, "f64");
            break;
        default:
            fob_alert("Uncaught primitive type %u\n", data_type->primitive_type);
            str[0] = '\0';
            break;
    }

    for (size_t i = 0; i < data_type->pointers; i++)
        strcat(str, "*");

    return str;
}
