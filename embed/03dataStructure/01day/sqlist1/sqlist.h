
/*
typedef int data_t;
#define N 128

struct sqlist_t {
	data_t data[N];
	int last;
};

typedef struct sqlist_t sqlist;//sqlist L; struct sqlist_t L;
typedef struct sqlist_t * sqlink;// struct sqlist_t * p; sqlink p;
*/

typedef int data_t;
#define N 128 

typedef struct {
	data_t data[N];
	int last;
}sqlist, *sqlink;

sqlink list_create();
int list_clear(sqlink L);
int list_delete(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink L);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);
int list_show(sqlink L);
