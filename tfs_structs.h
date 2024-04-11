#include <stdint.h>

#define TINYFS_MAGIC_NUM  0x74696E79
#define TINYFS_BLOCK_SIZE       4096

struct super_block {
    uint32_t fs_type;          /*number for tinyfs identification*/
    uint32_t block_size;       /*size of each block*/
    uint32_t block_num;        /*total number of blocks in fs*/

    uint32_t padding[TINYFS_BLOCK_SIZE - 3 * sizeof(uint32_t)];
}

struct bitmap_block {
    uint32_t *bits;            /*array of bits to indicate free/in-use status*/
    uint32_t block_num;

    uint32_t padding[TINYFS_BLOCKSIZE - 2 * sizeof(uint32_t)];
}

struct inode {
    uint32_t status;
    uint32_t size;
    uint32_t direct[POINTERS_PER_IODE];
    uint32_t indirect;
}
    

    
