#include <iostream>
using namespace std;

struct Test {
    uint8_t *a;
    uint8_t *b;
};

int main(){
    int aaa=-32;
    signed int ccc;

    ccc = (signed int)aaa;

    uint32_t bbb=0;
    uint32_t i = 0;

    bbb = aaa & 0x01;

    while(1)
    {
        aaa =   aaa >> 1;
        if(aaa & 0x01)
        {
            bbb += 1;
        }
        i += 1;
        if(i==63)
            break;
    }

    printf("bbb=%d", bbb);
    printf("\r\n");
    printf("ccc=%u",ccc);

    system("pause");
    return 0;
}