/* Full Compiler Check (no preprocessor) */

int main(int argc, char *argv[])
{
    /* Types */
    int x = 10, y = 0, z = 0;
    
    float x1 = 2.78867;
    char a = 'a';
    char *s = "This is a string";

    
    /* Operators (No Type Coersion) */
    x = 1 + 2;
    x += 1;

    x4 = y4 - z4;
    x4 -= 2;

    x1 = 1 * 2;
    x2 *= 3;

    x1 = x1 / 2;
    x2 /= 2;

    x = x % 10;
    x %= 10;

    x = x & 1;
    x &= 1;

    x = x | 1;
    x |= 1;

    x = x ^ 2;
    x ^= 2;

    x = ~x;

    x = !x;

    x = x << 1;
    x <<= 1;

    x4 = x4 >> 1;
    x4 >>= 1;
    
    x < 1;
    y > 0;

    x == y;


    return 0;
}
