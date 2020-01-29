#include <lcthw/hashmap_algos.h>
#include <lcthw/bstrlib.h>

const uint32_t FNV_PRIME = 16777619;
const uint32_t FNV_OFFSET_BASIS = 2166136261;

uint32_t Hashmap_fnv1a_hash(void *data)
{
    bstring s = (bstring)data;
    uint32_t hash = FNV_OFFSET_BASIS;
    int i = 0;

    for(i = 0; i < blength(s);i++) {
        hash ^= bchare(s, i , 0);
        hash *= FNV_PRIME;
    }

    return hash;
}
