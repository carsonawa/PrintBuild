// funny :)
#define _CRT_SECURE_NO_WARNINGS // C函数：老子哪门子不安全了？
#include "PrintBuild.h"

/* 生成打印程序函数
 * path		: 输出文件指定路径
 * count	: 指定打印次数
 * text		: 指定打印内容
*/
void build(const char* path, int count, const char* text)
{
	// 打开文件
	FILE* output = NULL;
	printf("i: 正在打开并写入文件，路径: %s\n", path);
	output = fopen(path, "w");
	if (output == NULL)
	{
		// 如果出现异常则打印错误信息并退出
		int errnum = errno;
		fprintf(stderr, "E: %s (%X)\n", strerror(errnum), errno);
		fputs("E: 在打开文件的过程中发生错误，请检查路径是否合法。", stderr);
		exit(errnum);
	}

	// 写入头文件声明与main函数声明
	fputs("#include <stdio.h>\nint main() {\n", output);
	for (int i = 0; i < count; i++)
	{
		// 循环写入打印函数
		fprintf(output, "    puts(%s);\n", text); 
	}
	// 封闭main函数代码块
	fputc('}', output);

	// 关闭文件
	fclose(output);

	printf("i: 文件已写入: %s\n", path);
}

// 程序入口
int main(int argc, char* argv[])
{
	switch (argc)
	{
	case 1:
		// 如果没有参数传入则执行此代码
		build(".\\out.c", 114514, "啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊");
		break;
	case 2:
		// 如果传入一个则当做输出路径
		build(argv[1], 114514, "啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊");
		break;
	case 3:
		// 如果传入两个个则当做输出路径、输出内容
		build(argv[1], 114514, argv[2]);
		break;
	default:
	{
		// 如果传入两个个则当做输出路径、输出内容、次数
		int count;
		build(argv[1], sscanf(argv[3], "%d", &count), argv[2]);
		break;
	}
	}
	return 0;
}
