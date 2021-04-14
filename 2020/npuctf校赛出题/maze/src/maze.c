#include<stdio.h>
#include<stdlib.h>

unsigned long long *map;

int main() {
    map = (unsigned long long *) malloc(49 * sizeof(unsigned long long));
    *map = 234545231;
    *(map + 1) = 344556530;
    *(map + 2) = 453523423550;
    *(map + 3) = 46563455531;
    *(map + 4) = 34524345344661;
    *(map + 5) = 34533453453451;
    *(map + 6) = 2343423124234420;
    *(map + 7) = 1423431;
    *(map + 8) = 54535240;
    *(map + 9) = 234242550;
    *(map + 10) = 23424242441;
    *(map + 11) = 2345355345430;
    *(map + 12) = 123422421;
    *(map + 13) = 2342420;
    *(map + 14) = 23414141;
    *(map + 15) = 23424420;
    *(map + 16) = 13535231;
    *(map + 17) = 2341;
    *(map + 18) = 23423414240;
    *(map + 19) = 1234422441;
    *(map + 20) = 53366745350;
    *(map + 21) = 253244531;
    *(map + 22) = 45463320;
    *(map + 23) = 24532661;
    *(map + 24) = 23433430;
    *(map + 25) = 23453660;
    *(map + 26) = 3453661;
    *(map + 27) = 3453326640;
    *(map + 28) = 245332535325535341;
    *(map + 29) = 7568546234640;
    *(map + 30) = 23445576731;
    *(map + 31) = 234534460;
    *(map + 32) = 234364561;
    *(map + 33) = 34455344551;
    *(map + 34) = 2345670;
    *(map + 35) = 2354657721451;
    *(map + 36) = 23464664430;
    *(map + 37) = 245646441;
    *(map + 38) = 234644640;
    *(map + 39) = 23643643334561;
    *(map + 40) = 2346463450;
    *(map + 41) = 2343345620;
    *(map + 42) = 3444651;
    *(map + 43) = 23451;
    *(map + 44) = 67541;
    *(map + 45) = 34575860;
    *(map + 46) = 67856741;
    *(map + 47) = 567678671;
    *(map + 48) = 567565671;
    unsigned long long *addr = map;
    printf("Input your flag:\n");
    while (1) {

        char c=getchar();
        if (c == '\n') {
            continue;
        }
        if (c == 'h') {
            if ((addr - map) % 7 == 0) {
                continue;
            } else {
                addr -= 1;
            }
        } else if (c == 'j') {
            if ((addr - map) >= 0 && (addr - map) <= 6) {
                continue;
            } else {
                addr -= 7;
            }
        } else if (c == 'k') {
            if ((addr - map) >= 42 && (addr - map) <= 48) {
                continue;
            } else {
                addr += 7;
            }
        } else if (c == 'l') {
            if ((addr - map) % 7 == 6) {
                continue;
            } else {
                addr += 1;
            }
        } else {
            continue;
        }
        unsigned long long tmp = *addr;
        if (tmp == 567565671) {
            printf("Congratulations!\n");
            printf("The flag is: flag{ YOUR INPUT }\n");
            exit(0);
        }
        if (tmp & 1) {
            continue;
        } else {
            break;
        }

    }
    printf("You Failed!\n");
    return 0;
}