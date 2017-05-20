template<typename T>
struct extract_value_type
{
    typedef T value_type;
};

template<template<typename> class X, typename T>
struct extract_value_type<X<T>>
{
    typedef T value_type;
};