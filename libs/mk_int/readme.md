# mk_int

## Unsigned integer arithmetic in C89/C90.

There are no dependencies except of C89/C90 capable compiler.
Not even the C standard library except of size_t, CHAR_BIT, UINT_MAX and similar limits (and assert in debug mode).
And even those can be easily eliminated.

### Example:

```cpp
#include "exact/mk_uint_64.h"

int main()
{
    static struct mk_uint64_s const s_boring = mk_uint64_c(0x01234567, 0x89abcdef);
    static struct mk_uint64_s const s_funny = mk_uint64_c(0xcafebabe, 0x0badf00d);

    struct mk_uint64_s a;
    struct mk_uint64_s b;
    struct mk_uint64_s c;
    unsigned char disk_buffer[8]; /* little endian */
    unsigned char network_buffer[8]; /* big endian */

    a = s_boring;
    b = s_funny;
    mk_uint64_mul(&c, &a, &b);
    /* 0x0123456789abcdef * 0xcafebabe0badf00d == 0x64027fa87e4c8523 */

    mk_uint64_to_buff_le(&c, &disk_buffer);
    /* 0x64027fa87e4c8523 == 23 85 4c 7e a8 7f 02 64 */

    mk_uint64_to_buff_be(&c, &network_buffer);
    /* 0x64027fa87e4c8523 == 64 02 7f a8 7e 4c 85 23 */

    /*

    Other operations:

    assign zero
    assign one
    assign integer, long, size_t
    convert to integer, long, size_t
    read from buffer (big or little endian)
    write to buffer (big or little endian)
    compare with zero, compare with maximum possible value
    binary not, or, and, xor
    shift left and right, rotate left and right
    equal to, not equal to, less than, less or equal than, greater than, greater or equal than
    increment by one, decrement by one
    add, subtract, multiply, divide, remainder

    Integer sizes of 8, 16, 32, 64, 128 bits.
    Larger integers can be easily added.

    */
}
```
