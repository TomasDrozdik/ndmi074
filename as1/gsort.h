#define _SORT_FUNC_INNER(prefix, item_type) void prefix ## _sort(item_type *array, int len)
#define _SORT_FUNC(prefix, item_type) _SORT_FUNC_INNER(prefix, item_type)

#if defined(SORT_CMP)
    #define _COMP(x, y) SORT_CMP(x, y) > 0
#elif defined(SORT_KEY)
    #define _COMP(x, y) SORT_KEY(x) > SORT_KEY(y)
#endif

#define _SWAP(x, y) \
    do { \
        typeof(*x) tmp = *x; \
        *x = *y; \
        *y = tmp; \
    } while (0)

_SORT_FUNC(SORT_PREFIX, SORT_TYPE)
{
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < len - 1; ++i) {
            if (_COMP(array[i], array[i + 1])) {
                swapped = 1;
                _SWAP(&array[i], &array[i + 1]);
            }
        }
    } while (swapped);
}

#undef _COMP
