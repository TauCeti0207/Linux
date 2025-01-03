#include "mystdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define FILE_MODE 0666

// "w", "a", "r"
// 封装open
_FILE *_fopen(const char *filename, const char *flag)
{
	assert(filename);
	assert(flag);

	int f = 0;
	int fd = -1;
	if (strcmp(flag, "w") == 0)
	{
		f = (O_CREAT | O_WRONLY | O_TRUNC);
		fd = open(filename, f, FILE_MODE);
	}
	else if (strcmp(flag, "a") == 0)
	{
		f = (O_CREAT | O_WRONLY | O_APPEND);
		fd = open(filename, f, FILE_MODE);
	}
	else if (strcmp(flag, "r") == 0)
	{
		f = O_RDONLY;
		fd = open(filename, f);
	}
	else
	{
		return NULL;
	}

	if (fd == -1)
		return NULL;

	_FILE *fp = (_FILE *)malloc(sizeof(_FILE));
	if (fp == NULL)
		return NULL;

	fp->fileno = fd;
	fp->flag = FLUSH_LINE; // 行刷新
	// fp->flag = FLUSH_ALL;
	fp->out_pos = 0; // 最开始缓冲区没有内容

	return fp;
}

// FILE中的缓冲区的意义是什么？？？？
/**
 * 向文件流中写入数据
 *
 * 该函数负责将一段字符数据写入到文件流的输出缓冲区中，并在特定条件下将缓冲区的内容刷新到文件中
 *
 * @param fp 文件指针，指向要写入的文件流
 * @param s 要写入的字符数据指针
 * @param len 要写入的字符数据的长度
 *
 * @return 返回成功写入的字符数量
 */
int _fwrite(_FILE *fp, const char *s, int len)
{
	// 示例字符串："abcd\n"
	memcpy(&fp->outbuffer[fp->out_pos], s, len); // 没有做异常处理, 也不考虑局部问题
	fp->out_pos += len;

	// 根据文件流的标志决定是否需要刷新缓冲区到文件
	if (fp->flag & FLUSH_NOW)
	{
		write(fp->fileno, fp->outbuffer, fp->out_pos);
		fp->out_pos = 0;
	}
	else if (fp->flag & FLUSH_LINE)
	{
		if (fp->outbuffer[fp->out_pos - 1] == '\n')
		{ // 不考虑其他情况
			write(fp->fileno, fp->outbuffer, fp->out_pos);
			fp->out_pos = 0;
		}
	}
	else if (fp->flag & FLUSH_ALL)
	{
		if (fp->out_pos == SIZE)
		{
			write(fp->fileno, fp->outbuffer, fp->out_pos);
			fp->out_pos = 0;
		}
	}

	return len;
}

/**
 * 函数名：_fflush
 * 功能：将缓冲区的数据强制写入到文件中
 * 参数：fp - 指向文件的结构体指针
 * 描述：本函数的作用是将文件输出缓冲区中的内容强制写入到文件中。
 *       它首先检查输出缓冲区是否有数据需要写入，如果有，则通过write函数将数据写入到文件，
 *       并将输出缓冲区的位置指针重置为0，表示已经成功写入所有数据。
 * 注意：本函数假定fp指向的文件结构体和缓冲区是有效的。
 */
void _fflush(_FILE *fp)
{
	// 检查是否有数据需要写入
	if (fp->out_pos > 0)
	{
		// 将缓冲区的数据写入到文件
		write(fp->fileno, fp->outbuffer, fp->out_pos);
		// 重置输出缓冲区的位置指针
		fp->out_pos = 0;
	}
}

void _fclose(_FILE *fp)
{
	if (fp == NULL)
		return;
	_fflush(fp);
	close(fp->fileno);
	free(fp);
}
