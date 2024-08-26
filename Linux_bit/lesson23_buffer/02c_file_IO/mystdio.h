/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-26 19:03:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-26 19:33:36
 */
// #pragma once
#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include <string.h>

#define SIZE 1024

#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_ALL 4

typedef struct IO_FILE
{
	int fileno; // fd
	int flag;	// 刷新方式 立即刷新、行刷新、全刷新
	// char inbuffer[SIZE]; //输入缓冲区
	// int in_pos;
	char outbuffer[SIZE]; // 输出缓冲区
	int out_pos;		  //
} _FILE;

_FILE *_fopen(const char *filename, const char *flag);
int _fwrite(_FILE *fp, const char *s, int len);
void _fclose(_FILE *fp);

#endif