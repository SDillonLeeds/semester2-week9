
typedef struct _data {
    int value;
} Data;

typedef struct _queue {
    unsigned int blockSize;          // default block-size
    unsigned int size;               // currently allocated size
    struct _data **data;    // queue array of Data*
    
    int front, back;
    unsigned int length; //Current length

} Queue;
