#include <stdio.h>
#include <string.h>
#define N 32
struct student{
	int no;         //考虑字节对齐 **** int4个字节
	char name[N];   //32个字节 对齐了
	float score;    // 4个字节  总共40字节
}s3 = {3,"s3",90},s4 = {4,"s4",89};

int main(int argc, const char *argv[])
{
	struct student s1,s2;
#if 0
	s1.name[0] = 'z';
	s1.name[1] = 's';
	s1.name[2] = 'd';
#endif
	strcpy(s1.name,"s1");
	s1.score = 90;

	s1.score = 99;
	s1.name[0] = 'S';
	printf("%d %s %.2f\n",s1.no,s1.name,s1.score);


	s2 = s1;
	s2.no =2;

	printf("%d %s %.2f\n",s2.no,s2.name,s2.score);
	printf("%d %s %.2f\n",s3.no,s3.name,s3.score);
	printf("%d %s %.2f\n",s4.no,s4.name,s4.score);

	printf("%ld %ld\n",sizeof(struct student),sizeof(s1));


	return 0;
}
