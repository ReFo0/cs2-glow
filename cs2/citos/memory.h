#pragma once
#include <cstdint>

auto module_client = (uintptr_t)GetModuleHandleA("client.dll");



template<typename T = uintptr_t, typename A>
T& read(A address) {
    auto addresss = (uintptr_t)address;
    if (addresss > 0x40000 && (addresss + sizeof(T)) < 0x7FFFFFFF0000)
        return *(T*)addresss;

    auto n = nullptr;
    return reinterpret_cast<T&>(n);
}


template <typename T>
void write(uintptr_t address, T data) {
    if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000)
        *(T*)(address) = data;
}
