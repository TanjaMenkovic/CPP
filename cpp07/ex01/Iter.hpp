#pragma once

#include <iostream>

template <typename T>
void    iter(T* arr, size_t len, void (*f)(T&))
{
    if (arr == NULL || f == NULL)
        return ;

    size_t i;
    for(i = 0; i < len; i++)
        f(arr[i]);
}